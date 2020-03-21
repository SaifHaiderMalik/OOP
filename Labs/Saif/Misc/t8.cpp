#include<iostream>

using namespace std;

//Diamond Problem

class A{

    public:
  
    void func(){

        cout <<"This is Class A" <<endl;
    }
};

class B :  virtual public A{

        public:

        void func(){

            cout <<"This is Class B" <<endl;
        }

};


class C :  virtual public A{

        public:
    
        void func(){

            cout <<"This is Class C" <<endl;
        }

};



class D : public B , public C {

        public:
      
     //   void func(){

       //     cout <<"This is Class D" <<endl;

        //}
};


int main(void){


    D ob;

    ob.func();

}