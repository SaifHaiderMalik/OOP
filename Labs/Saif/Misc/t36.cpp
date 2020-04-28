#include<iostream>
#include<string>
#include<map>

using namespace std;





int main(void){

// Key is char and Value is int

    map<char,int> m1;

//  Data can only be inserted as Pairs for map
    m1.insert(pair<char,int>('a',1));

// Use Key to display for maps as map is sorted for keys
   // cout << m1['a'];

// Key cannot be repeated but multiple values can be given

    map<char,int>::iterator p;
    p = m1.begin();

    cout << "KEY: " << p->first << " and Value: " << p->second << endl;

    p = m1.find('a');
    cout << p->second;

    return 0;
}