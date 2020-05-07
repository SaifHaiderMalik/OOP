#include <iostream>
using namespace std;

class A{

    static int revenue;
    public:

    static void setRevenue(int a){

        a = 100;
        revenue = a;
    }

    friend static int getRevenue();

 

};

friend static int A::getRevenue(){

        return revenue;
    }


class B{
    
    public:

    friend int A::getRevenue();

    
};


int main(void){

    A ob;

    ob.getRevenue();
}