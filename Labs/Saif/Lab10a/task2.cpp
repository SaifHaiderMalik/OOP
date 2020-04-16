#include<iostream>
#include<string>

using namespace std;
 
class Inventory{


      string id;             
      float cost;
      float sellingPrice;           
      
   public:

      
      Inventory(){

         id = "0000";
         cost = 0;
         sellingPrice = 0;

      }


      Inventory(string _id, float _cost, float _sellingPrice){

         id = _id;
         cost = _cost;
         sellingPrice = _sellingPrice;

      }


      friend ostream &operator<<(ostream &output, const Inventory &I){ 

         output << "id : " << I.id << " Cost : " << I.cost << " sellingPrice : " << I.sellingPrice;
         return output;            

      }

      friend istream &operator>>(istream  &input, Inventory &I){ 

         input >> I.id >> I.cost >> I.sellingPrice;
         return input;            

      }
};

int main(void) {

   Inventory I1("1111",1000,500), I2("2222",2000,250), I3;

   cout << "Enter the value of object : " << endl;
   cin >> I3;
   cout << "First Distance : " << I1 << endl;
   cout << "Second Distance :" << I2 << endl;
   cout << "Third Distance :" << I3 << endl;

   
}