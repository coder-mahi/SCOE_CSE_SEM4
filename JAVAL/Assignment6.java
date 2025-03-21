import java.lang.Thread;
class MyThread1 extends Thread{
    private int count = 0;

    @Override
    public void run() {
        System.out.println("Thread is running -- by extending Thread class....");
        try
        {
            for(int i=0;i<10;i++){
                System.out.println("My thread:>"+i);

                synchronizedCounter();

                System.out.println(unsynchronizedMethod());
                Thread.sleep(400);
            }
        }
        catch(Exception e){
            System.out.println("Thread is interrupted...");
        }

        finally{
            System.out.println("MyThread1 exiting.....");
        }
    }

    public synchronized void synchronizedCounter(){
        count++;
        System.out.println("synchronized counter incremented by 1... Counter ="+count);
    }

    public synchronized String unsynchronizedMethod(){
        return "un synchronized method called..";
    }
}

public class Assignment6 
{
    public static void main(String[] args)throws InterruptedException{
        Thread t1[]=new Thread[10];
        for(int i=0;i<5;i++)
        {
            t1[i] =new MyThread1();

        System.out.println("state of "+i+" before startt:"+t1[i].getState());
        t1[i].start();
        
        System.out.println("State of"+i+" after starting : "+t1[i].getState());

        while(t1[i].isAlive()){
            
        }
        System.out.println("statte of "+i+" after completed!!!!"+t1[i].getState()+"\n\n");

        }
    }
}