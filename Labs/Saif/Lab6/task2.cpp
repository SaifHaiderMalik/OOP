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

    int numOfApples(){

        return numberOfFruits;
    }
    

};

class Mangoes : public Fruit{

     int numOfApples(){

        return numberOfFruits;
    }
    
};

int main(void){

    int number;
    int total;
    int a,b;

    Apple A;
    Mangoes M;

    cout <<"Enter Number of Apple" <<endl;
    cin >> number;

    cout << "The number of Apples are: " << A.CalculateNumberOfFruit(number) <<endl;

    a = A.CalculateNumberOfFruit(number); 

    cout <<"Enter Number Of Mangoes" <<endl;
    cin >> number;

    b = M.CalculateNumberOfFruit(number);

    cout << "The number of Mangoes are: " << M.CalculateNumberOfFruit(number) <<endl;

    cout <<"The Total Number of Fruits are: " << a+b <<endl;
}