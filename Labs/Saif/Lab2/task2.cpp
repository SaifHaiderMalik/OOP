#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void showChoices();
void feetAndInchesToMetersAndCent(int _inches, int& _centimeter);
void metersAndCentTofeetAndInches(int _centimeter,int& _inches);

int main(void){

    showChoices();
}

void showChoices(){

        int choice;
        int feet;
        int inches;
        int meter;
        int centimeter;
       
        cout << "Press 1 to Convert feet and inches to meters and centimeter" << endl;
        cout << "Press 2 to Convert meters and centimeters into feet and inches" << endl;
        cout << "Press 0 to exit"; 
        cin >> choice;

        switch(choice){

            case 1:
                
                cout << "Enter Feet and Inches";
                cin >> feet >> inches;
                inches = inches + feet*12;
                feetAndInchesToMetersAndCent(inches, centimeter);
                cout << "Result:    " << "Meters:   " << centimeter/100 << "Centimeters:    " << centimeter%100;

                getch();
                main();
             
                break;

            case 2:
                
                cout << "Enter Meter and Centimeter";
                cin >> meter >> centimeter;
                centimeter = centimeter + meter*100;
                metersAndCentTofeetAndInches(centimeter,inches);
                cout << "Result:    " << "Feet:   " << inches/12 <<  "inches:   " << inches%12 ;

                main();
             
                break;


            case 0:

                return ;    
        }

}

void feetAndInchesToMetersAndCent(int _inches, int& _centimeter){

    _centimeter = _inches * 2.54;
    
}

void metersAndCentTofeetAndInches(int _centimeter, int& _inches){

        _inches = _centimeter/2.54;
}

