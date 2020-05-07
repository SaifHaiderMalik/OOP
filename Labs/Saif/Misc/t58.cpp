#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){

    vector<char> v1(5,'a');

    try{

        v1.at(13);

    }
    
    catch(out_of_range& e){
        cout << e.what() << endl;
    }

    catch(...){
        cout << "Some exception ocuured" << endl;
    }
}