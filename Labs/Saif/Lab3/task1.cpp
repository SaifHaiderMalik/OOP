#include <iostream>
#include <string>

using namespace std;

class Account 
{
    private:

    double balance;

    public:

    string name;
    long accountNumber;

    void setDetails(double _balance){

        balance = _balance;

    }

    double getDetails(){

        return balance;

    }

    void deposit(double _balance){

        balance = balance + _balance;

    }

    void withdraw(double _balance){

        if(balance < _balance){

            cout << "Error Amount to Withdraw is greater then current Balance" << endl;
            
        }

        else{

            balance = balance - _balance;
            
        }
    }

    void displayDetails(){

        cout << "Details are: " << endl;
        cout << "Acount Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: " << getDetails() << endl;
    }
 
};

int main(void){

    double accBalance;
    double depo,with;


    Account A;

    A.getDetails();

    cout << "Please Enter Details" << endl;
    cout << "Enter Name: " << endl;
    cin >> A.name;
    cout << "Enter Account Number" << endl;
    cin >> A.accountNumber;
    cout << "Enter Balance in bank" << endl;
    cin >> accBalance;

    A.setDetails(accBalance);

    cout << "Enter Deposit" << endl;
    cin >> depo;

    A.deposit(depo);
    

    cout << "1" << endl;

    cout << "Enter Money to be Withdraw" << endl;
    cin >> with;

    A.withdraw(with);
   
    A.displayDetails();

}