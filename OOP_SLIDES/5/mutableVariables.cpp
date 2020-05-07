#include <iostream>

using namespace std;

class A{
    //int val; //Gives Error: assignment of member 'A::val' in read-only object.
    mutable int val;

public:
    A(int x){
        val = x;
    }

    void changeVal(int x) const{
        val = x;
    }
};

int main(){
    A a(10);
    a.changeVal(20);
    return 0;
}