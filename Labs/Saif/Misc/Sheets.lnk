#include <iostream>
#include <cmath>
using namespace std;
class Obtuse;
class Acute {
    double a;
    double b;
    double theta; //in radians
    public:
    Acute() {

    }
    Acute(double b,double h,double t) {
        a=b;
        if(t<=90)
        theta=t*3.142/180;
        else
        {
            theta=0;
        }
        
        this->b=h*sin(theta);

    }
    friend void area(Acute &a,Obtuse &o);
};
class Obtuse {
    double a;
    double b;
    double theta; //in radians
    friend void area(Acute &a,Obtuse &o);
    public:
       Obtuse(double b,double h,double t) {
        a=b;
        if(t>90)
        theta=t*3.142/180;
        else
        {
            theta=0;
        }
        
        this->b=h*sin(theta);
    }
    Obtuse() {

    }
};
void area(Acute &a,Obtuse &o) {
    cout<<"acute: "<<(a.a*a.b)/2<<endl;
    cout<<"obtuse: "<<(o.a*o.b)/2<<endl;
}
int main() {
    Acute a(2,3,90);
    Obtuse o(4,5,91);
    area(a,o);
}