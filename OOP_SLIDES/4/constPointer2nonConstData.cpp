/*
Always points to the same memory location,
but the data at that location can be modified through the pointer.
*/
#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int b = 20;
    int* const pA = &a;
    cout << a << "\t" << b << "\t" << pA << "\t" << *pA << "\n";
    *pA = 20;
    cout << a << "\t" << b << "\t" << pA << "\t" << *pA << "\n";
    //pA = &b; //Gives Error: Assignment of read-only variable
}