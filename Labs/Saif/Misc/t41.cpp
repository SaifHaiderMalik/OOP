#include<iostream>
#include<string>
#include<fstream>

using namespace std;




int main(void){

    //D:// myfile.txt
    // Hello this is a test
    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");

    // reading a single character
   // char c = is.get();
   // cout << c << endl;

   // is.get(c);
    //cout << c << endl;
/*
    // reading a line 
    string lines[10];
    for(int i = 0;i < 10; i++){

        getline(is,lines[i]);
    }

    for(string line:lines){

        cout << line <<endl;
    }

    */

    // read text

    char * chArr = new char[100];
    is.read(chArr,100);

    cout << is.gcount() << endl;;
    
    for(int i = 0;i < 20; i++){

        cout << chArr[i];
    }

}