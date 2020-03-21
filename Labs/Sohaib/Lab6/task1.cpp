#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Marks{
protected:
    string rollNumber;
    string name;
    double marks;
    string subject;

private:

public:
    /*Marks(int _rollNumber){
        rollNumber = "ST" + to_string(_rollNumber);
        name = "";
        marks = 0;
    }*/

    string getRollNumber(){return rollNumber;}
    string getName(){return name.substr(0, 15);}
    double getMarks(){return marks;}
    double getAverage(){return marks / 100;}
    string getSubject(){return "";}

    void setRollNumber(int _rollNumber){
        rollNumber = "ST" + to_string(_rollNumber);
    }

    void setName(string _name){
        name = _name;
    }

    void setMarks(double _marks){
        marks = _marks;
    }

    double checkMarks(double _marks){
        while(_marks < 0 || _marks > 100){
            cout << "\033[FMarks Obtained in " << getSubject() << ":\t";
            cin >> _marks;
        }
        return _marks;
    }
};

class Physics : public Marks{
public:
    string getSubject(){return "Physics";}

};

class Chemistry : public Marks{
public:
    string getSubject(){return "Chemistry";}
    
};

class Mathematics : public Marks{
public:
    string getSubject(){return "Mathematics";}
    
};

int main(){
    unsigned int numOfStudents, count = 1, choice;
    double marks, totalMarks = 0, phyMarks = 0, chemMarks = 0, mathsMarks = 0;
    string name;

    cout << "CLASS REPORT" << endl;
    cout << "Number of Students in Class: ";
    cin >> numOfStudents;
    Marks MarksObj[numOfStudents];
    Physics PhyObj[numOfStudents];
    Chemistry ChemObj[numOfStudents];
    Mathematics MathsObj[numOfStudents];
    
    for(int i = 0; i < numOfStudents; i++){
        cout << "Student: " << (i + 1) << endl;
        MarksObj[i].setRollNumber(i);
        //PhyObj[i].setRollNumber(i);
        //ChemObj[i].setRollNumber(i);
        //MathsObj[i].setRollNumber(i);
        cout << "Student Name: ";
        cin.ignore();   //Clears cin input buffer so getline can be used for string with spaces
        getline(cin, name);
        MarksObj[i].setName(name);
        //PhyObj[i].setName(name);
        //ChemObj[i].setName(name);
        //MathsObj[i].setName(name);

        cout << "Marks Obtained in Physics:\t";
        cin >> marks;
        PhyObj[i].setMarks(PhyObj[i].checkMarks(marks));

        cout << "Marks Obtained in Chemistry:\t";
        cin >> marks;
        ChemObj[i].setMarks(ChemObj[i].checkMarks(marks));

        cout << "Marks Obtained in Mathematics:\t";
        cin >> marks;
        MathsObj[i].setMarks(MathsObj[i].checkMarks(marks));

        MarksObj[i].setMarks(PhyObj[i].getMarks() + ChemObj[i].getMarks() + MathsObj[i].getMarks());
    }

    while(count == 1){
        system("cls");
        cout << "\tMENU\n\t1> Students Report\n\t2> Class Stats\n\t3> Exit\n\tChoice: ";
        cin >> choice;

        switch (choice){
        case 1:
            system("cls");
            cout << "STUDENTS REPORT\n" << "ROLL#\t" << "Student Name" << setw(12)
                 << "Physics" << setw(12) << "Chemistry" << setw(12) << "Maths" << setw(12)
                 << "Total" << setw(12) << "Percentage" << endl;

            for(int i = 0; i < numOfStudents; i++){
                cout << MarksObj[i].getRollNumber() << "\t"
                     << MarksObj[i].getName() << setw(24 - MarksObj[i].getName().length())
                     << PhyObj[i].getMarks() << setw(12) << ChemObj[i].getMarks() << setw(12)
                     << MathsObj[i].getMarks() << setw(12) << MarksObj[i].getMarks() << setw(11)
                     << MarksObj[i].getMarks() / 3 << "%" << endl;
            }

            system("pause");
            break;

        case 2:
            system("cls");
            for(int i = 0; i < numOfStudents; i++){
                totalMarks += MarksObj[i].getMarks();
                phyMarks += PhyObj[i].getMarks();
                chemMarks += ChemObj[i].getMarks();
                mathsMarks += MathsObj[i].getMarks();
            }

            cout << "CLASS STATS\nNumber of Students:\t" << numOfStudents << endl;
            cout << "Physics Average:\t" << phyMarks / numOfStudents << endl;
            cout << "Chemistry Average:\t" << chemMarks / numOfStudents << endl;
            cout << "Mathematics Average:\t" << mathsMarks / numOfStudents << endl;
            cout << "Average Total Marks:\t" << totalMarks / numOfStudents << endl;
            cout << "Average Percentage:\t" << totalMarks / numOfStudents / 3 << "%" << endl;

            system("pause");
            break;

        case 3:
            count = 0;
            break;
        
        default:
            cout << "Invalid choice!" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}