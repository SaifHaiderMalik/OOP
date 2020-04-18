#include<iostream>
using namespace std;

//Friend Function //Friend Classes

class A {

    int a;

    friend void func();

    public:

    int b = 100;

};


int zzz = 66;

//Without friend private member of class is not accesible
void func(){

    A ob;
    ob.a = 20;
    ob.b;
    

    cout << ob.a << endl;
    cout <<ob.b << endl;
}

int main(void){

    func();
}


