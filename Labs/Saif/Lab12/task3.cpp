#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Person{

    char* name;
    int age;

    public:

    Person(){}

    Person(char* _name, int _age){

        name = _name;
        age = _age;

    }

    void display(){

        cout << name << endl;
        cout << age << endl;
    } 
};

int main(void){

    Person p1("Saif",20);
    Person p2;

    ofstream os("person.bin");
    os.write((char*) &p1, sizeof(p1));
    os.close();

    ifstream is("person.bin");

    is.read((char*) &p2, sizeof(p2));
    p2.display();

    return 0;

}