//Example Code for Static Variables:
//Program: Static and automatic variables

#include <iostream>

using namespace std;

void test ();

//int x = 0;


int main(){
    int count;
    for (count = 1; count <= 5; count++)
    test ();

    return 0;
}

void test ()
{
    static int x = 0;
    //int x = 0;
    //static int y = 10;
    int y = 10;
    x = x + 2;
    y = y + 1;
    cout << "Inside test x = " << x << " and y = " << y << endl;
}