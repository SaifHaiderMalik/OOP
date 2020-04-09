#include<iostream>

using namespace std;

//Design Pattern Singleton
//Not part of Course

class A{

    static A* instance;
    int var;


    A()
    {

    }

    public:

        static A* createInstance(){

            if(!instance)
                instance = new A;

                return instance;
        }
        

        void setVar(int var){

            this->var = var;
        }

        int getVar(){

            return var;

        }

};

//Initilization is must

A* A::instance = 0;


int main(void){

    A* ob;

   // ob->setVar(30);

   ob = ob->createInstance();

   ob->setVar(20);

   cout << ob->getVar() <<endl;

//Sharing same Instance of Class

   A* ob2;

   ob2 = ob2->createInstance();

   cout << ob2->getVar() <<endl;

}