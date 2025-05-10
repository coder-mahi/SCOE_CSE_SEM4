//bank management system
import java.lang.Thread;

class BankAccount{
    int bal = 0;
    BankAccount(int bal){
        this.bal = bal;
    }

    public synchronized void deposit(int amt){
        bal+=amt;
        System.out.println("Amount "+amt+" deposited..!");
    }

    public synchronized void withdraw(int amt) throws Exception{
        if(amt>bal){
            throw new Exception("Insuffiecient balance...");
        }
        bal-=amt;
        System.out.println("Amount "+amt+" withdraw..!");
    }

    public synchronized void checkBalance(){
        System.out.println("Current Balance :> "+bal);
    }
}

class DepositThread extends Thread{
    BankAccount acc;
    int amt;
    DepositThread(BankAccount acc,int amt){
        this.acc = acc;
        this.amt = amt;
    }
    public void run(){
        for(int i=0;i<3;i++){
            acc.deposit(amt);
            try{
                Thread.sleep(200);
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}

class WithdrawThread extends Thread{
    BankAccount acc;
    int amt;
    WithdrawThread(BankAccount acc,int amt){
        this.acc = acc;
        this.amt = amt;
    }
    public void run(){
        for(int i=0;i<3;i++){
            try {
                acc.withdraw(amt);
                Thread.sleep(200);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

class CheckBalanceThread extends Thread{
    BankAccount acc;
    CheckBalanceThread(BankAccount acc){
        this.acc = acc;
    }
    public void run(){
        for(int i=0;i<3;i++){
            try {
                acc.checkBalance();
                Thread.sleep(200);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
class ThreadX extends Thread{
    public void run(){

    }
}
public class MultiThreading {
    public static void main(String[] args){
        BankAccount obj = new BankAccount(10000);
        
        DepositThread d = new DepositThread(obj, 500);
        WithdrawThread w = new WithdrawThread(obj, 100);
        CheckBalanceThread b = new CheckBalanceThread(obj);

        d.start();
        w.start();
        b.start();

        try{
            d.join();
            w.join();
            b.join();
        }catch(Exception e){
            e.printStackTrace();
        }

        System.out.println("\nBank Management System operations completed.");

        ThreadX t = new ThreadX();
        System.out.println("before :"+t.getState());
        t.start();
        System.out.println("after start() :"+t.getState());
        t.yield();
        System.out.println("after yield() :"+t.getState());
        
    }
}
