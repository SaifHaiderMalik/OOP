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

class Test{
    int x ,y;
public:
    Test(){
    }
    Test(int x, int y){
        this->x = x;
        this->y = y;
    }

    Test& setX(int a){
        x = a;
        return *this;
    }

    setY(int b){
        y = b;
        //return *this;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};

int main(){
    //Test test(1, 2);
    Test* test = new Test[10];
    for(auto i = 0;i <10;i++){

        test[i](1,2);
    }
    test[0].setX(10);
    test[0].setY(20);
    cout << test[0].getX() << test[0].getY() << endl;
    //test.setX(100).setY(200);
    //cout << test.getX() << test.getY();
}