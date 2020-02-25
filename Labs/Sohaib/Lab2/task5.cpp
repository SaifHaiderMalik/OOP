#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

double tax(double _hourlyRate, int _consultingTime, bool _lowIncome){
    if(_lowIncome == true){
        if(_consultingTime <= 30){
            return 0;
        }
        else{
            _consultingTime -= 30;
            return (0.4 * _hourlyRate *_consultingTime) / 60;
        }
    }
    else{
        if(_consultingTime <= 20){
            return 0;
        }
        else{
            _consultingTime -= 20;
            return (0.7 * _hourlyRate * _consultingTime) / 60;
        }
    }
}

int main(){
    double hourlyRate;
    int consultingTime, incomeValue;
    bool lowIncome = true;

    cout << "Enter Hourly Rate: $";
    cin >> hourlyRate;
    cout << "Total Consulting Time (in Minutes): ";
    cin >> consultingTime;
    cout << "Your Income: $";
    cin >> incomeValue;

    if(incomeValue > 25000){
        lowIncome = false;
    }

    cout << endl << "Billing Amount: $" << tax(hourlyRate, consultingTime, lowIncome);

    getch();
    return 0;
}