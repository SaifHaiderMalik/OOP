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

class A{
    int x;
public:
    A(int x){
        this->x = x;
    }

    display(int x){
        cout << this->x << endl;
        cout << x;
    }
    display2(int x){
        cout << this->x << endl;
        cout << x;
    }
};

int main(){
    A a(77);
    a.display(88);
}