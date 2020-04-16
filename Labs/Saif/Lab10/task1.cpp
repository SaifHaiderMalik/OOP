#include<iostream>
#include<string>

using namespace std;


class Person{

    int age;

    public:

    Person(){

        age =0;
    }

    Person(int _age){

        age = _age;

    }

    bool operator ==(const Person& p){

        if(age == p.age){

            return true;
        }

        else{

            return false;
        }
    }

     bool operator !=(const Person& p){

        if(age != p.age){

            return true;
        }

        else{

            return false;
        }
    }

};



int main(void){


    int age1,age2;

    cout << "Enter Age of First Person: " <<endl;
    cin >> age1;

    Person ob1(age1);

    cout << "Enter Age of Second Person: " <<endl;
    cin >> age2;

    Person ob2(age2);

    if(ob1 == ob2){

        cout << "Both Persons age are equal " <<endl;

    }

    if(ob1 != ob2){

        cout << "Age for both Person are Not Equal " <<endl;

    }


}