#include<iostream>
#include<string>

using namespace std;


class Binary{

    int bit;

    public:

    Binary(){

        bit = 0;
 
    }

    Binary(int _bit){

        if(_bit == 0 || _bit == 1){

            bit = _bit;

        }

      

    }

    void setBinary(int _bit){

        if(_bit == 0 || _bit == 1){

            bit = _bit;

        }

    }

    int getBinary(){

        return bit;

    }


    int operator &&(const Binary& b){

        if(bit == 0 && b.bit == 0){

            return 0;

        }

        else if(bit == 1 && b.bit == 0){

            return 0;
        }

        else if(bit == 0 && b.bit ==1){

            return 0;
        }

        else if(bit == 1 && b.bit ==1){

            return 1;

        } 
    }



};


int main(void){

    int bit;
    int bulb;
    int i;

    Binary ob1,ob2;

    for(i=0;i<4;i++){

        cout << "Enter Bit1: " <<endl;
        cin >> bit;

        ob1.setBinary(bit);

        cout << "Enter Bit2: " <<endl;
        cin >> bit;

        ob2.setBinary(bit);

        bulb = ob1.getBinary() && ob2.getBinary();

        if(bulb == 0){

            cout << "Bulb off " <<endl;

        }

        else if(bulb == 1){

            cout << "Bulb On " <<endl;

        }

    }
    
}