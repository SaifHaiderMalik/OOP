#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void){

    ofstream os("C:\\Users\\sohai\\Desktop\\myfile.txt");
    os.seekp(5,ios::beg);

    os.put('A');

    int pos = os.tellp();
    cout << pos;
}