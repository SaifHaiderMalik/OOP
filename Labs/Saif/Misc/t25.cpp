#include<iostream>

using namespace std;

// GENERIC FUNCTION / Template Function


template<class T> void display(T a){

    cout << "This is : " << a <<endl;

}



int main(void){

   display(30);
   display('B');
   display("hello");
   display(4.5);

}