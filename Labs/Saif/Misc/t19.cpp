#include<iostream>

using namespace std;

//Abstract Classes

// if class has atleast one pure virtual function then that class becomes abstract that means the 
// class object cannot be created in main because it is incomplete class
//Abstract class cannot be initiated

class Employee{

    int empID;
    string empName;
    int salary;

    public:

    virtual void work() = 0; //pure virtual function or Abstract function

    void leave() //concrete function
    {

        cout << "30 day leave for ALL Employees" <<endl;

    }

};



class Accounts: public Employee{

    public:

    void work(){

        cout << "Manage accounts" <<endl;
    }

};


class HR: public Employee{

    public:

    void work(){

        cout << "Manage HR Work related" <<endl;
    }



};


int main(void){

    Accounts acc;

    acc.leave();

    HR hr;

    hr.leave();

}