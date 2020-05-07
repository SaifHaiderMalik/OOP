#include<iostream>
#include<string>

using namespace std;


template<class T1, class T2> void Swap(T1* a, T2*b){

    cout << "Before Swapping:" <<endl;
    cout << "A: " << *a << endl;
    cout << "B: " << *b << endl;

    double* temp;

    *temp = *a;
    *a = *b;
    *b = *temp;

    cout << "After Swapping: " <<endl;
    cout << "A: " << *a << endl;
    cout << "B: " << *b << endl;

}


int main(void){

    double a,b;

    cout << "Enter Number 1: " <<endl;
    cin >> a;

    cout << "Enter Number 2: " <<endl;
    cin >> b;

    Swap(&a,&b);

}
