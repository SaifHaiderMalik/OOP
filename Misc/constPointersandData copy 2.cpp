#include <cstdlib> //General purpose functions
#include <iostream> //Read and Write Data
#include <string>
#include <limits> //Functions for MIN and MAX values
#include <vector>
#include <sstream> //String Streams
#include <numeric> //Sequences of Values
#include <ctime>
#include <cmath>

using namespace std;

int main(){
	const int a = 10;
	int b = 50;
		
	 int* pA = &a;
    int * const pB = &b;
	//*pA = 20;		// this line will cause error
	//pA = &b;
    //a = 60;
    *pB = 20;
    //*pA = 20;
    cout << *pA << endl;
    cout << *pB << endl;
}
