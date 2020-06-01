#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main(){
    fstream nFile;
    string code, name, line, _age, _male;
    char sName[20];
    int age, rec;
    bool male;
    nFile.open("file.bin", ios::out | ios::app | ios::binary);
    cout << "Number of records you want to Enter: ";
    cin >> rec;
    for(int i = 0; i < rec; i++){
        cout << "Code: ";
        cin >> code;
        cin.ignore();
        cout << "Name: ";
        //getline(cin, name);0
        cin.getline(sName, 20);
        //cin.getline()
        cout << "Age: ";
        cin >> age;
        cout << "Is Male? ";
        cin >> male;

        //nFile << code << ";" << sName << ";" << age << ";" << male << endl;
        nFile << sName << "\n" << code << ";" << age << ";" << male << endl;
    }
    nFile.close();

    nFile.open("file.bin", ios::in | ios::binary);
    //while(getline(nFile, line)){
    while(nFile != EOF)){
        nfile.getline(ss, sName, ';');
        stringstream ss(line);
        getline(ss, code, ';');
        
        getline(ss, _age, ';');
        getline(ss, _male, ';');
        age = stoi(_age);
        male = stoi(_male);
        cout << boolalpha << "Code: " << code << "\nName: " << sName << "\nAge: " << age << "\nIs Male: " << male << "\n\n";
    }
    nFile.close();
    system("pause");
    return 0;
}