#include <iostream>

using namespace std;

class Student{
    public:
    string studentName;
    int id;

    void printName();

    void printId(){
        cout << "Student ID is: " << id;
    }
};

void Student::printName(){
    cout << "Student name is: " << studentName;
}

int main(){
    Student obj1;
    obj1.studentName = "Saif";
    obj1.id = 15;

    obj1.printName();
    cout << endl;
    obj1.printId();
    return 0;
}