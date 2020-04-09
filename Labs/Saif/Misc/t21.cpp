#include<iostream>
using namespace std;

//Stopping inheritance


class Dummy{

    private:

    Dummy(){

    }

    friend class A;
};





class A: virtual Dummy{




};

class B : public A{


};


int main(void){

    A ob;


}