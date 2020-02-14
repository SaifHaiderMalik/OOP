#include <iostream>
#include <string>

using namespace std;

class Employee{

    string firstName;
    string lastName;
    int monthlySalary;

    public:

    void setDetails(string _firstName,string _lastName,int _monthlySalary){

        firstName = _firstName;
        lastName = _lastName;
        if (_monthlySalary < 0){

            monthlySalary = 0;
        }

        else{
    
             monthlySalary = _monthlySalary;
        }   
    }


    string getFirstName(){

        return firstName;
    }

    string getLastName(){

        return lastName;
    }

    int getMonthlySalary(){

        return monthlySalary;
    }

    void setSalary(int Salary){

        if(Salary > 0){

        monthlySalary = Salary;

        }

        else {

            cout << "Error Salary is in minus" << endl; 
        }
    }
};

int main(){

    string fName;
    string lName;
    int Salary;
    int employeeSalary1;
    int employeeSalary2;
    int raisedSalary1;
    int raisedSalary2;


    cout << "Enter First Name" << endl;
    cin >> fName;
    cout << "Enter Last Name" << endl;
    cin >> lName;
    cout << "Enter Salary"<< endl;
    cin >> Salary;

    Employee E1;
    Employee E2;

    E1.setDetails(fName,lName,Salary);

    employeeSalary1 = E1.getMonthlySalary();

    cout << "First Employee Yearly Salary: " << employeeSalary1*12 <<endl;
    
    cout << "Enter First Name" << endl;
    cin >> fName;
    cout << "Enter Last Name" << endl;
    cin >> lName;
    cout << "Enter Salary"<< endl;
    cin >> Salary;

    E2.setDetails(fName,lName,Salary);

    employeeSalary2 = 12 * E2.getMonthlySalary();

    cout << "Second Employee Yearly Salary: " << employeeSalary2*12 << endl;

    raisedSalary1 = employeeSalary1 + (employeeSalary1*0.1);
    raisedSalary2 = employeeSalary2 + (employeeSalary2*0.1);

    E1.setSalary(raisedSalary1);
    E2.setSalary(raisedSalary2);

  
    cout << "First Employee Raised Salary" << E1.getMonthlySalary() * 12 << endl;
    cout << "Second Employee Raised Salary" << E2.getMonthlySalary() * 12 << endl;


}