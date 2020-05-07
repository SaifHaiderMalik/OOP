#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Employee{

    char * name;
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

    Employee e1("Aqib",12500.68);
    Employee e2("Hammad",13300.45);
    Employee e3("Ahsan",15000.20);
    Employee e;

    ofstream os("myobjtest.txt", ios::app);

    os.write((char*) &e1, sizeof(e1));
    os.write((char*) &e2, sizeof(e2));
    os.write((char*) &e3, sizeof(e3));
    os.close();

    ifstream is("myobjtest.txt");

    while(true){

        is.read((char*) &e,sizeof(e));

        if(is.eof()){

            break;
        }

        e.display();
    }


}