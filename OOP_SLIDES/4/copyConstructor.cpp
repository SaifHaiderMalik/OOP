/*
Default constructor always perform a shallow copy.
Changes made by one object are also made for the other object.
Deep copy is only possible with user-defined copy constructors.
In user-defined copy constructors, we make sure that pointers (or references) of copied object point to new memory locations.
*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
    char *s;
    int size;

public:
    A(const char *str = NULL){
        size = strlen(str);
        s = new char[size+1];
        strcpy(s, str);
    }

    /*A(const A& ob){
        size = ob.size;
        s = new char[size+1];
        strcpy(s, ob.s);
    }*/

    ~A(){
        delete s;
    }

    void print(){
        cout << s << endl;
    }

    void change(const char *str){
        delete [] s;
        size = strlen(str);
        s = new char[size+1];
        strcpy(s, str);
    }
};


int main(){
    A a1("0 String");
    A a2 = a1;

    a1.print();
    a2.print();

    a2.change("2 String");

    a1.print();
    a2.print();

    a1.change("1 String");

    a1.print();
    a2.print();

    a1 = a2;
    a1.change("1 String");

    a1.print();
    a2.print();

    return 0;
}