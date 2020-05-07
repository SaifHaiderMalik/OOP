#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main(void){

    char data[100];

    ofstream os;
    os.open("text1.txt");

    cout << "Enter Name" << endl;
    cin.getline(data,100);
    os << data << endl;

    cout << "Enter age: " <<endl;
    cin >> data;
    cin.ignore();
    os << data << endl;

    os.close();

    ifstream is;

    is.open("text1.txt");
    os.open("text2.txt");

    char ch;

    while(is.get(ch)){

        os << ch;
    }
   
    if (is.eof()) {
		cout << " File 1 Read Successfuly" << endl;
	}

	else {
		cout << "File 1 Not Read Successfuly" << endl;
	}

    is.close();
    os.close();


    is.open("text2.txt");

    while(is.get(ch)){

        cout << ch;

    }
   
	is.close();

    is.open("text2.txt");

    cout << "Content copied from File 1 to File 2" << endl;

    while(is.get(ch)){

        cout << ch;
    }

    
}