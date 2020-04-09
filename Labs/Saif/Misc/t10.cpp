#include<iostream>

using namespace std;

//previous 2 weeks classes is in polymerphism

class A{

    public:

// Parent class being virtual is enough (will call func of B)

   virtual void func(){

        cout <<"In A" <<endl;
    }
};


class B : public A{

    public:

    void func(){

        cout <<"In B" <<endl;
    }
};

int main(void){

    A* ob = new B;

    ob->func(); //Early Binding or Compile time Binding or Lazy Binding 
    //Late Binding or Runtime Binding
}



