#include<iostream>

using namespace std;

//Diamond Problem

class A{

    public:
    A(){

        cout <<"This is Class A" <<endl;
    }

};

class B : virtual public A{

        public:
        B(){

          cout <<"This is Class B" <<endl;
        }

};


class C : virtual public A{

        public:
        C(){

          cout <<"This is Class C" <<endl;

        }

};


class D : public B , public C {

        public:
        D(){

          cout <<"This is Class D" <<endl;
        }

};


int main(void){


    D ob;

}