#include <iostream>
#include <string>
using namespace std;

double Bill(double _hourlyrate,double _consultingTime,string _lowincome);

int main(void){

    double hourlyRate,consultingTime,income;
    string lowIncome = "false";

    cout << "Enter Hourly Rate: ";
    cin >> hourlyRate;
    cout << "Enter Consulting Time in Minutes: ";
    cin >> consultingTime;
    cout << "Enter Income: $";
    cin >> income;

    if(income <= 25000){
        lowIncome = "true";
    }

    cout << "Bill is : $" << Bill(hourlyRate,consultingTime,lowIncome);
}

double Bill(double _hourlyrate,double _consultingTime,string _lowincome){

    if (_lowincome == "true"){
        if(_consultingTime <=30){     
            return 0;
        }
        else {
            _consultingTime = _consultingTime - 30;
            return (_hourlyrate*0.4*_consultingTime/60);
        }
    }
    else{
        if(_consultingTime <= 20){
            return 0;
        }
        else {
            _consultingTime = _consultingTime - 20;
            return (_hourlyrate*0.7*_consultingTime/60);
        }
    }
}