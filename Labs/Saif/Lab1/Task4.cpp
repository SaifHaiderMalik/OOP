#include <iostream>
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

    float totalBill;
    float amountDue;
    int order;

    cout << "Press 1 for Plain Egg  $1.45\n Press 2 for Bacon and Egg   $2.45 \n Press 3 for Muffin $0.99\n Press 4 for french Toast    $1.99\n";
    cout << "Press 5 for Fruit Basket   $2.49\n Press 6 for Cereal    $0.69\n press 7 for Coffe  $0.50\n Press 8 for Tea    $0.75"; 
    cout << "Press 0 to Quit";

    while(order != 0){
        
        

    }



}