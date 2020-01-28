#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

string menuItem[] = {"Plain Egg", "Bacon and Egg", "Muffin", "French Toast sssssss", "Fruit Basket", "Cereal", "Coffee", "Tea"};
double menuPrice[] = {1.45, 2.45, 0.99, 990.99, 2.49, 0.69, 0.50, 0.75};

struct menuItemType
{
    string menuItem;
    double menuPrice;
};

int main(){
    int orderNumber, maxLimit = int(sizeof(menuPrice)/sizeof(menuPrice[0]));
    double grandTotal = 0;
    int* orderList = new int[maxLimit]{};
    menuItemType* menuList = new menuItemType[maxLimit]{};

    cout << fixed << setprecision(2) << string(41, '-') << endl << string(19, ' ') << "MENU" << endl << string(41, '-') << endl << " ITEM No | ITEM NAME" << string(12, ' ') << "|  PRICE" << endl << string(9, '-')<< "|" << string(22, '-') << "|" << string(8, '-');

    for(int32_t i = 0; i < maxLimit; i++){
        menuList[i].menuItem = menuItem[i];
        menuList[i].menuPrice = menuPrice[i];
        cout << setw(8) << endl << i+1 << " | " << menuList[i].menuItem << setw(22-menuItem[i].length()) << "|" << setw(7) << menuList[i].menuPrice;
    }

    cout << endl << string(41, '-') << endl;

    do{
        cout << "Enter 'Item No' to Order OR '0' to Generate Bill: ";
        cin >> orderNumber;
        orderList[orderNumber-1]++;
    } while (orderNumber != 0);

    system("cls");

    cout << string(59, '-') << endl << string(14, ' ') << "Welcome to Johnny's Restaurant" << endl << string(59, '-') << endl << " SERIAL# | ITEM NAME" << string(12, ' ') << "|  PRICE" << " | QTY |     TOTAL" << endl << string(9, '-')<< "|" << string(22, '-') << "|" << string(8, '-') << "|" << string(5, '-') << "|" << string(11, '-');

    for (int i = 0, j = 1; i < maxLimit; i++){
        if (orderList[i] == 0){
            continue;
        }

        cout << setw(8) << endl << j++ << " | " << menuList[i].menuItem << setw(22-menuItem[i].length()) << "|" << setw(7) << menuList[i].menuPrice << " |" << setw(4) << orderList[i] << " |" << setw(10) << menuList[i].menuPrice*orderList[i];

        grandTotal += (menuList[i].menuPrice*orderList[i]);
    }

    cout << endl << string(59, '-') << endl << setw(48) << "SUBTOTAL |" << setw(10) << grandTotal << endl << setw(48) << "TAX (5%) |" << setw(10) << grandTotal*0.05 << endl << setw(48) << "AMOUNT DUE |" << setw(10) << grandTotal+grandTotal*0.05 << endl << string(59, '-');
    
    getch();
    return 0;
}