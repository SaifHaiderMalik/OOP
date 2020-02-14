#include <iostream>

using namespace std; 

class Account{
    private:
    double balance; // Account balance
    
    public: //Public interface:
    string name; // Account holder
    long accountNumber; //	Account number

    void setDetails(double bal){
        balance = bal;
    }

    double getDetails(){
        return balance;
    }

    void displayDetails(){
        cout << "Details are: " << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: " << getDetails() << endl;
    }
};

int main(){
    double accBal;
    Account currentAccount[5];

    currentAccount.getDetails();

    cout<<"Please enter the details"<<endl;
    cout<<"Enter Name:"<<endl;
    getline(cin, currentAccount.name);

    cout<<"Enter Account Number:"<<endl;
    cin>>currentAccount.accountNumber;

    cout<<"Enter Account Balance:"<<endl;
    cin>>accBal;
    currentAccount.setDetails(accBal);
    cout<<endl;

    currentAccount.displayDetails();

    return 0;
}