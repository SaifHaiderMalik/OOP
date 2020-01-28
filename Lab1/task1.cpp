#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main(){
    float weightKilograms, weightPounds;

    cout << "Please Enter weight in Kilograms : ";
    cin >> weightKilograms;

    weightPounds = weightKilograms*2.2;

    cout << "Weight in Kilograms : " << fixed << setprecision(2) << weightKilograms << endl << "Weight in Pounds : " << weightPounds;

    getch();
    return 0;
}