#include<iostream>
#include<string>

using namespace std;

#include <iostream>
using namespace std;
 
class Students{

   private:
      float percentage;             
      float behavior;           
      

   public:
      
    Students() {

        percentage = 0;
        behavior = 0;

      }


    Students(float _percentage, float _behavior){
          
        percentage = _percentage;
         behavior = _behavior;
        

      }
      
      

      
    Students operator- (){

        percentage = -percentage;
        behavior = -behavior;

        return Students(percentage, behavior);

      }
      
      
      bool operator <(const Students& s) {
        if(percentage < s.percentage){

            return true;

        }

        if(percentage == s.percentage && behavior < s.behavior){

            return true;

        }
         
        return false;

      }
};

int main(void) {


   Students S1(11, 10), S2(5, 11);
 
    if( S1 < S2 ) {

        cout << "S1 is less than S2 " << endl;

    }
   
    else {

        cout << "S2 is less than S1 " << endl;

   }
   
   
}