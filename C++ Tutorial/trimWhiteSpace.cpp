#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

string TrimWhiteSpaces(string theString);

int main(){
    string aStr = "  \n\t These  Are    Just Some Random Words    ";
    cout << "*" << aStr << "*" << endl;
    aStr = TrimWhiteSpaces(aStr);
    cout << "*" << aStr << "*";

    return 0;
}

string TrimWhiteSpaces(string theString){
    string whiteSpaces(" \t\f\n\r");
    theString.erase(theString.find_last_not_of(whiteSpaces) + 1);
    theString.erase(0, theString.find_first_not_of(whiteSpaces));

    return theString;
}