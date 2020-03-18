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

string VectorToString(vector<string>& vec, char seprator);

int main(){
    vector<string> vCusts(3);
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";

    string sCusts = VectorToString(vCusts, ' ');
    cout << sCusts << endl;

    return 0;
}

string VectorToString(vector<string>& vec, char seprator){
    string theString;
    for(auto cust : vec){
        theString += cust + seprator;
    }
    
    return theString;
}