#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <map>

using namespace std;

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
class RESTAURANT;
class ADMINISTRATOR;
class CUSTOMER;
class FOOD;
class ORDER;
class TAXDEPARTMENT;
class TIMENOW;

vector<string> cuisineTitle{"Pizza","Burgers","Sandwiches","Fast Food","Bar.B.Q","Pakistani","Chinese","International","Seafood","Desserts","Cakes & Bakery","Beverage"};
vector<vector<string>> cities{{"Islamabad", "Area 1"}, {"Karachi", "Area 1", "Area 2", "Area 3", "Area 4", "Area 5"}, {"Lahore", "Area 1", "Area 2", "Area 3", "Area 4"}, {"Peshawar", "Area 1", "Area 2", "Area 3"}, {"Queta", "Area 1", "Area 2"}};

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
    string tnDate = to_string(day)+"/"+to_string(month + 1)+"/"+to_string(year + 1900);
    string tnTime = to_string(hours)+":"+to_string(minutes)+":"+to_string(seconds);

public:
    string getDate(){return tnDate;}
    string getTime(){return tnTime;}
};


class RESTAURANT{
    string managerID;
    string managerPassword;
    string restaurantCode;
    bool isActive;
    bool isOpen;
    int openTime;
    int closeTime;
    bool * daysOpen = new bool[7];
    string title;
    string description;
    string contactNumber;
    string address;
    int area;
    int city;
    int revenue;
    int tax;
    int ordersPending;
    int ordersCompleted;
    int ordersCancelled;
    bool freeDelivery;
    int minimumOrder;
    int deliveryCharges;
    bool * cuisines = new bool[12]{};
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

public:
    RESTAURANT(string _managerID, string _managerPassword, int _openTime, int _closeTime, string _title, string _description, string _contactNumber, string _address, int _area, int _city, bool _freeDelivery, int _minimumOrder, int _deliveryCharges){
        managerID = _managerID;
        managerPassword = _managerPassword;
        isActive = true;
        isOpen = false;
        openTime = _openTime;
        closeTime = _closeTime;
        title = _title;
        description = _description;
        contactNumber = _contactNumber;
        address = _address;
        area = _area;
        city = _city;
        revenue = tax = ordersPending = ordersCompleted = ordersCancelled = 0;
        freeDelivery = _freeDelivery;
        if(freeDelivery == true){
            minimumOrder = _minimumOrder;
        }
        else{
            minimumOrder = 0;
        }
        deliveryCharges = _deliveryCharges;
        menuCount = 0;
    }

    string getCode(){return restaurantCode;}
    string getTitle(){return title;}
    string getCity(){return cities[city][0];}
    string getArea(){return cities[city][area];}
    string getManagerID(){return managerID;}

    void setCode(string _code){
        restaurantCode = _code;
    }
};


class ADMINISTRATOR{
    const string userName;
    const string passWord;
    bool isOpen;
    int openTime;
    int closeTime;
    int revenue;
    int tax;
    vector<string> vouchersValid;
    vector<string> vouchersExpired;
    //int customerCount;
    //int restaurantCount;
    vector<RESTAURANT> restaurants;
    vector<CUSTOMER> customers;
    map <string, string> managerLink;
    map <string, string> custEmailLink;
    map <string, string> custContactLink;

public:
    ADMINISTRATOR(string _userName, string _passWord) : userName(_userName), passWord(_passWord){
        isOpen = false;
        openTime = 0;
        closeTime = 0;
        revenue = 0;
        tax = 0;
    }

    bool getIsOpen(){return isOpen;}
    int getOpenTime(){return openTime;}
    int getCloseTime(){return closeTime;}
    int getRestaurantSize(){return restaurants.size();}

    bool checkManager(string _managerID){
        if(managerLink[_managerID].length() == 0){
            return true;
        }else{
            cout << "Manager ID duplicate found!\n";
            return false;
        }
    }

    void setIsOpen(bool _isOpen){isOpen = _isOpen;}
    void setOpenTime(int _openTime){openTime = _openTime;}
    void setCloseTime(int _closeTime){closeTime = _closeTime;}

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

    void addRestaurant(RESTAURANT _restaurant){
        cout << "p1\n";
        restaurants.push_back(_restaurant);
        cout << "p2\n";
        if((restaurants.size()) < 10){
            cout << "p3\n";
            restaurants[restaurants.size() - 1].setCode("00" + to_string(restaurants.size()));
            cout << "p4\n";
        }else if((restaurants.size()) < 100){
            cout << "p5\n";
            restaurants[restaurants.size() - 1].setCode("0" + to_string(restaurants.size()));
            cout << "p6\n";
        }else{
            cout << "p7\n";
            restaurants[restaurants.size() - 1].setCode(to_string(restaurants.size()));
            cout << "p8\n";
        }
        cout << "p9\n";
        managerLink[restaurants[restaurants.size() - 1].getManagerID()] = restaurants[restaurants.size() - 1].getCode();
        cout << "p10\n";
    }

    void showRestaurants(){
        cout << "Code\t";
        for(int i = 0; i < restaurants.size(); i++){
            cout << restaurants[i].getCode() << "\t" << restaurants[i].getTitle() << "\t"
                 << restaurants[i].getCity() << "\t" << restaurants[i].getArea() << "\t"
                 << restaurants[i].getManagerID() << endl;
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
};


class CUSTOMER{
    string firstName;
    string lastName;
    string customerCode;
    string passWord;
    string emailAddress;
    string contactNumber;
    string address;
    int area;
    int city;
    int walletAmount;
    vector<string> vouchersUsed;
    int orderCount;

public:
    CUSTOMER(string _firstName, string _lastName, string _passWord, string _emailAddress, string _contactNumber, string _address, int _area, int _city, int _walletAmount, int _orderCount){
        firstName = _firstName;
        lastName = _lastName;
        passWord = _passWord;
        emailAddress = _emailAddress;
        contactNumber = _contactNumber;
        address = _address;
        area = _area;
        city = _city;
        walletAmount = 0;
        orderCount = 0;
    }
};


class FOOD{
    string itemCode;
    int cuisine;
    string title;
    string description;
    int stock;
    int limit;
    //bool haveSize;
    int time;

protected:
    int price;

public:
    FOOD(){}

    string getItemCode(){return itemCode;}
    int getCuisine(){return cuisine;}
    string getTitle(){return title;}
    string getDescription(){return description;}
    int getStock(){return stock;}
    int getLimit(){return limit;}
    int getPrice(){return price;}
    int getTime(){return time;}

    void setItemCode(string _itemCode){}
    void setCuisine(int _cuisine){}
    void setTitle(string _title){}
    void setDescription(string _description){}
    void setStock(int _stock){}
    void setLimit(int _limit){}
    void setPrice(int _price){}
    void setTime(int _time){}
};


class PIZZA : public FOOD{
    bool haveSize;
    vector<int> price;
    vector<string> size;

public:
    bool getHaveSize(){return haveSize;}
    int getPrice(int _index){return price[_index];}
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
    bool haveSize;
    vector<int> weight;

public:
    bool getHaveSize(){return haveSize;}
    int getPrice(int _index){return (price * weight[_index]);}
    int getWeight(int _index){return weight[_index];}
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

//void replaceSpace(string& _string);


int main(){
    string userName, passWord, managerID, managerPassword, restaurantCode, title, description, contactNumber, address, freeDeliver;
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
        }while(adminOb.checkManager(managerID) == false);
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
    system("cls");















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

/*void replaceSpace(string& _string){
    for(int i = 0; i < _string.length(); i++){}
}*/