#include<iostream>
#include<string>

using namespace std;


class Bank{

    public:

    virtual double getBalance(double _balance) = 0;
};


class BankA : public Bank{

    double balance;
    double withdraw = 0;

    public:

    BankA(){}

    BankA(double _balance){

        balance = _balance;
    }

    void Deposit(double _balance){
        balance = balance + _balance;
    }

    double getBalance(double _withdraw){
        if(_withdraw <= balance){

            withdraw = _withdraw;    
            balance = balance - _withdraw;
        }

        else{
            cout << "Balance is Insufficient" << endl;
            return 0;
        }

        return balance;
    }

    void showBalanceWithdraw(){

        cout << "Balance withdrawn: " << withdraw <<endl;
    }

    void showBalance(){

        cout << "Balance in Bank is: " << balance << endl;
    }
}; 


class BankB : public Bank{

    double balance;
    double withdraw = 0;

    public:

    BankB(){}

    BankB(double _balance){

        balance = _balance;
    }

    void Deposit(double _balance){
        balance = balance + _balance;
    }

    double getBalance(double _withdraw){
        if(_withdraw <= balance){

            withdraw = _withdraw;    
            balance = balance - _withdraw;
        }

        else{
            cout << "Balance is Insufficient" << endl;
            return 0;
        }

        return balance;
    }

    void showBalanceWithdraw(){

        cout << "Balance withdrawn: " << withdraw <<endl;
    }

    void showBalance(){

        cout << "Balance in Bank is: " << balance << endl;
    }
}; 

class BankC : public Bank{

    double balance;
    double withdraw = 0;

    public:

    BankC(){}

    BankC(double _balance){

        balance = _balance;
    }

    void Deposit(double _balance){
        balance = balance + _balance;
    }

    double getBalance(double _withdraw){
        if(_withdraw <= balance){

            withdraw = _withdraw;    
            balance = balance - _withdraw;
        }

        else{
            cout << "Balance is Insufficient" << endl;
            return 0;
        }

        return balance;
    }

    void showBalanceWithdraw(){

        cout << "Balance withdrawn: " << withdraw <<endl;
    }

    void showBalance(){

        cout << "Balance in Bank is: " << balance << endl;
    }
}; 


int main(void){


    BankA ob1(100);
    BankB ob2(150);
    BankC ob3(200);

    cout << "Bank A has 100 deposited" << endl;
    cout << "Bank B has 150 deposited" << endl;
    cout << "Bank C has 200 deposited" << endl;

    int choice;
    int a,b,c;
    int count = 1;
    double balance,withdraw;

    while(count = 1){

        MENU:
        cout << "Enter 1 to Choose Bank A " << endl;
        cout << "Enter 2 to Choose Bank B " << endl;
        cout << "Enter 3 to Choose Bank C " << endl;
        cout << "Enter 0 to Exit " << endl;
        cin >> choice;

        switch(choice){

            case 1:
                A:
                cout << "Enter 1 to Deposit in Bank" << endl;
                cout << "Enter 2 to Withdraw Money" << endl;
                cout << "Enter 3 to See Remaining Balance" << endl;
                cout << "Enter 4 to go Back" << endl;
                cin >> a;

                switch(a){

                    case 1:
                        cout << "Enter Money to Deposit: " <<endl;
                        cin >> balance;
                        ob1.Deposit(balance);
                        goto A;
                        break;
                
                    case 2:
                        cout << "Enter Money to Withdraw: " <<endl;
                        cin >> withdraw;
                        ob1.getBalance(withdraw);
                        ob1.showBalanceWithdraw();
                        ob1.showBalance();
                        goto A;
                        break;
                    
                    case 3:
                        ob1.showBalance();
                        goto A;
                        break;
                    
                    case 4:
                        goto MENU;
                        break;
                    
                    default:
                        cout << "Invalid Choice Entered" << endl;
                        goto A;
                        break;
                }
                goto MENU;
                break;

            case 2:
                B: 
                cout << "Enter 1 to Deposit in Bank" << endl;
                cout << "Enter 2 to Withdraw Money" << endl;
                cout << "Enter 3 to See Remaining Balance" << endl;
                cout << "Enter 4 to go Back" << endl;
                cin >> b;

                switch(b){

                    case 1:
                        cout << "Enter Money to Deposit: " <<endl;
                        cin >> balance;
                        ob2.Deposit(balance);
                        goto B;
                        break;
                
                    case 2:
                        cout << "Enter Money to Withdraw: " <<endl;
                        cin >> withdraw;
                        ob2.getBalance(withdraw);
                        ob2.showBalanceWithdraw();
                        ob2.showBalance();
                        goto B;
                        break;
                    
                    case 3:
                        ob2.showBalance();
                        goto B;
                        break;
                    
                    case 4:
                        goto MENU;
                        break;

                    default:
                        cout << "Invalid Choice Entered" << endl;
                        goto B;
                        break;
                }
                goto MENU;
                break;
            
            case 3:
                C:
                cout << "Enter 1 to Deposit in Bank" << endl;
                cout << "Enter 2 to Withdraw Money" << endl;
                cout << "Enter 3 to See Remaining Balance" << endl;
                cout << "Enter 4 to go Back" << endl;
                cin >> c;

                switch(c){

                    case 1:
                        cout << "Enter Money to Deposit: " <<endl;
                        cin >> balance;
                        ob3.Deposit(balance);
                        goto C;
                        break;
                
                    case 2:
                        cout << "Enter Money to Withdraw: " <<endl;
                        cin >> withdraw;
                        ob3.getBalance(withdraw);
                        ob3.showBalanceWithdraw();
                        ob3.showBalance();
                        goto C;
                        break;
                    
                    case 3:
                        ob3.showBalance();
                        goto C;
                        break;
                    
                    case 4:
                        goto MENU;
                        break;

                    default:
                        cout << "Invalid Choice Entered" << endl;
                        goto C;
                        break;
            
                }

                goto MENU;
                break;

            case 0:
                exit(0);
                break;

            default:
                cout << "Invalid Choice Entered" << endl;
                break;
        }   

    }

}