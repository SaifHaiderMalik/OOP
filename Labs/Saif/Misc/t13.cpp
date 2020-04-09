#include<iostream>

using namespace std;

//Operator Overloading

class Vector{

    int x,y;

    public:

    Vector(int x,int y){

        this->x = x;
        this->y = y;
    }

    Vector(){


    }

    void show(){

        cout << "x = " << x << " and y = " << y <<endl;
    }

    Vector& operator + (Vector ob){

            this->x = this->x + ob.x; //V1.x = v1.x + v2.x
            this->y = this->y + ob.y; //V1.y = v1.y + v2.y  
            return *this;

    }
};



int main(void){

    Vector v1(2,3);

    Vector v2(4,5);


    cout << "V1: ";
    v1.show();

    cout << "V2: ";
    v2.show(); 

    Vector v3(3,2);

    v3 = v1 + v2; // Implicit poerator overload call

      v3 = v1.operator+(v2); //   Explicit overload call

    cout <<"V3: ";
    v3.show();

    cout << "V1: ";
    v1.show();



    Vector v4;

    v4 = v1+v2+v3;

    cout << "V1: ";
    v1.show();


}

