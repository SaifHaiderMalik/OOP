#include<iostream>
#include<string>
#include<map>

using namespace std;


map<string, string> contacts;    
map<string, string>::iterator p;

void addContact(string name, string number){

    contacts.insert(pair<string,string>(name,number));

}

void showAll(){

    p = contacts.begin();
    while(p != contacts.end()){

        cout << "Name: " << p->first <<endl;
        cout << "Contac# " <<p->second <<endl;
        cout << "\n\n";
        p++; 
    }

}

void searchContact(string name){

    p = contacts.find(name);

    if( p != contacts.end()){

        cout << "Contact# " << p->second <<endl;
    }

    else{

        cout << "Contact does not exist" <<endl;
    }
}

void removeContact(string name){

    p = contacts.find(name);

    if(p != contacts.end()){

        contacts.erase(p);
    }

    else{

        cout << "Contact does not exist" <<endl; 
    }

}


// Map arrangement for Key is sorted in ascending
int main(void){

    addContact("Bilal","03001234567");
    addContact("Abid","090078601");
    addContact("Ali", "03123456789");

    showAll();
    searchContact("Abid");
    removeContact("Bilal");
    showAll();
    

}