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
    srand(time(NULL));
    int secretNum = rand() % 11;
    int guess = 0;
    do{
        cout << "Guess the Number: ";
        cin >> guess;
        if(guess > secretNum){
            cout << "Too Big\n";
        }
        if(guess < secretNum){
            cout << "Too Small\n";
        }
    } while(secretNum != guess);
    cout << "You Guessed it." << endl;

    return 0;
}