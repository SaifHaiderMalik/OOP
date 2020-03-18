#include<iostream>
using namespace std;

class A{

    public:
    A(int x){

        cout << "IN A " <<endl;
    }

    A(){


    }
};

class B: public A{

    public:
    B(int y):A(y){

        cout << "IN B" <<endl;
    }

    B(){

    }
};

class C: public B{

    public:
    C(int z):B(z){

        cout << "IN C" <<endl;
    }
};

int main(){

    C ob(5);

}
