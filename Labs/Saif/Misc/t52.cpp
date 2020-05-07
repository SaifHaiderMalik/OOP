#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main(void){

    ofstream os("mysimplefile.txt");
    os << "This is a simple Test";
}