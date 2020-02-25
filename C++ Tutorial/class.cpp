#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>
#include "Shape.h"
#include "Circle.h"
#include "Shape.cpp"
#include "Circle.cpp"
//#include "shape.h"

using namespace std;

void ShowArea(Shape& shape);

int main(){
    Shape square(10, 5);
    Circle circle(10);
    ShowArea(square);
    ShowArea(circle);
    return 0;
}

void ShowArea(Shape& shape){
    cout << "Area : " << shape.Area() << endl;
}