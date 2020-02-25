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

class Student{
public:
    int rollNumber, age;
    static int m;

    void setM(int x){
        m = x;
    }
private:
    static int n;
};//int Student::m = 100;




int main(){
    Student s1;
    //s1.setM(50);
   


}