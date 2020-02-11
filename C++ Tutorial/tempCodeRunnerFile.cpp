#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>

using namespace std;

int imGlobal = 0; //Global variable available to every function residing in this file
const double PI = 3.141; //Constant varianble it won't change

int main(){
    cout << "Hello World" << endl;
    bool married = true;
    char myGrade = 'A';

    cout << "Min unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
    cout << "Max unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;
    cout << "Min unsigned int: " << numeric_limits<unsigned int>::min() << endl;
    cout << "Max unsigned int: " << numeric_limits<unsigned int>::max() << endl;
    cout << "Min unsigned long int: " << numeric_limits<unsigned long int>::min() << endl;
    cout << "Max unsigned long int: " << numeric_limits<unsigned long int>::max() << endl;
    cout << "Min unsigned long int: " << numeric_limits<unsigned long long int>::min() << endl;
    cout << "Max unsigned long int: " << numeric_limits<unsigned long long int>::max() << endl;

    return 0;
}