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

class A;
void print(A a);


class A{
    int x;

public:
    A(){
        x = 1;
    }

    get() const{
        A a;
        print(a);
    }

    get_c(){
        x += 4;
        cout << "C";
    }
};

void print(A a){
    cout << "A";
    a.get_c();
}

int main(){
    A a1;
    a1.get();
}