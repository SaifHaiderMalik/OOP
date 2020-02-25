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

class Employee{
    string eID;
public:
    Employee(){
    }

    void setEID(string id){
        eID = "E-" + id;
        cout << eID;
    }
};

int main(){
    Employee emp1;
    emp1.setEID("1001");
}