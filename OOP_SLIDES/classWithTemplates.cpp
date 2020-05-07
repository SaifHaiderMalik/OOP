#include <iostream>

using namespace std;



/*void printA(T t){
    cout << 
}*/

class A{
    //T something;
public:
    template <class T>
    void printF(T _something){
        cout << "this is " << _something << endl;
    }
};

int main(){
    A a1;
    a1.printF("ssss dddsd sds");
    return 0;
}