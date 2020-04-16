#include<iostream>
#include<string>

using namespace std;


template<class T , int size> class MyList{

    T arr[size];

    public:

    void addElement(int index, T val){

        arr[index] = val;
    }

    bool searchElement(T val){

        for(int i = 0; i < size; i++){

            if(arr[i] == val){

                return true;

            }

        }

            
        return false;
         

    }
    

};


int main(void){

    MyList<char , 15> list1;

    list1.addElement(0,10);
    list1.addElement(1,20);
    list1.addElement(2,30);


    bool result = list1.searchElement(20);

    if(result)
        cout << "Found" <<endl;

    else 
        cout << "Not Found" <<endl;





}