#include<iostream>
#include<string>

using namespace std;

int main(void){

    int arr[10];
    int index;

    try{

        do{
            cin >> index;

            if(index < 0 || index > 9){
                //throw "Invalid index";
                throw out_of_range("Index out of Range");
            }
                arr[index] = index;
            
        }
        while(true);
    }

    catch(out_of_range& e){
        cout << e.what() << endl;
    }

    catch(const char * e){
        cout << e << endl;
    }

    catch(...){
        cout << "Error occured" << endl;
    }
}