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
    vector<int> vNums(2);
    vNums[0] = 1;
    vNums[1] = 2;
    vNums.push_back(3);
    cout << "Vector Size: " << vNums.size();
    return 0;
}