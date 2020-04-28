#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

class ADMINISTRATOR;
class RESTAURANT;
class CUSTOMER;
class FOOD;
class ORDER;
class TAXDEPARTMENT;

auto nowTime = chrono::system_clock::now();
time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
tm myLocalTime = *localtime(&sleepTime);
string ss = ctime(&sleepTime);
int day = myLocalTime.tm_mday;
int month = myLocalTime.tm_mon;
int year = myLocalTime.tm_year;
int hours = myLocalTime.tm_hour;
int minutes = myLocalTime.tm_min;
int seconds = myLocalTime.tm_sec;
//int x1 = myLocalTime.tm_isdst;
//int x2 = myLocalTime.tm_wday;
//int x3 = myLocalTime.tm_yday;

class ADMINISTRATOR{
    string userName;
    string passWord;
    bool isOpen;
    int openTime;
    int closeTime;
    int revenue;
    int taxPayable;
    vector<string> vouchersValid();
    vector<string> vouchersExpired();
    int customerCount;
    int restaurantCount;
    vector<RESTAURANT> restaurants();
    vector<CUSTOMER> customers();
};

class RESTAURANT{
    string managerID;
    string managerPassword;
    string restaurantCode;
    bool isOpen;
    int openTime;
    int closeTime;
    bool * daysOpen = new bool[7];
    string title;
    string description;
    int contactNumber;
    string contactAddress1;
    string contactAddress2;
    string contactAddress3;
    int revenue;
    int taxPayable;
    int ordersPending;
    int ordersCompleted;
    int ordersCancelled;
    bool freeDelivery;
    int deliveryCharges;
    bool * cuisines = new bool[10];
    int menuCount;
};

class CUSTOMER{
    string firstName;
    string lastName;
    string customerCode;
    string passWord;
    string emailAddress;
    int contactNumber;
    string contactAddress1;
    string contactAddress2;
    string contactAddress3;
    int walletAmount;
    vector<string> vouchersUsed;
    int orderCount;
};

int main(){
    cout << ss.substr(0, ss.length()-1) << endl;
    cout << "Date: " << day << "/" << (month + 1) << "/" << (year + 1900) << endl;
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    //cout << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;

    vector<string> myVec(0);
    myVec.push_back("A");
    myVec.push_back("B");
    myVec.push_back("C");
    myVec.erase(myVec.begin(), myVec.end());
    //myVec.pop_back();
    //myVec.erase("A");
    for(int i =0;i< myVec.size();i++){
        cout << i << " = " << myVec[i] << endl;
    }
    cout << myVec.size();
    return 0;
}