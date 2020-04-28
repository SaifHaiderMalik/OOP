#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");

    // random access
    // read pointer
    // seekg(how many steps to move, where to start from)
    //is.seekg(6, ios::beg);
    is.seekg(-2, ios::end);
    char * chArr = new char[10];
    is.read(chArr,10);

    for(int i =0; i <10; i++){

        cout << chArr[i];
    }


}