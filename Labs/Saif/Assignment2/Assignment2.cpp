#include <iostream>
#include <string>

using namespace std;

//Task b 
//Task c

class Gift{
    //inherited Gift class in flowers , perfume and cake.    
protected:
    string catID;
    int price;
    bool taxApplicable;
    int stock = 0;
    double taxPercent;
    int itemSold = 0;
    int weight;

private:
    //static functions in order to calculate the total tax and revenue
    static int tax;
    static int revenue;
    
public:
    
    // setter and getter functions
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
            itemSold++;
            calcRevTax(price, taxApplicable, taxPercent);
            cout << "Item Sold" << endl;
        }
        else{
            cout << "Stock has Depleted" << endl;
            return ;
        }
    }

    void Sale(int _weight){
        if(stock >= _weight){
            stock -= _weight;
            itemSold += _weight;
            price = _weight * 700;
            calcRevTax(price, taxApplicable, taxPercent);
            cout << "Item Sold" << endl;
        }
        else{
            cout << "Stock is Insufficient" <<endl;
        }
    }


    int getItemSold(){
        return itemSold;
    }

    string getCatID(){return catID;}
    int getPrice(){return price;}
    bool getTaxApplicable(){return taxApplicable;}
    int getStock(){return stock;}
    double getTaxPercent(){return taxPercent;}
    static int getRevenue(){return revenue;}
    static int getTax(){return tax;}


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

    //Task g
      Flowers(const Flowers &f){
        floralType = f.floralType ;
        catID = f.catID ;
        price = f.price;
        taxApplicable = f.taxApplicable;
    }

    //getter function

    string getFloralType(){return floralType;}

};



class Perfume : public Gift{
protected:
private:
    string brand;
    
public:

    Perfume(){}

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

    // setter and getter functions

    void setBrand(string _brand){

        if(_brand == "GUCCI"){
            brand = _brand;
        }
        else if(_brand == "VERSACE"){
            brand = _brand;
        }
        else if(_brand == "CHANEL"){
            brand = _brand;
        }
        else{
            cout << "Invalid Brand Name" <<endl;
        }
        
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

public:
    ChocolateCake(){
        catID = "CK1";
        taxApplicable = true;
        taxPercent = 0.04;
    }

    // setter and getter functions

    //replenish stocks
    void repStock(int _stock){
        stock += _stock;
    }

    void setWeight(int _weight){
        weight = _weight;
    }

    int getWeight(){return weight;}

    void setMsgOnCake(string _msgOnCake){
        msgOnCake = _msgOnCake;
    }

    void Sale(int _weight){
        if(stock >= _weight){
            stock -= _weight;
            itemSold += _weight;
            price = _weight * 700;
            calcRevTax(price, taxApplicable, taxPercent);
            cout << "Item Sold" << endl;
        }
        else{
            cout << "Stock is Insufficient" <<endl;
        }
    }
};

class HappyBundle : public Gift{
protected:

    int totalPrice;

private:
public:

    HappyBundle(){}

    HappyBundle(Flowers _flower, Perfume _perfume){
       catID = "HB1";
       totalPrice = _flower.getPrice() + _perfume.getPrice(); 
    }

    HappyBundle(Flowers _flower, ChocolateCake _cake){
        catID = "HB1";
        totalPrice = _flower.getPrice() + _cake.getPrice();
    }

    HappyBundle(Perfume _perfume, ChocolateCake _cake){
        catID = "HB1";
        totalPrice = _perfume.getPrice() + _cake.getPrice();
    }

    // setter and getter functions

    void Sale(Flowers& _flower, Perfume& _perfume){
        if(_flower.getStock() > 0 && _perfume.getStock() > 0)
        {
            _flower.Sale();
            _perfume.Sale();
        }
        else{
            cout << "Out of Stock!" << endl;
        }
    }

    void Sale(Flowers& _flower, ChocolateCake& _cake){
        if(_flower.getStock() > 0 && _cake.getStock() >= _cake.getWeight()){
            _flower.Sale();
            _cake.Sale(_cake.getWeight());
        }
        else{
            cout << "Out of Stock!" << endl;
        }
    }

    void Sale(Perfume& _perfume, ChocolateCake& _cake){
        if(_perfume.getStock() > 0 && _cake.getStock() >= _cake.getWeight()){
            _perfume.Sale();
            _cake.Sale(_cake.getWeight());
        }
        else{
            cout << "Out of Stock!" << endl;
        }
        
    }


