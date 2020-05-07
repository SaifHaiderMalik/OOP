#include <iostream>

using namespace std;

template<class T1> double Add(T1 a, T1 b){

    return a+b;

}
template<class T1> double Sub(T1 a, T1 b){

    return a-b;
}
template<class T1> double Mul(T1 a, T1 b){

    return a*b;

}
template<class T1> double Div(T1 a, T1 b){

    return a/b;

}

int main(void){

    cout << Sub(5.1,2.1) <<endl;
}