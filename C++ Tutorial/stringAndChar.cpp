#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    string str1 = "I'm a string";
    cout << "str1: " << str1 << endl;
    cout << "1st: " << str1[0] << endl;
    cout << "Last: " << str1.back() << endl;
    cout << "Length: " << str1.length() << endl;
    string str2 = str1; //OR string str2(str1);
    cout << "string str2 = str1 OR string str2(str1): " << str2 << endl;
    string str3(str2, 4);
    cout << "string str3(str2, 4): " << str3 << endl;
    string str4 = str1 + " and your not";
    cout << "string str4 = str1 + \" and your not\": " << str4 << endl;
    str4.append("!");
    cout << "str4.append(\"!\"): " << str4 << endl;
    str4.append(str4, 5, 7);
    cout << "str4.append(str4, 5, 7): " << str4 << endl;
    str4.erase(12, str4.length() - 1);
    cout << "str4.erase(12, str4.length() - 1): " << str4 << endl;

    if(str4.find("string") != string::npos){
        cout << "if(str4.find(\"string\") != string::npos) {str4.find(\"string\")}: " << str4.find("string") << endl;
    }

    cout << "str4.substr(6, 6): " << str4.substr(6, 6) << endl;
    string strNum = to_string(1 + 2);
    cout << "I'm a string: " << strNum << endl;
    cout << "Char @ Front: " << str4.front() << endl;
    cout << "Char @ Index 6: " << str4.at(6) << endl;
    cout << "Char @ Back: " << str4.back() << endl;
    string str5(5, 'X');
    cout << "string str5(5, 'X'): " << str5 << endl;
    reverse(str4.begin(), str4.end());
    cout << "reverse(str4.begin(), str4.end()): " << str4 << endl;
    transform(str4.begin(), str4.end()-6, str4.begin(), ::toupper);
    cout << "transform(str4.begin(), str4.end()-6, str4.begin(), ::toupper): " << str4 << endl;
    transform(str4.begin()+6, str4.end(), str4.begin()+6, ::toupper);
    cout << "transform(str4.begin()+6, str4.end(), str4.begin()+6, ::toupper): " << str4 << endl;
    cout << "(int)'A': " << (int)'A' << endl;
    string charToInt;
    for(char c: str4){
        charToInt += to_string((int)c) + ", ";
    }
    cout << "charToInt str4: " << charToInt << endl;
    string intToChar;
    for(int i = 0; i < charToInt.length(); i += 4){
        intToChar += stoi(charToInt.substr(i, 2));
    }
    cout << "intToChar str4: " << intToChar << endl;

    char letterZ = 'z';
    char num5 = '5';
    char aSpace = ' ';
    cout << "Is z a letter or number? " << isalnum(letterZ) << endl;
    cout << "Is z a letter? " << isalpha(letterZ) << endl;
    cout << "Is z a number? " << isdigit(letterZ) << endl;
    cout << "Is z a space? " << isspace(letterZ) << endl;
    cout << "Is 5 a letter or number? " << isalnum(num5) << endl;
    cout << "Is 5 a letter? " << isalpha(num5) << endl;
    cout << "Is 5 a number? " << isdigit(num5) << endl;
    cout << "Is 5 a space? " << isspace(num5) << endl;
    cout << "Is ' ' a letter or number? " << isalnum(aSpace) << endl;
    cout << "Is ' ' a letter? " << isalpha(aSpace) << endl;
    cout << "Is ' ' a number? " << isdigit(aSpace) << endl;
    cout << "Is ' ' a space? " << isspace(aSpace) << endl;
    
    return 0;
}