#include<iostream>
#include<string>

using namespace std;

int main(void){

// Bad Memory(Javascript)/Allocation
    try{
        int i = 0;
        while(i < 1){

            new int[1000000];
        }
    }
//catch all standard exception 
// exception class is a parent class
      catch(exception& e){
        cout << "Some Error Ocurred" << endl;
    }


    catch(bad_alloc& e){
        //cout << "cannot alllocate memory" << endl;
        cout << e.what() << endl;
    }

    catch(out_of_range& e){
        cout << "This Catch block will never be used for this code" << endl;
    }

  

    cout << "Code" << endl;
}