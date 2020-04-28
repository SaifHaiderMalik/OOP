#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");

    // random access
    // read pointer
    // seekg(how many steps to move, where to start from)
    is.seekg(-3, ios::end);
    
    char c;
    is.get(c);
    cout << c;

}