#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(void){

    map <int, int> voucherIndexLink;
    //map <string, int>::iterator p;
    //p = voucherIndexLink.begin();
    voucherIndexLink[5] = 50;
    for(int i = 0; i < 50; i++){
        cout << voucherIndexLink[i] << endl;
    }

    voucherIndexLink[10] = 5;

    //cout << voucherIndexLink.find(10) << endl;

    cout << voucherIndexLink[10] << endl;

    //cout << p->first << p->second << endl;
}