    bool operator >(const HappyBundle& h){

        if(totalPrice > h.totalPrice){
            return true;
        }
        else{
            return false;
        }
    }

};


class TaxationDept{
protected:
private:
public:
    // Getter function which return the value in gift class without inheriting gift to taxationDept
    // Task h
    int getTax(){return Gift::getTax();}
    int getRevenue(){return Gift::getRevenue();}

};


class NineTails{
protected:

private:
    string contactNo;
    string address;
    string email;

public:

// setter and getter functions

    void setContact(string _contactNo){
        contactNo = _contactNo;
    }

    void setAddress(string _address){
        address = _address;
    }

    void setEmail(string _email){
        email = _email;
    }

    string getContact(){return contactNo;}
    string getAddress(){return address;}
    string getEmail(){return email;}
};



int Gift::revenue = 0;
int Gift::tax = 0;


int main(void){

    int choice,stock,weight;
    string contact,address,email,message;
    int flowerType;
    int perfumeBrand;

 //Task a
    NineTails NT;
    Gift g1;
    TaxationDept TD;

    Perfume Gucci("GUCCI");
    Perfume Versace("VERSACE");
    Perfume Chanel("CHANEL");

    Flowers Rose("ROSE");
    Flowers Tulip("TULIP");
    Flowers Daisy("DAISY");

    ChocolateCake Cake;

    HappyBundle H1(Rose,Gucci);
    HappyBundle H2(Rose,Versace);
    HappyBundle H3(Rose,Chanel);
    HappyBundle H4(Rose,Cake);
    HappyBundle H5(Tulip,Gucci);
    HappyBundle H6(Tulip,Versace);
    HappyBundle H7(Tulip,Chanel);
    HappyBundle H8(Tulip,Cake);
    HappyBundle H9(Daisy,Gucci);
    HappyBundle H10(Daisy,Versace);
    HappyBundle H11(Daisy,Chanel);
    HappyBundle H12(Daisy,Cake);
    HappyBundle H13(Gucci, Cake);
    HappyBundle H14(Versace, Cake);
    HappyBundle H15(Chanel, Cake);

//  Stock Items
    Gucci.repStock(20);
    Versace.repStock(20);
    Chanel.repStock(20);

    Rose.repStock(25);
    Tulip.repStock(25);
    Daisy.repStock(25);

    Cake.repStock(40);

    // MENU label to come to the menu interface using goto MENU (similarly done for other labels)
    MENU:
    system("cls");
    cout << "\t1. Inventory Management\n\t2. Order Menu\n\t3. Taxation Department\n\t4. EXIT\n"
         << endl << "\t Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        goto INVENTORY;
        break;

    case 2:
        system("cls");
        cout << "Enter Contact No.: " <<endl;
        cin >> contact;
        NT.setContact(contact);
        cout << "Enter Address: " <<endl;
        cin >> address;
        NT.setAddress(address);
        cout << "Enter Email: " <<endl;
        cin >> email;
        NT.setEmail(email);
        
        goto ORDER;
        break;
    
    case 3:
        goto TAXDEPT;
        break;

    case 4:
        exit(0);
        break;

    default:
        break;
    }

    //Task f
    INVENTORY:
    system("cls");
    cout << "\t1. Check Stock\n\t2. Replenish Stock\n\t3. Go To Main Menu\n\t4. EXIT\n"
         << endl << "\t Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "FLOWERS:\nFloral Type\tIn Stock\tSold" << endl
             << Rose.getFloralType() << "\t\t" << Rose.getStock() << "\t\t" << Rose.getItemSold() << "\n"
             << Tulip.getFloralType() << "\t\t" << Tulip.getStock() << "\t\t" << Tulip.getItemSold() << "\n"
             << Daisy.getFloralType() << "\t\t" << Daisy.getStock() << "\t\t" << Daisy.getItemSold() << "\n" <<endl;
        
        cout << "PERFUMES:\nBrand\t\tIn Stock\tSold" << endl
             << Gucci.getBrand() << "\t\t" << Gucci.getStock() << "\t\t" << Gucci.getItemSold() << "\n"
             << Versace.getBrand() << "\t\t" << Versace.getStock() << "\t\t" << Versace.getItemSold() << "\n"
             << Chanel.getBrand() << "\t\t" << Chanel.getStock() << "\t\t" << Chanel.getItemSold() << "\n" << endl;
        
        cout << "CAKES:\nFlavor\t\tIn Stock\tSold" << endl
             << "Chocolate Cake\t" << Cake.getStock() << " Pounds\t" << Cake.getItemSold() << " Pounds\n" << endl;
        system("pause");
        goto INVENTORY;
        break;

