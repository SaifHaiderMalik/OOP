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

   friend void operator <<(ostream& ,Vector);

};

// Global Operator Overload

void operator << (ostream& o, Vector ob){

    o << "x: " << ob.x << " " <<  ob.y <<endl; 

}



int main(void){

    Vector v1(2,3);
    Vector v2(4,5);
    Vector v3(3,2);

   cout << v1;
   //   cout is an object of ostream class


  

}

