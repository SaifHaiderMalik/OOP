#include <iostream>
#include <string>

using namespace std;

int main(){
    int openTime, closeTime;
    string newTime;
    while(newTime != "q"){
        cout << "Open Time: ";
        cin >> openTime;
        cout << "Close Time: ";
        cin >> closeTime;
        while(newTime != "q" || newTime != "r"){
            cout << "New Time: ";
            cin >> newTime;
            if(newTime == "q" || newTime == "r"){
                break;
            }
            if(openTime == closeTime){
                cout << "Restaurant: Open" << endl;
            } else if(openTime > closeTime){
                if(((stoi(newTime) >= openTime) && (stoi(newTime) > closeTime)) || ((stoi(newTime) < openTime) && (stoi(newTime) <= closeTime))){
                    cout << "Restaurant: Open" << endl;
                } else{
                    cout << "Restaurant: Close" << endl;
                }
            } else{
                if((stoi(newTime) >= openTime) && (stoi(newTime) <= closeTime)){
                    cout << "Restaurant: Open" << endl;
                } else{
                    cout << "Restaurant: Close" << endl;
                }
            }
        }
    }
    
    return 0;
}