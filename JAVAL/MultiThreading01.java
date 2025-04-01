import java.lang.Thread;
class BankAccount 
{
    private int balance;
    public BankAccount(int initialBalance) 
    {
        this.balance=initialBalance;
    }

    public synchronized void deposit(int amount) {
        balance += amount;
System.out.println(Thread.currentThread().getName() + " deposited: "+amount+", Current Balance: "+balance);
        notifyAll(); 
    }

    public synchronized void withdraw(int amount) {
        while(amount>balance) 
        {
            System.out.println(Thread.currentThread().getName() +"is waiting to withdraw: " +amount+", Insufficient Balance!");
            try
            {
                wait(); 
            }
            catch(Exception e) 
            {
                e.printStackTrace();
            }
        }

        balance= balance-amount;

        System.out.println(Thread.currentThread().getName()+"withdraww:"+amount+",Current Balance: "+ balance);
    }

    public synchronized void checkBalance() 
    {
        System.out.println(Thread.currentThread().getName()+" checked balance: "+balance);
    }

    public void random(){
        System.out.println(Thread.currentThread().getName()+" Random method called...");
    }

}

class DepositThread extends Thread 
{
    private BankAccount account;
    private int amount;

    public DepositThread(BankAccount account,int amount)
    {
        this.account=account;
        this.amount=amount;
    }

    @Override
    public void run() 
    {
        for(int i=0;i<3;i++){
            account.deposit(amount);
            try 
            {
                Thread.sleep(700); 
            } 
            catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}

class WithdrawThread extends Thread {
    private BankAccount account;
    private int amount;

    public WithdrawThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run()
    {
        for(int i=0;i<3;i++){
            account.withdraw(amount);
            try 
            {
                Thread.sleep(700); 
            } 
            catch(InterruptedException e) 
            {
                e.printStackTrace();
            }
        }
    }
}

class BalanceInquiryThread extends Thread{
    private BankAccount account;

    public BalanceInquiryThread(BankAccount account) {
        this.account = account;
    }

    @Override
    public void run(){
        for (int i=0;i<3;i++){
            account.checkBalance();
            try {
                Thread.sleep(500); 
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}

public class MultiThreading01 
{
    public static void main(String[] args) 
    {
        BankAccount account = new BankAccount(1000); 

        DepositThread depositThread = new DepositThread(account, 500);
        WithdrawThread withdrawThread = new WithdrawThread(account, 300);
        BalanceInquiryThread balanceInquiryThread = new BalanceInquiryThread(account);

        depositThread.setName("DepositThread");
        withdrawThread.setName("WithdrawThread");
        balanceInquiryThread.setName("BalanceInquiryThread");

        System.out.println("\nStarting Bank Management System...");

        depositThread.start();
        withdrawThread.start();
        balanceInquiryThread.start();

        try 
        {
            depositThread.join();
            withdrawThread.join();
            balanceInquiryThread.join();
        } 
        catch(InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.println("\nBank Management System operations completed.");
    }
}