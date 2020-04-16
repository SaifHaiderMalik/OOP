#include<iostream>

using namespace std;

// GENERIC FUNCTION / Template Function


template<class T> void display(T a, int b){

    cout << "This is : " << a <<endl;
    cout << "This is : " << b <<endl;

}



int main(void){

    display('c', 3);

}