    case 2:
        system("cls");
        cout << "\t1. Flowers\n\t2. Perfumes\n\t3. Cake\n\t4. Go Back" << endl << "\t Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t1. Rose\n\t2. Tulip\n\t3. Daisy" << endl << "\t Enter Choice: ";
            cin >> choice;
            cout << "Enter quantity of stock to replenish: ";
            cin >> stock;

            if(choice == 1){
                Rose.repStock(stock);
            }
            else if(choice == 2){
                Tulip.repStock(stock);
            }
            else if(choice == 3){
                Daisy.repStock(stock);
            }
            else{
                cout << "invalid Choice entered" << endl;
            }

            goto INVENTORY;
            break;
        
        case 2:
            cout << "\t1. Gucci\n\t2. Versace\n\t3. Chanel" << endl << "\t Enter Choice: ";
            cin >> choice;
            cout << "Enter quantity of stock to replenish: ";
            cin >> stock;

            if(choice == 1){
                Gucci.repStock(stock);
            }
            else if(choice == 2){
                Versace.repStock(stock);
            }
            else if(choice == 3){
                Chanel.repStock(stock);
            }
            else{
                cout << "invalid Choice entered" <<endl;
            }

            goto INVENTORY;
            break;

        case 3:
            cout << "\tCake" << endl;
            cout << "Enter quantity of stock to replenish: ";
            cin >> stock;

            Cake.repStock(stock);

            goto INVENTORY;
            break;

        default:
            cout << "Invalid Choice Entered" <<endl;

