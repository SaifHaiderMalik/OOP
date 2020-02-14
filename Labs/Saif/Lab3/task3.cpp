#include <iostream>
#include <string>

using namespace std;

class Student{

    string name;
    string rollno;  

    public:

    double marks[4];
    
    void setDetails(string _name,string _rollno){

        name = _name;
        rollno = _rollno;
        

    }

    string getName(){

        return name;

    }

    string getRollNo(){

        return rollno;
    }

};

int main(){

    Student ob;

    string studentName;
    string rollnumber;
    double totalMarks = 0;   
    double percentage;

    cout << "Enter Name of Student" << endl;
    cin >> studentName;
    cout << "Enter RollNumber" << endl;
    cin >> rollnumber;
    cout << "Enter 4 Test Marks" << endl;
    
    for(int i = 0; i<4; i++){

            cin >> ob.marks[i];
            totalMarks = totalMarks + ob.marks[i];

        }

    ob.setDetails(studentName,rollnumber);

    percentage = totalMarks/4;

    cout << "Name of Student" << ob.getName() << endl;
    cout << "Roll number of Students" << ob.getRollNo() << endl;
    cout << "Stduent Score Marks: " << endl;

    for(int i = 0; i<4; i++){

        cout << ob.marks[i] << endl;
    }

    cout << "Total Marks" << totalMarks << endl;
    cout << "The Percentage is: " << percentage;

}