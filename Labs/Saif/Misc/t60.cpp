#include<iostream>
#include<string>

using namespace std;

class MyException : public exception{

    public:
    const char* what() const throw(){
            return "An exception of type MyException occured";
    }
};

int main(void){
    
    int i = 0;    

    try{
        if(i==0){
            throw MyException();
        }
    }
    catch(MyException& e){
        cout << e.what() << endl;
    }
    catch(exception& e){
        cout << "some error found" << endl; 
    }
}