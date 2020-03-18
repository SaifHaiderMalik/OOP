#include<iostream>
using namespace std;

class A{

    public:
    void show(){

        cout << "IN A" <<endl;
    }
};

class B: public A{

  
};

class C: public B{


};

int main(){

    C ob;
    ob.show();
}
