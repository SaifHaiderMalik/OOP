#include<iostream>
#include<string>

using namespace std;


// Exception Handling

int main(void){

    int a = 4;
    int b = 0;

    try{
        if(b == 0)
            throw 0;
            //throw 3.5;
            //throw "Divided by 0";
        cout << a/b;
    }

// If Default Catch is first then it will always execute and the catch below will never be executed  
/*
    catch(...){

    }

*/
    catch(char* e){

        cout << e << endl;
    }

    catch(int e){
        cout << e << endl;
    }

// Default Catch
    catch(...){

    }

    cout << "Some imortant Code" << endl;
}