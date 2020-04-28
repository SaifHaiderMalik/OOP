#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");
    
// If File exists then return True else False
    if(is){
    
    char c = is.get();
    cout << c <<endl;

    }

    else{
        cout << "File not Found" << endl;
    }
}