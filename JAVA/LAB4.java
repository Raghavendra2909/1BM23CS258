/*
 Develop a Java program to create a class Bank that maintains two kinds of account for its customers, one called savings account and the other current account. The savings account provides compound interest and withdrawal facilities but no cheque book facility. The  current account provides cheque book facility but no interest. Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.

Create a class Account that stores customer name, account number and type of account. From this derive the classes Cur-acct and Sav-acct to make them more specific to their requirements. Include the necessary methods in
order to achieve the following tasks:

a) Accept deposit from customer and update the balance.
b) Display the balance.
c) Compute and deposit interest
d) Permit withdrawal and update the balance

Check for the minimum balance, impose penalty if necessary and update the balance.
*/

class Account{
    double balance;
    String name;
    int accountnum;
    Account(String name, double balance, int accountnum){
        this.balance = balance;
        this.name = name;
        this.accountnum = accountnum;
    }
    void deposit(int amount){
        this.balance += amount;
        System.out.println("Processing deposit ................");
        System.out.println("Deposited amount: " + amount);

    }

    void withdraw(int amount){
        System.out.println("Processing withdrawl................." );
        if(amount > this.balance){
            System.out.println("Insufficient balance");
        }
        else{
            this.balance -= amount;
            System.out.println("Withdrawn amount: " + amount);
        }
    }
    void display(){
        System.out.println("Account Name: " + this.name);
        System.out.println("Account Number: " + this.accountnum);
        System.out.println("Balance= "+  this.balance);
    }
     
}
class  CurAcct extends Account{
    CurAcct(String name, double balance, int accountnum){
        super(name, balance, accountnum);
    }
    void display(){
        super.display();
        System.out.println("Account Type: Current Account");
    }
    void penalty(){
        if(this.balance<1000){
            this.balance -= 500;
        }
        else{
            System.out.println("Balance is sufficient");
        }
    }


}

class  SavingAcct extends Account{
    SavingAcct(String name, double balance, int accountnum){
        super(name,balance, accountnum);
    }
    void display(){
        super.display();
        System.out.println("Account Type: Saving Account");
    }
    void interest(float percent){
        this.balance += (this.balance * percent)/100;
        System.out.println("Interest added");
        System.out.println("Balance = "+  this.balance);
        
    }
}

public  class bankprogram{
    public static void main(String[] args) {
        SavingAcct s = new SavingAcct("Raju", 500, 354510104);
        s.display();
        s.deposit(4523);
        s.withdraw(1000);
        s.interest(5);
        s.withdraw(7000);
        s.display();

        System.out.println("--------------------------------------------------------------------------------------------------");

        CurAcct c = new CurAcct("Aakash", 4586, 354520107);
        c.display();
        c.deposit(454857);
        c.withdraw(4565);
        c.penalty();
        c.withdraw(654554654);
}
}


/*Output:
Account Name: Raju
Account Number: 354510104
Balance= 500.0
Account Type: Saving Account
Processing deposit ................
Deposited amount: 4523
Processing withdrawl.................
Withdrawn amount: 1000
Interest added
Balance = 4224.15
Processing withdrawl.................
Insufficient balance
Account Name: Raju
Account Number: 354510104
Balance= 4224.15
Account Type: Saving Account
--------------------------------------------------------------------------------------------------
Account Name: Aakash
Account Number: 354520107
Balance= 4586.0
Account Type: Current Account
Processing deposit ................
Deposited amount: 454857
Processing withdrawl.................
Withdrawn amount: 4565
Balance is sufficient
Processing withdrawl.................
Insufficient balance
*/
