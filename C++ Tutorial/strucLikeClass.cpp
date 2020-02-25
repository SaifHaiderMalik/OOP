#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>

using namespace std;

struct Shape{
    double length, width;
    Shape(double l =1, double w = 1){
        length = l;
        width = w;
    }
    double Area(){
        return length * width;
    }

    private:
    int id;
};

struct Circle : Shape{
    Circle(double width){
        this->width = width;
    }
    double Area(){
        return 3.14159 * pow((width / 2), 2);
    }
};

int main(){
    Shape shape(10, 10);
    cout << "Sqaure Area : " << shape.Area() << endl;
    Circle circle(10);
    cout << "Circle Area : " << circle.Area() << endl;
    Shape rectangle(10, 15);
    cout << "Rectangle Area : " << rectangle.Area() << endl;
    return 0;
}