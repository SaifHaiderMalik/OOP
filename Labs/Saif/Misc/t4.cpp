#include<iostream>
using namespace std;


class A{

    public:

    void func(){

        cout << "This is func() " <<endl;

    }

    void func(int a){

        cout << "This is func(int a) " <<endl;

    }

    void func(char a){

        cout << "This is func(char a) " <<endl;

    }

    void func(string a){

        cout << "This is func(string a) " <<endl;

    }

    void func(int a,float b){

        cout << "This is func(int a,float b) " <<endl;

    }

 // for function overload all function must be in the same scope.
};


int main(){

    A ob;
    ob.func();
    ob.func(10);
    ob.func('1');
    ob.func(5,3.5);

}




