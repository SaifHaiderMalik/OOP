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
#include <conio.h>
//#include <wchar.h>
#include "color.h"
#include "console.h"
#include "font.h"
#include "position.h"

using namespace std;

void cleanArea(int _x1, int _y1, int _x2, int _y2);
void setMessage(string message);
void setTitle(string message);
void setContinue();
void clearMain();
void showCuisine(int _index);

class FOOD;
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
                            {"ADMINISTRATOR > Show Details", "Summary", "Show Restaurants", "Show Customers", "Go Back"}, //2
                            {"ADMINISTRATOR > Show Details > Show Restaurants", "Show All", "By Cuisine", "By Location", "Go Back"}, //3
                            {"ADMINISTRATOR > Restaurant Management", "Add New", "Close", "Re-Open", "Find", "Go Back"}, //4
                            {"ADMINISTRATOR > Customer Management", "Add New", "Block", "Unblock", "Find", "Go Back"}, //5
                            {"ADMINISTRATOR > Voucher Management", "Add New", "Block", "Send", "Show", "Go Back"}, //6
                            {"RESTAURANT MANAGER", "Show Details", "Change Password", "Open/Close Restaurant", "Set Opening Days/Timings", "Modify Details", "Menu Management", "Order Management", "Go Back"}, //7
                            {"RESTAURANT MANAGER > Menu Management", "Add Item", "Modify Item Details", "Delete Item", "Show Details", "Go Back"}, //8
                            {"RESTAURANT MANAGER > Order Management", "Approve/Cancel Orders", "Show Details", "Go Back"}, //9
                            {"CUSTOMER", "New User", "Sign In", "Go Back"}, //10
                            {"CUSTOMER > Signed In", "Show Details", "Modify Details", "Order Food", "Order Details", "Voucher Management", "Go Back"}, //11
                            {"CUSTOMER > Signed In > Voucher Management", "Show Details", "Use Voucher", "Go Back"}, //12
                            {"ADMINISTRATOR > Show Details > Show Customers", "Show All", "By Location", "Go Back"}, //13
                            {"RESTAURANT MANAGER > Menu Management > Show Details", "Show All", "Show by Cuisine", "Show by Code", "Show by Title", "Show by Price", "Go Back"}, //14
                            {"CUSTOMER > Signed In > Order Food", "Show Restaurants", "Show Restaurants Menu", "Go Back"}}; //15

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

class FOOD{
private:
    //int stock;
    //int limit;
protected:
    double price;
    string itemCode;
    const int cuisine;
    string foodTitle;
    string foodDescription;
    int prepTime;
    double discount;
    int stock;
    int limit;

public:
    /*FOOD(int _cuisine, string _title, string _description, int _stock, int _limit, int _time, double _discount):cuisine(_cuisine){
        //cuisine = _cuisine;
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
    }*/

    FOOD(int _cuisine):cuisine(_cuisine){}

    string getItemCode(){return itemCode;}
    int getCuisine(){return cuisine;}
    string getTitle(){return foodTitle;}
    string getDescription(){return foodDescription;}
    int getStock(){return stock;}
    int getLimit(){return limit;}
    double getPrice(){return price;}
    double getDiscount(){return discount*100;}
    int getPrepTime(){return prepTime;}

    void setItemCode(string _itemCode){itemCode = _itemCode;}
    //void setCuisine(int _cuisine){}
    void setTitle(string _title){foodTitle = _title;}
    void setDescription(string _description){foodDescription = _description;}
    void setStock(int _stock){stock = _stock;}
    void setLimit(int _limit){limit = _limit;}
    void setPrice(double _price){price = _price;}
    void setDiscount(double _discount){discount = _discount/100;}
    void setPrepTime(int _time){prepTime = _time;}

    void showDetails(){
        cout << "\tCode: " << itemCode << "\n\tTitle: " << foodTitle << "\n\tDescription: " << foodDescription << "\n\tstock: " << stock << "\n\tLimit: " << limit << "\n\tTime: " << prepTime << "\n\tDiscount: " << discount << "\n\tPrice: " << price << endl;;
    }
};


class ORDERITEM{
    string code;
    int cuisine;
    string title;
    string description;
    double price;
    double discount;
    int prepTime;
    int quantity;

public:
    ORDERITEM(int _cuisine, string _code, string _title, string _description, double _price, double _discount, int _prepTime, int _quantity){
        code = _code;
        title = _title;
        cuisine = _cuisine;
        description = _description;
        price = _price;
        discount = _discount;
        prepTime = _prepTime;
        quantity = _quantity;
    }

    ORDERITEM(){}

    string getCode(){return code;}
    int getCuisine(){return cuisine;}
    string getTitle(){return title;}
    string getDescription(){return description;}
    double getPriceTotal(){return (price * quantity);}
    double getPriceTotalValue(){return (price * quantity * (1+discount));}
    double getPrice(){return price;}
    double getDiscountPercent(){return discount;}
    double getDiscountValue(){return (discount * price);}
    double getDiscountValueTotal(){return (discount * price * quantity);}
    int getPrepTime(){return prepTime;}
    int getQuantity(){return quantity;}

    void setCode(string _code){code = _code;}
    void setTitle(string _title){title = _title;}
    void setDescription(string _description){description = _description;}
    void setPrice(double _price){price = _price;}
    void setDiscountPercent(double _discount){discount = _discount;}
    void setPrepTime(int _time){prepTime = _time;}
    void setQuantity(int _quantity){quantity = _quantity;}
    void addQuantity(int _quantity){quantity += _quantity;}
};


class PIZZA : public FOOD{
    //bool haveSize;
    vector<double> price;
    vector<string> size;

public:
    PIZZA(string _title, string _description, int _stock, int _limit, int _time, double _discount, vector<double> _price, vector<string> _size):FOOD(0){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
        size = _size;
    }

    PIZZA():FOOD(0){}

    bool getHaveSize(){
        if(size.size() > 1){
            return true;
        }
        return false;
    }

    double getPrice(int _index){return price[_index];}
    vector<double> getPrice(){return price;}
    string getSize(int _index){return size[_index];}
    vector<string> getSize(){return size;}
    int getSizeLength(){return size.size();}
    void setPrice(vector<double> _price){
        price = _price;
    }
    void setSize(vector<string> _size){
        size = _size;
    }

    void showDetails(){
        cout << "\tCode: " << itemCode << "\n\tTitle: " << foodTitle << "\n\tDescription: " << foodDescription << "\n\tstock: " << stock << "\n\tLimit: " << limit << "\n\tTime: " << prepTime << "\n\tDiscount: " << discount;
        for(int i = 0; i < size.size(); i++){
            cout << "\n\n\tSize: " << (i + 1) << "\n\t\t" << size[i] << ": " << price[i];
        }
    }
};


