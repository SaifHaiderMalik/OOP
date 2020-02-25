#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <fstream> //file operations
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>
#include <bits/stdc++.h> //sort()
#include <algorithm> //copy_if()

using namespace std;

int main(){
    vector<int> myVec(10);
    iota(begin(myVec), end(myVec), 0);
    for(int i = 0; i < myVec.size(); ++i){
        cout << myVec[i] << endl;
    }

    for(auto i : myVec){
        cout << myVec[i] << endl;
    }
}