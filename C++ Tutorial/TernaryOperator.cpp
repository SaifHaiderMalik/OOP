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
    int age43 = 43;
    bool canVote = (age43 >= 43) ? true : false;
    cout << "Can I vote: " << canVote << endl;
    cout.setf(ios::boolalpha);
    cout << "Can I vote: " << canVote << endl;
}