import java.lang.Thread;
import java.lang.*;
class MyThread extends Thread{
    int count = 0;
    public void run(){
        System.out.println("run() method called...");
        try{
            for(int i=0; i<10; i++){
                System.out.println("MyThread :>"+i);
                syncMethod();
                asyncMethod();
                Thread.sleep(100);
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    public synchronized void syncMethod(){
        count++;
        System.out.println("Synchronized method called "+count);
        if(count==5){
            notify();
        }
    }
    public synchronized void asyncMethod(){
        System.out.println("Asynchronized method called...");
    }

}
public class  MultiThreadingPractice{
    public static void main(String[] args){
        Thread t[] = new Thread[2];
        for(int i=0; i<t.length; i++){
            t[i] = new MyThread();
            System.out.println("state of MyThread " + i + " before start: " + t[i].getState());
            t[i].start();
            System.out.println("state of MyThread " + i + " after start: " + t[i].getState());

            try{
                t[i].join();
                t[i].notify();
            }catch(Exception e){
                e.printStackTrace();
            }



            System.out.println("After Thread"+i+" is completed :>"+t[i].getState());
        }
    }
}