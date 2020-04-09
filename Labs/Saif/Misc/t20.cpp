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

    Employee(){

        cout << "Employee class constructor" <<endl;

    }

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

//If we donot overwrite pure virtual function from parent class in child class then 
//we have to make a pure virtual class in function 


class HR: public Employee{

    public:

    void work(){

        cout << "Manage HR Work related" <<endl;
    }


};


int main(void){

   Employee* emp = new HR; //late binding

   emp->work();


   emp = new Accounts;
   
   emp->work();

}