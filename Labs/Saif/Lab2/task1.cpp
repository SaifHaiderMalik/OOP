#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

double billResidential(string _accountNumber, int _channelCount){
    double billProcFee, basicFee, premiumChanRate, billingAmount;
    billProcFee = 4.5, basicFee = 20.5, premiumChanRate = 7.5;
    billingAmount = billProcFee + basicFee + (_channelCount * premiumChanRate);
    return billingAmount;
}

double billBusiness(string _accountNumber, int _channelCount, int _connectionCount){
    double billProcFee, basicFee, premiumChanRate, billingAmount;
    billProcFee = 15.00, basicFee = 75.00, premiumChanRate = 50.00;
    if(_connectionCount > 10){
        for(int i = 11; i <= _connectionCount; i++){
            basicFee += 5;
        }
    }

    billingAmount = billProcFee + basicFee + (_channelCount * premiumChanRate);
    return billingAmount;
}

int main(){
    int channelCount, connectionCount;
    char customerCode;
    string accountNumber;

    cout << "Customer Account No: ";
    cin >> accountNumber;
    cout << "Cutomer Code (r=Residential, b=Business): ";
    cin >> customerCode;
    cout << "Number of Premium Channels: ";
    cin >> channelCount;

    if(customerCode == 'r' || customerCode == 'R'){

        cout << endl << "BILL" << endl << "Customer Account No: " << accountNumber << endl;
        cout << "Customer Type: Residential" << endl;
        cout << "Bill Amount: " << billResidential(accountNumber, channelCount);
    }
    else if(customerCode == 'b' || customerCode == 'B'){

        cout << "Number of Basic Service Connections: ";
        cin >> connectionCount;
        cout << endl << "BILL" << endl << "Customer Account No: " << accountNumber << endl;
        cout << "Customer Type: Business" << endl;
        cout << "Bill Amount: " << billBusiness(accountNumber, channelCount, connectionCount);
    }

    getch();
    return 0;
}