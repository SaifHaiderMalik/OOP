#include <iostream>
#include <string>

using namespace std;

class Account 
{
    private:

    double balance;
    int transaction = 0;
    double interest;


    public:

    void setDetails(double _balance){

        balance = _balance;
        transaction = transaction + 1;

    }

    double getDetails(){

        return balance;

    }

    void deposit(double _balance){

        balance = balance + _balance;
        transaction = transaction + 1;

    }

    void withdraw(double _balance){

        if(balance < _balance){

            cout << "Error Amount to Withdraw is greater then current Balance" << endl;
            
        }

        else{

            balance = balance - _balance;
            
        }
    }
    
    int getTransactions(){

        return transaction;

    }

    void saveBalance(double _balance){

        balance = _balance;
    }

    void saveTransactions(int _transactions){

        transaction = _transactions;
    }

    double interestRate(int _year, double _rate){

        interest = balance * _year * (_rate/100);
        return interest;
    }
};

int main(void){

    double accBalance;
    double depo,with;
    double saveBal;
    int year;
    double principal;
    double rate;
    int choice,count;
    int cont = 1; 

    Account A;

    while (cont == 1){

    cout << "Menu" << endl;
    cout << "Press 1 to Save the Account Balance"<<endl;
    cout << "Press 2 to Save Transactions" << endl;
    cout << "Press 3 to Deposit Money" << endl;
    cout << "press 4 to Withdraw Money" << endl;
    cout << "Press 5 to Calculate interest"<< endl;
    cout << "Press 6 to get Current Account Balance" << endl;
    cout << "Press 7 to get Current Number of transactions" << endl;

    cin >> choice;

    switch(choice){

        case 1:
            cout << "Enter Balance to Save" << endl;
            cin >> saveBal;
            A.saveBalance(saveBal);
            break;

        case 2:
            cout << "enter Transactions to Save" << endl;
            cin >> count;
            A.saveTransactions(count);
            break;
        
        case 3:
            cout << "Enter Money to Deposit" << endl;
            cin >> depo;
            A.deposit(depo);
            break;

        case 4:
            cout << "Enter Money to Withdraw" << endl;
            cin >> with;
            A.withdraw(with);
            break;

        case 5:
            cout << "Enter No. of years" << endl;
            cin >> year;
            cout << "Enter Rate: " << endl;
            cin >> rate;

           cout << "Intereast is: " << endl << A.interestRate(year,rate);
            break;

        case 6:
            cout << "Current Balance is: " << A.getDetails();
            break;

        case 7:
            cout << "Current Transactions: " << A.getTransactions();
            break;

        case 0:
            cont = 0;
    }
    
    }
  
}