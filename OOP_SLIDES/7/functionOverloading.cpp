#include <iostream>

using namespace std;

class Base{
public:
    void f1(){
        cout << "This is Base\n";
    }

    virtual void f2(){
        cout << "This is Base\n";
    }
};

class Derived : public Base{
public:
    void f1(){
        cout << "This is Derived\n";
    }

    void f2(){
        cout << "This is Derived\n";
    }
};


int main(){
    Derived d;
    Base *b = &d;
    d.f1();
    d.f2();
    b->f1();
    b->f2();
    return 0;
}