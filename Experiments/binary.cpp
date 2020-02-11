#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

uint64_t power(uint64_t b, uint64_t e){
    return (e == 0) ? 1 : b * power(b, e - 1);
}

int main(){
    unsigned long long int count, in, out = 0, out2;
    //vector <char> hex
    cin >> in;

    //Binary To Decimal
    for(int i = 0; in != 0; i++){
        if(in%10 == 1){
            out += power(2, i);
        }
        in/=10;
    }

    //Decimal To Binary
    for(int i = 0; power(2, i) <= (in * 2); i++){
        count = i;
    }

    for(int i = count; i >= 0; i--){
        if(power(2, i) <= in){
            out += power(10, i);
            in -= power(2, i);
            cout << "i = " << i << ", in = " << in << ", out = " << out << endl;
        }
    }

    /*for(int i = 0; in != 0; i++){

    }*/
    cout << dec << in;
    oct
}