#include<iostream>
#include<string>

using namespace std;

//auto display(){

//    return 10;
//}

auto display()->int{

    return 110;
}



int main(void){

    auto i = 10;
    auto c = 'c';

    auto o = display();
    cout << o <<endl;
}