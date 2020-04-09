#include<iostream>

using namespace std;


class Divide{

    double x,y,z;

    public:

    Divide(double x,double y, double z){

        this->x = x;
        this->y = y;
        this->z = z;

    }

    Divide(){


    }

    Divide operator  / (Divide ob){

        Divide temp;

        temp.x = this->x / x;
        temp.y = this->y / y;
        return temp;
    }
};


int main(void){

    Divide d1(1,2,3);

    Divide d2(4,5,6);

    
}