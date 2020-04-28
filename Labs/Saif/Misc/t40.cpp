#include<iostream>
#include<string>

using namespace std;

class Gift;
class Perfume;
class Flower;
class Cake;
class HB;
class NineTails;
class TaxationDept;

// header and cpp files can be seperate.


class Gift{

    int quantity, price;
    string catId; // not going to use.

    public: 

    int static revenue; // just to save time.
    int static tax;

    Gift(){ }

    void setQuantity(int quantity){

        this->quantity = quantity;
    }

    void getQuantity(){return quantity;}

    void Bill(){

        cout << "Thank you for purchasing from Nine Tails" <endl;
    }
};

int Gift::revenue = 0;
int Gift::tax = 0;

class Perfume : virtual public Gift{

    string brand;

    public:

    Perfume(){};

    Perfume(string brand, int quantity){

        if(brand == "GUCCI"){
            stock -= quantity;
            revenue += (1200*quantity);
            tax += (1200*quantity ) * 0.07;
        }

        else if(brand == "VERSACE"){
            stock -= quantity;
            revenue += (1100*quantity);
            tax += (1100*quantity ) * 0.07;
        }

        //CHANEL
        else {
            stock -= quantity;
            revenue += (950*quantity);
            tax += (950*quantity ) * 0.07;
        }
    }

    int static stock;

    void Bill(){
        cout << "Thank you for Purchasing Perfume for Nine Tails" <<endl;
    }
};

int Perfume::stock = 50; 


class Flower : virtual public Gift{

    string flowerType;

    public:

    static int stock; 

    Flower(){   }

    Flower(string flowerType, int quantity){

        stock -= quantity;
        revenue += (50*quantity);
    }

    void Bill(){

        cout << "Thank you for Purchasing flowers" <<endl;
    }
};

int Flower::stock = 50;



class Cake : virtual public Gift{

    int weight;

    public: 

    static int stock;

    Cake(int weight, int quantity){

        stock -= quantity;
        revenue += (weight *700 * quantity);
        tax += (weight * 700 * quantity) * 0.04;

    }

    void Bill(){

        cout << "thank you for Purchasing cakes" <<endl;
    }
};

int Cake::stock = 50;


class HB : public Perfume, public Flower, public Cake{

// 1 is quanttity here

    int profit;

    HB(string  brand, int flowerType): Perfume(brand,1), Flower(flowerType,1),Cake(weight,1)
    {
        
        // profit = price of perfume + price of Flowers
    }

    HB(string brand, int weight): Perfume(brand,1), Flower(flowerType,1),Cake(weight,1)
    {


    }

    HB(int weight, string flowerType): Perfume(brand,1), Flower(flowerType,1),Cake(weight,1)
    {


    }

}; 


class NineTails{

    //other variables.

    int taxAmount;
    int revenue;

    public:

    NineTails(){

        taxAmount = Gift::tax;
        revenue = Gift::revenue;
    }

    friend class TaxationDept;
};


class TaxationDept{

    public:

    TaxationDept(){

        cout << "Tax to be collected" <<endl;
    }
};