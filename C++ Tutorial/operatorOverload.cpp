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

class Box{
protected:
public:
    double length, width, breadth;
    string boxString;

    Box(){
        length = 1, width = 1, breadth = 1;
    }

    Box(double l, double w, double b){
        length = l, width = w, breadth = b;
    }
    
    Box& operator ++ (){
        length++;
        width++;
        breadth++;
        return *this;
    }

    operator const char*(){
        ostringstream boxStream;
        boxStream << "Box : " << length << ", " << width << ", " << breadth;
        boxString = boxStream.str();
        return boxString.c_str();
    }

    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;
        return boxSum;
    }

    bool operator == (const Box& box2){
        return ((length == box2.length) && (width == box2.width) && (breadth == box2.breadth));
    }
private:
};

int main(){
    Box box(10, 10, 10);
    cout << "Box1 = " << box << endl;
    ++box;
    cout << "++Box1 = " << box << endl;
    Box box2(5, 5, 5);
    cout << "Box2 = " << box2 << endl;
    cout << "Box1 + Box2 = " << (box + box2) << endl;
    cout.setf(ios::boolalpha);
    cout << "Box1 == Box1 : " << (box == box) << endl;
    cout << "Box2 == Box2 : " << (box2 == box2) << endl;
    cout << "Box1 == Box2 : " << (box == box2) << endl;
    return 0;
}