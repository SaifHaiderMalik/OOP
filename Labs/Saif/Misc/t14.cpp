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

    // int is a dummy parameter
    //post increment
    void operator++(int){

        this->x = this->x + 1;
        this->y = this->y + 1;

    }

    //pre increment

    void operator++(){

        this->x = this->x + 1;
        this->y = this->y + 1;

    }

    /*

    Vector operator++(int){

        this->x = this->x +1;
        this->y = this-> +1;
        return *this;
    }

    
    Vector operator++(int){

        vector temp;
        temp->x = this->x +1;
        temp->y = this-> +1;
        return temp;
    }
    
    */
};



int main(void){

    Vector v1(2,3);
    Vector v2(4,5);
    Vector v3(3,2);

    ++v1;
    cout << "v1: ";
    v1.show();

    v2++;

    cout <<"V2: ";
    v2.show();


  

}

