#include<iostream>
#include<string>

using namespace std;

class Shape{

    virtual double RectangleArea(double length,double breadth) = 0;
    virtual double CircleArea(double radius);
    virtual double SquareArea(double length);

};

class Area : public Shape{

    public:

    double RectangleArea(double length,double breadth){

        return(length*breadth);
        
    }

    double CircleArea(double radius){

        return(3.142*radius*radius);
    }

    double SquareArea(double length){

        return(length*length);
    }

};

int main(void){

    double length,breadth,radius;

    Area ob;

    cout << "Enter length of Rectangle: " << endl;
    cin >> length;
    cout << "Enter Breadth of Rectangle: " << endl;
    cin >> breadth;

    cout << "Area of Rectangle is: " << ob.RectangleArea(length,breadth) << endl;

    cout << "Enter Radius of Circle: " << endl;
    cin >> radius;

    cout << "Area of Circle is: " << ob.CircleArea(radius) << endl;

    cout << "Enter length of sides of Square: " << endl;
    cin >> length;

    cout << "Area of Square is: " << ob.SquareArea(length) << endl;

   

}
