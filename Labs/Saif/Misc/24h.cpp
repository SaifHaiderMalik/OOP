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
            
            if(openTime == closeTime){
                cout << "1 Restaurant: Open" << endl; 
            }            
            else if(openTime > closeTime){
                if(((stoi(newTime) >= openTime) && (stoi(newTime) > closeTime)) || ((stoi(newTime) < openTime) && (stoi(newTime) < closeTime))){
                    cout << "2 Restaurant: Open" << endl;
                } else{
                    cout << "2 Restaurant: Close" << endl;
                }
            }
            else{
                if((stoi(newTime) >= openTime) && (stoi(newTime) <= closeTime)){
                    cout << "3 Restaurant: Open" << endl;
                } else{
                    cout << "3 Restaurant: Close" << endl;
                }
            }
        }
    }
    
    return 0;
}