import java.util.*;
import java.lang.*;
public class MyThread extends Thread{
    public void run(){
        System.out.println("run() method");
    }
    public synchronized void syncMethod(){
        for(int i = 0; i<5; i++){
            System.out.println("Synchronized method :> "+i);
            MyThread.sleep();
        }
    }
    public void unsyncMethod(){
        for(int i = 0; i<5; i++){
            System.out.println("UnSynchronized method :> "+i);
        }
    }
    public static void main(String[] args){
        MyThread t = new MyThread();
        System.out.println("Thread before start() :> "+t.getState());
        t.start();
        System.out.println("Thread after start() :> "+t.getState());
//        t.syncMethod();
//        System.out.println("Thread after syncMethod() :> "+t.getState());
//        t.unsyncMethod();
//        System.out.println("Thread after unsyncMethod() :> "+t.getState());
        t.destroy();
    }
}