#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Exception Handling

int divide(int a,int b){

    if(b == 0){
        throw "Divide by zero";
    }
    return a/b;
}

int main(void){

    try{
        cout << divide(4,8);
    }

    catch(const char* msg){
        cout << msg;
    }
    
}