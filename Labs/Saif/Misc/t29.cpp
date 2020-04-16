#include<iostream>

using namespace std;

// GENERIC FUNCTION / Template Function

//Overloaded only on the basis of Number of Parameters

template<class T> void display(T a){

    cout << "This is : " << a <<endl;

}


// overlaoded function different operations for different type of inputs

// overlaoded template same operation for different type of inputs


// Explicit Specialization

void display(int a){

    cout << "For int: " << a <<endl;

}

void display(float a){

    cout << "For Float: " << a <<endl;

}

int main(void){

    display(10);
    display(10.56);
    display("Hello");

}