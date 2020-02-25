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
    vector<string> words;
    stringstream ss("Some Random Words");
    string word;
    while(getline(ss, word, ' ')){
        words.push_back(word);
    }

    for(int i = 0; i < words.size(); i++){
        cout << words[i] << endl;
    }

    int arr3[] = {1, 2, 3};
    for(auto x: arr3){
        cout << x << endl;
    }
}