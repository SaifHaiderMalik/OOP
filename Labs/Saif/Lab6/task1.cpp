#include <iostream>
#include <string>
using namespace std;

class Marks{

    protected:

    string name;
    string rollnumber;
    double marks;

    public:

    Marks(string _name, string _rollnumber)
    {


        name = _name;
        _rollnumber = rollnumber;
        
    }

    Marks(){

        name = "";
        rollnumber = "";
    }

    double CalculateMarks(double score){

        marks = score;

        return marks;
    }

    void setName(string _name){

        name = _name;
    }

    void setRollNumber(string _rollnumber){

        rollnumber = _rollnumber;

    }

    string getName(){

        return name;
    }

    string getRollNumber(){

        return rollnumber;
    }


};

class Physics : public Marks
{
   

};

class Chemistry : public Marks
{


};

class Mathematics : public Marks
{
   

};

int main(void){

    string name;
    string rollnumber = "S";
    double marks;
    int numberOfStudents;
    double average;
    double marksinPhysics;
    double marksinChemistry;
    double marksinMathematics;
    double totalMarks;

    cout << "Enter Number of Students: " <<endl;
    cin >> numberOfStudents;

    Marks ob[numberOfStudents]; 

    for(auto i=0; i<numberOfStudents;i++){

        cout <<"Enter name Of students" <<endl;
        cin >> name;

        rollnumber = rollnumber + to_string(i+1000);

        ob[i].setName(name);

        ob[i].setRollNumber(rollnumber);

        cout << "Enter Marks of Student in Physics: " <<endl;
        cin >> marks;

        Physics Phy;

        marksinPhysics = Phy.CalculateMarks(marks);
        
        average = average + marksinPhysics;

        cout << "Enter Marks of Student in Chemistry: " <<endl;
        cin >> marks;

        Chemistry Ch;

        marksinChemistry = Ch.CalculateMarks(marks);

        average = average + marksinChemistry;

        cout << "Enter Marks of Student in Maths: " <<endl;
        cin >> marks;

        Mathematics Math;

        marksinMathematics = Math.CalculateMarks(marks);

        average = average + marksinMathematics;

        totalMarks = marksinChemistry + marksinMathematics + marksinPhysics;

        cout << "Name Of Student: " << ob[i].getName() <<endl;
        cout << "Roll Number Of Student: " << ob[i].getRollNumber() <<endl;

        cout <<"The Total Marks of the Student is: " << totalMarks <<endl;

        
    }

    cout <<endl << "The Average Marks of the class is: "<< average/numberOfStudents <<endl;


}