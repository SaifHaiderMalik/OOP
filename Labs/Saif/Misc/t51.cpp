#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Object information is written as binary because it is refrence type.


class Employee{

    char *name;
    float salary;

    public:

    Employee(){}

    Employee(char * n, float s){

        name = n;
        salary = s;
    }

    void display(){

        cout << name << endl;
        cout << salary << endl;
    }

};

int main(void){

    Employee e1("Ali", 12400.5);
    Employee e2("Hasan",14000.45);
    Employee e3;

    ofstream os("C:\\Users\\sohai\\Desktop\\emp.txt",ios::app);
    os.write((char*) &e1, sizeof(e1));
    os.write((char*) &e2, sizeof(e2));
    os.close();

    ifstream is("C:\\Users\\sohai\\Desktop\\emp.txt",ios::app);
    is.read((char*) &e3, sizeof(e3));
    e3.display();

    is.read((char*) &e3, sizeof(e3));
    e3.display();

    is.close();

}