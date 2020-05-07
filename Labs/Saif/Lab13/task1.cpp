#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2> double Add(T1 a, T2 b){

    return a+b;

}

template<class T1, class T2> double Subtract(T1 a, T2 b){

    return a-b;

}

template<class T1, class T2> double Multiply(T1 a, T2 b){

    return a*b;

}

template<class T1, class T2> double Divide(T1 a, T2 b){

    return (a/b);

}


int main(void){

    cout << Add(5,36.75) <<endl;
    cout << Subtract(5,2) <<endl;
    cout << Multiply(25.37,2) <<endl;
    cout << Divide(25,5) <<endl;

}
