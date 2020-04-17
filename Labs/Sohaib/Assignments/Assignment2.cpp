#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class NineTails{
protected:

private:
    string contactNo;
    string address;
    string email;

public:
};

class Gift{
protected:
    string catID;
    int price;
    bool taxApplicable;

private:
    static int tax;
    static int stock;
    static int revenue;
    
public:
};

class Flowers : public Gift{
protected:
private:
    string floralType;
    string floralTypes[3] = {"Rose", "Tulip", "Daisy"};
    Flowers(){}

public:

    Flowers(string _floralType){
        for(int i = 0; i < 3; i++){
            if(_floralType == floralTypes[i]){
                floralType = _floralType;
                catID = "FL1";
                price = 50;
                taxApplicable = false;
                break;
            }
            else if(i == 2){
                throw invalid_argument("Invalid Floral Type!");
                //this->~Flowers();
            }
        }
    }

    ~Flowers(){}

    int getPrice(){return price;}
    string getFloralType(){return floralType;}
};

class Perfume : public Gift{
protected:
private:
    string brand;
    //string brands[3] = {"GUCCI", "VERSACE", "CHANEL"};
    Perfume(){}

public:
    Perfume(string _brand){
        if(_brand == "GUCCI"){
            price = 1200;
        }
        else if(_brand == "VERSACE"){
            price = 1100;
        }
        else if(_brand == "CHANEL"){
            price = 950;
        }
        else{
            return;
        }
        brand = _brand;
        catID = "PF1";
        taxApplicable = true;
    }

    string getBrand(){return brand;}
    int getPrice(){return price;}
};

class ChocolateCake : public Gift{
protected:
private:
    int weight;
    string msgOnCake;
    ChocolateCake(){}

public:
    ChocolateCake(int _weight, string _msgOnCake){
        weight = _weight;
        msgOnCake = _msgOnCake;
        catID = "CK1";
        price = 700 * _weight;
        taxApplicable = true;
    }
};

class HappyBundle{
protected:
private:
public:
    HappyBundle(Flowers _flower, Perfume _perfume){
        cout << _flower.getFloralType() << endl;
        cout << _perfume.getBrand();
    }
};

class TaxationDept{
protected:
private:
public:
};

/*bool checkFloralType(string _floralType){
    transform(_floralType.begin(), _floralType.end(), _floralType.begin(), ::tolower);
    if(_floralType=="rose" || _floralType=="tulip" || _floralType=="daisy"){
        return true;
    }
    return false;
}*/

int main(){
    Flowers fl1("Rose");
    Perfume per1("GUCC");
    cout << per1.getPrice();
    HappyBundle hp1(fl1, per1);
    
    return 0;
}