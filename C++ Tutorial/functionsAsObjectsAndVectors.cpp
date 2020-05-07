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
#include <bits/stdc++.h> //sort() & function()
#include <algorithm> //copy_if()

using namespace std;

double MultBy2(double num){
    return num * 2;
};

double MultBy3(double num){
    return num * 3;
};

double DoMath(function<double(double)> func, double num){
    return func(num);
};

int main(){
    auto times2 = MultBy2;
    cout << "5 * 2 = " << times2(5) << endl;
    cout << "6 * 2 = " << DoMath(times2, 6) << endl;
    cout << "6 * 3 = " << DoMath(MultBy3, 6) << endl;

    vector<function<double(double)>> funcs(2);
    funcs[0] = MultBy2;
    funcs[1] = MultBy3;
    cout << "10 * 2 = " << funcs[0](10) << endl;
    cout << "10 * 3 = " << funcs[1](10) << endl;
    return 0;
}