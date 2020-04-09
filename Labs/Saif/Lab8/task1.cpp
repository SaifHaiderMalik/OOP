#include<iostream>
#include<string>
using namespace std;

class Message{

    string value;

    public:

    Message(string _value = "ABC"){

        value = _value;
    }

    void print(){

        cout << "The default String is: " << value <<endl;
    }

    void print(string _value){

        value = _value;
        //cout << "The String of Function is: " << _value <<endl;
        cout << "The String with argument function is: " << value <<endl;

    }


};

int main(void){

    string a;

    Message ob;

    

    cout << "Enter a String" <<endl;
    cin >> a;

    ob.print();
    ob.print(a);


}

