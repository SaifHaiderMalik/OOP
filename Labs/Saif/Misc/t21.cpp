#include<iostream>
using namespace std;

//Stopping inheritance

//incomplete definition


class Dummy{

    private:

    Dummy(){

    }

    public:
    int zzz;
    /*Dummy(int _a){

    }*/

    friend class A;
};





class A: virtual Dummy{




};

class B : public A{


};


int main(void){

    A ob;
    ob.zzz = 222;



}