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

vector<int> FindSubstringMatches(string theString, string substring);

int main(){
    string phrase = "To be or not to be but be";
    vector<int> matches = FindSubstringMatches(phrase, "be");
    for(int i = 0; i < matches.size(); ++i){
        cout << matches[i] << endl;
    }
    return 0;
}

vector<int> FindSubstringMatches(string theString, string substring){
    vector<int> matchingIndexes;
    int index = theString.find(substring, 0);
    while(index != string::npos){
        matchingIndexes.push_back(index);
        index = theString.find(substring, index + 1);
    }
    return matchingIndexes;
}