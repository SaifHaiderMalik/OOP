#include<iostream>
#include<string>

using namespace std;

class personType{

    string firstName;
    string lastName;
    string middleName;

    public:

    personType(string _FName,string _LName,string _MName){
        
        firstName = _FName;
        lastName = _LName;
        middleName = _MName;

    }

    void setFirstName(string _firstName){
        
        firstName = _firstName;

    }

    void setLastName(string _lastName){

        lastName = _lastName;
    }

    void setMiddleName(string _middleName){

        middleName = _middleName;
    }

     void checkFirstName(string _firstName){

        if(firstName == _firstName){

            cout << "First Name is Same" <<endl;
        }

        else{

            cout << "First Name does not Match " <<endl;
        }

    }

      void checkLastName(string _lastName){

        if(lastName == _lastName){

            cout << "Last Name is Same" <<endl;
        }

        else{

            cout << "Last Name does not Match " <<endl;
        }

    }
    
};


int main(void){

    string FN;
    string LN;
    string MN;
    string checkFName;
    string checkLName;
    string checkMName;
  
    cout << "Enter First Name: " <<endl;
    cin >> FN;

    cout << "Enter Last Name: " <<endl;
    cin >> LN;

    cout << "Enter Middle Name: " <<endl;
    cin >> MN;

    personType ob(FN,LN,MN);

    cout << "Enter First Name to Check: " <<endl;
    cin >> checkFName;

    ob.checkFirstName(checkFName);

    cout << "Enter Last Name to Check: " <<endl;
    cin >> checkLName;

    ob.checkLastName(checkLName);



}