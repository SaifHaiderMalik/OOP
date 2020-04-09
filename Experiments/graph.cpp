#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

using namespace std;

class COUNTRY{
    int dead;

public:
    int getDead(){return dead;}

    void setDead(int _dead){dead = _dead;}
};

void gotoxy(int x,int y)
{
        COORD coord={0,0};
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){
    COUNTRY pakistan, india;
    pakistan.setDead(650);
    india.setDead(300);
    int data[4] = {100, 200, 300, 500};
    int x = 1, y = 16, i, j;
    /*for(int k = 0; k < 2; k++){
        cout << data[k]/100;
    }*/

    for(i = 0; i < 4; i++){
        //gotoxy(x,16);
        //cout << i;
        for(j = 0; j < (data[i]/100); j++){
            gotoxy(x, y);
            cout << char(219);
            y--;
        }
        x+=2;
        y=16;
    }
    system("pause");
}