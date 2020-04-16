#include<iostream>
#include<string>

using namespace std;


// Explicit spezialization

template <> class MyList<int>
{

    int arr[10];

    public:

    MyList(){

        cout << "In Generic " <<endl;
    }
};


template <class T >

int main(void){

    MyList<char> list1;

    MyList<int> list2;





}