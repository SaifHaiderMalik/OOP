#include <iostream>
#include <math.h>
#include <conio.h>


using namespace std;

double distance (int _x1,int _x2,int _y1,int _y2);
double radius(int _X1, int _Y1, int _X2, int _Y2);
double circumference(double radius);
double area(double radius);

int main(void){

    int x1,x2,y1,y2;
    double _dis,_diameter,_circumference,_area,_rad;
    
    cout << "Enter Points (X1 Y1) and (X2 Y2)" << endl;
    cin >> x1 >> y1 >> x2 >> y2;

    _dis = distance(x1,x2,y1,y2); 
    _rad = radius(x1,x2,y1,y2);
    _circumference = circumference(_rad);
    _area = area(_rad);

    cout << "Distance: " << _dis << endl << "Radius: " <<_rad << endl;  
    cout << "circumference: " <<_circumference << endl << "Area: " << _area;
}

double distance (int _x1,int _x2,int _y1,int _y2){

    return sqrt(pow(_x2-_x1,2) + pow(_y2-_y1,2));
}

double radius(int _X1, int _Y1, int _X2, int _Y2){

    return distance(_X1, _Y1, _X2, _Y2);
}

double circumference(double radius){

    return (2*3.1416*radius);
}

double area(double radius){
    
    return (3.1416*pow(radius,2));

}
