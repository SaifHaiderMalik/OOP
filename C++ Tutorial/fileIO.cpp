#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <fstream> //file operations
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>
#include <bits/stdc++.h> //sort()
#include <algorithm> //copy_if()

using namespace std;

int main(){
    ofstream writeToFile;
    ifstream readFromFile;
    string txtToWrite = "", txtFromFile = "";
    int i=0;

    /*
    out:    for writing only
    app:    append @ EOF only
    ate:    appenf @ any place of file (initial position: EOF)
    trunc:  erase all data in file first
    in:     for reading only
    we can combine these options with |
    */
    writeToFile.open("test.txt", ios_base::out | ios_base::trunc);
    if(writeToFile.is_open()){
        writeToFile << "First Line\n";
        cout << "Enter data to write on 2nd line: ";
        getline(cin, txtToWrite);
        writeToFile << "Second Line: "+txtToWrite+"\n";
        writeToFile.close();
    }

    readFromFile.open("test.txt", ios_base::in);
    if(readFromFile.is_open()){
        while(readFromFile.good()){
            getline(readFromFile, txtFromFile);
            cout << i << txtFromFile << endl;
            i++;
        }
        readFromFile.close();
    }

    return 0;
    
}