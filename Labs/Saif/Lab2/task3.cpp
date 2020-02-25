#include <iostream>
#include <string>
using namespace std;

void regularService(int _minutes,double& _amountDue);
void premiumService(int _minutesDay,int _minutesNight,double& _amountDue);

int main(void){

    int minutes, minutesDay, minutesNight;
    double amountDue;
    char serviceCode;
    string accountNumber;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter serviceCode (R=Regular & P=Premium): ";
    cin >> serviceCode;

    if(serviceCode == 'r' || serviceCode == 'R'){

        cout << "Enter Minutes Used: ";
        cin >> minutes;

        regularService(minutes, amountDue);

        cout << endl << "::BILL GENERATED::" << endl;
        cout << "Account Number is:\t" << accountNumber << endl;
        cout << "Service Type is:\tRegular" << endl;
        cout << "Minutes used:\t\t" << minutes << endl;
        cout << "Bill is:\t\t$" << amountDue;
    }
    else if(serviceCode == 'p' || serviceCode == 'P'){

        cout << "Enter Minutes used in the Day: ";
        cin >> minutesDay;
        cout << "Enter Minutes used in the Night: ";
        cin >> minutesNight;

        premiumService(minutesDay,minutesNight,amountDue);

        cout << endl << "::BILL GENERATED::" << endl;
        cout << "Account Number is:\t" << accountNumber << endl;
        cout << "Service Type is:\tPremium" << endl;
        cout << "Minutes used (Day):\t" << minutesDay << endl;
        cout << "Minutes used (Night):\t" << minutesNight << endl;
        cout << "Bill is:\t\t$" << amountDue;
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