#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
}; 

int main() {
    menuItemType menuList[8];

    menuList[0].menuItem = {"Plain Egg"};
    menuList[0].menuPrice = 1.45;
    menuList[1].menuItem = {"Bacon and Egg"};
    menuList[1].menuPrice = 2.45;
    menuList[2].menuItem = {"Muffin"};
    menuList[2].menuPrice = 0.99;
    menuList[3].menuItem = {"Franch Toast"};
    menuList[3].menuPrice = 1.99;
    menuList[4].menuItem = {"Fruit Basket"};
    menuList[4].menuPrice = 2.49;
    menuList[5].menuItem = {"Cereal"};
    menuList[5].menuPrice = 0.69;
    menuList[6].menuItem = {"Coffe"};
    menuList[6].menuPrice = 0.50;
    menuList[7].menuItem = {"Tea"};
    menuList[7].menuPrice = 0.75;

    float totalBill, tax, amountDue = 0;
    int order, quantity;

    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << "::MENU LIST::" << endl;
    for(int i = 0; i <= 7; i++){
        cout << "ITEM# " << (i + 1) << ": " << menuList[i].menuItem << " $" << menuList[i].menuPrice << endl;
    }
    cout << "OR Enter '0' to Quit" << endl;
    cout << endl << "Enter Number of Items to Order: "; 
    cin >> quantity;

    for(;quantity > 0;quantity--){

        cout << "Enter 'Item Code' or '0' to Quit and Calculate Bill: ";
        cin >> order;
        
        switch(order){

            case 0: 
                cout << "You have Quit" << endl;
                quantity = 0;
                break;

            case 1: 
                cout << "You have ordered " << menuList[0].menuItem<< " $" << menuList[0].menuPrice << endl;
                amountDue = amountDue + menuList[0].menuPrice;
                break;

            case 2:
                cout << "You have ordered " << menuList[1].menuItem<< " $" << menuList[1].menuPrice << endl;
                amountDue = amountDue + menuList[1].menuPrice;
                break;

            case 3:
                cout << "You have ordered " << menuList[2].menuItem<< " $" << menuList[2].menuPrice << endl;
                amountDue = amountDue + menuList[2].menuPrice;
                break;

            case 4:
                cout << "You have ordered " << menuList[3].menuItem<< " $" << menuList[3].menuPrice << endl;
                amountDue = amountDue + menuList[3].menuPrice;
                break;
            
            case 5:
                cout << "You have ordered " << menuList[4].menuItem<< " $" << menuList[4].menuPrice << endl;
                amountDue = amountDue + menuList[4].menuPrice;
                break;

            case 6:
                cout << "You have ordered " << menuList[5].menuItem<< " $" << menuList[5].menuPrice << endl;
                amountDue = amountDue + menuList[5].menuPrice;
                break;

            case 7:
                cout << "You have ordered " << menuList[6].menuItem << " $" << menuList[6].menuPrice << endl;
                amountDue = amountDue + menuList[6].menuPrice;
                break;

            case 8:
                cout << "You have ordered " << menuList[7].menuItem << " $" << menuList[7].menuPrice << endl;
                amountDue = amountDue + menuList[7].menuPrice;
                break;    

            default:
                cout << "Error"<< endl;
                break;                      
        }
    }

    tax = amountDue * 0.05;
    totalBill = amountDue + tax;

    cout << fixed << setprecision(2); //Format output with two decimal places
    cout << "BILL GENERATED";
    cout << endl << "Tax: $" << tax;
    cout << endl << "Amount Due: $" << totalBill;
}