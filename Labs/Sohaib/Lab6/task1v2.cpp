#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Marks{
protected:
    int numOfStudents=2;
    string* rollNumber = new string[numOfStudents];
    string* name = new string[numOfStudents];
    double* marks = new double[numOfStudents]{0};

private:

public:
    Marks(int _numOfStudents){
        numOfStudents = _numOfStudents;
        for(int i = 0; i < numOfStudents; i++){
            rollNumber[i] ="R" + to_string(i);
        }
    }

    string getRollNumber(int _roll){return rollNumber[_roll];}
    string getName(int _roll){return name[_roll];}
    double getMarks(int _roll){return marks[_roll];}
    double getAverage(int _roll){return marks[_roll] / 100;}

    /*void setRollNumber(int _rollNumber){
        rollNumber = "ST" + to_string(_rollNumber);
    }

    void setName(string _name){
        name = _name;
    }

    void setMarks(double _marks){
        marks = _marks;
    }*/
};

class Physics : public Marks{

};

class Chemistry : public Marks{
    
};

class Mathematics : public Marks{
    
};

int main(){
    unsigned int numOfStudents;
    double marks, totalMarks = 0, phyMarks = 0, chemMarks = 0, mathsMarks = 0;
    string name;

    cout << "CLASS REPORT\nNumber of Students in Class: ";
    cin >> numOfStudents;
    Marks MarksObj(numOfStudents);

    for(int i = 0; i < numOfStudents; i++){
        cout << i << MarksObj.getRollNumber(i);
    }

}