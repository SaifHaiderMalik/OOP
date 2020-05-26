//
// _WIN32_WINNT version constants
//
//#define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0
//#define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000
//#define _WIN32_WINNT_WINXP                  0x0501 // Windows XP
//#define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003
//#define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista
//#define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista
//#define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008
//#define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista
//#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7
//#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8
//#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1
//#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10
//#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10*/

//#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wreturn-type"

#define _WIN32_WINNT 0x0A00
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <vector>
#include <map>
#include <Windows.h>
//#include <consoleapi3.h>
//#include <stdlib.h>
//#include <dos.h>
//#include <stdio.h>
#include <conio.h>
//#include <wchar.h>
#include "color.h"
#include "console.h"
#include "font.h"
#include "position.h"

using namespace std;

//void replaceSpace(string& _string);
void cleanArea(int _x1, int _y1, int _x2, int _y2);
void setMessage(string message);
void setTitle(string message);
void setContinue();
void clearMain();

class PIZZA;
class BURGER;
class SANDWICHE;
class FASTFOOD;
class BARBQ;
class PAKISTANI;
class CHINESE;
class INTERNATIONAL;
class SEAFOOD;
class DESSERT;
class CAKE;
class BEVERAGE;
class CUSTOMER;
class RESTAURANT;
class ADMINISTRATOR;
class FOOD;
class ORDER;
class TAXDEPARTMENT;
class TIMENOW;

vector<string> cuisineTitle{"Pizza","Burgers","Sandwiches","Fast Food","Bar.B.Q","Pakistani","Chinese","International","Seafood","Desserts","Cakes & Bakery","Beverage"};
vector<vector<string>> cities{{"Islamabad", "Area 1"},
                              {"Karachi", "Area 1", "Area 2", "Area 3", "Area 4", "Area 5"},
                              {"Lahore", "Area 1", "Area 2", "Area 3", "Area 4"},
                              {"Peshawar", "Area 1", "Area 2", "Area 3"},
                              {"Queta", "Area 1", "Area 2"}};
vector<vector<vector<int>>> distance {{{5}},
                                      {{5,15,25,25,15},{15,5,15,25,25},{25,15,5,15,25},{25,25,15,5,15},{15,25,25,15,5}},
                                      {{5,15,25,15},{15,5,15,25},{25,15,5,15},{15,25,15,5}},
                                      {{5,15,15},{15,5,15},{15,15,5}},
                                      {{5,15},{15,5}}};
