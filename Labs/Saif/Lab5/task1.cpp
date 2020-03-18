#include<iostream>
#include<string>
using namespace std;

class Employee{

    string employeeName;
    const int employeeId;

    public:

    Employee(int Id,string name): employeeId(Id),employeeName(name)
    {


    }

    void setName(string _name)
    {

        employeeName = _name;

    }

    string getName() const
    {
        
        return employeeName;

    }

       int getId() const
    {
        
        return employeeId;

    }

};

int main(void){

    string name;
    int id;
    int count = 1;

    cout << "Enter Name of Employee" <<endl;
    cin >> name;

    cout << "Enter Id of Employee" <<endl;
    cin >> id;
  
    Employee Employee1(id,name);

    
    cout <<"The Names and Id of the Employee are:" <<endl;
    cout << Employee1.getName() << " " << Employee1.getId() <<endl;

    cout << "Enter Name of Employee" <<endl;
    cin >> name;

    cout << "Enter Id of Employee" <<endl;
    cin >> id;

    Employee Employee2(id,name);

    
    cout <<"The Names and Id of the Employee are:" <<endl;
    cout << Employee2.getName() << " " << Employee2.getId() <<endl;

    cout << "Enter Name of Employee" <<endl;
    cin >> name;

    cout << "Enter Id of Employee" <<endl;
    cin >> id;

    Employee Employee3(id,name);

    cout <<"The Names and Id of the Employee are:" <<endl;
    cout << Employee3.getName() << " " << Employee3.getId();


}