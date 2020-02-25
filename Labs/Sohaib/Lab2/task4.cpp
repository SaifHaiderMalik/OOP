#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <conio.h>

using namespace std;

double distance(int _X1, int _Y1, int _X2, int _Y2){
    return sqrt(pow(_X2 - _X1, 2)+pow(_Y2 - _Y1, 2));
}

double radius(int _X1, int _Y1, int _X2, int _Y2){
    return distance(_X1, _Y1, _X2, _Y2);
}

double circumference(double _radius){
    return 2 * M_PI * _radius;
}

double area(double _radius){
    return M_PI * pow(_radius, 2);
}

int main(){
    int X1, Y1, X2, Y2;
    
    cout << "Enter X & Y for the point on Center of the Circle: ";
    cin >> X1 >> Y1;
    cout << "Enter X & Y for the point on Circumference of the Circle: ";
    cin >> X2 >> Y2;

    cout << "Circle's Radius: " << radius(X1, Y1, X2, Y2) << endl;
    cout << "Circle's Diameter: " << radius(X1, Y1, X2, Y2) * 2 << endl;
    cout << "Circle's Circumference: " << circumference(radius(X1, Y1, X2, Y2)) << endl;
    cout << "Circle's Area: " << area(radius(X1, Y1, X2, Y2)) << endl;

    getch();
    return 0;
}