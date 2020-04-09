#include<iostream>
using namespace std;

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

            this->x = this->x + ob.x; 
            this->y = this->y + ob.y;
            return *this;

    }
};



int main(void){

    int v1x,v2x,v1y,v2y;

    cout << "Enter X Coordinates of V1: " <<endl;
    cin >> v1x;

    cout << "Enter Y Coordinates of V1: " <<endl;
    cin >> v1y;

    cout << "Enter X Coordinates of V2: " <<endl;
    cin >> v2x;

    cout << "Enter Y Coordinates of V2: " <<endl;
    cin >> v2y;

    Vector v1(v1x,v1y);

    Vector v2(v2x,v2y);

    cout << "V1: ";
    v1.show();

    cout << "V2: ";
    v2.show(); 

    Vector v3;

    v3 = v1 + v2; 

    cout <<"V3: ";
    v3.show();




}

