import java.lang.Thread;

public class BankAccount
{
    private int balance;
    public BankAccount(int intialBalance){
        balance =intialBalance;
    }
    synchronized void deposit(int amount){
        balance+=amount;
        System.out.println(Thread.currentThread().getName()+"Ammount deposited :> "+amount+" -->balance :"+balance);
    }
    synchronized void withdraw(int amount){
        if(amount>balance){
            System.out.println("insufficient balance..");
        }else{
            balance-=amount;
            System.out.println(Thread.currentThread().getName()+"Ammount withdraw :> "+amount+" -->balance :"+balance);
        }
    }

    void checkBalance(){
        System.out.println(Thread.currentThread().getName()+"-> Current balancee:"+balance);
    }

}

public WithdrawThread extends Thread{
    private BankAccount account;
    private int amount;

    public WithdrawThread(BankAccount account,int amount) 
    {
        this.account=account;
        this.amount=amount;
    }
    
    @Override
    public void run()
    {
        for(int i=0;i<3;i++) {
            account.withdraw(amount);
            try{
                Thread.sleep(400);
            } 
            catch(Exception e)
            {
                e.printStackTrace();
            }
            finally{
                System.out.println("Withdraw thread finally executed...");
            }
        }
    }
}
public DepositThread extends Thread{
    private BankAccount acc;
    private int amount;
    DepositThread(BankAccount acc, int amount){
        this.acc =acc;
        this.amount= amount;
    }
    @Override
    public void run(){
        for(int i=0;i<3;i++){
            acc.deposit(amount);
            try{
                Thread.sleep(500);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            finally{
                System.out.println("Deposit Thread Finally executed...");
            }
        }
    }
}

public class AccountInquiry extends Thread{
    private BankAccount acc;
    private int balance;
    AccountInquiry(BankAccount acc){
        this.acc = acc;
    }
    @Override
    public void run(){
        for(int i=0;i<3;i++){
            acc.checkBalance();
            try
            {
                Thread.sleep(400);
            }catch(Exception e){
                e.printStackTrace();
            }
            finally{
                System.out.println("Deposit Thread Finally executed...");
            }
        }
    }
}
public class BankManagementSystem 
{
    public static void main(String[] args){
        BankAccount obj = new BankAccount(10000);
        
        DepositThread d = new DepositThread(obj, 500);
        WithdrawThread w = new WithdrawThread(obj, 4000);
        AccountInquiry inquiry = new AccountInquiry(obj);
    
        System.out.println("Starting Bank Management System...");
    
        d.start();
        w.start();
        inquiry.start();
    
        try
        {
            d.join();
            w.join();
            inquiry.join();
        }
        catch(Exception e){
            e.printStackTrace();
        }
        System.out.println("operations completed....");
    }
}