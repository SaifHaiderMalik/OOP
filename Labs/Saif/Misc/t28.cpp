#include<iostream>

using namespace std;

// GENERIC FUNCTION / Template Function

//Overloaded only on the basis of Number of Parameters

template<class T> void display(T a){

    cout << "This is : " << a <<endl;

}


template<class T1, class T2> void display(T1 a, T2 b){

    cout << "This is: " << a <<endl;
    cout << "And This is : " << b <<endl;

}


int main(void){

    display(4);
    display(5, 'c');

}