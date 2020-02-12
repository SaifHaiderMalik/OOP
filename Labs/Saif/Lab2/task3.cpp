#include <iostream>
#include <string>
using namespace std;

void regularService(int _minutes,double& _amountDue);
void premiumService(int _minutesDay,int _minutesNight,double& _amountDue);


int main(void){

    int accountNumber, minutes, minutesDay, minutesNight;
    double amountDue;
    char serviceCode;

    cout << "Enter Account Number";
    cin >> accountNumber;

    cout << "Enter serviceCode";
    cin >> serviceCode;

    if(serviceCode == 'r'){

        cout << "Enter Minutes Used" << endl;
        cin >> minutes;

        regularService(minutes, amountDue);

        cout << "Account Number is: " << accountNumber << endl;
        cout << "Service Code is:   " << serviceCode << endl;
        cout << "Bill is: $" << amountDue;

    }

    else if (serviceCode == 'p'){

        cout << "Enter Minutes used in the Day" << endl;
        cin >> minutesDay;
        cout << endl << "Enter Minutes used in the Night" << endl;
        cin >> minutesNight;

        premiumService(minutesDay,minutesNight,amountDue);

        cout << "Account Number is: " << accountNumber << endl;
        cout << "Service Code is:   " << serviceCode << endl;
        cout << "Bill is: $" << amountDue;


    }


    else{

        cout << "Error";
    }
}

void regularService(int _minutes,double& _amountDue){

        if(_minutes > 50){

            _amountDue = 10 + (_minutes - 50)*0.2;
        }

        else{

            _amountDue = 10;
        }

}

void premiumService(int _minutesDay,int _minutesNight,double& _amountDue){

    _amountDue = 25;

    if(_minutesDay > 75){

        _amountDue += (_minutesDay - 75)*0.10;

    }

    if(_minutesNight > 100){

        _amountDue = _amountDue + (_minutesNight - 100)*0.05;

    }

    else {

        return; 
    }

}
