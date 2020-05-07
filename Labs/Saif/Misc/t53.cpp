#include<iostream>
#include<fstream>
#include<string>

using namespace std;


// Although char* and string are compatible the internal working vastly differs.
// char* allocates sequence of memory blocks. At first 4 blocks are aloocated if the char increases so does the block
// When we create string basically we create an object and it is stored in a heap
// The problem is in the second parameter sizeof 

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
    Employee e3;

    ofstream os("empdatabase.txt", ios::app);

    os.write((char*) &e1, sizeof(e1));
    os.write((char*) &e2, sizeof(e2));
    os.close();


// while(eof) for looping

    ifstream is("empdatabase.txt");

    is.read((char*) &e3, sizeof(e3));
    e3.display();

    is.read((char*) &e3, sizeof(e3));
    e3.display();


}