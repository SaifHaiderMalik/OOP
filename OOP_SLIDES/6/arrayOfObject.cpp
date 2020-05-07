#include <iostream>

using namespace std;

class A{
    int int1;

public:
    A(){}

    A(int _int1){
        int1 = _int1;
    }

    int getInt1(){return int1;}
};



int main(){
    A ob1;
    A ob2(10);
    A arr[] = {ob1, ob2};
    A arr2[2];
    A arr3[2]{20, 30};
    cout << ob1.getInt1() << endl;
    cout << ob2.getInt1() << endl;

    cout << "A arr[] = {ob1, ob2};" << endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i].getInt1() << endl;
    }

    cout << "A arr2[2];" << endl;
    for(int i = 0; i < 5; i++){
        cout << arr2[i].getInt1() << endl;
    }

    cout << "A arr3[2]{20, 30};" << endl;
    for(int i = 0; i < 5; i++){
        cout << arr3[i].getInt1() << endl;
    }

    A* arrOb[] = {new A, new A};
    cout << "A* arrOb[] = {new A, new A};" << endl;
    for(int i = 0; i < 2; i++){ //index exceeding 1 gives error @ runtime
        cout << arrOb[i]->getInt1() << endl;
    }

    arrOb[2] = new A(50);
    cout << "A* arrOb[] = {new A, new A};\narrOb[2] = new A(50);" << endl;
    for(int i = 0; i < 3; i++){ //index exceeding 2 gives error @ runtime
        cout << arrOb[i]->getInt1() << endl;
    }

    arrOb[5] = new A(500);
    cout << "A* arrOb[] = {new A, new A};\narrOb[2] = new A(50);\narrOb[5] = new A(500);" << endl;
    cout << arrOb[5]->getInt1() << "\tThis line is not in loop" << endl;
    for(int i = 0; i < 5; i++){ //index exceeding 2 gives error @ runtime since index 3&4 are missing
        cout << arrOb[i]->getInt1() << endl;
    }
    
    return 0;
}