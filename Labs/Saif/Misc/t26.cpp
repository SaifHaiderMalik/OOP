#include<iostream>

using namespace std;

// GENERIC FUNCTION / Template Function


template<class T1, class T2> void display(T1 a, T2 b){

    cout << "This is : " << a <<endl;
    cout << "This is : " << b <<endl;

}



int main(void){

   display(30 , 'c');
   display('B', 20);
   display("hello", "world"); // Specialization of Function is not done so no Error
   display(4.5, 2);

}