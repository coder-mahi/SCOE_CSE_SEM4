import java.lang.Thread;

class BankAccount 
{
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    public synchronized void deposit(int amount) {
        balance = balance + amount;
        System.out.println(Thread.currentThread().getName()+"Amoount deposited :> "+amount+", Current Balance: " + balance);
    }

    public synchronized void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println(Thread.currentThread().getName() + " withdrew: " + amount + ", Current Balance: " + balance);
        } else {
            System.out.println(Thread.currentThread().getName() + " tried to withdraw: " + amount + ", Insufficient Balance!");
        }
    }

    public synchronized void checkBalance() {
        System.out.println(Thread.currentThread().getName() + " checked balance: " + balance);
    }
}

class DepositThread extends Thread {
    private BankAccount account;
    private int amount;

    public DepositThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        for (int i = 0; i < 3; i++) {
            account.deposit(amount);
            try {
                Thread.sleep(300); // Simulate delay
            } catch (InterruptedException e) {
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
    public void run() {
        for (int i = 0; i < 3; i++) {
            account.withdraw(amount);
            try {
                Thread.sleep(400); // Simulate delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class BalanceInquiryThread extends Thread {
    private BankAccount account;

    public BalanceInquiryThread(BankAccount account) {
        this.account = account;
    }

    @Override
    public void run() {
        for (int i = 0; i < 3; i++) {
            account.checkBalance();
            try {
                Thread.sleep(500); // Simulate delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class MultiThreading01 {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000); // Initial balance

        DepositThread depositThread = new DepositThread(account, 500);
        WithdrawThread withdrawThread = new WithdrawThread(account, 300);
        BalanceInquiryThread balanceInquiryThread = new BalanceInquiryThread(account);

        System.out.println("Starting Bank Management System...");

        depositThread.start();
        withdrawThread.start();
        balanceInquiryThread.start();

        try {
            depositThread.join();
            withdrawThread.join();
            balanceInquiryThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Bank Management System operations completed.");
    }
}