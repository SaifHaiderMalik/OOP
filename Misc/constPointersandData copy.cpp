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

class A
{
	public:
	A(){

    }

	static void f( ){
        int b = f2(); // will cause error
    }
	
	int f2( ){
       return 55;
	}
}; 

int main(){
	A ob;
}
