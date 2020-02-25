#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float weightInKg;
    cout << "Enter Weight in Kilograms: ";
    cin >> weightInKg;
    float weightInPound = weightInKg*2.2;
    cout << fixed << setprecision(2); //Format output with two decimal places
    cout << "Weight in Kilograms is: " << weightInKg << endl;
    cout << "Weight in Pounds is: " << weightInPound;
}