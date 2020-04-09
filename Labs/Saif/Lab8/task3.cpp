#include<iostream>
#include<string>

using namespace std;


class Shape{

    protected:

    double a;
    double b;

    public:

    virtual void Print(double length , double breadth){

        cout << "The Area of Rectangle is: " << length*breadth <<endl;
    }
};


class Rectangle : public Shape{

    public:

    void Print(double length , double breadth){

        cout << "The Area of Rectangle is: " << length*breadth <<endl;

    }

};


class Square : public Shape{

    public:

    void Print(double length,double breadth){

        if(length == breadth){

        cout << "The Area of Square is: " << length*length <<endl;
        }

        else{

            cout <<"It is not a Square " <<endl;
        }

    }

};


int main(void){

    double length;
    double breadth;

    cout << "Enter Side 1 of Square: " <<endl;
    cin >> length;

    cout << "Enter Side 2 of Square: " <<endl;
    cin >> breadth; 

    Square s;

    Shape* Sh;

    Sh = &s;

    Sh->Print(length,breadth);

    cout << "Enter Length of Rectangle: " <<endl;
    cin >> length;

    cout << "Enter Breadth of Rectangle: " <<endl;
    cin >> breadth;

    Rectangle r;

    Sh = &r;

    Sh->Print(length,breadth);

    
}