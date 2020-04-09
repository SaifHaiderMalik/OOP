#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string *stringPtr = new string(), str1;
    int stringLength;
    cout << "Please Enter String to Reverse: ";
    getline(cin, *stringPtr);
    cout << *stringPtr;
    stringLength = (*stringPtr).length();
    cout << stringLength;
    cout << "The Reverse of String is: ";
    for(int i = stringLength; i >= 0; i--){
        cout << (*stringPtr)[i];
    }
    return 0;
}