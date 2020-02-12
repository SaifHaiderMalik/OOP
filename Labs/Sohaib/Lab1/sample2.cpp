//Program to read five numbers, find their sum, and
//print the numbers in reverse order.

#include <iostream>

using namespace std;

int main(){
    int item[5]; //Declare an array item of five components
    int sum = 0;
    int counter;

    cout << "Enter five numbers: ";

    for (counter = 0; counter < 5; counter++){
        cin >> item[counter];
        sum += item[counter];
    }

    cout << endl;

    cout << "The sum of the numbers is: " << sum << endl;
    cout << "The numbers in reverse order are: ";

    //Print the numbers in reverse order.
    for (counter = 4; counter >= 0; counter--){
        cout << item[counter] << " ";
    }
    cout << endl;
    
    return 0;
}