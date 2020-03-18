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

    double CalculateMarks(double score){

        marks = score;

        return marks;
    }

    double CalculateAverage(double score){

        
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
    string rollnumber;
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

        cout <<"Enter Roll Number Of Student" <<endl;
        cin >>rollnumber;

        ob[i](name,rollnumber);

        cout << "Enter Marks of Student in Physics: " <<endl;
        cin >> marks;

        Physics Phy;

        marksinPhysics = Phy.CalculateMarks(marks);
        
        cout << "Enter Marks of Student in Chemistry: " <<endl;
        cin >> marks;

        Chemistry Ch;

       marksinChemistry = Ch.CalculateMarks(marks);

        cout << "Enter Marks of Student in Maths: " <<endl;
        cin >> marks;

        Mathematics Math;

        marksinMathematics = Math.CalculateMarks(marks);

        totalMarks = marksinChemistry + marksinMathematics + marksinPhysics;

        cout <<"The Total Marks of the Student is: " << totalMarks <<endl;

        cout << "The Average Marks of the Student is: " << average <<endl; 




    }


    




}