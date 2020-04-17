#include<iostream>
#include<string>

using namespace std;

class NineTails{
private:
    string contactNo;
    string address;
    string email;
};


class Gift{
private:
    int revenue;

protected:
    string catID;
    int price;
    bool taxApplicable;
    int tax;
    int stock;

public:
    void Bill(){}
};


class Flowers : public Gift{
protected:
    string floralType;

public:
    Flowers(){}

    Flowers(string type){
        if(type == "Rose" || type == "rose" || type == "Tulip" || type == "tulip" || type == "Daisy" || type == "daisy"){
            floralType = type;
            price = 50;
            catID = "FL1";
        }
    }

    void setFloralType(string type){
        if(type == "Rose" || type == "rose" || type == "Tulip" || type == "tulip" || type == "Daisy" || type == "daisy"){
            floralType = type;
            price = 50;
            catID = "FL1";
        }
        else{
            cout << "Invalid Item Name Entered " <<endl;
        }
    }
    
    string getFloralType(){
        return floralType;
    }


    void ReplenishStock(int _stock){
        stock = _stock;
    }

    int GetStock(){
        return stock;
    }


    void Sale(){
        stock = stock - 1;
    }
};


class Perfume : public Gift{
protected:
    string brand;

public:
    Perfume(){}

    Perfume(string _brand){
        if(_brand == "GUCCI" || _brand == "gucci"){            
            brand = _brand;
            price = 1200;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "VERSACE" || _brand == "versace"){
            brand = _brand;
            price = 1100;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "CHANEL" || _brand == "chanel"){
            brand = _brand;
            price = 950;
            catID = "PF1";
            tax = price*4/100;
        }
        else{
            cout << "Invalid Item Name Entered " <<endl;
        }
    }

    void setPerfumeType(string _brand){
        if(_brand == "GUCCI" || _brand == "gucci"){            
            brand = _brand;
            price = 1200;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "VERSACE" || _brand == "versace"){
            brand = _brand;
            price = 1100;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "CHANEL" || _brand == "chanel"){
            brand = _brand;
            price = 950;
            catID = "PF1";
            tax = price*4/100;
        }
        else{
            cout << "Invalid Item Name Entered " <<endl;
        }
    }

    void ReplenishStock(int _stock){
        stock = _stock;
    }

    int GetStock(){
        return stock;
    }

    string getPerfumeType(){
        return brand;
    }

    void Sale(){
        stock = stock - 1;
    }
};




class ChocolateCake : public Gift{
protected:
    int weight;
    string msgOnCake;

public:
    ChocolateCake(){}

    ChocolateCake(int _weight, string message = ""){
        weight = _weight;
        msgOnCake = message;
        price = 700*weight;
        catID = "CK1";
        tax = price*7/100;        
    }

    void setWeight(int weight){
        this->weight = weight;
        price = weight*700;
        catID = "CK1";
        tax = price*7/100;
    }

    void setMessage(string message){
        msgOnCake = message;
    }

    void Sale(){
        stock = stock - 1;
    } 

    void ReplenishStock(int _stock){
        stock = _stock;
    }

    int GetStock(){
        return stock;
    }
};


class HappyBundle : public Flowers, public Perfume, public ChocolateCake{
public:
    HappyBundle(){}

    /*void setFloralType(string type){
        if(type == "Rose" || type == "rose" || type == "Tulip" || type == "tulip" || type == "Daisy" || type == "daisy"){
            floralType = type;
            price = 50;
            catID = "FL1";
        }
        else{
            cout << "Invalid Item Name Entered " <<endl;
        }
    }

    void setPerfume(string _brand){
        if(_brand == "GUCCI" || _brand == "gucci"){            
            brand = _brand;
            price = 1200;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "VERSACE" || _brand == "versace"){
            brand = _brand;
            price = 1100;
            catID = "PF1";
            tax = price*4/100;
        }
        else if(_brand == "CHANEL" || _brand == "chanel"){
            brand = _brand;
            price = 950;
            catID = "PF1";
            tax = price*4/100;
        }
        else{
            cout << "Invalid Item Name Entered " <<endl;
        }
    }

    void setWeight(int weight){
        this->weight = weight;
        price = weight*700;
        catID = "CK1";
        tax = price*7/100;
    }

    void setMessage(string message){
        msgOnCake = message;
    }*/
};



class TaxationDept{
};



int main(){
    string brand;
    string b;
    int stock;

    Perfume* ob = (Perfume*)new Gift;

    cout << "Enter Stock of Perfume availabel " <<endl;
    cin >> stock;

    cout << "Enter Perfume brand (GUCCI,VERSACE,CHANEL) " <<endl;
    cin >> brand;

    ob->setPerfumeType("GUCCI");

    cout << "The Perfume Brand is: " << ob->getPerfumeType() <<endl;

}