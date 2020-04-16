#include<iostream>
using namespace std;

class A{

    public:
    A(int x){

        cout << "IN A " <<endl;
    }

    A(){

        cout << "\nA Default Constructor Called\n";


    }
};

class B: public A{

    public:
    B(int y):A(y){

        cout << "IN B" <<endl;
    }

    B(){
        cout << "\nB Default Constructor Called\n";

    }
};

class C: public B{

    public:
    /*C(int z):B(z){

        cout << "IN C" <<endl;
    }*/

    C(int z){

        cout << "IN C" <<endl;
    }
};

int main(){

    C ob(5);

}
