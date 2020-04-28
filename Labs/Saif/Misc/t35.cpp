#include<iostream>
#include<string>
#include<vector>

using namespace std;


// can dynamically grow as we continue to add elements


int main(void){

    vector<int> v1;
    vector<char> v2(5);
    vector<char> v3(5,'a');
    vector<int> v4(v1);

    cout << v1.size() <<endl;
    cout << v2.size() <<endl;
    cout << v3.size() <<endl;
    cout << v4.size() <<endl;


    v1.push_back(1);
    v1.push_back(2);

    cout << v1.size() <<endl;

    cout << v3[0] <<endl;
    cout << v3[1] <<endl;

    vector<char>::iterator ptr;

    ptr = v3.begin();
    ptr += 4;

// starting from ptr , move steps further

    //v3.insert(ptr,1,'b');

    v3.insert(ptr,1,'b');

    /*
    cout << v3[0] <<endl;
    cout << v3[1] <<endl;
    cout << v3[2] <<endl;
    cout << v3[3] <<endl;
    cout << v3[4] <<endl;
    */

   for(auto v: v3){

       cout << v <<endl;
   }
    
}