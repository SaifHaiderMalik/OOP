#include<iostream>
using namespace std;

class A{

    public:


};


class B: public A{

    public:

    void func(){

        cout << "this is B" <<endl;
    }

};

class C: public B{

    public:

    void func(){

        cout << "This is C" <<endl;
    }

};

//If func in class B not present then parent class func will be executed if not in parent then grandparent. 

//Function ki body mein code irrelevant to overloading and overriding

// cannot call child function through parent

int main(void){

    A ob;
    ob.func();
}