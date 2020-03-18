#include<iostream>
#include<string>
using namespace std;


class BankAccount{

    string nameOfdepositor;
    const string accountNumber;
    string typeOfAccount;
    double balance;
    double rateOfInterest;

    public:

    BankAccount():accountNumber("5645")
    {

        nameOfdepositor = "";
        typeOfAccount = "";
        balance = 0;
        rateOfInterest = 0;
    }

    BankAccount(string name,string number,string type,double amount,double rate):accountNumber(number)
    {
        
        nameOfdepositor = name;
        typeOfAccount = type;
        balance = amount;
        rateOfInterest = rate;

    }

    void setName(string name){nameOfdepositor = name;}
    //void setAccountNumber(string number){accountNumber = number;}
    void setTypeOfAccount(string type){typeOfAccount = type;}
    void setBalance(double amount){balance = amount;}
    void setRateOfInterest(double rate){rateOfInterest = rate;} 


    void DepositAmount(double amount){

        if(amount > 0){

        balance = balance + amount;

        }

        else{

            cout <<"Invalid Amount Deposit" <<endl;
        }
    }

    void withdraw(double amount){

        if(balance >= amount){

            balance = balance - amount;

        }

        else{
            
            cout << "Balance is insufficient" <<endl;
        }
    }

    void display(){

        cout << "The Customer Name is: " << nameOfdepositor <<endl;
        cout << "The Account Number is: " << accountNumber <<endl;
        cout << "The Type of Account is: " << typeOfAccount <<endl;
        cout << "The balance is: " << balance <<endl;
    }

    void displayrateOfInterest(){

        cout << "The Rate is: " << rateOfInterest << "%"<<endl;
    }

    double calculateInterest(int year){

        double interest;

        interest = year * balance * rateOfInterest/100;

        return interest; 
    }


};


int main(void){

    string name;
    string accountNum;
    string type;
    double amount;
    double rate;
    int year;
    int count = 1;
    int choice;

    
    cout << "Method 1" <<endl;

    cout << "Enter Name of Depositor: " <<endl;
    cin >> name;

    cout << "Enter Account Number: " <<endl;
    cin >> accountNum;

    cout << "Enter Type of Account: " <<endl;
    cin >> type;

    cout << "Enter Balance of Account: " <<endl;
    cin >> amount;

    cout << "Enter Percentage Rate of Interest: " <<endl;
    cin >> rate;

    BankAccount ob(name,accountNum,type,amount,rate);

    while(count == 1){

    cout << "Press 1 to Deposit Amount" <<endl;
    cout << "Press 2 to Withdraw Amount" <<endl;
    cout << "Press 3 to Display Details" <<endl;
    cout << "Press 4 to Display Rate of Interest" <<endl;
    cout << "Press 5 to Calculate Interest" <<endl;
    cout << "Press 6 to Exit" <<endl;

    cin >> choice;

    switch(choice){

        case 1:

        cout << "Enter Amount to Deposit: " <<endl;
        cin >> amount;

        ob.DepositAmount(amount);

        break;

        case 2:

        cout << "Enter Money to Withdraw: " <<endl;
        cin >> amount;

        ob.withdraw(amount);

        break;

        case 3:

        ob.display();

        break;

        case 4:

        ob.displayrateOfInterest();

        break;

        case 5:

        cout << "Enter year Amount Deposited to calculate Interest: " <<endl;
        cin >> year;

        cout << "The Interest is: " << ob.calculateInterest(year) <<endl;
        
        break;

        case 6:

            count = 0;
            break;

        default:

            cout <<"Error" <<endl;
            break;
        
        }
    }

    cout << "Method 2" <<endl;

    BankAccount B;
    
    count = 1;

    cout << "Enter Name of Depositor: " <<endl;
    cin >> name;

    B.setName(name);

    cout << "Enter Type of Account: " <<endl;
    cin >> type;

    B.setTypeOfAccount(type);

    cout << "Enter Balance of Account: " <<endl;
    cin >> amount;

    B.setBalance(amount);

    cout << "Enter Percentage Rate of Interest: " <<endl;
    cin >> rate;

    B.setRateOfInterest(rate);

     while(count == 1){

    cout << "Press 1 to Deposit Amount" <<endl;
    cout << "Press 2 to Withdraw Amount" <<endl;
    cout << "Press 3 to Display Details" <<endl;
    cout << "Press 4 to Display Rate of Interest" <<endl;
    cout << "Press 5 to Calculate Interest" <<endl;
    cout << "Press 6 to Exit" <<endl;

    cin >> choice;

    switch(choice){

        case 1:

        cout << "Enter Amount to Deposit: " <<endl;
        cin >> amount;

        B.DepositAmount(amount);

        break;

        case 2:

        cout << "Enter Money to Withdraw: " <<endl;
        cin >> amount;

        B.withdraw(amount);

        break;

        case 3:

        B.display();

        break;

        case 4:

        B.displayrateOfInterest();

        break;

        case 5:

        cout << "Enter year Amount Deposited to calculate Interest: " <<endl;
        cin >> year;

        cout << "The Interest is: " << B.calculateInterest(year) <<endl;
        
        break;

        case 6:

            count = 0;
            break;

        default:

            cout <<"Error" <<endl;
            break;
        
        }
    }

   





}