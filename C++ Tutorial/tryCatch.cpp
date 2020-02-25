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
        if(num2 == 0){
            throw "Division by Zero Error";
        }
        else{
            cout << num1 / num2 << endl;
        }
    }
    catch(const char* exp){
        cerr << "Error: " << exp << endl;
    }
    
    return 0;
}