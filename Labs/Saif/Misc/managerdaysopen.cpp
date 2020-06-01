//#define _WIN32_WINNT 0x0A00
#include<iostream>
//#include<console.h>
#include<string>
#include<vector>
#include <iomanip>
#include <Windows.h>
#include "position.h"

using namespace std;

vector<string> days{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; 
bool * daysOpen = new bool[7]{false};


void showManagerRestaurant(){
    gotoxy(66, (getY() + 2));
        cout << "WORKING DAYS\n\t\t\t\t\t" << char(218);

        cout << string(6,char(196)) << char(194);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(194);
        }
        
        cout << "\b" << char(191) << "\n\t\t\t\t\t" << char(179);
        cout << " Code " << char(179);
        for(int i=0;i < days.size();i++){
            cout << string((days[i].length()-(days[i].length()/2)-1),' ') << i << string((days[i].length()-(days[i].length()/2)),' ') << char(179);
        }
        cout << "\n\t\t\t\t\t" << char(195);

        cout << string(6,char(196)) << char(194);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(194);
        }
        cout << "\b" << char(191) << "\n\t\t\t\t\t" << char(179);
        cout << " Days " << char(179);
        for(int i = 0; i < days.size(); i++){
            cout << days[i] << char(179);
        }
        
        cout << "\n\t\t\t\t\t" << char(195);
        cout << string(6,char(196)) << char(179);

        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(197);
        }
        

        cout << "\b" << char(180) << "\n\t\t\t\t\t" <<char(179) << "Status" << char(179) ;
              
        for(int j = 0; j < days.size(); j++){
            if(daysOpen[j] == true){cout << "OPEN" << string((days[j].length() - 4), ' ') << char(179);} else{
            cout << "CLOSE" << string((days[j].length() - 5), ' ') << char(179);}
        }
        
        cout << "\n\t\t\t\t\t" << char(212);
        cout << string(6,char(196)) << char(193);
        for(int i = 0; i < days.size(); i++){
            cout << string(days[i].length(), char(196)) << char(193);
        }
        cout << "\b" << char(217);
}

void showDays(){
    gotoxy(2, 7);
    cout << boolalpha << fixed << setprecision(2);
    cout << "\t\t\t\t\tDAYS" << "\n\t" << char(218) << string(6, char(196));
    for(int i=0;i< days.size();i++){
        cout << char(194) << string(days[i].length(),char(196));
    }
    cout << char(191) << "\n\t" << char(179) << " CODE " << char(179);
    for(int i = 0; i < days.size();i++){
        cout << setw(days[i].length()-2) << i << "  " << char(179);
    }
    cout << "\n\t" << char(195) << string(6, char(196));
    for(int i=0;i< days.size();i++){
        cout << char(197) << string(days[i].length(),char(196));
    }
    cout << char(180) << "\n\t" << char(179) << " DAYS ";
    for(int i=0;i< days.size();i++){
        cout << char(179) << days[i];
    }
    cout << char(179) << "\n\t" << char(195) << string(6, char(196));
    for(int i=0;i< days.size();i++){
        cout << char(197) << string(days[i].length(),char(196));
    }
    cout << char(180) << "\n\t" << char(179) << "STATUS";
    for(int i=0;i< days.size();i++){
        cout << char(179);
        if(daysOpen[i]==true){
            cout << setw(days[i].length()) << "OPEN";
        } else{
            cout << setw(days[i].length()) << "CLOSE";
        }
    }
    cout << char(179) << "\n\t" << char(192) << string(6,char(196));
    for(int i=0;i< days.size();i++){
        cout << char(193) << string(days[i].length(),char(196));
    }
    cout << char(217);
}


int main(void){
    string choice;
    do{
        showDays();
        cout << "\n\tChoice: ";
        getline(cin, choice);
        if(daysOpen[stoi(choice)] == true){
            cout << "2";
            daysOpen[stoi(choice)] = false;
        } else{
            daysOpen[stoi(choice)] = true;
        }
    }while(stoi(choice) < 7);
    

    
    system("pause");


}