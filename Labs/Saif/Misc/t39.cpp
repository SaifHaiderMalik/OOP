#include<iostream>
#include<string>

using namespace std;

int main(void){

    char* word = "Hello";
    cout << word << endl;
    cout << static_cast<void*>(word) << endl;

}
