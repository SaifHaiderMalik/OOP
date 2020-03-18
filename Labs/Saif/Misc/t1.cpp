#include<iostream>
using namespace std;

class A{

    private: int x = 10;
    public: int y = 20;
    protected: int z = 30;

};

class B: public A
{
    public:
    void showB(){

        //cout << x <<endl;
        cout << y <<endl;
        cout << z <<endl;
    }

};

class C: public B
{
 
    public:
    void showC(){

        //cout << x <<endl;
        cout << y <<endl;
        cout << z <<endl;

    }
};

int main(void){

    B ob;

    ob.showB();

}