#include<iostream>
using namespace std;

class A{

    public:

    void func(){

        cout << "This is A" <<endl;
    }


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

int main(void){

    C ob;
    ob.func();
}