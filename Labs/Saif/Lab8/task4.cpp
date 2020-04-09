#include<iostream>
#include<string>

using namespace std;




class Bank{

    protected:

    double balance;

    public:

    virtual double getBalance(double withdraw){

        return 0;
    }

    virtual void deposit(double _balance){

        balance = _balance;
    }

};


class BankA : public Bank{

    public:

    double getBalance(double withdraw){

        if(withdraw <= balance){
            
            balance = balance - withdraw;

            return withdraw;

        }

        else{

            cout << " Amount to Withdraw is greater than deposited amount " <<endl;

            return 0;

        }

    }

    void deposit(double _balance){

        balance = _balance;

    }

};

class BankB : public Bank{

    public:

    double getBalance(double withdraw){

        if(withdraw <= balance){
            
            balance = balance - withdraw;

            return withdraw;
            
        }

        else{

            cout <<" Amount to Withdraw is greater than deposited amount " <<endl;

            return 0;
        }

    }

    void deposit(double _balance){


        balance = _balance;

    }

};

class BankC : public Bank{

    public:
  
    double getBalance(double withdraw){

        if(withdraw <= balance){

            balance = balance - withdraw;

            return withdraw;
            
        }

        else{

            cout <<" Amount to Withdraw is greater than deposited amount " <<endl;

            return 0;

        }

    }

    void deposit(double _balance){

        balance = _balance;
    }

};


int main(void){

    double deposit;
    double withdraw;

    BankA A;

    cout <<"Enter Amount to Deposit in Bank A: " <<endl;
    cin >> deposit;

    A.deposit(deposit);

    cout << "Enter Amount to Withdraw: " <<endl;
    cin >> withdraw;

    cout << "Amount Withdraw: " << A.getBalance(withdraw) <<endl;

    BankB B;

    cout <<"Enter Amount to Deposit in Bank B: " <<endl;
    cin >> deposit;

    B.deposit(deposit);

    cout << "Enter Amount to Withdraw: " <<endl;
    cin >> withdraw;

    cout << "Amount Withdraw: " << B.getBalance(withdraw) <<endl;

    BankC C;

    cout <<"Enter Amount to Deposit in Bank C: " <<endl;
    cin >> deposit;

    C.deposit(deposit);

    cout << "Enter Amount to Withdraw: " <<endl;
    cin >> withdraw;

    cout << "Amount Withdraw: " << C.getBalance(withdraw) <<endl;

}