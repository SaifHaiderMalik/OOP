#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;


int main(void){

    char data[100];

    char ch;

    ofstream os;
    os.open("myfile.txt");

    cout << "Enter Name" << endl;
    cin.getline(data,100);

    os << data << endl;

    cout << "length of name: " << strlen(data) << endl;

    cout << "Enter age: " <<endl;
    cin >> data;
    cin.ignore();

    os << data << endl;

    os.close();

    ifstream is;

    is.open("myfile.txt");

    cout << "Reading from the file" << endl;

    while(is.get(ch)){

        cout << ch;
    }

    is.close(); 

}