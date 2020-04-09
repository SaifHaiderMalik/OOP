#include<iostream>
using namespace std;

//Friend Function //Friend Classes

class Employee {

    int empID;

    friend class HR;
};


//Without friend private member of class is not accesible

//employee members Only accesible through object

// acceser(setter and getter) functions are expensive functions

//Although friend is going against abstraction it is allowed

class HR {

    Employee e;

    public:

    HR(){

        e.empID = 616;
        cout << e.empID;
    }
};

int main(void){

    HR ob;
}


