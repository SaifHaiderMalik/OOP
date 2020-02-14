#include <iostream>
#include <iomanip>

using namespace std;

class Student{
    private:
    int rollno;

    public:
    int getRollno(){
        return rollno;
    }
    void setRollno(int i){
        rollno = i;
    }
};

int main(){
    Student A;
    A.setRollno(0);
    cout << A.getRollno();
    A.setRollno(1);
    cout << A.getRollno();
}