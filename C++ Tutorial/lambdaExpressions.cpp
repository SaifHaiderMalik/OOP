#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
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

vector<int> GenerateRandomVect(int numOfNums, int min, int max);

int main(){
    vector<int> vecVals = GenerateRandomVect(10, 1, 50);

    cout << "Unsorted Random Vector" << endl;
    for(auto val:vecVals){
        cout << val << endl;
    }

    sort(vecVals.begin(), vecVals.end(), [](int x, int y){return x < y;});

    cout << endl << "Sorted Random Vector" << endl;
    for(auto val:vecVals){
        cout << val << endl;
    }

    vector<int> evenVecVals;
    copy_if(vecVals.begin(), vecVals.end(), back_inserter(evenVecVals), [](int x){return (x % 2) == 0;});
    cout << endl << "Even Sorted Random Vector" << endl;
    for(auto val:evenVecVals){
        cout << val << endl;
    }

    int sum = 0;
    for_each(vecVals.begin(), vecVals.end(), [&](int x){sum += x;});
    cout << endl << "Sum of Random Vector" << endl;
    cout << sum << endl;

    int eSum = 0;
    for_each(evenVecVals.begin(), evenVecVals.end(), [&](int x){eSum += x;});
    cout << endl << "Sum of Even Random Vector" << endl;
    cout << eSum << endl;

    return 0;
}

vector<int> GenerateRandomVect(int numOfNums, int min, int max){
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randValues = 0;
    while(i < numOfNums){
        randValues = min + rand() % ((max + 1) - min);
        vecValues.push_back(randValues);
        i++;
    }
    return vecValues;
}