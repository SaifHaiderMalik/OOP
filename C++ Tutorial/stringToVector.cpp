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

vector<string> StringToVector(string theString, char seprator);

int main(){
    vector<string> vec = StringToVector("This is Random String", ' ');
    for(auto v : vec){
        cout << v << endl;
    }

    return 0;
}

vector<string> StringToVector(string theString, char seprator){
    vector<string> vecWords;
    stringstream ss(theString);
    string sIndivStr;
    while(getline(ss, sIndivStr, seprator)){
        vecWords.push_back(sIndivStr);
    }
    return vecWords;
}