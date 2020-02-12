#include <iostream>
using namespace std;

int main(){
    float weightInKg;
    cout << "Enter Weight in kilograms";
    cin >> weightInKg;
    float weightInPound = weightInKg*2.2;
    cout << "Weight in Kg is:" << weightInKg << "Weight in Pound is:" << weightInPound;
}