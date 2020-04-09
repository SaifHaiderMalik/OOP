#include<iostream>
#include<string>

using namespace std;

class Base {

    protected:

    double a;
    double b;

    public:

    void Area(){

        a = 0;
        b = 0;

    }


};


class Derived : public Base{

    public:

    double Area(double a, double b){

        return a*b;
    }
};


int main(void){

    double length;
    double breadth;

    cout << "Enter Length: " <<endl;
    cin >> length;

    cout << "Enter Breadth: " <<endl;
    cin >>breadth;

    Base A;

    A.Area();

    Derived ob;

    cout << "The Area of Rectangle is: " << ob.Area(length,breadth) <<endl;



}