class BURGER : public FOOD{
public:
    BURGER(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(1){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class SANDWICHE : public FOOD{
public:
    SANDWICHE(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(2){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class FASTFOOD : public FOOD{
public:
    FASTFOOD(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(3){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class BARBQ : public FOOD{
public:
    BARBQ(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(4){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class PAKISTANI : public FOOD{
public:
    PAKISTANI(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(5){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class CHINESE : public FOOD{
public:
    CHINESE(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(6){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class INTERNATIONAL : public FOOD{
public:
    INTERNATIONAL(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(7){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class SEAFOOD : public FOOD{
public:
    SEAFOOD(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(8){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class DESSERT : public FOOD{
public:
    DESSERT(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(9){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};


class CAKE : public FOOD{
    //bool haveSize;
    //vector<double> weight;

public:
    /*CAKE(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price, vector<double> _weight):FOOD(10){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
        weight = _weight;
    }*/

    CAKE(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(10){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }

    //CAKE():FOOD(10){}

    /*bool getHaveSize(){
        if(weight.size() > 1){
            return true;
        }
        return false;
    }*/

    /*double getPrice(int _index){return price;}
    double getPriceUnit(){return price;}
    double getWeight(int _index){return weight[_index];}
    vector<double> getWeight(){return weight;}
    void setWeight(vector<double> _weight){
        weight = _weight;
    }*/
};


class BEVERAGE : public FOOD{
public:
    BEVERAGE(string _title, string _description, int _stock, int _limit, int _time, double _discount, double _price):FOOD(11){
        foodTitle = _title;
        foodDescription = _description;
        stock = _stock;
        limit = _limit;
        prepTime = _time;
        discount = _discount;
        price = _price;
    }
};



class ORDER{
    string orderNumber;
    TIMENOW orderTime;
    vector<ORDERITEM> orderItems;
    bool isPaid;
    bool isApproved;

public:
    string getOrderNumber(){return orderNumber;}
    string getDate(){return orderTime.getDate();}
    string getTime(){return orderTime.getTime();};
    bool getIsPaid(){return isPaid;}
    bool getIsApproved(){return isApproved;}
    int getOrderItemsSize(){return orderItems.size();}
    vector<ORDERITEM> getOrderItems(){return orderItems;}
    ORDERITEM getOrderItems(int _index){return orderItems[_index];}

    void setIsPaid(bool _bool){
        isPaid = _bool;
    }

    void setIsApproved(bool _bool){
        isPaid = _bool;
    }

    void setOrderNumber(string _orderNumber){orderNumber = _orderNumber;}

    

    void addOrderItem(string _restCode, string _custCode, ORDERITEM _order){
        for(int i = 0; i < orderItems.size(); i++){
            if(_order.getCode() == orderItems[i].getCode()){
                orderItems[i].addQuantity(_order.getQuantity());
                return;
            }
        }
        orderItems.push_back(_order);
    }

    int getBill(){
        int amount = 0;
        for(int i = 0; i < orderItems.size(); i++){
            amount += orderItems[i].getPriceTotal();
        }
        return amount;
    }

    int getPrepTime(){
        int duration = 0;
        for(int i =0; i < orderItems.size(); i++){
            if(duration < orderItems[i].getPrepTime()){
                duration = orderItems[i].getPrepTime();
            }
        }
        return duration;
    }
    /*bool hasPizza(){
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
    }*/
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
    vector<ORDER> restOrders;
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

    RESTAURANT(){}

    string getCode(){return restaurantCode;}
    string getTitle(){return title;}
    string getAddress(){return address;}
    string getCity(){return cities[city][0];}
    string getArea(){return cities[city][area];}
    string getManagerID(){return managerID;}
    string getManagerPassword(){return managerPassword;}
    string getTime(){return (to_string(openTime) + " - " + to_string(closeTime));}
    bool getIsRestActive(){return isRestActive;}
    bool getIsRestOpen(){return isRestOpen;}
    int getOpenTime(){return openTime;}
    int getCloseTime(){return (closeTime + 1);}
    int getMenuCount(){return menuCount;}
    int getOrderSize(){return restOrders.size();}

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

    bool hasFood(int _cuisine){
        if((_cuisine == 0) && (hasPizza() == true)){
            return true;
        } else if((_cuisine == 1) && (hasBurgers() == true)){
            return true;
        } else if((_cuisine == 2) && (hasSandwiches() == true)){
            return true;
        } else if((_cuisine == 3) && (hasFastfoods() == true)){
            return true;
        } else if((_cuisine == 4) && (hasBarbqs() == true)){
            return true;
        } else if((_cuisine == 5) && (hasPakistanis() == true)){
            return true;
        } else if((_cuisine == 6) && (hasChineses() == true)){
            return true;
        } else if((_cuisine == 7) && (hasInternationals() == true)){
            return true;
        } else if((_cuisine == 8) && (hasSeafoods() == true)){
            return true;
        } else if((_cuisine == 9) && (hasDesserts() == true)){
            return true;
        } else if((_cuisine == 10) && (hasCakes() == true)){
            return true;
        } else if((_cuisine == 11) && (hasBeverages() == true)){
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
    double getRestDiscount(){return (restDiscount * 100);}
    string getContactNumber(){return contactNumber;}
    double getRestRevenue(){return restRevenue;}
    double getRestTax(){return restTax;}
    int getOrdersPending(){return ordersPending;}
    int getOrdersCompleted(){return ordersCompleted;}
    int getOrdersCancelled(){return ordersCancelled;}
    bool getFreeDelivery(){return freeDelivery;}
    int getMinimumOrder(){return minimumOrder;}
    double getDeliveryCharges(){return deliveryCharges;}
    string getDescription(){return description;}

    void setCode(string _code){
        restaurantCode = _code;
    }
    void setManagerID(string _managerID){
        managerID = _managerID;
    }
    void setManagerPassword(string _managerPassword){
        managerPassword = _managerPassword;
    }
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
    void setDiscount(double _int){
        restDiscount = _int/100;
    }
    void setFreeDelivery(bool _bool){
        freeDelivery = _bool;
    }
    void setMininmumOrder(int _int){
        minimumOrder = _int;
    }
    void setDeliveryCharges(double _double){
        deliveryCharges = _double;
    }
    void IncreaseordersPending(int _oredersPending){
        ordersPending = _oredersPending;
    }

    bool managerLogin(string _managerID, string _password){
        if(managerID == _managerID && managerPassword == _password){
            cout << "Welcome " << managerID << " to " << title << endl;
            return true;
        }else{
            cout << "Bad Manager ID or Password!" << endl;
            return false;
        }
    }

    void setDayOpen(int _day){
        daysOpen[_day] = true;
    }

    void setDayClose(int _day){
        daysOpen[_day] = false;
    }

    string createItemCode(int _cuisine, int _item){
        if(_cuisine < 10){
            if(_item < 10){
                return ("0" + to_string(_cuisine) + "00" + to_string(_item));
            } else if(_item < 100){
                return ("0" + to_string(_cuisine) + "0" + to_string(_item));
            } else{
                return ("0" + to_string(_cuisine) + to_string(_item));
            }
        } else{
            if(_item < 10){
                return (to_string(_cuisine) + "00" + to_string(_item));
            } else if(_item < 100){
                return (to_string(_cuisine) + "0" + to_string(_item));
            } else{
                return (to_string(_cuisine) + to_string(_item));
            }
        }
    }

    void addItem(PIZZA _pizza){
        pizzas.push_back(_pizza);
        pizzas[pizzas.size()-1].setItemCode(restaurantCode + createItemCode(0, pizzas.size()));
    }

    void addItem(BURGER _burger){
        burgers.push_back(_burger);
        burgers[burgers.size()-1].setItemCode(restaurantCode + createItemCode(1, burgers.size()));
    }

    void addItem(SANDWICHE _sandwich){
        sandwiches.push_back(_sandwich);
        sandwiches[sandwiches.size()-1].setItemCode(restaurantCode + createItemCode(2, sandwiches.size()));
    }

    void addItem(FASTFOOD _fastFood){
        fastfoods.push_back(_fastFood);
        fastfoods[fastfoods.size()-1].setItemCode(restaurantCode + createItemCode(3, fastfoods.size()));
    }

    void addItem(BARBQ _barBQ){
        barbqs.push_back(_barBQ);
        barbqs[barbqs.size()-1].setItemCode(restaurantCode + createItemCode(4, barbqs.size()));
    }

    void addItem(PAKISTANI _pakistani){
        pakistanis.push_back(_pakistani);
        pakistanis[pakistanis.size()-1].setItemCode(restaurantCode + createItemCode(5, pakistanis.size()));
    }

    void addItem(CHINESE _chinese){
        chineses.push_back(_chinese);
        chineses[chineses.size()-1].setItemCode(restaurantCode + createItemCode(6, chineses.size()));
    }

    void addItem(INTERNATIONAL _international){
        internationals.push_back(_international);
        internationals[internationals.size()-1].setItemCode(restaurantCode + createItemCode(7, internationals.size()));
    }

    void addItem(SEAFOOD _seaFood){
        seafoods.push_back(_seaFood);
        seafoods[seafoods.size()-1].setItemCode(restaurantCode + createItemCode(8, seafoods.size()));
    }

    void addItem(DESSERT _dessert){
        desserts.push_back(_dessert);
        desserts[desserts.size()-1].setItemCode(restaurantCode + createItemCode(9, desserts.size()));
    }

    void addItem(CAKE _cake){
        cakes.push_back(_cake);
        cakes[cakes.size()-1].setItemCode(restaurantCode + createItemCode(10, cakes.size()));
    }

    void addItem(BEVERAGE _beverage){
        beverages.push_back(_beverage);
        beverages[beverages.size()-1].setItemCode(restaurantCode + createItemCode(11, beverages.size()));
    }

    string deleteItem(string _itemCode){
        int i = (stoi(_itemCode.substr(5, 3)) - 1);
        if((_itemCode.substr(3, 2) == "00") && (i < pizzas.size())){
            pizzas[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "01") && (i < burgers.size())){
            burgers[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "02") && (i < sandwiches.size())){
            sandwiches[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "03") && (i < fastfoods.size())){
            fastfoods[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "04") && (i < barbqs.size())){
            barbqs[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "05") && (i < pakistanis.size())){
            pakistanis[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "06") && (i < chineses.size())){
            chineses[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "07") && (i < internationals.size())){
            internationals[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "08") && (i < seafoods.size())){
            seafoods[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "09") && (i < desserts.size())){
            desserts[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "10") && (i < cakes.size())){
            cakes[i].setStock(0);
            return ("Item Deletion Successful!");
        } else if((_itemCode.substr(3, 2) == "11") && (i < beverages.size())){
            beverages[i].setStock(0);
            return ("Item Deletion Successful!");
        } else{
            return ("Item Deletion Unsuccessful! Invalid Code!");
        }
    }

    void showFood(int _cuisine, int _index){
        //pizzas[_index].showDetails();
        burgers[_index].showDetails();
    }

    void displayRestMenu(int _cuisine){
        int title[6] = {10, 20, 30, 19, 8, 15};
        cout << "\t\t\t\t" << char(218);
        for(int i = 0; i < 6; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t\t\t\t" << char(179) << setw(title[0]) << "ItemCode " << char(179) << setw(title[1]) << "TITLE " << char(179) << setw(title[2]) << "DESCRIPTION " << char(179) << setw(title[3]) << "PRICE " << char(179) << setw(title[4]) << "DISCOUNT" << char(179) << setw(title[5]) << "DELIVERY TIME " << char(179);
        cout << "\n\t\t\t\t" << char(195);
        for(int i = 0; i < 6; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        switch (_cuisine){
        case 0:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < pizzas.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << pizzas[j].getItemCode() << char(179) << setw(title[1]) << pizzas[j].getTitle() << char(179) << setw(title[2]) << pizzas[j].getDescription() << char(179) << setw(8) << pizzas[j].getPrice(0) << " - " << setw(8) << pizzas[j].getPrice(pizzas[j].getPrice().size()-1) << char(179) << setw(title[4]) << pizzas[j].getDiscount() << char(179) << setw(title[5]) << (to_string(pizzas[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 1:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < burgers.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << burgers[j].getItemCode() << char(179) << setw(title[1]) << burgers[j].getTitle() << char(179) << setw(title[2]) << burgers[j].getDescription() << char(179) << setw(8) << burgers[j].getPrice() << " - " << setw(8) << burgers[j].getPrice() << char(179) << setw(title[4]) << burgers[j].getDiscount() << char(179) << setw(title[5]) << (to_string(burgers[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 2:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < sandwiches.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << sandwiches[j].getItemCode() << char(179) << setw(title[1]) << sandwiches[j].getTitle() << char(179) << setw(title[2]) << sandwiches[j].getDescription() << char(179) << setw(8) << sandwiches[j].getPrice() << " - " << setw(8) << sandwiches[j].getPrice() << char(179) << setw(title[4]) << sandwiches[j].getDiscount() << char(179) << setw(title[5]) << (to_string(sandwiches[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 3:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < fastfoods.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << fastfoods[j].getItemCode() << char(179) << setw(title[1]) << fastfoods[j].getTitle() << char(179) << setw(title[2]) << fastfoods[j].getDescription() << char(179) << setw(8) << fastfoods[j].getPrice() << " - " << setw(8) << fastfoods[j].getPrice() << char(179) << setw(title[4]) << fastfoods[j].getDiscount() << char(179) << setw(title[5]) << (to_string(fastfoods[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 4:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < barbqs.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << barbqs[j].getItemCode() << char(179) << setw(title[1]) << barbqs[j].getTitle() << char(179) << setw(title[2]) << barbqs[j].getDescription() << char(179) << setw(8) << barbqs[j].getPrice() << " - " << setw(8) << barbqs[j].getPrice() << char(179) << setw(title[4]) << barbqs[j].getDiscount() << char(179) << setw(title[5]) << (to_string(barbqs[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 5:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < pakistanis.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << pakistanis[j].getItemCode() << char(179) << setw(title[1]) << pakistanis[j].getTitle() << char(179) << setw(title[2]) << pakistanis[j].getDescription() << char(179) << setw(8) << pakistanis[j].getPrice() << " - " << setw(8) << pakistanis[j].getPrice() << char(179) << setw(title[4]) << pakistanis[j].getDiscount() << char(179) << setw(title[5]) << (to_string(pakistanis[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 6:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < chineses.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << chineses[j].getItemCode() << char(179) << setw(title[1]) << chineses[j].getTitle() << char(179) << setw(title[2]) << chineses[j].getDescription() << char(179) << setw(8) << chineses[j].getPrice() << " - " << setw(8) << chineses[j].getPrice() << char(179) << setw(title[4]) << chineses[j].getDiscount() << char(179) << setw(title[5]) << (to_string(chineses[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 7:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < internationals.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << internationals[j].getItemCode() << char(179) << setw(title[1]) << internationals[j].getTitle() << char(179) << setw(title[2]) << internationals[j].getDescription() << char(179) << setw(8) << internationals[j].getPrice() << " - " << setw(8) << internationals[j].getPrice() << char(179) << setw(title[4]) << internationals[j].getDiscount() << char(179) << setw(title[5]) << (to_string(internationals[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 8:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < seafoods.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << seafoods[j].getItemCode() << char(179) << setw(title[1]) << seafoods[j].getTitle() << char(179) << setw(title[2]) << seafoods[j].getDescription() << char(179) << setw(8) << seafoods[j].getPrice() << " - " << setw(8) << seafoods[j].getPrice() << char(179) << setw(title[4]) << seafoods[j].getDiscount() << char(179) << setw(title[5]) << (to_string(seafoods[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 9:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < desserts.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << desserts[j].getItemCode() << char(179) << setw(title[1]) << desserts[j].getTitle() << char(179) << setw(title[2]) << desserts[j].getDescription() << char(179) << setw(8) << desserts[j].getPrice() << " - " << setw(8) << desserts[j].getPrice() << char(179) << setw(title[4]) << desserts[j].getDiscount() << char(179) << setw(title[5]) << (to_string(desserts[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 10:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < cakes.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << cakes[j].getItemCode() << char(179) << setw(title[1]) << cakes[j].getTitle() << char(179) << setw(title[2]) << cakes[j].getDescription() << char(179) << setw(8) << cakes[j].getPrice() << " - " << setw(8) << cakes[j].getPrice() << char(179) << setw(title[4]) << cakes[j].getDiscount() << char(179) << setw(title[5]) << (to_string(cakes[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;

        case 11:
            if(hasFood(cuisineTitle[_cuisine]) == true){
                for(int j = 0; j < beverages.size(); j++){
                    cout << "\n\t\t\t\t" << char(179) << setw(title[0]) << beverages[j].getItemCode() << char(179) << setw(title[1]) << beverages[j].getTitle() << char(179) << setw(title[2]) << beverages[j].getDescription() << char(179) << setw(8) << beverages[j].getPrice() << " - " << setw(8) << beverages[j].getPrice() << char(179) << setw(title[4]) << beverages[j].getDiscount() << char(179) << setw(title[5]) << (to_string(beverages[j].getPrepTime()) + " Minutes ") << char(179);
                }
            } else{
                cout << "\n\t\t\t\t" << char(179) << " No Item Available in Cuisine: " << cuisineTitle[_cuisine] << char(179);
            }
            break;
        
        default:
            break;
        }
        cout << "\n\t\t\t\t" << char(212);
        for(int i = 0; i < 6; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
    }

    /*void modifyItem(string _ItemCode){

    }*/

    PIZZA * getPizza(int _index){
        if(_index < pizzas.size()){
            return &pizzas[_index];
        }
    }
    BURGER * getBurger(int _index){
        if(_index < burgers.size()){
            return &burgers[_index];
        }
    }

    SANDWICHE * getSandwich(int _index){
        if(_index < sandwiches.size()){
            return &sandwiches[_index];
        }
    }

    FASTFOOD * getFastFood(int _index){
        if(_index < fastfoods.size()){
            return &fastfoods[_index];
        }
    }

    BARBQ * getBarbq(int _index){
        if(_index < barbqs.size()){
            return &barbqs[_index];
        }
    }

    PAKISTANI * getPakistani(int _index){
        if(_index < pakistanis.size()){
            return &pakistanis[_index];
        }
    }

    CHINESE * getChinese(int _index){
        if(_index < chineses.size()){
            return &chineses[_index];
        }
    }

    INTERNATIONAL * getInternational(int _index){
        if(_index < internationals.size()){
            return &internationals[_index];
        }
    }

    SEAFOOD * getSeafood(int _index){
        if(_index < seafoods.size()){
            return &seafoods[_index];
        }
    }

    DESSERT * getDessert(int _index){
        if(_index < desserts.size()){
            return &desserts[_index];
        }
    }

    CAKE * getCake(int _index){
        if(_index < cakes.size()){
            return &cakes[_index];
        }
    }

    BEVERAGE * getBeverage(int _index){
        if(_index < beverages.size()){
            return &beverages[_index];
        }
    }

    int getPizzaItemSize(int _index){
        return pizzas[_index].getSizeLength();
    }

    void showDetails(){
        cout << "\tTitle:\t\t\t" << title << "\n\n\tDescription:\t\t" << description.substr(0, 100) << "\n\n\tManager ID:\t\t" << managerID << string(45 - managerID.length(), ' ') << "Code:\t\t" << restaurantCode << "\n\n\tContact Number:\t\t" << contactNumber << string(45 - contactNumber.length(), ' ') << "Address:\t\t" << address << "\n\n\tArea:\t\t\t" << getArea() << string(45 - getArea().length(), ' ') << "City:\t\t" << getCity() << "\n\n\tActive:\t\t\t" << setw(5) << isRestActive << string(40, ' ') << "Open:\t\t" << isRestOpen << "\n\n\tFree Delivery:\t\t" << setw(5) << freeDelivery << string(40, ' ') << "Minimum Order:\t" << minimumOrder << "\n\n\tDelivery Charges:\t" << deliveryCharges << string(49 - to_string(deliveryCharges).length(), ' ') << "Discount:\t\t" << (restDiscount * 100) << "%\n\n\tTotal Income:\t\t" << restRevenue << string(49 - to_string(restRevenue).length(), ' ') << "Tax:\t\t" << restTax << "\n\n\tOrders Pending:\t\t" << ordersPending << string(45 - to_string(ordersPending).length(), ' ') << "Orders Completed:\t" << ordersCompleted << "\n\n\tOrders Cancelled:\t" << ordersCancelled << string(45 - to_string(ordersCancelled).length(), ' ') << "Timings:\t\t" << openTime << " - " << closeTime;
        cout << "\n\n\n\tWORKING DAYS\n\t" << char(218);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179);
        for(int i = 0; i < days.size(); i++){
            cout << days[i] << char(179);
        }
        cout << "\n\t" << char(195);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(197);
        }
        cout << "\b" << char(180) << "\n\t" << char(179);
        for(int j = 0; j < days.size(); j++){
            if(daysOpen[j] == true){cout << " YES" << string((days[j].length() - 4), ' ') << char(179);} else{
            cout << " NO" << string((days[j].length() - 3), ' ') << char(179);}
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(193);
        }
        cout << "\b" << char(217);
        
        cout << "\n\n\n\tCUISINES AVAILABLE\n\t" << char(218);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << cuisineTitle[i] << char(179);
        }
        cout << "\n\t" << char(195);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(197);
        }
        cout << "\b" << char(180) << "\n\t" << char(179);

        for(int j = 0; j < cuisineTitle.size(); j++){
            if(hasFood(cuisineTitle[j]) == true){cout << " YES" << string((cuisineTitle[j].length() - 4), ' ') << char(179);} else{
            cout << " NO" << string((cuisineTitle[j].length() - 3), ' ') << char(179);}
        }
        
        cout << "\n\t" << char(212);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(193);
        }
        cout << "\b" << char(217) << "\n\t";
    }

    void displayDays(){
        cout << "\n\t" << char(218) << string(6, char(196));
        for(int i=0;i< days.size();i++){
            cout << char(194) << string(days[i].length(),char(196));
        }
        cout << char(191) << "\n\t" << char(179) << " CODE " << char(179);
        for(int i = 0; i < days.size();i++){
            cout << setw(days[i].length()-2) << i << "  " << char(179);
        }
        cout << "\n\t" << char(195) << string(6, char(196));
        for(int i=0;i< days.size();i++){
            cout << char(197) << string(days[i].length(),char(196));
        }
        cout << char(180) << "\n\t" << char(179) << " DAYS ";
        for(int i=0;i< days.size();i++){
            cout << char(179) << days[i];
        }
        cout << char(179) << "\n\t" << char(195) << string(6, char(196));
        for(int i=0;i< days.size();i++){
            cout << char(197) << string(days[i].length(),char(196));
        }
        cout << char(180) << "\n\t" << char(179) << "STATUS";
        for(int i=0;i< days.size();i++){
            cout << char(179);
            if(daysOpen[i]==true){
                cout << setw(days[i].length()) << "OPEN";
            } else{
                cout << setw(days[i].length()) << "CLOSE";
            }
        }
        cout << char(179) << "\n\t" << char(192) << string(6,char(196));
        for(int i=0;i< days.size();i++){
            cout << char(193) << string(days[i].length(),char(196));
        }
        cout << char(217);
    }

    int confirmOrder(ORDER &_order){
        cout << _order.getIsPaid() << endl;
        vector<ORDERITEM> orderItems = _order.getOrderItems();
        for(int i = 0; i < orderItems.size(); i++){
            cout << orderItems[i].getQuantity() << ",";
            int foodIndex = (stoi(orderItems[i].getCode().substr(5, 3)) - 1);
            switch(orderItems[i].getCuisine()){
            case 0:
                if(orderItems[i].getQuantity() > pizzas[foodIndex].getLimit() || orderItems[i].getQuantity() > pizzas[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 1:
                if(orderItems[i].getQuantity() > burgers[foodIndex].getLimit() || orderItems[i].getQuantity() > burgers[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 2:
                if(orderItems[i].getQuantity() > sandwiches[foodIndex].getLimit() || orderItems[i].getQuantity() > sandwiches[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 3:
                if(orderItems[i].getQuantity() > fastfoods[foodIndex].getLimit() || orderItems[i].getQuantity() > fastfoods[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 4:
                if(orderItems[i].getQuantity() > barbqs[foodIndex].getLimit() || orderItems[i].getQuantity() > barbqs[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 5:
                if(orderItems[i].getQuantity() > pakistanis[foodIndex].getLimit() || orderItems[i].getQuantity() > pakistanis[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 6:
                if(orderItems[i].getQuantity() > chineses[foodIndex].getLimit() || orderItems[i].getQuantity() > chineses[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 7:
                if(orderItems[i].getQuantity() > internationals[foodIndex].getLimit() || orderItems[i].getQuantity() > internationals[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 8:
                if(orderItems[i].getQuantity() > seafoods[foodIndex].getLimit() || orderItems[i].getQuantity() > seafoods[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 9:
                if(orderItems[i].getQuantity() > desserts[foodIndex].getLimit() || orderItems[i].getQuantity() > desserts[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 10:
                if(orderItems[i].getQuantity() > cakes[foodIndex].getLimit() || orderItems[i].getQuantity() > cakes[foodIndex].getStock()){
                    return 0;
                }
                break;

            case 11:
                if(orderItems[i].getQuantity() > beverages[foodIndex].getLimit() || orderItems[i].getQuantity() > beverages[foodIndex].getStock()){
                    return 0;
                }
                break;
            
            default:
                break;
            }
        }
        cout << "Big Pass" << endl;
        _order.setIsApproved(true);
        restRevenue += _order.getBill();
        restOrders.push_back(_order);
        return (_order.getBill() * (-1));
    }

    int getLimit(int _cuisine, int _index){
        switch (_cuisine){
        case 0:
            return pizzas[_index].getLimit();
            break;
        
        case 1:
            return burgers[_index].getLimit();
            break;
        
        case 2:
            return sandwiches[_index].getLimit();
            break;

        case 3:
            return fastfoods[_index].getLimit();
            break;

        case 4:
            return barbqs[_index].getLimit();
            break;

        case 5:
            return pakistanis[_index].getLimit();
            break;

        case 6:
            return chineses[_index].getLimit();
            break;

        case 7:
            return internationals[_index].getLimit();
            break;

        case 8:
            return seafoods[_index].getLimit();
            break;

        case 9:
            return desserts[_index].getLimit();
            break;

        case 10:
            return cakes[_index].getLimit();
            break;

        case 11:
            return beverages[_index].getLimit();
            break;
        
        default:
            break;
        }
    }

    int getStock(int _cuisine, int _index){
        switch (_cuisine){
        case 0:
            return pizzas[_index].getStock();
            break;
        
        case 1:
            return burgers[_index].getStock();
            break;
        
        case 2:
            return sandwiches[_index].getStock();
            break;

        case 3:
            return fastfoods[_index].getStock();
            break;

        case 4:
            return barbqs[_index].getStock();
            break;

        case 5:
            return pakistanis[_index].getStock();
            break;

        case 6:
            return chineses[_index].getStock();
            break;

        case 7:
            return internationals[_index].getStock();
            break;

        case 8:
            return seafoods[_index].getStock();
            break;

        case 9:
            return desserts[_index].getStock();
            break;

        case 10:
            return cakes[_index].getStock();
            break;

        case 11:
            return beverages[_index].getStock();
            break;
        
        default:
            break;
        }
    }
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
    vector<ORDER> custOrders;
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
        walletAmount = 10000;
        //orderCount = 0;
        isActive = true;
    }

    CUSTOMER(){}

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
    //int getArea(){return custArea;}
    //int getCity(){return custCity;}
    string getCity(){return cities[custCity][0];}
    string getArea(){return cities[custCity][custArea];}
    double getWalletAmount(){return walletAmount;}
    int getOrderCount(){return orderCount;}
    string getVoucherUsed(int _index){return pastVouchers[_index];}
    string getVoucher(int _index){return vouchers[_index];}
    vector<string> getVoucherUsed(){return pastVouchers;}
    vector<string> getVoucher(){return vouchers;}
    bool getIsActive(){return isActive;}
    int getOrderSize(){return custOrders.size();}

    void addVoucher(string _voucher){
        vouchers.push_back(_voucher);
    }

    string chargeWallet(int _value){
        if(_value > 0){
            walletAmount += _value;
            return ("Wallet ReCharge Successful! Amount is " + to_string(_value));
        } else if(_value < 0){
            return "Wallet ReCharge Unsuccessful! Voucher Expired!";
        } else{
            return "Wallet ReCharge Unsuccessful! Voucher Invalid!";
        }
    }

    string payOrder(int _value){
        walletAmount += _value;
        if(_value < 0){
            return "Order Completed Successfully!";
        } else if(_value == 0){
            return "Insufficient Item ";
        } else{
            return "Something went wrong!";
        }
    }

    string createOrderNumber(){
        if(custOrders.size() < 10){
            return ("00" + to_string(custOrders.size()));
        }else if(custOrders.size() < 100){
            return ("0" + to_string(custOrders.size()));
        }else{
            return to_string(custOrders.size());
        }
    }

    void addOrder(ORDER _order, string _restCode){
        _order.setOrderNumber(_restCode + customerCode + createOrderNumber());
        custOrders.push_back(_order);
    }

    ORDER * getNewOrder(){
        return &custOrders[(custOrders.size() - 1)];
    }
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

    string getRestPassword(int _index){return restaurants[_index].getManagerPassword();}
    
    void setRestPassword(int _index, string _password){
        restaurants[_index].setManagerPassword(_password);
    }

    bool getRestStatus(int i){return restaurants[i].getIsRestOpen();}

    void changeRestStatus(int i){
        if(restaurants[i].getIsRestOpen() == true){
            restaurants[i].setIsRestOpen(false);
        } else{
            restaurants[i].setIsRestOpen(true);
        }
    }

    RESTAURANT * getRestaurant(int _index){return &restaurants[_index];}

    CUSTOMER * getCustomer(int _index){return &customers[_index];}

    int checkManager(string _managerID){
        if(managerLink[_managerID].length() == 0){
            return -1;
        }else{
            if(managerLink[_managerID] == "000"){
                setMessage("Following Manager account is suspended!");
            }else{
                setMessage("Manager ID found!");
            }
            return stoi(managerLink[_managerID]);
        }
    }

    int checkCustomer(string _email, string _contactNumber){
        if((custEmailLink[_email].length() == 0) && (custContactLink[_contactNumber].length() == 0)){
            return -1;
        } else if(custEmailLink[_email].length() == 0){
            setMessage("Contact Number " + _contactNumber + " is linked with another Email Address!");
        } else if(custContactLink[_contactNumber].length() == 0){
            setMessage("Email Address " + _email + " is linked with another Account!");
        } else{
            if(custEmailLink[_email] == "0000"){
                setMessage("Following Customer account is suspended!");
            }else{
                setMessage("Following Customer already own an Account!");
            }
            return stoi(custEmailLink[_email]);
        }
    }

    int checkCustomer(string _emailContact){
        if(custEmailLink[_emailContact].length() > 0){
            if(custEmailLink[_emailContact] != "0000"){
                return stoi(custEmailLink[_emailContact]);
            } else{
                return 0;
            }
        } else{
            if(custContactLink[_emailContact].length() > 0){
                if(custEmailLink[custContactLink[_emailContact]].length() > 0){
                    if(custEmailLink[custContactLink[_emailContact]] != "0000"){
                        return stoi(custEmailLink[custContactLink[_emailContact]]);
                    } else{
                        return 0;
                    }
                } else{
                    return -1;
                }
            }
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

    string getCustPassword(int _index){return customers[_index].getCustPassword();}

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

    string removeRestaurant(string _managerID){
        if(managerLink[_managerID] == "000"){
            return "Restaurant is already removed!";
        }else if(managerLink[_managerID].length() == 0){
            return "Restaurant does not exist!";
        }else{
            restaurants[stoi(managerLink[_managerID]) - 1].setIsRestActive(false);
            restaurants[stoi(managerLink[_managerID]) - 1].setIsRestOpen(false);
            managerLink[_managerID] = "000";
            return "Restaurant has been removed!";
        }
    }

    string reOpenRestaurant(string _managerID){
        if(managerLink[_managerID].length() == 0){
            return "Restaurant does not exist!";
        }else if(managerLink[_managerID] == "000"){
            int restIndex = searchRestByMangerID(_managerID);
            if(restIndex == -1){
                return "Restaurant does not exist!";
            }else{
                managerLink[_managerID] = restaurants[restIndex].getCode();
                restaurants[restIndex].setIsRestActive(true);
                return "Restaurant has been Re-Opened!";
            }
        } else{
            return "Restaurant is already Active!";
        }
    }

    void showRestaurants(){
        gotoxy(70, 7);
        int title[16] = {5, 16, 25, 10, 10, 12, 12, 6, 1, 1, 1, 1, 1, 1, 1, 8};
        cout << "RESTAURANTS (ALL)\n\t" << char(218);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "MANAGER ID " << char(179) << setw(title[2]) << "TITLE " << char(179) << setw(title[3]) << "CITY " << char(179) << setw(title[4]) << "AREA " << char(179) << setw(title[5]) << "INCOME " << char(179) << setw(title[6]) << "TAX " << char(179) << setw(title[7]) << "ACTIVE" << char(179) << setw(title[8]) << "S" << char(179) << setw(title[9]) << "M" << char(179) << setw(title[10]) << "T" << char(179) << setw(title[11]) << "W" << char(179) << setw(title[12]) << "T" << char(179) << setw(title[13]) << "F" << char(179) << setw(title[14]) << "S" << char(179) << setw(title[15]) << "TIMINGS" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        for(int j = 0; j < restaurants.size(); j++){
            cout << "\n\t" << char(179) << setw(title[0]) << restaurants[j].getCode() << char(179) << setw(title[1]) << restaurants[j].getManagerID() << char(179) << setw(title[2]) << restaurants[j].getTitle() << char(179) << setw(title[3]) << restaurants[j].getCity() << char(179) << setw(title[4]) << restaurants[j].getArea() << char(179) << setw(title[5]) << restaurants[j].getRestRevenue() << char(179) << setw(title[6]) << restaurants[j].getRestTax() << char(179) << setw(title[7]) << restaurants[j].getIsRestActive() << char(179);
            for(int k = 0; k < 7; k++){
                if(restaurants[j].getDaysOpen(k) == true){
                    cout << char(254) << char(179);
                } else{
                    cout << " " << char(179);
                }
            }
            cout << setw(title[15]) << restaurants[j].getTime() << char(179);
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
    }

    void showRestaurants(string _title){
        int recordCount = 0;
        gotoxy(70, 7);
        int title[16] = {5, 16, 25, 10, 10, 12, 12, 6, 1, 1, 1, 1, 1, 1, 1, 8};
        cout << "RESTAURANTS (ALL)\n\t" << char(218);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "MANAGER ID " << char(179) << setw(title[2]) << "TITLE " << char(179) << setw(title[3]) << "CITY " << char(179) << setw(title[4]) << "AREA " << char(179) << setw(title[5]) << "INCOME " << char(179) << setw(title[6]) << "TAX " << char(179) << setw(title[7]) << "ACTIVE" << char(179) << setw(title[8]) << "S" << char(179) << setw(title[9]) << "M" << char(179) << setw(title[10]) << "T" << char(179) << setw(title[11]) << "W" << char(179) << setw(title[12]) << "T" << char(179) << setw(title[13]) << "F" << char(179) << setw(title[14]) << "S" << char(179) << setw(title[15]) << "TIMINGS" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);

        for(int j = 0; j < restaurants.size(); j++){
            if(restaurants[j].getTitle().length() >= _title.length()){
                for(int i = 0; i <= (restaurants[j].getTitle().length() - _title.length()); i++){
                    if(restaurants[j].getTitle().substr(i, _title.length()) == _title){
                        cout << "\n\t" << char(179) << setw(title[0]) << restaurants[j].getCode() << char(179) << setw(title[1]) << restaurants[j].getManagerID() << char(179) << setw(title[2]) << restaurants[j].getTitle() << char(179) << setw(title[3]) << restaurants[j].getCity() << char(179) << setw(title[4]) << restaurants[j].getArea() << char(179) << setw(title[5]) << restaurants[j].getRestRevenue() << char(179) << setw(title[6]) << restaurants[j].getRestTax() << char(179) << setw(title[7]) << restaurants[j].getIsRestActive() << char(179);
                        for(int k = 0; k < 7; k++){
                            if(restaurants[j].getDaysOpen(k) == true){
                                cout << char(254) << char(179);
                            } else{
                                cout << " " << char(179);
                            }
                        }
                        cout << setw(title[15]) << restaurants[j].getTime() << char(179);
                        recordCount++;
                    }
                }
            }
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
        if(recordCount == 0){
            setMessage("Restaurants with Title \"" + _title + "\" Not Found!");
        } else{
            setMessage(to_string(recordCount) + " Restaurants Found with Title \"" + _title + "\"");
        }
    }

    void showRestaurants(int i){
        gotoxy(64, 7);
        cout << "RESTAURANT DETAILS\n\n" << "\tTitle:\t\t\t" << restaurants[i].getTitle() << "\n\n\tDescription:\t\t" << restaurants[i].getDescription().substr(0, 100) << "\n\n\tManager ID:\t\t" << restaurants[i].getManagerID() << setw(70-getX()) << "\t" << "Code:\t\t\t" << restaurants[i].getCode()  << "\n\n\tContact Number:\t\t" << restaurants[i].getContactNumber() << setw(70-getX()) << "\t" << "Address:\t\t" << restaurants[i].getAddress() << "\n\n\tArea:\t\t\t" << restaurants[i].getArea() << setw(70-getX()) << "\t" << "City:\t\t\t" << restaurants[i].getCity() << "\n\n\tActive:\t\t\t" << restaurants[i].getIsRestActive() << setw(70-getX()) << "\t" << "Open:\t\t\t" << restaurants[i].getIsRestOpen() << "\n\n\tFree Delivery:\t\t" << restaurants[i].getFreeDelivery() << setw(70-getX()) << "\t" << "Minimum Order:\t\t" << restaurants[i].getMinimumOrder() << "\n\n\tDelivery Charges:\t" << restaurants[i].getDeliveryCharges() << setw(70-getX()) << "\t" << "Discount:\t\t" << restaurants[i].getRestDiscount() << "%\n\n\tTotal Income:\t\t" << restaurants[i].getRestRevenue() << setw(70-getX()) << "\t" << "Tax:\t\t\t" << restaurants[i].getRestTax() << "\n\n\tOrders Pending:\t\t" << restaurants[i].getOrdersPending() << setw(70-getX()) << "\t" << "Orders Completed:\t" << restaurants[i].getOrdersCompleted() << "\n\n\tOrders Cancelled:\t" << restaurants[i].getOrdersCancelled() << setw(70-getX()) << "\t" << "Timings:\t\t" << restaurants[i].getOpenTime() << " - " << restaurants[i].getCloseTime();
        gotoxy(66, (getY() + 2));
        cout << "WORKING DAYS\n\t\t\t\t\t" << char(218);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t\t\t\t\t" << char(179);
        for(int i = 0; i < days.size(); i++){
            cout << days[i] << char(179);
        }
        cout << "\n\t\t\t\t\t" << char(195);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(197);
        }
        cout << "\b" << char(180) << "\n\t\t\t\t\t" << char(179);
        for(int j = 0; j < days.size(); j++){
            if(restaurants[i].getDaysOpen(j) == true){cout << " YES" << string((days[j].length() - 4), ' ') << char(179);} else{
            cout << " NO" << string((days[j].length() - 3), ' ') << char(179);}
        }
        cout << "\n\t\t\t\t\t" << char(212);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(193);
        }
        cout << "\b" << char(217);
        
        gotoxy(63, (getY() + 2));
        cout << "CUISINES AVAILABLE\n\t" << char(218);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << cuisineTitle[i] << char(179);
        }
        cout << "\n\t" << char(195);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(197);
        }
        cout << "\b" << char(180) << "\n\t" << char(179);

        for(int j = 0; j < cuisineTitle.size(); j++){
            if(restaurants[i].hasFood(cuisineTitle[j]) == true){cout << " YES" << string((cuisineTitle[j].length() - 4), ' ') << char(179);} else{
            cout << " NO" << string((cuisineTitle[j].length() - 3), ' ') << char(179);}
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << string(cuisineTitle[i].length(), char(196)) << char(193);
        }
        cout << "\b" << char(217);
    }

    void showRestWithCuisine(string _cuisine){
        int recordCount = 0;
        gotoxy(70, 7);
        int title[16] = {5, 16, 25, 10, 10, 12, 12, 6, 1, 1, 1, 1, 1, 1, 1, 8};
        cout << "RESTAURANTS {" << _cuisine << "}\n\t" << char(218);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "MANAGER ID " << char(179) << setw(title[2]) << "TITLE " << char(179) << setw(title[3]) << "CITY " << char(179) << setw(title[4]) << "AREA " << char(179) << setw(title[5]) << "INCOME " << char(179) << setw(title[6]) << "TAX " << char(179) << setw(title[7]) << "ACTIVE" << char(179) << setw(title[8]) << "S" << char(179) << setw(title[9]) << "M" << char(179) << setw(title[10]) << "T" << char(179) << setw(title[11]) << "W" << char(179) << setw(title[12]) << "T" << char(179) << setw(title[13]) << "F" << char(179) << setw(title[14]) << "S" << char(179) << setw(title[15]) << "TIMINGS" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        for(int j = 0; j < restaurants.size(); j++){
            if(restaurants[j].hasFood(_cuisine) == true){
                cout << "\n\t" << char(179) << setw(title[0]) << restaurants[j].getCode() << char(179) << setw(title[1]) << restaurants[j].getManagerID() << char(179) << setw(title[2]) << restaurants[j].getTitle() << char(179) << setw(title[3]) << restaurants[j].getCity() << char(179) << setw(title[4]) << restaurants[j].getArea() << char(179) << setw(title[5]) << restaurants[j].getRestRevenue() << char(179) << setw(title[6]) << restaurants[j].getRestTax() << char(179) << setw(title[7]) << restaurants[j].getIsRestActive() << char(179);
                for(int k = 0; k < 7; k++){
                    if(restaurants[j].getDaysOpen(k) == true){
                        cout << char(254) << char(179);
                    } else{
                        cout << " " << char(179);
                    }
                }
                cout << setw(title[15]) << restaurants[j].getTime() << char(179);
            }
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
        if(recordCount == 0){
            setMessage("Restaurants with Cuisine \"" + _cuisine + "\" Not Found!");
        } else{
            setMessage(to_string(recordCount) + " Restaurants Found with Cuisine \"" + _cuisine + "\"");
        }
    }

    void showRestOnLocation(int _city, int _area){
        int recordCount = 0;
        gotoxy(70, 7);
        int title[16] = {5, 16, 25, 10, 10, 12, 12, 6, 1, 1, 1, 1, 1, 1, 1, 8};
        cout << "RESTAURANTS @ " <<  cities[_city][0] << ": " << cities[_city][_area] << "\n\t" << char(218);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "MANAGER ID " << char(179) << setw(title[2]) << "TITLE " << char(179) << setw(title[3]) << "CITY " << char(179) << setw(title[4]) << "AREA " << char(179) << setw(title[5]) << "INCOME " << char(179) << setw(title[6]) << "TAX " << char(179) << setw(title[7]) << "ACTIVE" << char(179) << setw(title[8]) << "S" << char(179) << setw(title[9]) << "M" << char(179) << setw(title[10]) << "T" << char(179) << setw(title[11]) << "W" << char(179) << setw(title[12]) << "T" << char(179) << setw(title[13]) << "F" << char(179) << setw(title[14]) << "S" << char(179) << setw(title[15]) << "TIMINGS" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        for(int j = 0; j < restaurants.size(); j++){
            if((restaurants[j].getCity() == cities[_city][0]) && (restaurants[j].getArea() == cities[_city][_area])){
                cout << "\n\t" << char(179) << setw(title[0]) << restaurants[j].getCode() << char(179) << setw(title[1]) << restaurants[j].getManagerID() << char(179) << setw(title[2]) << restaurants[j].getTitle() << char(179) << setw(title[3]) << restaurants[j].getCity() << char(179) << setw(title[4]) << restaurants[j].getArea() << char(179) << setw(title[5]) << restaurants[j].getRestRevenue() << char(179) << setw(title[6]) << restaurants[j].getRestTax() << char(179) << setw(title[7]) << restaurants[j].getIsRestActive() << char(179);
                for(int k = 0; k < 7; k++){
                    if(restaurants[j].getDaysOpen(k) == true){
                        cout << char(254) << char(179);
                    } else{
                        cout << " " << char(179);
                    }
                }
                cout << setw(title[15]) << restaurants[j].getTime() << char(179);
            }
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 16; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
        if(recordCount == 0){
            setMessage("Restaurants @ " + cities[_city][0] + ": " + cities[_city][_area] + " Not Found!");
        } else{
            setMessage(to_string(recordCount) + " Restaurants Found @ " + cities[_city][0] + ": " + cities[_city][_area]);
        }
    }

    void findRestWithManager(string _managerID){
        int i = -1;
        if(managerLink[_managerID].length() == 0){
            setMessage("No Restaurant found with ManagerID: " + _managerID);
        } else if(managerLink[_managerID] == "000"){
            setMessage("Restaurant is Permanently Closed");
            i = searchRestByMangerID(_managerID);
        } else{
            i = stoi(managerLink[_managerID]) - 1;
            setMessage("Restaurant Found!");
        }
        if(i >= 0){
            showRestaurants(i);
        }
    }

    string addVoucher(string _voucher, double _value){
        if(_voucher.length() < 10){
            _voucher = string((10-_voucher.length()), '0') + _voucher;
        } else if(_voucher.length() > 10){
            _voucher = _voucher.substr(0, 10);
        }
        if(voucherValueLink[_voucher] == -1){
            return "Voucher Exists but Expired!";
        } else if(voucherValueLink[_voucher] > 0){
            return "Voucher already exists!";
        } else{
            vouchers.push_back(_voucher);
            voucherValueLink[_voucher] = _value;
            voucherIndexLink[_voucher] = (vouchers.size() - 1);
            return "Voucher Added!";
        }
    }

    /*string removeVoucher(string _voucher){
        voucherValueLink[_voucher] = 0;
    }*/

    string blockVoucher(string _voucher){
        if(voucherValueLink[_voucher] > 0){
            voucherValueLink[_voucher] = -1;
            return "Voucher Expired!";
        } else if(voucherValueLink[_voucher] == -1){
            return "Voucher already Expired!";
        } else{
            return "Voucher Does not Exist";
        }
    }

    string sendVoucher(string _custCode, string _voucher){
        int custIndex = (stoi(_custCode) - 1);
        if(custIndex < customers.size()){
            if(voucherValueLink[_voucher] > 0){
                customers[custIndex].addVoucher(_voucher);
                return ("Voucher sent to " + customers[custIndex].getCustomerCode());
            } else{
                return "Invalid Voucher Code!";
            }
        } else{
            return "Invalid Customer Code!";
        }
    }

    int cashVoucher(string _voucher){
        int amount = voucherValueLink[_voucher];
        voucherValueLink[_voucher] = -1;
        return amount;
    }

    string showVouchers(){
        cout << "\t" << char(218) << string(10, char(196)) << char(194) << string(14, char(196)) << char(191) << "\n\t" << char(179) << setw(10) << "CODE" << char(179) << setw(14) << "STATUS/VALUE " << char(179);
        for(int i = 0; i < vouchers.size(); i++){
            cout << "\n\t" << char(195) << string(10, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(10) << vouchers[i] << char(179);
            if(voucherValueLink[vouchers[i]] == -1){
                cout << setw(14) << "Expired ";
            } else if(voucherValueLink[vouchers[i]] == 0){
                cout << setw(14) << "Blocked ";
            } else{
                cout << setw(13) << voucherValueLink[vouchers[i]] << " ";
            }
            cout << char(179);
        }
        cout << "\n\t" << char(192) << string(10, char(196)) << char(193) << string(14, char(196)) << char(217);
        if(vouchers.size() > 0){
            return (to_string(vouchers.size()) + "Records Found!");
        } else{
            return "No Record Found of any Voucher";
        }
    }

    string showVouchers(string _code){
        int count = 0;
        cout << "\t" << char(218) << string(10, char(196)) << char(194) << string(14, char(196)) << char(191) << "\n\t" << char(179) << setw(10) << "CODE" << char(179) << setw(14) << "STATUS/VALUE " << char(179);
        for(int i = 0; i < vouchers.size(); i++){
            if(vouchers[i] == _code){
                cout << "\n\t" << char(195) << string(10, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(10) << vouchers[i] << char(179);
                if(voucherValueLink[vouchers[i]] == -1){
                    cout << setw(14) << "Expired ";
                } else if(voucherValueLink[vouchers[i]] == 0){
                    cout << setw(14) << "Blocked ";
                } else{
                    cout << setw(13) << voucherValueLink[vouchers[i]] << " ";
                }
                cout << char(179);
                count++;
            }
        }
        cout << "\n\t" << char(192) << string(10, char(196)) << char(193) << string(14, char(196)) << char(217);
        if(count > 0){
            return (to_string(count) + "Records Found!");
        } else{
            return ("No Record Found of any Voucher with Code: " + _code);
        }
    }

    void showVouchersCust(vector<string> _vouchers){
        cout << "\t" << char(218) << string(10, char(196)) << char(194) << string(14, char(196)) << char(191) << "\n\t" << char(179) << setw(10) << "CODE" << char(179) << setw(14) << "STATUS/VALUE " << char(179);
        for(int i = 0; i < _vouchers.size(); i++){
            cout << "\n\t" << char(195) << string(10, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(10) << _vouchers[i] << char(179);
            if(voucherValueLink[_vouchers[i]] == -1){
                cout << setw(14) << "Expired ";
            } else if(voucherValueLink[_vouchers[i]] == 0){
                cout << setw(14) << "Blocked ";
            } else{
                cout << setw(13) << voucherValueLink[_vouchers[i]] << " ";
            }
            cout << char(179);
        }
    }

    string showVouchers(int _choice){
        int count = 0;
        cout << "\t" << char(218) << string(10, char(196)) << char(194) << string(14, char(196)) << char(191) << "\n\t" << char(179) << setw(10) << "CODE" << char(179) << setw(14) << "STATUS/VALUE " << char(179);
        for(int i = 0; i < vouchers.size(); i++){
            if(_choice == 1){
                if(voucherValueLink[vouchers[i]] > 0){
                    cout << "\n\t" << char(195) << string(10, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(10) << vouchers[i] << char(179);
                    if(voucherValueLink[vouchers[i]] == -1){
                        cout << setw(14) << "Expired ";
                    } else if(voucherValueLink[vouchers[i]] == 0){
                        cout << setw(14) << "Blocked ";
                    } else{
                        cout << setw(13) << voucherValueLink[vouchers[i]] << " ";
                    }
                    cout << char(179);
                    count++;
                }
            } else{
                if(voucherValueLink[vouchers[i]] == _choice){
                    cout << "\n\t" << char(195) << string(10, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(10) << vouchers[i] << char(179);
                    if(voucherValueLink[vouchers[i]] == -1){
                        cout << setw(14) << "Expired ";
                    } else if(voucherValueLink[vouchers[i]] == 0){
                        cout << setw(14) << "Blocked ";
                    } else{
                        cout << setw(13) << voucherValueLink[vouchers[i]] << " ";
                    }
                    cout << char(179);
                    count++;
                }
            }
        }
        cout << "\n\t" << char(192) << string(10, char(196)) << char(193) << string(14, char(196)) << char(217);
        if(count > 0){
            return (to_string(count) + "Records Found!");
        } else{
            return "No Record Found!";
        }
    }

    void addCustomer(CUSTOMER _customer){
        customers.push_back(_customer);
        customers[customers.size()-1].setCustomerCode(createCustCode(customers.size()));
        custEmailLink[customers[customers.size()-1].getEmailAddress()] = customers[customers.size()-1].getCustomerCode();
        custContactLink[customers[customers.size()-1].getContactNumber()] = customers[customers.size()-1].getEmailAddress();
    }

    string removeCustomer(string _emailAddress){
        if(custEmailLink[_emailAddress] == "0000"){
            return "Customer is already removed!";
        }else if(custEmailLink[_emailAddress].length() == 0){
            return "Customer does not exist";
        }else{
            customers[stoi(custEmailLink[_emailAddress]) - 1].setIsActive(false);
            custEmailLink[_emailAddress] = "0000";
            return "Customer has been removed";
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

    string activateCustomer(string _emailAddress){
        if(custEmailLink[_emailAddress].length() == 0){
            return "Customer does not exist";
        }else if(custEmailLink[_emailAddress] == "0000"){
            int restIndex = searchCustByEmail(_emailAddress);
            if(restIndex == -1){
                return "Customer does not exist!";
            }else{
                custEmailLink[_emailAddress] = customers[restIndex].getCustomerCode();
                customers[restIndex].setIsActive(true);
                return "Customer has been Activated!";
            }
        } else{
            return "Customer is already Active!";
        }
    }

    string changeCustEmail(int _index, string _email){
        if(custEmailLink[_email].length() == 0){
            swap(custEmailLink[customers[_index].getEmailAddress()], custEmailLink[_email]);
            custContactLink[customers[_index].getContactNumber()] = _email;
            customers[_index].setEmailAddress(_email);
            return "Email Change Successful!";
        } else{
            return "Email Address already in use on another Account!";
        }
        
    }

    string changeCustContact(int _index, string _contact){
        if(custContactLink[_contact].length() == 0){
            swap(custContactLink[customers[_index].getContactNumber()], custContactLink[_contact]);
            custEmailLink[customers[_index].getEmailAddress()] = _contact;
            customers[_index].setCustContactNumber(_contact);
            return "Contact Number Change Successful!";
        } else{
            return "Contact Number already in use on another Email!";
        }
        
    }

    void showCustomer(){
        gotoxy(70, 7);
        int title[10] = {6, 14, 14, 25, 15, 10, 11, 9, 6, 7};
        cout << "CUSTOMERS (ALL)\n\t" << char(218);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "FIRST NAME " << char(179) << setw(title[2]) << "LAST NAME " << char(179) << setw(title[3]) << "EMAIL ADDRESS " << char(179) << setw(title[4]) << "CONTACT NUMBER" << char(179) << setw(title[5]) << "AREA " << char(179) << setw(title[6]) << "CITY " << char(179) << setw(title[7]) << "CASH " << char(179) << setw(title[8]) << "ORDERS" << char(179) << setw(title[9]) << "ACTIVE" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        for(int j = 0; j < customers.size(); j++){
            cout << "\n\t" << char(179) << setw(title[0]) << customers[j].getCustomerCode() << char(179) << setw(title[1]) << customers[j].getFirstName() << char(179) << setw(title[2]) << customers[j].getLastName() << char(179) << setw(title[3]) << customers[j].getEmailAddress() << char(179) << setw(title[4]) << customers[j].getContactNumber() << char(179) << setw(title[5]) << customers[j].getArea() << char(179) << setw(title[6]) << customers[j].getCity() << char(179) << setw(title[7]) << customers[j].getWalletAmount() << char(179) << setw(title[8]) << customers[j].getOrderCount() << char(179) << setw(title[9]) << customers[j].getIsActive() << char(179);
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
    }

    void showCustomer(int i){

    }

    void showCustOnLocation(int _city, int _area){
        int title[10] = {6, 14, 14, 25, 15, 10, 11, 9, 6, 7};
        gotoxy(55, 7);
        cout << "CUSTOMERS @" << cities[_city][0] << ": " << cities[_city][_area] << "\n\t" << char(218);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t" << char(179) << setw(title[0]) << "CODE " << char(179) << setw(title[1]) << "FIRST NAME " << char(179) << setw(title[2]) << "LAST NAME " << char(179) << setw(title[3]) << "EMAIL ADDRESS " << char(179) << setw(title[4]) << "CONTACT NUMBER" << char(179) << setw(title[5]) << "AREA " << char(179) << setw(title[6]) << "CITY " << char(179) << setw(title[7]) << "CASH " << char(179) << setw(title[8]) << "ORDERS" << char(179) << setw(title[9]) << "ACTIVE" << char(179);
        cout << "\n\t" << char(195);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(197);
        }
        cout << "\b" << char(180);
        for(int j = 0; j < customers.size(); j++){
            if((customers[j].getCity() == cities[_city][0]) && (customers[j].getArea() == cities[_city][_area])){
                cout << "\n\t" << char(179) << setw(title[0]) << customers[j].getCustomerCode() << char(179) << setw(title[1]) << customers[j].getFirstName() << char(179) << setw(title[2]) << customers[j].getLastName() << char(179) << setw(title[3]) << customers[j].getEmailAddress() << char(179) << setw(title[4]) << customers[j].getContactNumber() << char(179) << setw(title[5]) << customers[j].getArea() << char(179) << setw(title[6]) << customers[j].getCity() << char(179) << setw(title[7]) << customers[j].getWalletAmount() << char(179) << setw(title[8]) << customers[j].getOrderCount() << char(179) << setw(title[9]) << customers[j].getIsActive() << char(179);
            }
        }
        cout << "\n\t" << char(212);
        for(int i = 0; i < 10; i++){
            cout << string(title[i], char(196)) << char(193);
        }
        cout << "\b" << char(217) << endl;
    }

    /*void sendVoucher(string _emailAddress,string _voucher){
        customers[stoi(custEmailLink[_emailAddress])-1].setVoucher(_voucher);
    }*/

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






class TAXDEPARTMENT{
    string taxAdmin;
    string taxPass;
    vector<double> cuisineTax;
};


int main(){
    stringstream ss;
    string inputString, choiceString, inputItem, inputItemSub, inputItems = "", strVecInput;
    string managerID, managerPassword, restaurantCode, title, description, contactNumber, address, openTime, closeTime, freeDelivery, restDiscount, minimumOrder, deliveryCharges;
    string firstName, lastName, customerCode, custPassword, emailAddress, custContactNumber, custAddress;
    string userName,passWord;
    string itemCode,foodTitle,foodDescription;
	string orderNumber;
    bool scrSizeCheck, firstInput = true;
    bool isRestActive, isRestOpen, isActive, isOpen, isPaid, isApproved;
    bool daysOpen[7] = {false,false,false,false,false,false,false};
    int fontSize = 19, menuIndex = 0, itemIndex, choice, restIndex, custIndex, foodIndex, sizeIndex, priceIndex, intVecInput, cuisineIndex, quantity;
    int area, city, ordersPending, ordersCancelled, menuCount;
    int custArea, custCity, orderCount, intInput;
    int cuisine, stock, limit, prepTime;
    int openTimeAdmin, closeTimeAdmin;
    double restRevenue, restTax, walletAmount, revenue, tax, floatVecInput;
    double price, discount;
    vector<string> strVec;
    vector<double> floatVecPrice, floatVecWeight;
    fstream adminFile;
    setConsoleSize(144, 47);
    setFontSize(fontSize, 500, L"Courier New");
    SetConsoleTitle("Food-Panda");
    //showCuisine();
    //system("pause");
    cout << boolalpha << fixed << setprecision(2);

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
        adminFile.close();
        goto ADMIN;
        
    } else{
        getline(adminFile, userName);
        getline(adminFile, passWord);
        adminFile.close();
        setMessage("Administrator Found!");
        goto CreateAdmin;
    }

    ADMIN:
    setMessage("Administrator Details not Found! Setting Up Administrator");
    gotoxy(36, 7);
    cout << "Administrator ID: ";
    getline(cin, userName);
    gotoxy(36, 9);
    cout << "Administrator Password: ";
    getline(cin, passWord);
    adminFile.open("admin.dat", ios::out | ios::app | ios::binary);
    adminFile << userName << endl << passWord << endl;
    adminFile.close();
    
    CreateAdmin:
    ADMINISTRATOR adminOb(userName, passWord);
    RESTAURANT * restOB = new RESTAURANT;
    CUSTOMER * custOB = new CUSTOMER;
    ORDER * orderOB = new ORDER;

    MENU:
    setTitle(menu[menuIndex][0]);
    gotoxy(1, 6);
    for(int i = 6; i <= 44; i++){
        cout << char(186) << setw(143) << char(186) << endl;
    }
    cleanArea(2, 6, 143, 44);
    for(int i = 1; i < menu[menuIndex].size(); i++){
        gotoxy(4, 5+(i*2));
        if(i == (menu[menuIndex].size() - 1)){
            cout << "0> ";
            itemIndex = i + 1;
        } else{
            cout << i << "> ";
        }
        cout << menu[menuIndex][i];
    }

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
    case 1: //Administrator
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

    case 113:
        menuIndex = 13;
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

    case 141:
        cleanArea(2, 6, 143, 44);
        setTitle("Adding New Voucher");
        gotoxy(2, 7);
        cout << "\tEnter Voucher Code:\t";
        getline(cin, inputItem);
        cout << "\n\tEnter Voucher Value:\t";
        cin >> intInput;
        cin.clear();
        cin.ignore();
        setMessage(adminOb.addVoucher(inputItem, intInput));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 142:
        cleanArea(2, 6, 143, 44);
        setTitle("Block Voucher");
        gotoxy(2, 7);
        cout << "\tEnter Voucher Code:\t";
        getline(cin, inputItem);
        setMessage(adminOb.blockVoucher(inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 143: //Send
        cleanArea(2, 6, 143, 44);
        setTitle("Send Voucher");
        gotoxy(2, 7);
        cout << "\tEnter Voucher Code:\t";
        getline(cin, inputItem);
        cout << "\n\tEnter Customer Code:\t";
        getline(cin, customerCode);
        setMessage(adminOb.sendVoucher(customerCode, inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 144: //Show
        cleanArea(2, 6, 143, 44);
        setTitle("Show Vouchers");
        gotoxy(2, 7);
        cout << "\t1> Show All\n\n\t2> Find Voucher by Code\n\n\t3> Show Unused\n\n\t4> Show Expired\n\n\t5> Show Blocked\n\n\tChoice:\t";
        cin >> intInput;
        cin.clear();
        cin.ignore();
        cleanArea(2, 6, 143, 44);
        gotoxy(2, 7);
        if(intInput == 1){
            setMessage(adminOb.showVouchers());
        } else if(intInput == 2){
            cout << "\tVoucher Code:\t";
            getline(cin, inputItem);
            cleanArea(2, 6, 143, 44);
            gotoxy(2, 7);
            setMessage(adminOb.showVouchers(inputItem));
        } else if(intInput == 3){
            setMessage(adminOb.showVouchers(1));
        } else if(intInput == 4){
            setMessage(adminOb.showVouchers(-1));
        } else if(intInput == 5){
            setMessage(adminOb.showVouchers(0));
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 2: //Restaurant Manager
        cleanArea(2, 6, 143, 44);
        setMessage("Please enter Manager Credentials");
        gotoxy(36, 7);
        if(adminOb.getRestaurantSize() > 0){
            cout << "Manager ID: ";
            getline(cin, managerID);
            gotoxy(36, 9);
            cout << "Manager Password: ";
            getline(cin, managerPassword);
            restIndex = (adminOb.checkManager(managerID) - 1);
            if((restIndex >= 0) && (adminOb.getRestPassword(restIndex) == managerPassword)){
                setMessage("Manager Authentication Successfull!");
                restOB = adminOb.getRestaurant(restIndex);
                menuIndex = 7;
            } else{
                setMessage("Bad ID/Password!");
                menuIndex = 0;
                choiceString = "";
            }
        } else{
            menuIndex = 0;
            choiceString = "";
            setMessage("There is no Record of any Restaurant!");
        }
        goto MENU;
        break;

    case 21:
        cleanArea(2, 6, 143, 44);
        setTitle("RESTAURANT DETAILS");
        gotoxy(2, 7);
        restOB->showDetails();
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 22: //Manager Password Change
        cleanArea(2, 6, 143, 44);
        setTitle("CHANGING PASSWORD");
        gotoxy(2, 7);
        cout << "\tOld Password:\t";
        getline(cin, passWord);
        cout << "\n\tRetype Old Password:\t";
        getline(cin, managerPassword);
        if(passWord == managerPassword){
            cout << "\n\tNew Password:\t";
            getline(cin, managerPassword);
            if(restOB->getManagerPassword() == passWord){
                restOB->setManagerPassword(managerPassword);
                setMessage("Password Change Successful!");
            } else{
                setMessage("Password Change Unsuccessful, Wrong Password!");
            }
        } else{
            setMessage("Password does not match!");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 23: //Manager > Restaurant Open/Close
        if(restOB->getIsRestOpen() == false){
            restOB->setIsRestOpen(true);
            setMessage("Restaurant Open");
        } else{
            restOB->setIsRestOpen(false);
            setMessage("Restaurant Closed");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 24: //Restaurant Day/Time Setup
        cleanArea(2, 6, 143, 44);
        setTitle("Setting Up Opening Days/Timings");
        gotoxy(2, 7);
        cout << "\t1> Change Opening Days\n\n\t2> Change Timings\n\n\t0> Go Back\n\n\tChoice:\t";
        getline(cin, inputItem);
        if(inputItem == "1"){
            setMessage("Enter 0 - 6 to change Status or 'q' to quit.");
            do{
                cleanArea(2, 6, 143, 44);
                gotoxy(2, 7);
                restOB->displayDays();
                cout << "\n\n\tCode:\t";
                getline(cin, inputItem);
                if((inputItem.length() == 1) && (inputItem[0] >= 48 && inputItem[0] < 55)){
                    if(restOB->getDaysOpen(stoi(inputItem)) == true){
                        restOB->setDayClose(stoi(inputItem));
                        setMessage("Now Restaurant will stay Closed on " + days[stoi(inputItem)]);
                    } else {
                        restOB->setDayOpen(stoi(inputItem));
                        setMessage("Now Restaurant will stay Open on " + days[stoi(inputItem)]);
                    }
                } else if(inputItem == "q"){
                    setMessage("");
                } else{
                    setMessage("Invalid Input");
                }
            } while(tolower(inputItem[0]) != 'q');
        } else if(inputItem == "2"){
            cleanArea(2, 6, 143, 44);
            gotoxy(2, 7);
            cout << "\tOpening Time:\t";
            cin >> openTime;
            cout << "\tClosing Time:\t";
            cin >> closeTime;
            restOB->setOpenTime(stoi(openTime));
            restOB->setCloseTime(stoi(closeTime));
            cin.clear();
            cin.ignore();
            setMessage("Restaurant's Timings Changed");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 25: //Modifying Restaurant Details
        cleanArea(2, 6, 143, 44);
        setTitle("Modifying Restaurant Details");
        gotoxy(2, 7);
        cout << "\t1> Title\n\n\t2> Description\n\n\t3> Contact Number\n\n\t4> Location\n\n\t5> Discount Percentage\n\n\t6> Delivery Options\n\n\t0> Go Back\n\n\tChoice:\t";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(2, 7);
        if(inputItem == "1"){
            cout << "\tCurrent Title:\t";
            getline(cin, inputItem);
            cout << "\tNew Title:\t";
            getline(cin, title);
            if(restOB->getTitle() == inputItem && title.length() > 0){
                restOB->setTitle(title);
                setMessage("Restaurant Title Changed!");
            } else if(title.length() == 0){
                setMessage("Restaurant Title Unchanged!");
            } else{
                setMessage("Restaurant Title not matched!");
            }
        } else if(inputItem == "2"){
            cout << "\tCurrent Description:\t" << restOB->getDescription().substr(0, 100) << "\n\n\tNew Description:\t";
            getline(cin, inputItem);
            if(inputItem.length() > 0){
                restOB->setDescription(inputItem);
                setMessage("Restaurant Description Changed!");
            } else{
                setMessage("Restaurant Description Unchanged!");
            }
        } else if(inputItem == "3"){
            cout << "\tCurrent Contact Number:\t" << restOB->getContactNumber() << "\n\n\tNew Contact Number:\t";
            getline(cin, inputItem);
            if(inputItem.length() > 0){
                restOB->setContactNumber(inputItem);
                setMessage("Restaurant Contact Number Changed!");
            } else{
                setMessage("Restaurant Contact Number Unchanged!");
            }
        } else if(inputItem == "4"){
            cout << "\tCities:\n";
            for(int i = 0; i < cities.size(); i++){
                cout << "\t\t" << i << ") " << cities[i][0] << endl;
            }
            cout << "\tChoice:\t";
            cin >> city;
            cout << "\n\tArea:\n";
            for(int i = 1; i < cities[city].size(); i++){
                cout << "\t\t" << i << ") " << cities[city][i] << endl;
            }
            cout << "\tChoice:\t";
            cin >> area;
            cin.clear();
            cin.ignore();
            cout << "\n\tAddress:\t";
            getline(cin, address);
            restOB->setCity(city);
            restOB->setArea(area);
            restOB->setAddress(address);
            setMessage("Restaurant Location Changed!");
        } else if(inputItem == "5"){
            cout << "\tCurrent Discount Percentage:\t" << restOB->getRestDiscount() << "%\n\n\tNew Discount Percentage:\t";
            cin >> discount;
            cin.clear();
            cin.ignore();
            restOB->setDiscount(discount);
            setMessage("Restaurant Discount Percentage Changed!");
        } else if(inputItem == "6"){
            cout << "\tDo you offer Free Delivery (y/n):\t";
            if(tolower(getche()) == 'y'){
                restOB->setFreeDelivery(true);
                cout << "\n\n\tMinimum Order for Free Delivery:\t";
                getline(cin, inputItem);
                restOB->setMininmumOrder(stoi(inputItem));
                if(stoi(inputItem) > 0){
                    cout << "\n\tDelivery Charges for Orders less than " << inputItem << ":\t";
                    getline(cin, inputItem);
                    restOB->setDeliveryCharges(stod(inputItem));
                } else{
                    restOB->setDeliveryCharges(0);
                }
            } else{
                restOB->setFreeDelivery(false);
                restOB->setMininmumOrder(0);
                cout << "\n\n\tDelivery Charges for All Orders:\t";
                getline(cin, inputItem);
                restOB->setDeliveryCharges(stod(inputItem));
            }
            setMessage("Restaurant Delivery Options Changed!");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 26:
        menuIndex = 8;
        goto MENU;
        break;

    case 261: //MENU > Add Item
        setTitle("RESTAURANT > MENU > Adding Item");
        setMessage("Enter '0 - 11' to Add Item OR anything else to Quit.");
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\tCuisine List:";
        for(int i = 0; i < cuisineTitle.size(); i++){
            cout << "\n\n\t\t" << i << "> " << cuisineTitle[i];
        }
        cout << "\n\tChoice:\t";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        if(((inputItem.length() == 1) && (inputItem[0] >= 48 && inputItem[0] < 58)) || inputItem == "10" || inputItem == "11"){
            cout << "\tTitle:\t\t\t";
            getline(cin, title);
            cout << "\n\tDescription:\t\t";
            getline(cin, description);
            cout << "\n\tStock:\t\t\t";
            cin >> stock;
            cout << "\n\tMax Order Limit:\t";
            cin >> limit;
            cout << "\n\tPreparation Time:\t";
            cin >> prepTime;
            cout << "\n\tDiscount Percentage:\t";
            cin >> discount;
            cin.clear();
            cin.ignore();
            if(inputItem != "0"){
                cout << "\n\tPrice (per Unit/Pound):\t";
                cin >> price;
                cin.clear();
                cin.ignore();
            }
            if(inputItem == "0"){
                strVec.clear();
                floatVecPrice.clear();
                cout << "\n\tDo you offer \"" << title << "\" in different sizes? (y/n):\t";
                if(tolower(getche()) == 'y'){
                    cout << "\n\n\tNumber of Sizes:\t";
                    cin >> intInput;
                    cin.clear();
                    cin.ignore();
                    for(int i = 0; i < intInput; i++){
                        cleanArea(2, 6, 143, 44);
                        gotoxy(1, 7);
                        cout << "\n\tSize: " << (i + 1) << "\n\n\tSize Description:\t";
                        cin >> strVecInput;
                        strVec.push_back(strVecInput);
                        cout << "\n\tPrice:\t";
                        cin >> floatVecInput;
                        floatVecPrice.push_back(floatVecInput);
                        cin.clear();
                        cin.ignore();
                        //cout << "\n";
                    }
                } else{
                    cout << "\n\tDef";
                    strVec.push_back("Default");
                    cout << "\n\tPrice:\t";
                    cin >> floatVecInput;
                    floatVecPrice.push_back(floatVecInput);
                    cin.clear();
                    cin.ignore();
                }
                PIZZA pizzaOB(title, description, stock, limit, prepTime, discount, floatVecPrice, strVec);
                restOB->addItem(pizzaOB);
            } else if(inputItem == "1"){
                BURGER burgerOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(burgerOB);
            } else if(inputItem == "2"){
                SANDWICHE sandwichOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(sandwichOB);
            } else if(inputItem == "3"){
                FASTFOOD fastFoodOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(fastFoodOB);
            } else if(inputItem == "4"){
                BARBQ barbqOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(barbqOB);
            } else if(inputItem == "5"){
                PAKISTANI pakistaniOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(pakistaniOB);
            } else if(inputItem == "6"){
                CHINESE chineseOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(chineseOB);
            } else if(inputItem == "7"){
                INTERNATIONAL internationalOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(internationalOB);
            } else if(inputItem == "8"){
                SEAFOOD seaFoodOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(seaFoodOB);
            } else if(inputItem == "9"){
                DESSERT dessertOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(dessertOB);
            } else if(inputItem == "10"){
                CAKE cakeOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(cakeOB);
            } else if(inputItem == "11"){
                BEVERAGE beverageOB(title, description, stock, limit, prepTime, discount, price);
                restOB->addItem(beverageOB);
            }
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 262: //MENU > Modifying Item
        setTitle("RESTAURANT > MENU > Modifying Item");
        setMessage("Enter Item Code to modify it!");
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\tItem Code:\t";
        getline(cin, inputItem);
        if((inputItem.length() == 8) && (inputItem.substr(0, 3) == restOB->getCode())){
            cleanArea(2, 6, 143, 44);
            gotoxy(1, 7);
            cout << "\tOld Title:\n\tNew Title:\n\n\tOld Description:\n\tNew Description:\n\n\tOld Stock:\n\tNew Stock:\n\n\tOld Order Limit:\n\tNew Order Limit:\n\n\tOld Preparation Time:\n\tNew  Preparation Time:\n\n\tOld Discount:\n\tNew  Discount:";
            
            if(inputItem.substr(3, 2) == "00"){
                PIZZA * pizzaOB = new PIZZA;
                pizzaOB = restOB->getPizza(stoi(inputItem.substr(5, 3)) - 1);
                gotoxy(1, 7);
                cout << "\t\t\t\t" << pizzaOB->getTitle() << "\n\n\n\t\t\t\t" << pizzaOB->getDescription() << "\n\n\n\t\t\t\t" << pizzaOB->getStock() << "\n\n\n\t\t\t\t" << pizzaOB->getLimit() << "\n\n\n\t\t\t\t" << pizzaOB->getPrepTime() << "\n\n\n\t\t\t\t" << pizzaOB->getDiscount();
                gotoxy(1, 6);
                for(int i = 0; i < 6; i++){
                    cout << "\n\n\t\t\t\t";
                    getline(cin, inputItemSub);
                    if(inputItemSub.length() != 0){
                        if(i == 0){pizzaOB->setTitle(inputItemSub);}
                        else if(i == 1){pizzaOB->setDescription(inputItemSub);}
                        else if(i == 2){pizzaOB->setStock(stoi(inputItemSub));}
                        else if(i == 3){pizzaOB->setLimit(stoi(inputItemSub));}
                        else if(i == 4){pizzaOB->setPrepTime(stoi(inputItemSub));}
                        else if(i == 5){pizzaOB->setDiscount(stod(inputItemSub));}
                    }
                }
                strVec.clear();
                floatVecPrice.clear();
                cout << "\n\tDo you offer \"" << pizzaOB->getTitle() << "\" in different sizes? (y/n):\t";
                if(tolower(getche()) == 'y'){
                    cout << "\n\n\tNumber of Sizes:\t";
                    cin >> intInput;
                    cin.clear();
                    cin.ignore();
                    for(int i = 0; i < intInput; i++){
                        cleanArea(2, 6, 143, 44);
                        gotoxy(1, 7);
                        cout << "\n\tSize: " << (i + 1) << "\n\n\tSize Description:\t";
                        cin >> strVecInput;
                        strVec.push_back(strVecInput);
                        cout << "\n\tPrice:\t";
                        cin >> floatVecInput;
                        floatVecPrice.push_back(floatVecInput);
                        cin.clear();
                        cin.ignore();
                        //cout << "\n";
                    }
                } else{
                    strVec.push_back("Default");
                    cout << "\n\tPrice:\t";
                    cin >> floatVecInput;
                    floatVecPrice.push_back(floatVecInput);
                    cin.clear();
                    cin.ignore();
                }
                pizzaOB->setSize(strVec);
                pizzaOB->setPrice(floatVecPrice);
            } else if((inputItem[3] == '0' && (inputItem[4] > 48 && inputItem[4] < 58)) || inputItem == "10" || inputItem == "11"){
                cout << "\n\n\tOld Price:\n\tNew Price:";
                FOOD * foodOB = new FOOD(stoi(inputItem.substr(3, 2)));
                if(inputItem.substr(3, 2) == "01"){
                    foodOB = restOB->getBurger(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "02"){
                    foodOB = restOB->getSandwich(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "03"){
                    foodOB = restOB->getFastFood(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "04"){
                    foodOB = restOB->getBarbq(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "05"){
                    foodOB = restOB->getPakistani(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "06"){
                    foodOB = restOB->getChinese(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "07"){
                    foodOB = restOB->getInternational(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "08"){
                    foodOB = restOB->getSeafood(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "09"){
                    foodOB = restOB->getDessert(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "10"){
                    foodOB = restOB->getCake(stoi(inputItem.substr(5, 3)) - 1);
                } else if(inputItem.substr(3, 2) == "11"){
                    foodOB = restOB->getBeverage(stoi(inputItem.substr(5, 3)) - 1);
                }
                gotoxy(1, 7);
                cout << "\t\t\t\t" << foodOB->getTitle() << "\n\n\n\t\t\t\t" << foodOB->getDescription() << "\n\n\n\t\t\t\t" << foodOB->getStock() << "\n\n\n\t\t\t\t" << foodOB->getLimit() << "\n\n\n\t\t\t\t" << foodOB->getPrepTime() << "\n\n\n\t\t\t\t" << foodOB->getDiscount() << "\n\n\n\t\t\t\t" << foodOB->getPrice();
                gotoxy(1, 6);
                for(int i = 0; i < 7; i++){
                    cout << "\n\n\t\t\t\t";
                    getline(cin, inputItemSub);
                    if(inputItemSub.length() != 0){
                        if(i == 0){foodOB->setTitle(inputItemSub);}
                        else if(i == 1){foodOB->setDescription(inputItemSub);}
                        else if(i == 2){foodOB->setStock(stoi(inputItemSub));}
                        else if(i == 3){foodOB->setLimit(stoi(inputItemSub));}
                        else if(i == 4){foodOB->setPrepTime(stoi(inputItemSub));}
                        else if(i == 5){foodOB->setDiscount(stod(inputItemSub));}
                        else if(i == 6){foodOB->setPrice(stod(inputItemSub));}
                    }
                }
            }
        } else{
            setMessage("Invalid Code");
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 263: //MENU > Deleting Item
        setTitle("RESTAURANT > MENU > Deleting Item");
        setMessage("Enter Item Code to delete it!");
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\tItem Code:";
        getline(cin, inputItem);
        if((inputItem.length() == 8) && (inputItem.substr(0, 3) == restOB->getCode())){
            restOB->deleteItem(inputItem);
        } else{
            setMessage("Invalid Code");
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 264:
        menuIndex = 14;
        goto MENU;
        break;

    case 2641:
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        restOB->showFood(1, 0);
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
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

    case 31:
        do{
            cleanArea(2, 6, 143, 44);
            gotoxy(1, 7);
            cout << "\tEmail Address:\t";
            getline(cin, emailAddress);
            cout << "\tContact Number:\t";
            getline(cin, contactNumber);
        }while(adminOb.checkCustomer(emailAddress, contactNumber) != -1);
        cout << "\n\tCities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << "\t\t" << i << ") " << cities[i][0] << endl;
        }
        cout << "\tChoice:\t\t";
        cin >> city;
        cout << "\n\tArea:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << "\t\t" << i << ") " << cities[city][i] << endl;
        }
        cout << "\tChoice:\t\t";
        cin >> area;
        cin.clear();
        cin.ignore();
        cout << "\n\tAddress:\t";
        getline(cin, address);
        cout << "\n\tFirst Name:\t";
        getline(cin, firstName);
        cout << "\n\tLast Name:\t";
        getline(cin, lastName);
        cout << "\n\tPassword:\t";
        getline(cin, passWord);
        {
            CUSTOMER custOb(firstName, lastName, passWord, emailAddress, contactNumber, address, area, city);
            adminOb.addCustomer(custOb);
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 32:
        cleanArea(2, 6, 143, 44);
        setMessage("Please enter Customer Credentials");
        gotoxy(36, 7);
        if(adminOb.getCustomerSize() > 0){
            cout << "Customer Email/Contact: ";
            getline(cin, emailAddress);
            gotoxy(36, 9);
            cout << "Customer Password: ";
            getline(cin, passWord);
            custIndex = (adminOb.checkCustomer(emailAddress) - 1);
            if((custIndex >= 0) && (adminOb.getCustPassword(custIndex) == passWord)){
                setMessage("Customer Authentication Successfull!");
                custOB = adminOb.getCustomer(custIndex);
                menuIndex = 11;
            } else{
                setMessage("Bad Email/Contact OR Password!");
                menuIndex = 10;
                //choiceString = "";
                choiceString = choiceString.substr(0, (choiceString.length()-1));
            }
        } else{
            menuIndex = 10;
            //choiceString = "";
            choiceString = choiceString.substr(0, (choiceString.length()-1));
            setMessage("There is no Record of any Customer!");
        }
        goto MENU;
        break;

    case 321:
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << custOB->getAddress() << endl;
        cout << custOB->getArea() << endl;
        cout << custOB->getCity() << endl;
        cout << custOB->getContactNumber() << endl;
        cout << custOB->getCustomerCode() << endl;
        cout << custOB->getCustPassword() << endl;
        cout << custOB->getEmailAddress() << endl;
        cout << custOB->getFirstName() << endl;
        cout << custOB->getIsActive() << endl;
        cout << custOB->getLastName() << endl;
        cout << custOB->getOrderCount() << endl;
        cout << custOB->getOrderSize() << endl;
        //cout << custOB->getVoucherUsed() << endl;
        cout << custOB->getWalletAmount() << endl;
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 322:
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\t1> Change Password\n\n\t2> Change Email Address\n\n\t3> Change Contact Number\n\n\t4> Change Location\n\n\t0> Go Back\n\n\tChoice:\t";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        if(inputItem == "1"){
            cout << "\tOld Password:\t\t";
            getline(cin, passWord);
            cout << "\n\tNew Password:\t\t";
            getline(cin, managerPassword);
            cout << "\n\tRetype New Password:\t";
            getline(cin, inputItemSub);
            if(managerPassword == inputItemSub){
                cout << "passWord: " << passWord << "\tcust: " << custOB->getCustPassword();
                system("pause");
                if(passWord == custOB->getCustPassword()){
                    custOB->setCustPassword(inputItemSub);
                    setMessage("Password Change Successful!");
                } else{
                    setMessage("Wrong Password! Password Change Unsuccessful!");
                }
            } else{
                setMessage("New Password not Matched!");
            }
        } else if(inputItem == "2"){
            cout << "\tPassword:\t";
            getline(cin, passWord);
            if(passWord == custOB->getCustPassword()){
                cout << "\n\tNew Email Address:\t";
                getline(cin, emailAddress);
                setMessage(adminOb.changeCustEmail(custIndex, emailAddress));
            } else{
                setMessage("Wrong Password Entered!");
            }
        } else if(inputItem == "3"){
            cout << "\tPassword:\t";
            getline(cin, passWord);
            if(passWord == custOB->getCustPassword()){
                cout << "\n\tNew Contact Number:\t";
                getline(cin, contactNumber);
                setMessage(adminOb.changeCustContact(custIndex, contactNumber));
            } else{
                setMessage("Wrong Password Entered!");
            }
        } else if(inputItem == "4"){
            cout << "\tCities:\n";
            for(int i = 0; i < cities.size(); i++){
                cout << "\t\t" << i << ") " << cities[i][0] << endl;
            }
            cout << "\tChoice:\t";
            cin >> city;
            cout << "\n\tArea:\n";
            for(int i = 1; i < cities[city].size(); i++){
                cout << "\t\t" << i << ") " << cities[city][i] << endl;
            }
            cout << "\tChoice:\t";
            cin >> area;
            cin.clear();
            cin.ignore();
            cout << "\n\tAddress:\t";
            getline(cin, address);
            custOB->setCustCity(city);
            custOB->setCustArea(area);
            custOB->setCustAddress(address);
            setMessage("Customer Location Changed!");
        } else{
            setMessage("");
        }
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 323:
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\tRestaurant Code:\t";
        getline(cin, restaurantCode);
        if(restaurantCode.length() == 3){
            cuisineIndex = -1;
            restIndex = (stoi(restaurantCode) - 1);
            if(restIndex < adminOb.getRestaurantSize()){
                restOB = adminOb.getRestaurant(restIndex);
                if(custOB->getCity() == restOB->getCity()){
                    ORDER tempOrder;
                    custOB->addOrder(tempOrder, restOB->getCode());
                    orderOB = custOB->getNewOrder();
                    ORDERITEM orderItemOB;
                    do{
                        showCuisine(cuisineIndex);
                        cout << "\n\n\tChoice:\t";
                        cin >> cuisineIndex;
                        cin.clear();
                        cin.ignore();
                        if(cuisineIndex >= 0 && cuisineIndex < 12){
                            showCuisine(cuisineIndex);
                            cleanArea(33, 6, 143, 44);
                            gotoxy(1, 7);
                            if(restOB->hasFood(cuisineIndex) == false){
                                //cuisineIndex = -12;
                                goto ORDEREND;
                            } else{
                                restOB->displayRestMenu(cuisineIndex);
                                cout << "\n\n\t\t\t\tChoice:\t";
                                getline(cin, itemCode);
                                foodIndex = (stoi(itemCode.substr(5, 3)) - 1);
                            }
                            if(cuisineIndex == 0){
                                PIZZA * pizzaOB = new PIZZA;
                                pizzaOB = restOB->getPizza(foodIndex);
                                cout << "\n\t\t\t\tSizes Available:\t";
                                for(int i = 0; i < pizzaOB->getSizeLength(); i++){
                                    cout << "\n\t\t\t\t\t" << i << "> " << pizzaOB->getSize(i) << ":\t" << pizzaOB->getPrice(i);
                                    if(i == (pizzaOB->getSizeLength() - 1)){
                                        cout << "\n\t\t\t\tChoice:\t";
                                        cin >> sizeIndex;
                                    }
                                }
                            }
                            cout << "\n\t\t\t\tMax Limit:\t" << restOB->getLimit(cuisineIndex, foodIndex) << "\t\tStock Available:\t" << restOB->getStock(cuisineIndex, foodIndex) << "\n\t\t\t\tQuantity:\t";
                            cin >> quantity;
                            cin.clear();
                            cin.ignore();
                            if(quantity <= restOB->getLimit(cuisineIndex, foodIndex) && quantity <= restOB->getStock(cuisineIndex, foodIndex)){
                                if(cuisineIndex == 0){
                                    PIZZA * pizzaOB = new PIZZA;
                                    pizzaOB = restOB->getPizza(foodIndex);
                                    ORDERITEM tempOrderItemOB(0, pizzaOB->getItemCode(), pizzaOB->getTitle(), pizzaOB->getSize(sizeIndex), pizzaOB->getPrice(sizeIndex), pizzaOB->getDiscount(), pizzaOB->getPrepTime(), quantity);
                                    orderItemOB = tempOrderItemOB;
                                } else{
                                    FOOD * foodOB = new FOOD(cuisineIndex);
                                    if(cuisineIndex == 1){
                                        foodOB = restOB->getBurger(foodIndex);
                                    } else if(cuisineIndex == 2){
                                        foodOB = restOB->getSandwich(foodIndex);
                                    } else if(cuisineIndex == 3){
                                        foodOB = restOB->getFastFood(foodIndex);
                                    } else if(cuisineIndex == 4){
                                        foodOB = restOB->getBarbq(foodIndex);
                                    } else if(cuisineIndex == 5){
                                        foodOB = restOB->getPakistani(foodIndex);
                                    } else if(cuisineIndex == 6){
                                        foodOB = restOB->getChinese(foodIndex);
                                    } else if(cuisineIndex == 7){
                                        foodOB = restOB->getInternational(foodIndex);
                                    } else if(cuisineIndex == 8){
                                        foodOB = restOB->getSeafood(foodIndex);
                                    } else if(cuisineIndex == 9){
                                        foodOB = restOB->getDessert(foodIndex);
                                    } else if(cuisineIndex == 10){
                                        foodOB = restOB->getCake(foodIndex);
                                    } else if(cuisineIndex == 11){
                                        foodOB = restOB->getBeverage(foodIndex);
                                    }
                                    ORDERITEM tempOrderItemOB(cuisineIndex, foodOB->getItemCode(), foodOB->getTitle(), "", foodOB->getPrice(), foodOB->getDiscount(), foodOB->getPrepTime(), quantity);
                                    orderItemOB = tempOrderItemOB;
                                }
                                cout << "\n\t\t\t\tEnter \"+\" to add more Items OR \"q\" to Quit OR \"c\" to Confirm:\t";
                                getline(cin, inputItem);
                                if(inputItem[0] == '+'){
                                    orderOB->addOrderItem(restOB->getCode(), custOB->getCustomerCode(), orderItemOB);
                                } else if(inputItem[0] == 'c'){
                                    cout << "pass1" << endl;
                                    system("pause");
                                    orderOB->addOrderItem(restOB->getCode(), custOB->getCustomerCode(), orderItemOB);
                                    cout << "pass2" << endl;
                                    system("pause");
                                    if(custOB->getWalletAmount() >= orderOB->getBill()){
                                        cout << "pass3" << endl;
                                        system("pause");
                                        orderOB->setIsPaid(true);
                                        cout << "pass4" << endl;
                                        system("pause");
                                        setMessage(custOB->payOrder(restOB->confirmOrder(*orderOB)));
                                        cout << "pass5" << endl;
                                        system("pause");
                                    } else{
                                        setMessage("Insufficient Funds to Complete Order! Please Recharge & Reorder.");
                                    }
                                    cuisineIndex = 12;
                                } else if(inputItem[0] == 'q'){
                                    cuisineIndex = 12;
                                    setMessage("Exit.");
                                }
                            } else{
                                setMessage("Order Quantity Exceeds Stock/Limit!");
                            }
                        }
                        ORDEREND:
                        if(cuisineIndex == -1){
                            setMessage("Restaurant does not offer this Cuisine");
                        }
                    } while(cuisineIndex >= 0 && cuisineIndex < 12);
                } else{
                    setMessage("Restaurant: " + restOB->getTitle() + "do not offer services in " + custOB->getCity());
                }
            } else{
                setMessage("Invalid Restaurant Code: " + restaurantCode);
            }
        } else{
            setMessage("You Entered Invalid Restaurant Code!");
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 325:
        menuIndex = 12;
        goto MENU;
        break;

    case 3251:
        setTitle("Displaying Voucher Details");
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\t1> Show New Vouchers\n\n\t2> Show Past Vouchers\n\n\tChoice:\t";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        if(inputItem == "1"){
            adminOb.showVouchersCust(custOB->getVoucher());
        }else if(inputItem == "2"){
            adminOb.showVouchersCust(custOB->getVoucherUsed());
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 3252:
        setTitle("Recharge Wallet");
        cleanArea(2, 6, 143, 44);
        gotoxy(1, 7);
        cout << "\tVoucher Code:\t";
        getline(cin, inputItem);
        setMessage(custOB->chargeWallet(adminOb.cashVoucher(inputItem)));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
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

    case 1130:
        menuIndex = 2;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 260:
        menuIndex = 7;
        choiceString = choiceString.substr(0, (choiceString.length()-2));
        goto MENU;
        break;

    case 2640:
        menuIndex = 8;
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

    case 121: //New Restaurant
        do{
            cleanArea(2, 6, 143, 44);
            gotoxy(1, 7);
            cout << "\tManager ID:\t\t";
            getline(cin, managerID);
        }while(adminOb.checkManager(managerID) != -1);
        cout << "\tManager Password:\t";
        getline(cin, managerPassword);
        cout << "\n\tCities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << "\t\t" << i << ") " << cities[i][0] << endl;
        }
        cout << "\tChoice:\t";
        cin >> city;
        cout << "\n\tArea:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << "\t\t" << i << ") " << cities[city][i] << endl;
        }
        cout << "\tChoice:\t";
        cin >> area;
        cin.clear();
        cin.ignore();
        cout << "\n\tAddress:\n\tRestaurant Title:\n\tRestaurant Description:\n\tContact Number:\n\tOpening Time:\n\tClosing Time:\n\tDiscount Percentage:";
        gotoxy(1, getY()-6);
        for(int i = 1; i < 8; i++){
            cout << "\t\t\t\t  ";
            getline(cin, inputItem);
            inputItems = inputItems + inputItem + ";";
        }
        cout << "\tDo you offer Free Delivery (y/n):\t";
        if(getche() == 'y'){
            inputItems = inputItems + "1;";
            cout << "\n\tMinimum Order for Free Delivery:\t";
            getline(cin, inputItem);
            inputItems = inputItems + inputItem + ";";
            if(stoi(inputItem) > 0){
                cout << "\tDelivery Charges for Orders less than " << inputItem << ":\t";
                getline(cin, inputItem);
                inputItems = inputItems + inputItem;
            } else{
                inputItems = inputItems + "0";
            }
        } else{
            inputItems = inputItems + "0" + ";";
            inputItems = inputItems + "0" + ";";
            cout << "\n\tDelivery Charges:\t";
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

    case 1131:
        cleanArea(2, 6, 143, 44);
        gotoxy(3, 7);
        adminOb.showCustomer();
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
        cin.clear();
        cin.ignore();
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 1132:
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
                adminOb.showCustOnLocation(city, area);
                system("pause");
            }
        }
        cin.clear();
        cin.ignore();
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 122:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\tManager ID:\t";
        getline(cin, inputItem);
        setMessage(adminOb.removeRestaurant(inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 132:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\tCustomer Email Address:\t";
        getline(cin, inputItem);
        setMessage(adminOb.removeCustomer(inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 123:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\tManager ID:\t";
        getline(cin, inputItem);
        setMessage(adminOb.reOpenRestaurant(inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 133:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\tCustomer Email Address:\t";
        getline(cin, inputItem);
        setMessage(adminOb.activateCustomer(inputItem));
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;
    
    case 124:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\t1> Manager ID\n\n\t2> Restaurant Code\n\n\t3> Restaurant Title\n\n\t0> Go Back\n\n\t Choice: ";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        if(inputItem == "1"){
            cout << "\tManager ID:\t";
            getline(cin, inputItem);
            cleanArea(2, 6, 143, 44);
            gotoxy(4, 7);
            adminOb.findRestWithManager(inputItem);
        } else if(inputItem == "2"){
            cout << "\tRestaurant Code:\t";
            getline(cin, inputItem);
            if((stoi(inputItem) >= 0) && (stoi(inputItem) < adminOb.getRestaurantSize())){
                setMessage("Restaurant Found!");
                adminOb.showRestaurants(stoi(inputItem));
            } else{
                setMessage("Restaurant with Code " + inputItem + " Not Found!");
            }
        } else if(inputItem == "3"){
            cout << "\tRestaurant Title:\t";
            getline(cin, inputItem);
            cleanArea(2, 6, 143, 44);
            gotoxy(3, 7);
            adminOb.showRestaurants(inputItem);
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 134:
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        cout << "\t1> Customer Code\n\n\t2> Email Address\n\n\t3> Contact Number\n\n\t4> Customer Name\n\n\t0> Go Back\n\n\t Choice: ";
        getline(cin, inputItem);
        cleanArea(2, 6, 143, 44);
        gotoxy(4, 7);
        if(inputItem == "1"){
            cout << "\tCustomer Code:\t";
            getline(cin, inputItem);
            if((stoi(inputItem) >= 0) && (stoi(inputItem) < adminOb.getCustomerSize())){
                setMessage("Customer Found!");
                adminOb.showRestaurants(stoi(inputItem));
            } else{
                setMessage("Customer with Code " + inputItem + " Not Found!");
            }
            cleanArea(2, 6, 143, 44);
            gotoxy(4, 7);
            adminOb.findRestWithManager(inputItem);
        } else if(inputItem == "2"){
            cout << "\tEmail Address:\t";
            getline(cin, inputItem);
            if((stoi(inputItem) >= 0) && (stoi(inputItem) < adminOb.getRestaurantSize())){
                setMessage("Restaurant Found!");
                adminOb.showRestaurants(stoi(inputItem));
            } else{
                setMessage("Restaurant with Code " + inputItem + " Not Found!");
            }
        } else if(inputItem == "3"){
            cout << "\tContact Number:\t";
            getline(cin, inputItem);
            cleanArea(2, 6, 143, 44);
            gotoxy(3, 7);
            adminOb.showRestaurants(inputItem);
        } else if(inputItem == "4"){
            cout << "\tCustomer Name:\t";
            getline(cin, inputItem);
            cleanArea(2, 6, 143, 44);
            gotoxy(3, 7);
            adminOb.showRestaurants(inputItem);
        }
        system("pause");
        choiceString = choiceString.substr(0, (choiceString.length()-1));
        goto MENU;
        break;

    case 131: //New Customer
        do{
            cleanArea(2, 6, 143, 44);
            gotoxy(1, 7);
            cout << "\tEmail Address:\t";
            getline(cin, emailAddress);
            cout << "\tContact Number:\t";
            getline(cin, contactNumber);
        }while(adminOb.checkCustomer(emailAddress, contactNumber) != -1);
        cout << "\n\tCities:\n";
        for(int i = 0; i < cities.size(); i++){
            cout << "\t\t" << i << ") " << cities[i][0] << endl;
        }
        cout << "\tChoice:\t\t";
        cin >> city;
        cout << "\n\tArea:\n";
        for(int i = 1; i < cities[city].size(); i++){
            cout << "\t\t" << i << ") " << cities[city][i] << endl;
        }
        cout << "\tChoice:\t\t";
        cin >> area;
        cin.clear();
        cin.ignore();
        cout << "\n\tAddress:\t";
        getline(cin, address);
        cout << "\n\tFirst Name:\t";
        getline(cin, firstName);
        cout << "\n\tLast Name:\t";
        getline(cin, lastName);
        cout << "\n\tPassword:\t";
        getline(cin, passWord);
        {
            CUSTOMER custOb(firstName, lastName, passWord, emailAddress, contactNumber, address, area, city);
            adminOb.addCustomer(custOb);
        }
        system("pause");
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

void showCuisine(int _index){
    cleanArea(2, 6, 143, 44);
    gotoxy(2,7);
    cout << "\t" << char(218) << string(2, char(196)) << char(194) << string(14, char(196)) << char(191) << "\n\t" << char(179) << "C#" << char(179) << setw(14) << "CUISINES   " << char(179);
    for(int i = 0; i < cuisineTitle.size(); i++){
        cout << "\n\t" << char(195) << string(2, char(196)) << char(197) << string(14, char(196)) << char(180) << "\n\t" << char(179) << setw(2) << i << char(179) << setw(14) << cuisineTitle[i] << char(179);
        if(_index == i){
            cout << "  " << char(254);
        }
    }
    cout << "\n\t" << char(192) << string(2, char(196)) << char(193) << string(14, char(196)) << char(217);
}