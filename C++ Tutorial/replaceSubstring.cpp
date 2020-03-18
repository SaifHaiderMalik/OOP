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

string ReplaceAllSubstring(string theString, string substring, string newString);

int main(){
    cout << ReplaceAllSubstring("to know or not to know", "know", "be") << endl;
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

string ReplaceAllSubstring(string theString, string substring, string newString){
    vector<int> matches = FindSubstringMatches(theString, substring);
    if(matches.size() != 0){
        int lengthDifference = newString.size() - substring.size();
        int timesLooped = 0;
        for(auto index : matches){
            theString.replace(index + (timesLooped * lengthDifference), substring.size(), newString);
            timesLooped++;
        }
    }
    return theString;
}