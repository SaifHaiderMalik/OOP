#include<iostream>
using namespace std;

class Complex{

    int real;
    int imaginary;

    public:

    Complex(int _real,int _imaginary){

        real = _real;
        imaginary = _imaginary;
    }

    void show(){

        cout << "Real Number: " << real << " Imaginary Number: " << imaginary <<endl;
    }

    Complex& operator + (Complex ob){

            this->real = this->real + ob.real;
            this->imaginary = this->imaginary + ob.imaginary;
            return *this;

    }



};

int main(void){

    int real;
    int imaginary;

    cout <<"Enter Real Number of first complex number: " <<endl;
    cin >> real;

    cout <<"Enter Imaginary Number of first complex number: " <<endl;
    cin >> imaginary;

    Complex c1(real,imaginary);

    cout <<"Enter Real Number of first complex number: " <<endl;
    cin >> real;

    cout <<"Enter Imaginary Number of first complex number: " <<endl;
    cin >> imaginary;

    Complex c2(real,imaginary);

    cout << "C1: ";
    c1.show();

    cout << "C2: ";
    c2.show();


    Complex c3 = c1 + c2;

  
    cout << "C3: ";
    c3.show();

}
