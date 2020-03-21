#include<iostream>

using namespace std;

class A{

    public:

    void func(){

        cout << "In Class A" <<endl;
    }

};


class B : public A{

    public:

    void func(){

        cout << "In Class B" <<endl;
    }
};


int main(void){

//Early Binding if without new B
// A* ob

   // A* ob = new B; //Upcasting

    B* ob = (B*) new A; //downcasting Must use syntax  (Object*)
    ob->func();

}