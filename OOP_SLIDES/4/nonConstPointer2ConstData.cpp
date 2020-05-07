/*
Pointer can be modified to point to any other data,
but the data to which it points cannot be modified through that pointer.
*/
#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int b = 20;

    const int* pA = &a;
    cout << a << "\t" << b << "\t" << pA << "\t" << *pA << "\n";
    //*pA = 20; //Gives Error: assignment of read-only location
    pA = &b;
    cout << a << "\t" << b << "\t" << pA << "\t" << *pA << "\n";
    return 0;
}