            goto INVENTORY;
            break;
        }

        break;

    case 3:
        goto MENU;
        break;

    case 4:
        exit(0);
        break;
    
    default:
        cout << "Invalid Choice Entered" <<endl;

        goto INVENTORY;
        break;
    }


    ORDER:
    system("cls");
    cout << "\t1. Flowers\n\t2. Perfumes\n\t3. Chocolate Cake\n\t4. Happy Bundles\n\t5. Go To Main Menu\n\t6. EXIT\n"
         << endl << "\t Enter Choice: ";
    cin >> choice;
    cout << NT.getContact() << "\t" << NT.getAddress() << "\t" << NT.getEmail() << endl;

    switch (choice)
    {
    case 1:
        cout << "Choose Type of Flower:\n\t1. Rose\n\t2. Tulip\n\t3. Daisy" <<endl;
        cin >> choice;

        if(choice == 1){
            Rose.Sale();
        }
        else if(choice == 2){
            Tulip.Sale();
        }
        else if(choice == 3){
            Daisy.Sale();
        }
        else{
            cout <<"Invalid Choice Entered" <<endl;
        }

        system("pause");
        goto ORDER;    
        break;

    case 2:
        cout << "Choose Brand of Perfume:\n\t1. Gucci\n\t2. Versace\n\t3. Chanel" <<endl;
        cin >> choice;

        if(choice == 1){
            Gucci.Sale();
        }
        else if(choice == 2){
            Versace.Sale();
        }
        else if(choice == 3){
            Chanel.Sale();
        }
        else{
            cout <<"Invalid Choice Entered" <<endl;
        }
        
        system("pause");
        goto ORDER;    
        break;

    case 3:
        cout << "Enter weight of Cake in pounds: " <<endl;
        cin >> weight;
        cout << "Enter Message on Cake" <<endl;
        cin >> message;

        Cake.setMsgOnCake(message);
        Cake.Sale(weight);
       
        system("pause");
        goto ORDER;    
        break;

    case 4:
        goto BUNDLE;
        break;

    case 5:
        goto MENU;
        break;

    case 6:
        exit(0);
        break;
    
    default:
        break;
    }


    BUNDLE:
    system("cls");
    cout << "\t1. Flower & Perfume\n\t2. Flower & Chocolate Cake\n\t3. Perfume & Chocolate Cake\n\t4. Go To Order Menu\n\t5. EXIT\n"
         << endl << "\t Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Choose Type of Flower:\n\t1. Rose\n\t2. Tulip\n\t3. Daisy" <<endl;
        cin >> flowerType;
        cout << "Choose Brand of Perfume:\n\t1. Gucci\n\t2. Versace\n\t3. Chanel" <<endl;
        cin >> perfumeBrand;
        
        if(flowerType == 1 && perfumeBrand == 1){
            H1.Sale(Rose, Gucci);
        }
        else if(flowerType == 1 && perfumeBrand == 2){
            H2.Sale(Rose, Versace);
        }
        else if(flowerType == 1 && perfumeBrand == 3){
            H3.Sale(Rose, Chanel);
        }
        else if(flowerType == 2 && perfumeBrand == 1){
            H5.Sale(Tulip, Gucci);
        }
        else if(flowerType == 2 && perfumeBrand == 2){
            H6.Sale(Tulip, Versace);
        }
        else if(flowerType == 2 && perfumeBrand == 3){
            H7.Sale(Tulip, Chanel);
        }
        else if(flowerType == 3 && perfumeBrand == 1){
            H9.Sale(Daisy, Gucci);
        }
        else if(flowerType == 3 && perfumeBrand == 2){
            H10.Sale(Daisy, Versace);
        }
        else if(flowerType == 3 && perfumeBrand == 3){
            H11.Sale(Daisy, Chanel);
        }
       
        system("pause");
        goto ORDER;    
        break;
    
    case 2:
        cout << "Choose Type of Flower:\n\t1. Rose\n\t2. Tulip\n\t3. Daisy" << endl;
        cin >> flowerType;

        if(choice == 1){
            cout << "Enter weight of Chocolate Cake: " << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H4.Sale(Rose, Cake);
        }
        else if(choice == 2){
            cout << "Enter weight of Chocolate Cake" << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H8.Sale(Tulip,Cake);
        }
        else if(choice == 3){
            cout << "Enter weight of Chocolate Cake" << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H12.Sale(Daisy,Cake);
        }
        else{
            cout <<"Invalid Choice Entered" << endl;
        }

        system("pause");
        goto ORDER;
        break;

    case 3:
        cout << "Choose Brand of Perfume:\n\t1. Gucci\n\t2. Versace\n\t3. Chanel" <<endl;
        cin >> perfumeBrand;
        if(choice == 1){
            cout << "Enter weight of Chocolate Cake: " << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H13.Sale(Gucci, Cake);
        }
        else if(choice == 2){
            cout << "Enter weight of Chocolate Cake" << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H14.Sale(Versace,Cake);
        }
        else if(choice == 3){
            cout << "Enter weight of Chocolate Cake" << endl;
            cin >> weight;
            Cake.setWeight(weight);
            H15.Sale(Chanel,Cake);
        }
        else{
            cout <<"Invalid Choice Entered" << endl;
        }

        system("pause");
        goto ORDER;
        break;

    case 4:
        goto ORDER;
        break;

    case 5:
        exit(0);
        break;
    
    default:
        break;
    }


    TAXDEPT:
    system("cls");
    cout << "\t1. Check Revenue\n\t2. Check Tax\n\t3. Go To Main Menu\n\t4. EXIT\n"
         << endl << "\t Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Revenue: " << TD.getRevenue();
        system("pause");
        goto TAXDEPT;
        break;
    
    case 2:
        cout << "Tax: " << TD.getTax();
        system("pause");
        goto TAXDEPT;
        break;
    
    case 3:
        goto MENU;
        break;
    
    case 4:
        exit(0);
        break;
    
    default:
        break;
    }





    // Task (d)

    /*
    Gift* ob = new Perfume;

    ob->setCatID("PF1");
    cout << "ID: " << ob->getCatID() <<endl;
    ob->repStock(10);
    cout << "Stock: " << ob->getStock() <<endl;
    ob->setPrice(1200);
    cout << "Price: " << ob->getPrice() <<endl;
    ob->setTaxApplicable(true);
    cout << "Tax Applicable: " << ob->getTaxApplicable() <<endl;
    ob->setTaxPercentage(0.07);
    cout << "TaxPercent: " <<ob->getTaxPercent();
    ob->Sale();
    cout << "Revenue: " << ob->getRevenue() <<endl;
    cout << "Tax: " << ob->getTax();*/



    // Task e
    /*
    HappyBundle HA(Rose, Gucci);
    HappyBundle HB(Daisy, Versace);
    HappyBundle HC(Tulip, Chanel);

    cout << "HA(Rose, Gucci)\nHB(Daisy, Versace)\nHC(Tulip, Chanel)" << endl;
    cout << boolalpha;
    cout << "(HA > HB): " << (HA > HB) << endl;
    cout << "(HA > HC): " << (HA > HC) << endl;
    cout << "(HB > HA): " << (HB > HA) << endl;
    cout << "(HB > HC): " << (HB > HC) << endl;
    cout << "(HC > HA): " << (HC > HA) << endl;
    cout << "(HC > HB): " << (HC > HB) << endl;
    */
}