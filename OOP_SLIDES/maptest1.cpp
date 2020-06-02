#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> emailLink;
    emailLink["Sohaib"] = "sohaib@gmail.com";
    emailLink["Haider"] = "haider@gmail.com";
    cout << "Sohaib:\t" << emailLink["Sohaib"] << endl;
    cout << "Haider:\t" << emailLink["Haider"] << endl;

    swap(emailLink["Sohaib"], emailLink["Haider"]);
    cout << "Sohaib:\t" << emailLink["Sohaib"] << endl;
    cout << "Haider:\t" << emailLink["Haider"] << endl;
    return 0;
}