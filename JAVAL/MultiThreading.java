import java.lang.Thread;

class MyThread1 extends Thread 
{
    private int count = 0;
    @Override
    public void run() {
        System.out.println("Thread is running -- by extending Thread class....");
        try 
        {
            for(int i = 0; i < 10; i++) {
                System.out.println("MyThread1: " + i);
                synchronizedCounter();
                System.out.println(unsynchronizedMethod());
                Thread.sleep(400);
            }
        } catch (Exception e) {
            System.out.println("Thread is interrupted...");
        } finally {
            System.out.println("MyThread1 exiting.....");
        }
    }

    public synchronized void synchronizedCounter() {
        count++;
        System.out.println("synchronized counter incremented by 1... Counter =" + count);
        if (count == 5) {
            notify();
        }
    }

    public synchronized String unsynchronizedMethod() {
        return "un synchronized method called..";
    }
}

class MyThread2 implements Runnable {
    private int count = 0;

    @Override
    public void run() {
        System.out.println("Thread is running -- by implementing Runnable interface....");
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println("MyThread2: " + i);
                synchronizedCounter();
                System.out.println(unsynchronizedMethod());
                Thread.sleep(400);
            }
        } catch (Exception e) {
            System.out.println("Thread is interrupted...");
        } finally {
            System.out.println("MyThread2 exiting.....");
        }
    }

    public synchronized void synchronizedCounter() {
        count++;
        System.out.println("synchronized counter incremented by 1... Counter =" + count);
        if (count == 5) {
            notify();
        }
    }

    public synchronized String unsynchronizedMethod() {
        return "un synchronized method called..";
    }
}

public class MultiThreading {
    public static void main(String[] args) throws InterruptedException {
        Thread t1[] = new Thread[5];
        Thread t2[] = new Thread[5];

        for (int i = 0; i < 5; i++) {
            t1[i] = new MyThread1();
            t2[i] = new Thread(new MyThread2());

            System.out.println("state of MyThread1 " + i + " before start: " + t1[i].getState());
            t1[i].start();
            System.out.println("State of MyThread1 " + i + " after starting: " + t1[i].getState());

            System.out.println("state of MyThread2 " + i + " before start: " + t2[i].getState());
            t2[i].start();
            System.out.println("State of MyThread2 " + i + " after starting: " + t2[i].getState());

            synchronized (t1[i]) {
                while (t1[i].isAlive()) {
                    t1[i].wait();
                }
            }

            synchronized (t2[i]) {
                while (t2[i].isAlive()) {
                    t2[i].wait();
                }
            }

            System.out.println("state of MyThread1 " + i + " after completed: " + t1[i].getState() + "\n\n");
            System.out.println("state of MyThread2 " + i + " after completed: " + t2[i].getState() + "\n\n");
        }
    }
}