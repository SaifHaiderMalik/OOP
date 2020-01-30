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
int keyPosition, keyPressed, cfg0, cbg0, cfg1, cbg1, cfg2, cbg2, cfg3, cbg3;
keyPosition = 1, keyPressed = 0;
cfg0 = cbg1 = cfg2 = cfg3 = 15;
cbg0 = cfg1 = cbg2 = cbg3 = 0;
gotoxy(10, 10);
cout << char(201) << string(27, char(205)) << char(187) << endl;
gotoxy(10, 11);
cout << char(186) << setw(18) << " main menu" << setw(10) << char(186) << endl;gotoxy(10, 12);
cout << char(204) << string(27, char(205)) << char(185) << endl;
gotoxy(10, 13);
cout << char(186) << setw(28) << char(186) << endl;
gotoxy(10, 14);
cout << char(199) << string(27, char(196)) << char(182) << endl;
gotoxy(10, 15);
cout << char(186) << setw(28) << char(186) << endl;
gotoxy(10, 16);
cout << char(199) << string(27, char(196)) << char(182) << endl;
gotoxy(10, 17);
cout << char(186) << setw(28) << char(186) << endl;
gotoxy(10, 18);
cout << char(200) << string(27, char(205)) << char(188) << endl;
while (keyPressed != 13){
        SetColor(cfg0, cbg0);
        gotoxy(11, 13);
        SetColor(cfg1, cbg1);
        cout << string(5, ' ') << char(32) << "1" << char(32) << " " << "asas asas" << string(9, ' ');
        gotoxy(11, 15);
        SetColor(cfg2, cbg2);
        cout << string(5, ' ') << char(32) << "2" << char(32) << " " << "asasas asasas" << string(5, ' ');
        gotoxy(11, 17);
        SetColor(cfg3, cbg3);
        cout << string(5, ' ') << char(32) << "3" << char(32) << " " << "asasa asas" << string(8, ' ');
        gotoxy(11, 19);
        keyPressed = getche();
        if(keyPressed == 80 && keyPosition != 3){
                keyPosition++;
        }
        else if(keyPressed == 72 && keyPosition != 1){
                keyPosition--;
        }
        else if(keyPressed > 48 && keyPressed < 52){
                keyPosition = keyPressed - 48;
        }
        cfg0 = cfg1 = cfg2 = cfg3 = 15;
        cbg0 = cbg1 = cbg2 = cbg3 = 0;
        if(keyPosition == 1){
                swap(cfg1, cbg1);
        }
        else if(keyPosition == 2){
                swap(cfg2, cbg2);
        }
        else if(keyPosition == 3){
                swap(cfg3, cbg3);
        }
}
}