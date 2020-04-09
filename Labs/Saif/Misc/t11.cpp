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

    Vector operator + (Vector ob){

            Vector temp;

            temp.x = this->x + ob.x; //temp.x = v1.x + v2.x
            temp.y = this->y + ob.y; //temp.y = v1.y + v2.y  
            return temp;

    }
};



int main(void){

    Vector v1(2,3);

    Vector v2(4,5);

    cout << "V1: ";
    v1.show();

    cout << "V2: ";
    v2.show(); 


    Vector v3 = v1 + v2;

    cout <<"V3: ";
    v3.show();
}

