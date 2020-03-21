#include<iostream>
#include<string>

using namespace std;

class Fruit{

    protected:

    int numberOfFruits;

    public:

    int CalculateNumberOfFruit(int num){

       numberOfFruits = num;

       return numberOfFruits;
    }
};

class Apple : public Fruit {

   

};

class Mangoes : public Fruit{

    
};

int main(void){

    int number;
    int total;
    int a,b;

    Apple A;
    Mangoes M;

    cout <<"Enter Number of Apple" <<endl;
    cin >> number;
   
    a = A.CalculateNumberOfFruit(number); 

    cout <<"Enter Number Of Mangoes" <<endl;
    cin >> number;

    b = M.CalculateNumberOfFruit(number);


    cout << "The number of Apples are: " << a <<endl;
    cout << "The number of Mangoes are: " << b <<endl;

    cout <<"The Total Number of Fruits are: " << a+b <<endl;
}