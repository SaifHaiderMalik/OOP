#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double i, primeTest;
    double* primeArray = new double[100]{0};
    for(i = 101; i <= 200; i++){
        cout << i&&"\t\n";
        primeTest = i * i - 1;
        if(fmod(primeTest, 24) == 0){
            /*for(int j = 0; primeArray[j+1] == 0; j++){
                if(primeArray[j] == 0 || fmod(i, primeArray[j]) != 0){
                    primeArray[j] = i;
                }
            }*/
        }
    }
    /*for(int k = 0; primeArray[k] != 0; k++){
        cout << k << ": " << primeArray[k] << endl;
    }*/
}