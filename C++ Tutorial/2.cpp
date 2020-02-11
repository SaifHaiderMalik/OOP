#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <typeinfo>
//#include <climits>
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
    auto whatAmI = 's';

    cout << "Min unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
    cout << "Max unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;
    cout << "Min unsigned int: " << numeric_limits<unsigned int>::min() << endl;
    cout << "Max unsigned int: " << numeric_limits<unsigned int>::max() << endl;
    cout << "Min unsigned long int: " << numeric_limits<unsigned long int>::min() << endl;
    cout << "Max unsigned long int: " << numeric_limits<unsigned long int>::max() << endl;
    cout << "Min unsigned long long int: " << numeric_limits<unsigned long long int>::min() << endl;
    cout << "Max unsigned long long int: " << numeric_limits<unsigned long long int>::max() << endl << endl;

    cout << "Min short int: " << numeric_limits<short int>::min() << endl;
    cout << "Max short int: " << numeric_limits<short int>::max() << endl;
    cout << "Min int: " << numeric_limits<int>::min() << endl;
    cout << "Max int: " << numeric_limits<int>::max() << endl;
    cout << "Min long int: " << numeric_limits<long int>::min() << endl;
    cout << "Max long int: " << numeric_limits<long int>::max() << endl;
    cout << "Min long long int: " << numeric_limits<long long int>::min() << endl;
    cout << "Max long long int: " << numeric_limits<long long int>::max() << endl << endl;

    cout << "Min UINT_8: " << UINT8_MAX << endl;
    cout << "Max UINT_16: " << UINT16_MAX << endl;
    cout << "Max UINT_32: " << UINT32_MAX << endl;
    cout << "Max UINT_64: " << UINT64_MAX << endl << endl;

    cout << "Min INT_8: " << INT8_MIN << endl;
    cout << "Max INT_8: " << INT8_MAX << endl;
    cout << "Min INT_16: " << INT16_MIN << endl;
    cout << "Max INT_16: " << INT16_MAX << endl;
    cout << "Min INT_32: " << INT32_MIN << endl;
    cout << "Max INT_32: " << INT32_MAX << endl;
    cout << "Min INT_64: " << INT64_MIN << endl;
    cout << "Max INT_64: " << INT64_MAX << endl << endl;

    cout << "Min float: " << numeric_limits<float>::min() << endl;
    cout << "Max float: " << numeric_limits<float>::max() << endl;
    cout << "Min double: " << numeric_limits<double>::min() << endl;
    cout << "Max double: " << numeric_limits<double>::max() << endl;
    cout << "Min long double: " << numeric_limits<long double>::min() << endl;
    cout << "Max long double: " << numeric_limits<long double>::max() << endl << endl;
    cout << typeid(whatAmI).name() << whatAmI;

    return 0;
}