#include<iostream>
#include<string>

using namespace std;

class Marks{

    
    int physics;
    int chemistry;
    int computer;
    int math;
    public:

    virtual double getPercentage() = 0;
};

class A : public Marks{

    int physics = 0;
    int computer = 0;
    int math = 0;
    double percentage = 0;

    public:
    A(int _physics,int _math, int _computer){

        if(_physics <= 100 && _physics > 0 && _math <= 100 && _math > 0 && _computer <= 100 && _computer> 0){
        physics = _physics;
        math = _math;
        computer = _computer;
        }

        else{
            cout << "Invalid Marks Entered" << endl;
        }
    }

    double getPercentage(){

        percentage = (((physics + math + computer)*100)/300);
        return percentage;
    }

};


class B : public Marks{

    int physics = 0;
    int chemistry = 0;
    int computer = 0;
    int math = 0;
    double percentage = 0;
    public:

    B(int _physics,int _math, int _computer,int _chemistry){

        if(_physics <= 100 && _physics > 0 && _math <= 100 && _math > 0 && _computer <= 100 && _computer> 0
        && _chemistry <= 100 && _chemistry > 0){
        physics = _physics;
        math = _math;
        computer = _computer;
        chemistry = _chemistry;
        }

        else{
            cout << endl << "Invalid Marks Entered" << endl;
        }
    }

    double getPercentage(){

        percentage = ((physics + math + computer + chemistry)*100)/400;
        return percentage;
    }

};


int main(void){

    int chemistry;
    int math;
    int computer;
    int physics;

    cout << "Enter Student A marks" << endl;
    cout << "Enter Marks in physics" << endl;
    cin >> physics;
    cout << "Enter Marks in Math" << endl;
    cin >> math;
    cout << "Enter Marks in Computer" << endl;
    cin >> computer;

    A ob1(physics,math,computer);
    cout << "The Percentage of Student A is: " << ob1.getPercentage() << endl;

    cout << "Enter Student B Marks" << endl;
    cout << "Enter Marks in physics" << endl;
    cin >> physics;
    cout << "Enter Marks in Math" << endl;
    cin >> math;
    cout << "Enter Marks in Computer" << endl;
    cin >> computer;
    cout << "Enter Marks in Chemistry" << endl;
    cin >> chemistry;

    B ob2(physics,math,computer,chemistry);
    cout << "The Percentage of Student B is: " << ob2.getPercentage() << endl;
}