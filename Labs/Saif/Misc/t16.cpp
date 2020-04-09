#include<iostream>
using namespace std;

//Friend Function //Friend Classes

class A {

    int a;


    friend void func();

};


//Without friend private member of class is not accesible
void func(){

    A ob;
    ob.a = 20;

    cout << ob.a;
}

int main(void){

    func();
}


