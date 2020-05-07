#include <iostream>

using namespace std;

class A{
    const int x;
    const int y;

public:
    A(int a, int b) : x(a), y(b){
    }

    void getX(){cout << x << endl;}
    void getY(){cout << y << endl;}
};

int main(){
    A a1(10, 20);
    a1.getX();
    a1.getY();
    return 0;
}