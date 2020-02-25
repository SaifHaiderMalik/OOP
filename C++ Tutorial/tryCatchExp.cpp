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

int main(){
    double num1 = 10, num2 = 0;
    try{
        cout << "Throwing Exception\n";
        throw runtime_error("Error Occured");
        cout << "Can you print me?\n";
    }
    catch(const exception &e){
        cerr << "Handled Exception : " << e.what() << '\n';
    }
    
    return 0;
}