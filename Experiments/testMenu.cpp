#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
//#include <dos.h>
#include <Windows.h>

using namespace std;

void gotoxy(int x,int y)
{
        COORD coord={0,0};
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void SetColor(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);		
}

int main(){
int keyPosition, keyPressed, cfg0, cbg0, cfg1, cbg1, cfg2, cbg2;
keyPosition = 1, keyPressed = 0;
cfg0 = cbg1 = cfg2 = 15;
cbg0 = cfg1 = cbg2 = 0;
gotoxy(10, 10);
cout << char(201) << string(15, char(205)) << char(187) << endl;
gotoxy(10, 11);
cout << char(186) << setw(12) << " MAIN MENU" << setw(4) << char(186) << endl;gotoxy(10, 12);
cout << char(204) << string(15, char(205)) << char(185) << endl;
gotoxy(10, 13);
cout << char(186) << setw(16) << char(186) << endl;
gotoxy(10, 14);
cout << char(199) << string(15, char(196)) << char(182) << endl;
gotoxy(10, 15);
cout << char(186) << setw(16) << char(186) << endl;
gotoxy(10, 16);
cout << char(200) << string(15, char(205)) << char(188) << endl;
while (keyPressed != 13){
        SetColor(cfg0, cbg0);
        gotoxy(11, 13);
        SetColor(cfg1, cbg1);
        cout << string(3, ' ') << " ADD" << string(13, ' ');
        gotoxy(11, 15);
        SetColor(cfg2, cbg2);
        cout << string(3, ' ') << " DELETE" << string(10, ' ');
        gotoxy(11, 17);
        keyPressed = getche();
        if(keyPressed == 80 && keyPosition != 2){
                keyPosition++;
        }
        else if(keyPressed == 72 && keyPosition != 1){
                keyPosition--;
        }
        else if(keyPressed > 48 && keyPressed < 51){
                keyPosition = keyPressed - 48;
        }
        cfg0 = cfg1 = cfg2 = 15;
        cbg0 = cbg1 = cbg2 = 0;
        if(keyPosition == 1){
                swap(cfg1, cbg1);
        }
        else if(keyPosition == 2){
                swap(cfg2, cbg2);
        }
}
}