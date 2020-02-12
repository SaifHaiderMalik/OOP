//Example Code for Value Returning Functions:
#include <iostream>

using namespace std;

double larger (double x, double y)
{
    double max;
    if (x >= y){
        max = x;
    }
    else{
        max = y;
    }

    return max;
}

double compareThree (double x, double y, double z)
{
    return larger (x, larger (y, z));
}


int main(){
    double one = 10, two = 20, maxNum, maxNum3;
    cout << "The larger of 5 and 6 is " << larger (5, 6) << endl; //Line 1
    cout << "The larger of " << one << " and " << two << " is " << larger (one, two) << endl; //Line 2
    cout << "The larger of " << one << " and 29 is " << larger (one, 29) << endl; //Line 3
    maxNum = larger (38.45, 56.78); //Line 4
    maxNum3 = compareThree(one, two, maxNum);
    cout << "one: " << one << endl << "two: " << two << endl << "maxNum: " << maxNum << endl << "maxNum3: " << maxNum3;
}