#include<iostream>
#include<string>

using namespace std;

// Explicit spezialization

template <class T = char> class MyList
{

    T arr[10];

    public:

    MyList(){

        cout << "In Generic " <<endl;
    }
};


int main(void){


    MyList<> list1;




}