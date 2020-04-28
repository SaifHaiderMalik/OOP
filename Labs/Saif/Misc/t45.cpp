#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile2.txt");

// Opening file in Append mode
    ofstream os("C:\\Users\\sohai\\Desktop\\myfile2.txt", ios :: app);
    // os.put('B');

    os.write("Hello This is file2",15);
    
}