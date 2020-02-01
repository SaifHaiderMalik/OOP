#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

double billProcFee, basicFee, premiumChanRate, billingAmount;

double billResidential(int _accountNumber, int _channelCount){
    billProcFee = 4.5, basicFee = 20.5, premiumChanRate = 7.5;
    billingAmount = billProcFee + basicFee + (_channelCount * premiumChanRate);
    return billingAmount;
}

double billBusiness(int _accountNumber, int _channelCount, int _connectionCount){
    billProcFee = 15, basicFee = 75, premiumChanRate = 50;
    if(_connectionCount > 10){
        for(int i = 11; i <= _connectionCount; i++){
            basicFee += 5;
        }
    }
    billingAmount = billProcFee + basicFee + (_channelCount * premiumChanRate);
    return billingAmount;
}

int main(){
    int accountNumber, channelCount, connectionCount;
    char customerCode;
    cout << "Customer Account No: ";
    cin >> accountNumber;
    cout << "Cutomer Code (R=Residential, B=Business): ";
    cin >> customerCode;
    cout << "Number of Premium Channels: ";
    cin >> channelCount;
    if(tolower(customerCode) == 'r'){
        cout << endl << "BILL" << endl << "Customer Account No: " << accountNumber << endl << "Customer Type: Residential" << endl << "Bill Amount: " << billResidential(accountNumber, channelCount);
    }
    else if(tolower(customerCode) == 'b'){
        cout << "Number of Basic Service Connections: ";
        cin >> connectionCount;
        cout << endl << "BILL" << endl << "Customer Account No: " << accountNumber << endl << "Customer Type: Business" << endl << "Bill Amount: " << billBusiness(accountNumber, channelCount, connectionCount);
    }

    getch();
    return 0;
}