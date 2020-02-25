#include <iostream>
#include <string>

using namespace std;

class CounterType{

    static int count;

    public:

   void setCounter(int _counter){

       if(_counter > 0){

            count = _counter;

        }
   }

   void setIncreaseCounter(){

       count = count + 1;
   }

   void setDecreaseCounter(){

       if(count > 0){

       count = count - 1;

        }
   }

   int returnCounter(){

       return count;
   }

   void getCounter(){

       cout << "The Count is: " << count;
   }

}; int CounterType :: count = 0; 

int main(){

    int counter;
    int c;

    CounterType ob;

    cout << "Enter Counter"<< endl;
    cin >> counter;

    ob.setCounter(counter);

    cout << endl << "Counter set is: " << endl;

    CounterType ob1;

    ob1.getCounter();

    CounterType ob2;

    ob2.setDecreaseCounter();

    cout << endl << "Counter Decreased is: " << endl;

    ob.getCounter();

    ob2.setIncreaseCounter();

    cout <<  endl <<"Counter Increased is: " << endl;

    ob.getCounter();

    c = ob.returnCounter();

    cout << endl << "Count Returned is: " << c << endl;


}