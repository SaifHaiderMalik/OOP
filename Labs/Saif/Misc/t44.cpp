#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");

// Loop if more than one line    
    //string lines[10];
    //getline(is,lines[0]);
    //cout << lines[0] << endl;

// Specified number of characters
    char * chArr = new char[10];
    is.read(chArr,10);

    for(int i = 0; i < 10; i++){

        cout << chArr[i];
    }
}