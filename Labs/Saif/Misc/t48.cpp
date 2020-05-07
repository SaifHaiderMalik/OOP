#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void){

    ifstream is("C:\\Users\\sohai\\Desktop\\myfile.txt");

    if(is){
        is.seekg(0,ios::end);
        int pos = is.tellg();
        is.seekg(0,ios::beg);

        char * text = new char[pos];
        is.read(text,pos);

        for(int i = 0;i < pos; i++){

            cout << text[i];
        }
    }

    else{
        cout << "File Not Found" << endl;
    }
}