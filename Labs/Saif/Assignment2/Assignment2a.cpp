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
    int stock = 0;
    double taxPercent;

private:
    static int tax;
    static int revenue;
    //int revenue;

    friend int returnRevenue(Gift);
    friend int returnTax(Gift);
    
public:
    //friend int returnRevenue(Gift);


    void setCatID(string _catID){

        catID = _catID;
    }

    void setPrice(int _price){

        price = _price;
    }

    void setTaxApplicable(bool _taxApplicable){

        taxApplicable = _taxApplicable;
    }

    void repStock(int _stock){
        stock += _stock;
    }

    void setTaxPercentage(double _taxPercent){

        taxPercent = _taxPercent;
    }

    static void calcRevTax(int _price, bool _taxApplicable, double _taxPercent){
        revenue += _price;
        if(_taxApplicable == true){
            tax += (_price * _taxPercent);
        }
    }

    void Sale(){

        if(stock > 0){
            stock--;
            calcRevTax(price, taxApplicable, taxPercent);
            /*revenue += price;
            if(taxApplicable == true){
                tax += price * taxPercent;
            }*/
        }
        else{
            cout << "Stock has Depleted" << endl;
            return ;
        }



    }

    string getCatID(){return catID;}
    int getPrice(){return price;}
    bool getTaxApplicable(){return taxApplicable;}
    int getStock(){return stock;}
    double getTaxPercent(){return taxPercent;}


};

class Flowers : public Gift{
protected:
private:
    string floralType;
    

public:

    Flowers(string _floralType){
        floralType = _floralType;
        catID = "FL1";
        price = 50;
        taxApplicable = false;
    }

    string getFloralType(){return floralType;}

};

class Perfume : public Gift{
protected:
private:
    string brand;
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
        taxPercent = 0.07;
    }

    string getBrand(){return brand;}
    int getPrice(){return price;}
    void repStock(int _stock){
        stock += _stock;
    }

    
};

class ChocolateCake : public Gift{
protected:
private:
    int weight;
    string msgOnCake;
    //ChocolateCake(){}

public:
    ChocolateCake(){
        catID = "CK1";
        taxApplicable = true;
        taxPercent = 0.04;
    }

    void repStock(int _stock){
        stock += _stock;
    }

    void setWeight(int _weight){
        weight = _weight;
    }

    void setMsgOnCake(string _msgOnCake){
        msgOnCake = _msgOnCake;
    }

    void Sale(int _weight){
        if(stock >= _weight){
            stock = stock - _weight;
        }

        else{

            cout << "Stock is Insufficient" <<endl;
        }
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

int Gift::revenue;
int Gift::tax;

int returnRevenue(Gift g){return g.revenue;}
int returnTax(Gift g){return g.tax;}

/*bool checkFloralType(string _floralType){
    transform(_floralType.begin(), _floralType.end(), _floralType.begin(), ::tolower);
    if(_floralType=="rose" || _floralType=="tulip" || _floralType=="daisy"){
        return true;
    }
    return false;
}*/

int main(){
    Gift g1;
    Flowers fl1("Rose");
    //fl1.repStock(5);
    cout << fl1.getStock() << endl;
    cout << fl1.getStock() << endl;
    Perfume per1("GUCCI");
    cout << per1.getPrice();
    HappyBundle hp1(fl1, per1);
    //fl1.repStock(10);
    //fl1.Sale();
    cout << per1.getPrice() << endl;
    cout << per1.getStock();
    per1.repStock(10);
    cout << per1.getStock();
    per1.Sale();
    cout << per1.getStock();
    cout << "Revenue: " << returnRevenue(g1) << " Tax: " << returnTax(g1);
    
    return 0;
}