vector<string> days{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
vector<vector<string>> menu{{"MAIN  MENU", "Administrator", "Restaurant Manager", "Customer", "EXIT"}, //0
                            {"ADMINISTRATOR", "Show Details", "Restaurant Management", "Customer Management", "Vouchers Management", "Go Back"}, //1
                            {"ADMINISTRATOR > Show Details", "Summary", "Show Restaurants", "Go Back"}, //2
                            {"ADMINISTRATOR > Show Details > Show Restaurants", "Show All", "By Cuisine", "By Location", "Go Back"}, //3
                            {"ADMINISTRATOR > Restaurant Management", "Add New", "Close", "Re-Open", "Find", "Go Back"}, //4
                            {"ADMINISTRATOR > Customer Management", "Add New", "Block", "Unblock", "Find", "Go Back"}, //5
                            {"ADMINISTRATOR > Voucher Management", "Add New", "Block", "Send", "Show", "Go Back"}, //6
                            {"RESTAURANT MANAGER", "Show Details", "Change Password", "Open/Close Restaurant", "Set Opening Days/Timings", "Modify Details", "Menu Management", "Order Management", "Go Back"}, //7
                            {"RESTAURANT MANAGER > Menu Management", "Add Item", "Modify Item Details", "Delete Item", "Show Details", "Go Back"}, //8
                            {"RESTAURANT MANAGER > Order Management", "Approve/Cancel Orders", "Show Details", "Go Back"}, //9
                            {"CUSTOMER", "New User", "Sign In", "Sign Out", "Go Back"}, //10
                            {"CUSTOMER > Signed In", "Show Details", "Modify Details", "Order Food", "Order Details", "Voucher Management", "Go Back"}, //11
                            {"CUSTOMER > Signed In > Voucher Management", "Show Details", "Use Voucher", "Go Back"}}; //12

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
//int weekDay = myLocalTime.tm_wday;
//int x1 = myLocalTime.tm_isdst;
//int x2 = myLocalTime.tm_wday;
//int x3 = myLocalTime.tm_yday;
void newTime(){
    nowTime = chrono::system_clock::now();
    sleepTime = chrono::system_clock::to_time_t(nowTime);
    myLocalTime = *localtime(&sleepTime);
    day = myLocalTime.tm_mday;
    month = myLocalTime.tm_mon;
    year = myLocalTime.tm_year;
    hours = myLocalTime.tm_hour;
    minutes = myLocalTime.tm_min;
    seconds = myLocalTime.tm_sec;
}


class TIMENOW{
    string tnDate;
    string tnTime;

public:
    TIMENOW(){
        tnDate = to_string(day)+"/"+to_string(month + 1)+"/"+to_string(year + 1900);
        tnTime = to_string(hours)+":"+to_string(minutes)+":"+to_string(seconds);
    }

    void setTime(int _hours,int _minutes, int seconds){
        tnTime = to_string(hours)+":"+to_string(minutes)+":"+to_string(seconds);
    }

    void setDate(){
        tnDate = to_string(day)+"/"+to_string(month + 1)+"/"+to_string(year + 1900);
    }
    
    string getDate(){return tnDate;}
    string getTime(){return tnTime;}
};


class RESTAURANT{
    string managerID;
    string managerPassword;
    string restaurantCode;
    bool isRestActive;
    bool isRestOpen;
    int openTime;
    int closeTime;
    bool * daysOpen = new bool[7]{false};
    string title;
    string description;
    string contactNumber;
    string address;
    int area;
    int city;
    double restRevenue;
    double restTax;
    int ordersPending;
    int ordersCompleted;
    int ordersCancelled;
    bool freeDelivery;
    int minimumOrder;
    double deliveryCharges;
    //bool * cuisines = new bool[12]{};
    vector<PIZZA> pizzas;
    vector<BURGER> burgers;
    vector<SANDWICHE> sandwiches;
    vector<FASTFOOD> fastfoods;
    vector<BARBQ> barbqs;
    vector<PAKISTANI> pakistanis;
    vector<CHINESE> chineses;
    vector<INTERNATIONAL> internationals;
    vector<SEAFOOD> seafoods;
    vector<DESSERT> desserts;
    vector<CAKE> cakes;
    vector<BEVERAGE> beverages;
    int menuCount;
    double restDiscount;

public:
    RESTAURANT(string _managerID, string _managerPassword, int _openTime, int _closeTime, string _title, string _description, string _contactNumber, string _address, int _area, int _city, bool _freeDelivery, int _minimumOrder, double _deliveryCharges, double _restDiscount){
        managerID = _managerID;
        managerPassword = _managerPassword;
        isRestActive = true;
        isRestOpen = false;
        openTime = _openTime;
        closeTime = _closeTime - 1;
        title = _title;
        description = _description;
        contactNumber = _contactNumber;
        address = _address;
        area = _area;
        city = _city;
        restRevenue = restTax = 0.0;
        ordersPending = ordersCompleted = ordersCancelled = 0;
        freeDelivery = _freeDelivery;
        if(freeDelivery == true){
            minimumOrder = _minimumOrder;
        }
        else{
            minimumOrder = 0;
        }
        deliveryCharges = _deliveryCharges;
        menuCount = 0;
        restDiscount = (_restDiscount/100);
    }

    string getCode(){return restaurantCode;}
    string getTitle(){return title;}
    string getCity(){return cities[city][0];}
    string getArea(){return cities[city][area];}
    string getManagerID(){return managerID;}
    string getManagerPassword(){return managerPassword;}
    bool getIsRestActive(){return isRestActive;}
    bool getIsRestOpen(){return isRestOpen;}
    int getOpenTime(){return openTime;}
    int getCloseTime(){return (closeTime + 1);}
    int getMenuCount(){return menuCount;}

    bool hasPizza(){
        if(pizzas.size() > 0){
            return true;
        }
        return false;
    }

    bool hasBurgers(){
        if(burgers.size() > 0){
            return true;
        }
        return false;
    }

    bool hasSandwiches(){
        if(sandwiches.size() > 0){
            return true;
        }
        return false;
    }

    bool hasFastfoods(){
        if(fastfoods.size() > 0){
            return true;
        }
        return false;
    }

    bool hasBarbqs(){
        if(barbqs.size() > 0){
            return true;
        }
        return false;
    }

    bool hasPakistanis(){
        if(pakistanis.size() > 0){
            return true;
        }
        return false;
    }

    bool hasChineses(){
        if(chineses.size() > 0){
            return true;
        }
        return false;
    }

    bool hasInternationals(){
        if(internationals.size() > 0){
            return true;
        }
        return false;
    }

    bool hasSeafoods(){
        if(seafoods.size() > 0){
            return true;
        }
        return false;
    }

    bool hasDesserts(){
        if(desserts.size() > 0){
            return true;
        }
        return false;
    }

    bool hasCakes(){
        if(cakes.size() > 0){
            return true;
        }
        return false;
    }

    bool hasBeverages(){
        if(beverages.size() > 0){
            return true;
        }
        return false;
    }

    bool hasFood(string _cuisine){
        if((_cuisine == cuisineTitle[0]) && (hasPizza() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[1]) && (hasBurgers() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[2]) && (hasSandwiches() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[3]) && (hasFastfoods() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[4]) && (hasBarbqs() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[5]) && (hasPakistanis() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[6]) && (hasChineses() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[7]) && (hasInternationals() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[8]) && (hasSeafoods() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[9]) && (hasDesserts() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[10]) && (hasCakes() == true)){
            return true;
        } else if((_cuisine == cuisineTitle[11]) && (hasBeverages() == true)){
            return true;
        } else{
            return false;
        }
    }

    void getDaysOpen(){
        for(int i = 0; i < 7; i++){
            if(daysOpen[i] == true){
                cout << days[i].substr(0, 3) << ",";
            }
        }
        cout << endl;
    }

    bool getDaysOpen(int _index){return daysOpen[_index];}

    double getRestRevenue(){return restRevenue;}
    double getRestTax(){return restTax;}
    int getOrdersPending(){return ordersPending;}
    int getOrdersCompleted(){return ordersCompleted;}
    int getOrdersCancelled(){return ordersCancelled;}
    //bool freeDelivery;
    //int minimumOrder;
    //double deliveryCharges;

    void setCode(string _code){
        restaurantCode = _code;
    }
    void setManagerID(string _managerID){
        managerID = _managerID;
    }
    /*void setManagerPassword(string _managerPassword){
        managerPassword = _managerPassword;
    }*/
    void setIsRestActive(bool _isActive){
        isRestActive = _isActive;
    }
    void setIsRestOpen(bool _isOpen){
        isRestOpen = _isOpen;
    }
    void setOpenTime(int _opneTime){
        openTime = _opneTime;
    }
    void setCloseTime(int _closeTime){
        closeTime = _closeTime;
    }
    void setTitle(string _title){
        title = _title;
    }
    void setDescription(string _description){
        description = _description;
    }
    void setContactNumber(string _contact){
        contactNumber = _contact;
    }
    void setAddress(string _address){
        address = _address;
    }
    void setArea(int _area){
        area = _area;
    }
    void setCity(int _city){
        city = _city;
    }
    void setRestRevenue(double _restRevenue){
        restRevenue = _restRevenue;
    }
    void increaseRestRevenue(double _restRevenue){
        restRevenue = restRevenue + _restRevenue;
    }
    void setRestTax(double _restTax){
        restTax = _restTax;
    }
    void increaseRestTax(double _restTax){
        restTax = restTax + _restTax;
    }
    void setOrdersPending(int _ordersPending){
        ordersPending = _ordersPending;
    }
    void IncreaseordersPending(int _oredersPending){
        ordersPending = _oredersPending;
    }

    bool managerLogin(string _managerID, string _password){
        if(managerID == _managerID && managerPassword == _password){
            cout << "Welcome " << managerID << " to " << title << endl;
            return true;
        }else{
            cout << "Bad Mnager ID or Password!" << endl;
            return false;
        }
    }

    void setDayOpen(int _day){
        daysOpen[_day] = true;
    }

    void setDayClose(int _day){
        daysOpen[_day] = false;
    }

    void addPizza(){}
};


class CUSTOMER{
    string firstName;
    string lastName;
    string customerCode;
    string custPassword;
    string emailAddress;
    string custContactNumber;
    string custAddress;
    bool isActive; 
    int custArea;
    int custCity;
    double walletAmount;
    vector<string> vouchers;
    vector<string> pastVouchers;
    int orderCount;

public:
    CUSTOMER(string _firstName, string _lastName, string _passWord, string _emailAddress, string _contactNumber, string _address, int _area, int _city){
        firstName = _firstName;
        lastName = _lastName;
        custPassword = _passWord;
        emailAddress = _emailAddress;
        custContactNumber = _contactNumber;
        custAddress = _address;
        custArea = _area;
        custCity = _city;
        walletAmount = 0;
        orderCount = 0;
    }

    void setFirstName(string _first){
        firstName = _first;
    }
    void setLastName(string _last){
        lastName = _last;
    }
    void setCustomerCode(string _code){
        customerCode = _code;
    }
    void setCustPassword(string _password){
        custPassword = _password;
    }
    void setEmailAddress(string _emailAddress){
        emailAddress = _emailAddress;
    }
    void setCustContactNumber(string _contactNumber){
        custContactNumber = _contactNumber;
    }
    void setCustAddress(string _address){
        custAddress = _address;
    }
    void setCustArea(int _area){
        custArea = _area;
    }
    void setCustCity(int _city){
        custCity = _city;
    }
    void setWalletAmount(double _walletAmount){
        walletAmount = _walletAmount;
    }
    void setOrderCount(int _order){
        orderCount = _order;
    }
    void setVoucher(string _voucher){
        vouchers.push_back(_voucher);
    }
    void setIsActive(bool _isActive){
        isActive = _isActive;
    }

    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    string getCustomerCode(){return customerCode;}
    string getCustPassword(){return custPassword;}
    string getEmailAddress(){return emailAddress;}
    string getContactNumber(){return custContactNumber;} 
    string getAddress(){return custAddress;}
    int getArea(){return custArea;}
    int getCity(){return custCity;}
    double getWalletAmount(){return walletAmount;}
    int getOrderCount(){return orderCount;}
    string getVoucherUsed(int _index){return vouchers[_index];}
    bool getIsActive(){return isActive;}
};


class ADMINISTRATOR{
    const string userName;
    const string passWord;
    bool isOpen;
    int openTimeAdmin;
    int closeTimeAdmin;
    double revenue;
    double tax;
    vector<string> vouchers;
    //vector<string> vouchersExpired;
    vector<RESTAURANT> restaurants;
    vector<CUSTOMER> customers;
    map <string, string> managerLink;
    map <string, string> custEmailLink; //(Email >> Code)
    map <string, string> custContactLink; //(Contact >> Email)
    map <string, double> voucherValueLink;
    map <string, int> voucherIndexLink;

public:
    ADMINISTRATOR(string _userName, string _passWord) : userName(_userName), passWord(_passWord){
        isOpen = false;
        openTimeAdmin = 0;
        closeTimeAdmin = 0;
        revenue = 0;
        tax = 0;
    }

    string getUserName(){return userName;}
    string getPassWord(){return passWord;}
    //bool getIsOpen(){return isOpen;}
    bool getIsOpen(){
        newTime();
        if(openTimeAdmin == closeTimeAdmin){
            return true;
        } else if(openTimeAdmin > closeTimeAdmin){
            if(((hours >= openTimeAdmin) && (hours > closeTimeAdmin)) || ((hours < openTimeAdmin) && (hours <= closeTimeAdmin))){
                return true;
             } else{
                return false;
            }
        } else{
            if((hours >= openTimeAdmin) && (hours <= closeTimeAdmin)){
                return true;
            } else{
                return false;
            }
        }
    }
    int getOpenTime(){return openTimeAdmin;}
    int getCloseTime(){return closeTimeAdmin;}
    //double revenue;
    //double tax;
    int getRestaurantSize(){return restaurants.size();}
    int getCustomerSize(){return customers.size();}

    int checkManager(string _managerID){
        if(managerLink[_managerID].length() == 0){
            return -1;
        }else{
            if(managerLink[_managerID] == "000"){
                setMessage("Following Manager account is suspended!");
            }else{
                setMessage("Manager ID duplicate found!");
            }
            return stoi(managerLink[_managerID]);
        }
    }

    void setIsOpen(bool _isOpen){isOpen = _isOpen;}
    void setOpenTime(int _openTime){openTimeAdmin = _openTime;}
    void setCloseTime(int _closeTime){closeTimeAdmin = _closeTime;}

    /*void setRestaurantCode(){
        if((restaurants.size() + 1) < 10){
            restaurants[restaurants.size()].setCode("00" + to_string((restaurants.size() + 1)));
        }
    }*/

    /*void setRestaurantLink(string _managerID, RESTAURANT& _restaurant){
        if(managerLink[_managerID].length() == 0){
            setRestaurantCode();
            managerLink[_managerID] = restaurants[restaurants.size()].getCode();
        }
    }*/

    string createRestCode(int _code){
        if(_code < 10){
            return ("00" + to_string(_code));
        }else if(_code < 100){
            return ("0" + to_string(_code));
        }else{
            return to_string(_code);
        }
    }

    string createCustCode(int _code){
        if(_code < 10){
            return ("000" + to_string(_code));
        }else if(_code < 100){
            return ("00" + to_string(_code));
        }else if(_code < 1000){
            return ("0" + to_string(_code));
        }else{
            return to_string(_code);
        }
    }

    void addRestaurant(RESTAURANT _restaurant){
        restaurants.push_back(_restaurant);
        restaurants[restaurants.size() - 1].setCode(createRestCode(restaurants.size()));
        managerLink[restaurants[restaurants.size() - 1].getManagerID()] = restaurants[restaurants.size() - 1].getCode();
    }

    int searchRestByMangerID(string _managerID){
        for(int i = 0; i < restaurants.size(); i++){
            if(restaurants[i].getManagerID() == _managerID){
                return i;
            }else{
                if(i == (restaurants.size() - 1)){
                    return -1;
                }
                continue;
            }
        }
    }

    void removeRestaurant(string _managerID){
        if(managerLink[_managerID] == "000"){
            cout << "Restaurant is already removed!" << endl;
        }else if(managerLink[_managerID].length() == 0){
            cout << "Restaurant does not exist" << endl;
        }else{
            restaurants[stoi(managerLink[_managerID]) - 1].setIsRestActive(false);
            restaurants[stoi(managerLink[_managerID]) - 1].setIsRestOpen(false);
            managerLink[_managerID] == "000";
            cout << "Restaurant has been removed" << endl;
        }
    }

    /*void reOpenRestaurant(string _managerID){
        if(managerLink[_managerID].length() == 0){
            cout << "Restaurant does not exist" << endl;
        }else if(managerLink[_managerID] == "000"){
            int restIndex = searchRestByMangerID(_managerID);
            if(restIndex == -1){
                cout << "Restaurant does not exist!" << endl;
            }else{
                managerLink[_managerID] == createRestCode(restIndex + 1);
                restaurants[stoi(managerLink[_managerID]) - 1].setIsActive(false);
                restaurants[stoi(managerLink[_managerID]) - 1].setIsOpen(false);
                managerLink[_managerID] == "000";
                cout << "Restaurant has been removed" << endl;
            }
        }
    }*/

    void reOpenRestaurant(string _managerID){
        if(managerLink[_managerID].length() == 0){
            cout << "Restaurant does not exist" << endl;
        }else if(managerLink[_managerID] == "000"){
            int restIndex = searchRestByMangerID(_managerID);
            if(restIndex == -1){
                cout << "Restaurant does not exist!" << endl;
            }else{
                managerLink[_managerID] == restaurants[restIndex].getCode();
                restaurants[(restIndex - 1)].setIsRestActive(true);
                cout << "Restaurant has been Re-Opened!" << endl;
            }
        }
    }

    void showRestaurants(){
        cout << "CODE | ManagerID |" << string(10, ' ') << "TITLE" << string(10, ' ') << "|    CITY    |    AREA    |    INCOME    |    TAX    | OPEN | S | M | T | W | T | F | S | TIMINGS\n";
        for(int i = 0; i < restaurants.size(); i++){
            gotoxy(4, i+8);
            cout << restaurants[i].getCode() << " | " << restaurants[i].getManagerID().substr(0, 9) << string(10-restaurants[i].getManagerID().length(), ' ') <<"| " << restaurants[i].getTitle().substr(0, 23) << string(23-restaurants[i].getTitle().length(), ' ') << " | " << restaurants[i].getCity() << string(10-restaurants[i].getCity().length(), ' ') << " | " << restaurants[i].getArea() << string(10-restaurants[i].getArea().length(), ' ') << " | " << setw(12) << restaurants[i].getRestRevenue() << " | " << setw(9) << restaurants[i].getRestTax() << " | ";
            if(restaurants[i].getIsRestActive() == true){
                cout << setw(7) << "YES | ";
            } else{
                cout << setw(7) << "NO | ";
            }
            for(int j = 0; j < 7; j++){
                if(restaurants[i].getDaysOpen(j) == true){
                    cout << "Y | ";
                } else{
                    cout << "N | ";
                }
            }
            cout << restaurants[i].getOpenTime() << " - " << restaurants[i].getCloseTime() << endl;
        }
    }

    void showRestaurants(string _restaurantCode){
        int i = stoi(_restaurantCode) - 1;
        if(i < restaurants.size()){
            cout << restaurants[i].getCode() << "\t" << restaurants[i].getTitle() << "\t"
                 << restaurants[i].getCity() << "\t" << restaurants[i].getArea() << "\t"
                 << restaurants[i].getManagerID() << endl;
        }else{
            cout << "No Restaurant found with the Code: " << _restaurantCode << endl;
        }
    }

    void showRestWithCuisine(string _cuisine){
        int lineSpace = 0;
        cout << "CODE | ManagerID |" << string(10, ' ') << "TITLE" << string(10, ' ') << "|    CITY    |    AREA    |    INCOME    |    TAX    | OPEN | S | M | T | W | T | F | S | TIMINGS\n";
        for(int i = 0; i < restaurants.size(); i++){
            if(restaurants[i].hasFood(_cuisine) == true){
                gotoxy(4, lineSpace+8);
                lineSpace++;
                cout << restaurants[i].getCode() << " | " << restaurants[i].getManagerID().substr(0, 9) << string(10-restaurants[i].getManagerID().length(), ' ') <<"| " << restaurants[i].getTitle().substr(0, 23) << string(23-restaurants[i].getTitle().length(), ' ') << " | " << restaurants[i].getCity() << string(10-restaurants[i].getCity().length(), ' ') << " | " << restaurants[i].getArea() << string(10-restaurants[i].getArea().length(), ' ') << " | " << setw(12) << restaurants[i].getRestRevenue() << " | " << setw(9) << restaurants[i].getRestTax() << " | ";
                if(restaurants[i].getIsRestActive() == true){
                    cout << setw(7) << "YES | ";
                } else{
                    cout << setw(7) << "NO | ";
                }
                for(int j = 0; j < 7; j++){
                    if(restaurants[i].getDaysOpen(j) == true){
                        cout << "Y | ";
                    } else{
                        cout << "N | ";
                    }
                }
                cout << restaurants[i].getOpenTime() << " - " << restaurants[i].getCloseTime() << endl;
            }
        }
    }

    void showRestOnLocation(int _city, int _area){
        int lineSpace = 0;
        cout << "CODE | ManagerID |" << string(10, ' ') << "TITLE" << string(10, ' ') << "|    CITY    |    AREA    |    INCOME    |    TAX    | OPEN | S | M | T | W | T | F | S | TIMINGS\n";
        for(int i = 0; i < restaurants.size(); i++){
            if((restaurants[i].getCity() == cities[_city][0]) && (restaurants[i].getArea() == cities[_city][_area])){
                gotoxy(4, lineSpace+8);
                lineSpace++;
                cout << restaurants[i].getCode() << " | " << restaurants[i].getManagerID().substr(0, 9) << string(10-restaurants[i].getManagerID().length(), ' ') <<"| " << restaurants[i].getTitle().substr(0, 23) << string(23-restaurants[i].getTitle().length(), ' ') << " | " << restaurants[i].getCity() << string(10-restaurants[i].getCity().length(), ' ') << " | " << restaurants[i].getArea() << string(10-restaurants[i].getArea().length(), ' ') << " | " << setw(12) << restaurants[i].getRestRevenue() << " | " << setw(9) << restaurants[i].getRestTax() << " | ";
                if(restaurants[i].getIsRestActive() == true){
                    cout << setw(7) << "YES | ";
                } else{
                    cout << setw(7) << "NO | ";
                }
                for(int j = 0; j < 7; j++){
                    if(restaurants[i].getDaysOpen(j) == true){
                        cout << "Y | ";
                    } else{
                        cout << "N | ";
                    }
                }
                cout << restaurants[i].getOpenTime() << " - " << restaurants[i].getCloseTime() << endl;
            }
        }
    };

    void addVoucher(string _voucher, double _value){
        if(voucherValueLink[_voucher] == -1){
            cout << "Voucher Exists but Expired!" << endl;
        } else if(voucherValueLink[_voucher] > 0){
            cout << "Voucher already exists!" << endl;
        } else{
            vouchers.push_back(_voucher);
            voucherValueLink[_voucher] = _value;
            voucherIndexLink[_voucher] = (vouchers.size() - 1);
            cout << "Voucher Added!" << endl;
        }
    }

    void removeVoucher(string _voucher){
        voucherValueLink[_voucher] = 0;
    }

    void expireVoucher(string _voucher){
        if(voucherValueLink[_voucher] > 0){
            voucherValueLink[_voucher] = -1;
            cout << "Voucher Expire!" << endl;
        } else if(voucherValueLink[_voucher] == -1){
            cout << "Voucher already Expired!" << endl;
        } else{
            cout << "Voucher Doesnot Exist" << endl;
        }
    }

    void addCustomer(CUSTOMER _customer){
        customers.push_back(_customer);
        customers[customers.size()-1].setCustomerCode(createCustCode(customers.size()));
        custEmailLink[customers[customers.size()-1].getEmailAddress()] = customers[customers.size()-1].getCustomerCode();
        custContactLink[customers[customers.size()-1].getContactNumber()] = customers[customers.size()-1].getEmailAddress();
    }

    void removeCustomer(string _emailAddress){
        if(custEmailLink[_emailAddress] == "0000"){
            cout << "Customer is already removed!" << endl;
        }else if(custEmailLink[_emailAddress].length() == 0){
            cout << "Customer does not exist" << endl;
        }else{
            customers[stoi(custEmailLink[_emailAddress]) - 1].setIsActive(false);
            custEmailLink[_emailAddress] == "0000";
            cout << "Customer has been removed" << endl;
        }
    }

    int searchCustByEmail(string _emailAddress){
        for(int i = 0; i < customers.size(); i++){
            if(customers[i].getEmailAddress() == _emailAddress){
                return i;
            }else{
                if(i == (customers.size() - 1)){
                    return -1;
                }
                continue;
            }
        }
    }

    void activateCustomer(string _emailAddress){
        if(custEmailLink[_emailAddress].length() == 0){
            cout << "Customer does not exist" << endl;
        }else if(custEmailLink[_emailAddress] == "0000"){
            int restIndex = searchCustByEmail(_emailAddress);
            if(restIndex == -1){
                cout << "Customer does not exist!" << endl;
            }else{
                custEmailLink[_emailAddress] == customers[restIndex].getCustomerCode();
                customers[(restIndex - 1)].setIsActive(true);
                cout << "Customer has been Activated!" << endl;
            }
        }
    }

    void sendVoucher(string _emailAddress,string _voucher){
        customers[stoi(custEmailLink[_emailAddress])-1].setVoucher(_voucher);
    }

    int calcOrders(string _type){
        int ordersCount = 0;
        if(_type == "Pending"){
            for(int i = 0; i < restaurants.size(); i++){
                ordersCount =+ restaurants[i].getOrdersPending();
            }
        } else if(_type == "Completed"){
            for(int i = 0; i < restaurants.size(); i++){
                ordersCount =+ restaurants[i].getOrdersCompleted();
            }
        } else if(_type == "Cancelled"){
            for(int i = 0; i < restaurants.size(); i++){
                ordersCount =+ restaurants[i].getOrdersCancelled();
            }
        } else{
            return -1;
        }
        return ordersCount;
    }

    int calcVouchers(string _type){
        int vouchersCount = 0;
        for(int i = 0; i < vouchers.size(); i++){
            if(voucherValueLink[vouchers[i]] > 0){
                vouchersCount++;
            }
        }
        if(_type == "Unused"){
            return vouchersCount;
        } else if(_type == "Used"){
            return (vouchers.size() - vouchersCount);
        }
    }

    int calcRestaurants(string _type){
        int restaurantsCount = 0;
        for(int i = 0; i < restaurants.size(); i++){
            if(managerLink[restaurants[i].getManagerID()] != "000"){
                restaurantsCount++;
            }
        }
        if(_type == "Active"){
            return restaurantsCount;
        } else if(_type == "Closed"){
            return (restaurants.size() - restaurantsCount);
        }
    }

    int calcCustomers(string _type){
        int customersCount = 0;
        for(int i = 0; i < customers.size(); i++){
            if(custEmailLink[customers[i].getEmailAddress()] != "0000"){
                customersCount++;
            }
        }
        if(_type == "Active"){
            return customersCount;
        } else if(_type == "Removed"){
            return (customers.size() - customersCount);
        }
    }

    void showSummary(){
        cout << "\tAdmin:\t\t>\t" << userName << "\n\n\tIs Open:\t>\t";
        if(getIsOpen() == true){
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << "\n\n\tTimings:\t>\t" << openTimeAdmin << " - " << closeTimeAdmin << "\n\n\tRevenue:\t>\t" << revenue << "\n\n\tTax:\t\t>\t" << tax << "\n\n\tVouchers Used:\t>\t" << calcVouchers("Used") << "\n\n\tVouchers Unused:\t" << calcVouchers("Unused") << "\n\n\tRestaurants Active:\t" << calcRestaurants("Active") << "\n\n\tRestaurants Closed:\t" << calcRestaurants("Closed") << "\n\n\tCustomers Active:\t" << calcCustomers("Active") << "\n\n\tCustomers Removed:\t" << calcCustomers("Removed") << "\n\n\tOrders Completed:\t" << calcOrders("Completed") << "\n\n\tOrders Pending:\t>\t" << calcOrders("Pending") << "\n\n\tOrders Cancelled:\t" << calcOrders("Cancelled") << endl;
    }

};


class FOOD{
    string itemCode;
    int cuisine;
    string foodTitle;
    string foodDescription;
    int stock;
    int limit;
    //bool haveSize;
    int prepTime;
    double discount;

protected:
    double price;

public:
    FOOD(int _cuisine, string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price){
        cuisine = _cuisine;
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }

    string getItemCode(){return itemCode;}
    int getCuisine(){return cuisine;}
    string getTitle(){return foodTitle;}
    string getDescription(){return foodDescription;}
    int getStock(){return stock;}
    int getLimit(){return limit;}
    double getPrice(){return price;}
    int getPrepTime(){return prepTime;}

    void setItemCode(string _itemCode){}
    void setCuisine(int _cuisine){}
    void setTitle(string _title){}
    void setDescription(string _description){}
    void setStock(int _stock){}
    void setLimit(int _limit){}
    void setPrice(double _price){}
    void setPrepTime(int _time){}
};


class PIZZA : public FOOD{
    //bool haveSize;
    vector<double> price;
    vector<string> size;

public:
    bool getHaveSize(){
        if(size.size() > 1){
            return true;
        }
        return false;
    }

    double getPrice(int _index){return price[_index];}
    string getSize(int _index){return size[_index];}
};


class BURGER : public FOOD{};
class SANDWICHE : public FOOD{};
class FASTFOOD : public FOOD{};
class BARBQ : public FOOD{};
class PAKISTANI : public FOOD{};
class CHINESE : public FOOD{};
class INTERNATIONAL : public FOOD{};
class SEAFOOD : public FOOD{};
class DESSERT : public FOOD{};
class BEVERAGE : public FOOD{};


class CAKE : public FOOD{
    //bool haveSize;
    vector<double> weight;

public:
    bool getHaveSize(){
        if(weight.size() > 1){
            return true;
        }
        return false;
    }
    double getPrice(int _index){return (price * weight[_index]);}
    double getWeight(int _index){return weight[_index];}
};


class ORDER{
    string orderNumber;
    TIMENOW orderTime;
    vector<PIZZA> pizzas;
    vector<BURGER> burgers;
    vector<SANDWICHE> sandwiches;
    vector<FASTFOOD> fastfoods;
    vector<BARBQ> barbqs;
    vector<PAKISTANI> pakistanis;
    vector<CHINESE> chineses;
    vector<INTERNATIONAL> internationals;
    vector<SEAFOOD> seafoods;
    vector<DESSERT> desserts;
    vector<CAKE> cakes;
    vector<BEVERAGE> beverages;
    bool isPaid;
    bool isApproved;
};


class TAXDEPARTMENT{
    string taxAdmin;
    string taxPass;
    vector<double> cuisineTax;
};


int main(){
    stringstream ss;
    string inputString, choiceString, inputItem, inputItems = "";
    string managerID, managerPassword, restaurantCode, title, description, contactNumber, address, openTime, closeTime, freeDelivery, restDiscount, minimumOrder, deliveryCharges;
    string firstName, lastName, customerCode, custPassword, emailAddress, custContactNumber, custAddress;
    string userName,passWord;
    string itemCode,foodTitle,foodDescription;
	string orderNumber;
    bool scrSizeCheck, firstInput = true;
    bool isRestActive, isRestOpen, isActive, isOpen, isPaid, isApproved;
    bool daysOpen[7] = {false,false,false,false,false,false,false};
    int fontSize = 19, menuIndex = 0, itemIndex, choice, restIndex, custIndex;
    int area, city, ordersPending, ordersCancelled, menuCount;
    int custArea, custCity, orderCount;
    int cuisine, stock, limit, prepTime;
    int openTimeAdmin, closeTimeAdmin;
    double restRevenue, restTax, walletAmount, revenue, tax;
    double discount, price;
    //object for File handling
    fstream adminFile;
    setConsoleSize(144, 47);
    setFontSize(fontSize, 500, L"Courier New");
    SetConsoleTitle("Food-Panda");

    cout << char(201) << string(142, char(205)) << char(187) << endl;
    cout << char(186) << setw(76) << "Food-Panda" << setw(67) << char(186) << endl;
    cout << char(204) << string(142, char(205)) << char(185) << endl;
    cout << char(186) << setw(143) << char(186) << endl;
    cout << char(199) << string(142, char(196)) << char(182) << endl;

    for(int i = 6; i <= 44; i++){
        cout << char(186) << setw(143) << char(186) << endl;
    }
    cout << char(199) << string(142, char(196)) << char(182) << endl;
    cout << char(186) << " Message: " << setw(133) << char(186) << endl;
    cout << char(200) << string(142, char(205)) << char(188);

    do{
        setMessage("Font Size is " + to_string(fontSize));
        gotoxy(25, 7);
        cout << "Can you See complete Double-:Lined Border inlined with you screen? (y/n): ";
        if(tolower(getche()) == 'n'){
            gotoxy(25, 9);
            cout << "You want it bigger or smaller? (b/s): ";
            if(tolower(getche()) == 'b'){
                setFontSize(++fontSize, 500, L"Courier New");
            } else{
                setFontSize(--fontSize, 500, L"Courier New");
            }
            scrSizeCheck = false;
        } else{
            scrSizeCheck = true;
        }
        cleanArea(25, 7, 143, 9);
    } while(scrSizeCheck == false);

    adminFile.open("admin.dat", ios::in | ios::binary);
    if(!adminFile.is_open()){
        //gotoxy(12, 46);
        //cout << "Administrator Details not Found!";
        adminFile.close();
        goto ADMIN;
        
    } else{
        getline(adminFile, userName);
        getline(adminFile, passWord);
        adminFile.close();
        setMessage("Administrator Found!");
        goto CreateAdmin;
    }

    //Creating AdminOB for th First Time
    ADMIN:
    setMessage("Administrator Details not Found! Setting Up Administrator");
    gotoxy(36, 7);
    cout << "Administrator ID: ";
    getline(cin, userName);
    gotoxy(36, 9);
    cout << "Administrator Password: ";
    getline(cin, passWord);
    
    CreateAdmin:
    adminFile.open("admin.dat", ios::out | ios::app | ios::binary);
    adminFile << userName << endl << passWord << endl;
    adminFile.close();
    ADMINISTRATOR adminOb(userName, passWord);

    MENU:
    setTitle(menu[menuIndex][0]);
    //gotoxy((135-menu[0][0].length())/2, 4);
    //cout << menu[0][0] << endl;
    gotoxy(1, 6);
    for(int i = 6; i <= 44; i++){
        cout << char(186) << setw(143) << char(186) << endl;
    }
    cleanArea(2, 6, 143, 44);
    for(int i = 1; i < menu[menuIndex].size(); i++){
        //gotoxy((132-menu[0][2].length())/2, 5+(i*2));
        gotoxy(4, 5+(i*2));
        if(i == (menu[menuIndex].size() - 1)){
            cout << "0> ";
            itemIndex = i + 1;
        } else{
            cout << i << "> ";
        }
        cout << menu[menuIndex][i];
        /*if(i == (menu[menuIndex].size() - 1)){
            cout << "\nInput: " << choiceString;
        }*/
    }
    

    /*do{
        cleanArea(12, 5+(itemIndex*2), 46, 5+(itemIndex*2));
        gotoxy(4, 5+(itemIndex*2));
        cout << "Choice: ";
        getline(cin, inputString);
        if(inputString.length() != 0){
            choice = stoi(inputString);
        }
    } while((inputString.length() == 0) || (choice > (menu[menuIndex].size()-2)));
    choiceString = choiceString + to_string(choice);*/

    do{
        if(firstInput == false){
            setMessage("Invalid Input!");
        }
        cleanArea(12, 5+(itemIndex*2), 46, 5+(itemIndex*2));
        gotoxy(4, 5+(itemIndex*2));
        cout << "Choice: ";
        getline(cin, inputString);
        firstInput = false;
    } while(inputString.length() == 0 || inputString.length() > 1);
    firstInput = true;
    choiceString = choiceString + inputString;

    switch (stoi(choiceString)){
    case 1:
        cleanArea(2, 6, 143, 44);
        setMessage("Please enter Administrator Credentials");
        gotoxy(36, 7);
        cout << "Administrator ID: ";
        getline(cin, userName);
        gotoxy(36, 9);
        cout << "Administrator Password: ";
        getline(cin, passWord);
        if(userName == adminOb.getUserName() && passWord == adminOb.getPassWord()){
            setMessage("Administrator Authentication Successfull!");
            menuIndex = 1;
        } else{
            setMessage("Bad Username/Password!");
            menuIndex = 0;
            choiceString = "";
        }
        goto MENU;
        break;
    
    case 11:
        menuIndex = 2;
        goto MENU;
        break;

    case 112:
        menuIndex = 3;
        goto MENU;
        break;

    case 12:
        menuIndex = 4;
        goto MENU;
        break;

    case 13:
        menuIndex = 5;
        goto MENU;
        break;

    case 14:
        menuIndex = 6;
        goto MENU;
        break;

    case 2:
        menuIndex = 7;
        goto MENU;
        break;

    case 26:
        menuIndex = 8;
        goto MENU;
        break;

    case 27:
        menuIndex = 9;
        goto MENU;
        break;

    case 3:
        menuIndex = 10;
        goto MENU;
        break;

    case 32:
        menuIndex = 11;
        goto MENU;
        break;

    case 325:
        menuIndex = 12;
        goto MENU;
        break;

    case 10:
        menuIndex = 0;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 20:
        menuIndex = 0;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 30:
        menuIndex = 0;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 110:
        menuIndex = 1;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;
    
    case 120:
        menuIndex = 1;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;
    
    case 130:
        menuIndex = 1;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 140:
        menuIndex = 1;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 1120:
        menuIndex = 2;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 260:
        menuIndex = 7;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 270:
        menuIndex = 7;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 320:
        menuIndex = 10;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;
    
    case 3250:
        menuIndex = 11;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 121:
        //clearMain();
        
        //setMessage(choiceString);
        /*gotoxy(1, 7);
        cout << "\tManager ID:\n\n\tManager Password:\n\n\tCities:";
        for(int i = 0; i < cities.size(); i++){
            cout << "\n\t\t" << i << ") " << cities[i][0] << endl;
        }
        cout << "\n\tChoice:\n\n\tAreas:";
        for(int i = 1; i < cities[city].size(); i++){
            cout << "\n\t\t" << i << ") " << cities[city][i] << endl;
        }
        cout << "\n\tChoice:\n\n\tAddress:\n\n\tRestaurant Title:\n\n\tRestaurant Description:\n\n\tContact Number:\n\n\tOpening Time:\n\n\tClosing Time:\n\n\tDiscount Percentage:\n\n\tDo you offer Free Delivery (y/n):\n";
        do{
            gotoxy(30, 7);
            getline(cin, inputItem);
        }while(adminOb.checkManager(inputItem) != -1);
        inputItems = inputItem;
        gotoxy(30, getY()+2);
        getline(cin, inputItem);
        inputItems = inputItems + ";" + inputItem;
        gotoxy(30, getY()+cities.size()+2);
        getline(cin, inputItem);
        inputItems = inputItems + ";" + inputItem;
        gotoxy(30, getY()+cities[stoi(inputItem)].size()+2);
        getline(cin, inputItem);
        inputItems = inputItems + ";" + inputItem;*/
        do{
            cleanArea(2, 6, 143, 44);
            gotoxy(1, 7);
            cout << "\tManager ID:\t\t";
            getline(cin, managerID);
        }while(adminOb.checkManager(managerID) != -1);
        cout << "\tManager Password:\t";
        getline(cin, managerPassword);
        //clearMain();
        cout << "\n\tCities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << "\t\t" << i << ") " << cities[i][0] << endl;
        }
        cout << "\tChoice:\t";
        cin >> city;
        //clearMain();
        cout << "\n\tArea:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << "\t\t" << i << ") " << cities[city][i] << endl;
        }
        cout << "\tChoice:\t";
        cin >> area;
        cin.clear();
        cin.ignore();
        //clearMain();
        cout << "\n\tAddress:\n\tRestaurant Title:\n\tRestaurant Description:\n\tContact Number:\n\tOpening Time:\n\tClosing Time:\n\tDiscount Percentage:";
        gotoxy(1, getY()-6);
        for(int i = 1; i < 8; i++){
            cout << "\t\t\t\t  ";
            getline(cin, inputItem);
            inputItems = inputItems + inputItem + ";";
        }
        cout << "\tDo you offer Free Delivery (y/n):\t";
        //cin >> freeDeliver;
        //cout << "\t\t\t\t  ";
        if(getche() == 'y'){
            //freeDelivery = true;
            //inputItem = "1";
            inputItems = inputItems + "1;";
            cout << "\n\tMinimum Order for Free Delivery:\t";
            getline(cin, inputItem);
            inputItems = inputItems + inputItem + ";";
            if(stoi(inputItem) > 0){
                cout << "\tDelivery Charges for Orders less than " << inputItem << ":\t";
                //cin >> deliveryCharges;
                getline(cin, inputItem);
                inputItems = inputItems + inputItem;
            } else{
                inputItems = inputItems + "0";
            }
        } else{
            //inputItem = 0;
            inputItems = inputItems + "0" + ";";
            inputItems = inputItems + "0" + ";";
            cout << "\n\tDelivery Charges:\t";
            //cin >> deliveryCharges;
            getline(cin, inputItem);
            inputItems = inputItems + inputItem;
        }
        ss.str(inputItems);
        getline(ss, address, ';');
        getline(ss, title, ';');
        getline(ss, description, ';');
        getline(ss, contactNumber, ';');
        getline(ss, openTime, ';');
        getline(ss, closeTime, ';');
        getline(ss, restDiscount, ';');
        getline(ss, freeDelivery, ';');
        getline(ss, minimumOrder, ';');
        getline(ss, deliveryCharges, ';');
        
        {
            RESTAURANT restOb(managerID, managerPassword, stoi(openTime), stoi(closeTime), title, description, contactNumber, address, area, city, stoi(freeDelivery), stod(minimumOrder), stod(deliveryCharges), stod(restDiscount));
            adminOb.addRestaurant(restOb);
        }
        inputItems = "";
        ss.clear();
        
        //getline(ss, inputItems);
        //ss.str(inputItems);
        //getline(ss, restTitle, ';')
        //getline(ss, inputItem, ';')
        //openTime = stoi(inputItem);
        /*cout << "Manager Password: ";
        cin >> managerPassword;
        cout << "Opening Time: ";
        cin >> openTime;
        cout << "Closing Time: ";
        cin >> closeTime;
        cout << "Restaurant Title: ";
        cin >> title;
        cout << "Restaurant Description: ";
        cin >> description;
        cout << "Contact Number: ";
        cin >> contactNumber;
        cout << "Cities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << i << ") " << cities[i][0] << endl;
        }
        cout << "Choice: ";
        cin >> city;
        cout << "Areas:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << i << ") " << cities[city][i] << endl;
        }
        cout << "Choice: ";
        cin >> area;
        cout << "Address: ";
        cin >> address;
        cout << "Do you offer Free Delivery (y/n): ";
        cin >> freeDeliver;
        if(freeDeliver == "y"){
            freeDelivery = true;
            cout << "Minimum Order for Free Delivery: ";
            cin >> minimumOrder;
            if(minimumOrder > 0){
                cout << "Delivery Charges for Orders less than " << minimumOrder << ": ";
                cin >> deliveryCharges;
            }
        }else{
            cout << "Delivery Charges: ";
            cin >> deliveryCharges;
        }
        cout << "Discount Percentage: ";
        cin >> restDiscount;
        cout << "pass1\n";
        RESTAURANT restOb(managerID, managerPassword, openTime, closeTime, title, description, contactNumber, address, area, city, freeDelivery, minimumOrder, deliveryCharges, restDiscount);
        cout << "pass2\n";
        adminOb.addRestaurant(restOb);
        cout << "pass3\n";
        cout << adminOb.getRestaurantSize() << endl;
        getline(cin, userName);*/
        //setContinue();
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        setMessage(title);
        goto MENU;
        break;

    case 1121:
        cleanArea(2, 6, 143, 44);
        gotoxy(3, 7);
        adminOb.showRestaurants();
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 111:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        adminOb.showSummary();
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 1122:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << "\t" << (i + 1) << "> " << cuisineTitle[i] << "\n" << endl;
        }
        cout << "\t0> Go Back\n\n\tChoice: ";
        getline(cin, inputItem);
        inputItem = to_string(stoi(inputItem) - 1);
        if(inputItem != "-1"){
            cleanArea(2, 6, 143, 44);
            gotoxy(3, 7);
            adminOb.showRestWithCuisine(cuisineTitle[stoi(inputItem)]);
            system("pause");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 1123:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        for(int i = 0; i < cities.size(); i++){
            cout << "\t" << (i + 1) << "> " << cities[i][0] << "\n" << endl;
        }
        cout << "\t0> Go Back\n\n\tChoice: ";
        cin >> city;
        city--;
        if(city != -1){
            cleanArea(2, 6, 143, 44);
            gotoxy(4, 7);
            for(int i = 1; i < cities[city].size(); i++){
                cout << "\t" << i << "> " << cities[city][i] << "\n" << endl;
            }
            cout << "\t0> Go Back\n\n\tChoice: ";
            cin >> area;
            if(area != 0){
                cleanArea(2, 6, 143, 44);
                gotoxy(3, 7);
                adminOb.showRestOnLocation(city, area);
                system("pause");
            }
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 0:
        system("exit");
        /*if(menuIndex == 0){
            system("exit");
        }
        else
        menuIndex = 10;
        goto MENU;*/
        break;

    default:
        break;
    }

    gotoxy(20, 20);
    system("pause");
    
    
    
    /*string userName, passWord, managerID, managerPassword, restaurantCode, title, description, contactNumber, address, freeDeliver;
    int choice, openTime, closeTime, minimumOrder = 0, deliveryCharges, area, city;
    bool freeDelivery = false;
    cout << "Administrator ID: ";
    cin >> userName;
    cout << "Administrator Password: ";
    cin >> passWord;
    ADMINISTRATOR adminOb(userName, passWord);
    
    MainMenu:
    system("cls");
    cout << "Adminstrator\nRestaurant\nCustomer\nTax\nChoice: ";
    cin >> choice;

    switch (choice){
    case 1:
        goto AdminMenu;
        break;
    
    case 2:
        goto RestMenu;
        break;
    
    default:
        break;
    }

    AdminMenu:
    system("cls");
    cout << "Add Restaurant\nShow Restaurants\nShow Restaurant (code)\nChoice: ";
    cin >> choice;

    switch (choice){
    case 1:{
        do{
            cout << "Manager ID: ";
            cin >> managerID;
        }while(adminOb.checkManager(managerID) != -1);
        cout << "Manager Password: ";
        cin >> managerPassword;
        cout << "Opening Time: ";
        cin >> openTime;
        cout << "Closing Time: ";
        cin >> closeTime;
        cout << "Restaurant Title: ";
        cin >> title;
        cout << "Restaurant Description: ";
        cin >> description;
        cout << "Contact Number: ";
        cin >> contactNumber;
        cout << "Cities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << i << ") " << cities[i][0] << endl;
        }
        cout << "Choice: ";
        cin >> city;
        cout << "Areas:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << i << ") " << cities[city][i] << endl;
        }
        cout << "Choice: ";
        cin >> area;
        cout << "Address: ";
        cin >> address;
        cout << "Do you offer Free Delivery (y/n): ";
        cin >> freeDeliver;
        if(freeDeliver == "y"){
            freeDelivery = true;
            cout << "Minimum Order for Free Delivery: ";
            cin >> minimumOrder;
            if(minimumOrder > 0){
                cout << "Delivery Charges for Orders less than " << minimumOrder << ": ";
                cin >> deliveryCharges;
            }
        }else{
            cout << "Delivery Charges: ";
            cin >> deliveryCharges;
        }
        cout << "pass1\n";
        RESTAURANT restOb(managerID, managerPassword, openTime, closeTime, title, description, contactNumber, address, area, city, freeDelivery, minimumOrder, deliveryCharges);
        cout << "pass2\n";
        adminOb.addRestaurant(restOb);
        cout << "pass3\n";
        cout << adminOb.getRestaurantSize() << endl;
        system("pause");
    }
        goto MainMenu;
        break;
    
    case 2:
        adminOb.showRestaurants();
        system("pause");
        break;

    case 3:
        cout << "Restaurant Code: ";
        cin >> restaurantCode;
        adminOb.showRestaurants(restaurantCode);
        system("pause");
        break;

    default:
        break;
    }

    RestMenu:
    system("cls");*/















    /*cout << ss.substr(0, ss.length()-1) << endl;
    cout << "Date: " << day << "/" << (month + 1) << "/" << (year + 1900) << endl;
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;

    vector<string> myVec(0);
    myVec.push_back("A");
    myVec.push_back("B");
    myVec.push_back("C");
    myVec.erase(myVec.begin(), myVec.end());
    for(int i =0;i< myVec.size();i++){
        cout << i << " = " << myVec[i] << endl;
    }
    cout << myVec.size() << endl;
    cout << cuisineTitle.size() << endl;
    system("pause");
    newTime();
    cout << ss.substr(0, ss.length()-1) << endl;
    cout << "Date: " << day << "/" << (month + 1) << "/" << (year + 1900) << endl;
    cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;*/
    return 0;
}

void cleanArea(int _x1, int _y1, int _x2, int _y2){
    for(int i = _y1; i <= _y2; i++){
        gotoxy(_x1, _y1++);
        cout << string((_x2 - _x1 + 1), ' ') << endl;
    }
}

void clearMain(){
    cleanArea(1, 6, 144, 44);
    gotoxy(1, 7);
}

//Sets Message at bottom
void setMessage(string message){
    cleanArea(12, 46, 143, 46);
    gotoxy(12, 46);
    cout << message;
}

void setContinue(){
    cleanArea(12, 46, 143, 46);
    gotoxy(12, 46);
    system("pause");
}

void setTitle(string message){
    cleanArea(2, 4, 143, 4);
    gotoxy(73-message.length()/2, 4);
    cout << message;
}

/*void replaceSpace(string& _string){
    for(int i = 0; i < _string.length(); i++){}
}*/