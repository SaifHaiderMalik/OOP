#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

void billRegular(int _minutes, double& _amountDue){
    _amountDue = 10;
    if(_minutes > 50){
        _minutes -= 50;
        _amountDue += (_minutes * 0.2);
    }
}

void billPremium(int _minutesDay, int _minutesNight, double& _amountDue){
    _amountDue = 25;
    if(_minutesDay > 75){
        _minutesDay -= 75;
        _amountDue += (_minutesDay * 0.1);
    }

    if(_minutesNight > 100){
        _minutesNight -= 100;
        _amountDue += (_minutesNight * 0.05);
    }
}

int main(){
    int accountNumber, minutes, minutesDay, minutesNight;
    double amountDue;
    char serviceCode;
    string typeService;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Service Code (R=Regular & P=Premium): ";
    cin >> serviceCode;

    if(tolower(serviceCode) == 'r'){
        cout << "Number of Minutes Service was used?: ";
        cin >> minutes;
        typeService = "Regular";
        billRegular(minutes, amountDue);
    }
    else if(tolower(serviceCode) == 'p'){
        cout << "Number of Minutes Service was used during Day time?: ";
        cin >> minutesDay;
        cout << "Number of Minutes Service was used during Night time?: ";
        cin >> minutesNight;
        typeService = "Premium";
        minutes = minutesDay + minutesNight;
        billPremium(minutesDay, minutesNight, amountDue);
    }
    
    cout << fixed << setprecision(2) << endl << "TELEPHONE BILL" << endl << "Account Number: " << accountNumber << endl << "Type of Service: " << typeService << endl << "Number of Minutes the Telephone Service was used: " << minutes << endl << "Amount Due: $" << amountDue;

    getch();
    return 0;
}