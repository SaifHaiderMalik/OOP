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
int jjmjm, nhnhn, bgbgb0, vfvfv0, bgbgb1, vfvfv1, bgbgb2, vfvfv2, bgbgb3, vfvfv3;
jjmjm = 1, nhnhn = 0;
bgbgb0 = vfvfv1 = bgbgb2 = bgbgb3 = 15;
vfvfv0 = bgbgb1 = vfvfv2 = vfvfv3 = 0;
gotoxy(10, 10);
cout << char(201) << string(23, char(205)) << char(187) << endl;
gotoxy(10, 11);
cout << char(186) << setw(16) << " dfdf dfdf" << setw(8) << char(186) << endl;gotoxy(10, 12);
cout << char(204) << string(23, char(205)) << char(185) << endl;
gotoxy(10, 13);
cout << char(186) << setw(24) << char(186) << endl;
gotoxy(10, 14);
cout << char(199) << string(23, char(196)) << char(182) << endl;
gotoxy(10, 15);
cout << char(186) << setw(24) << char(186) << endl;
gotoxy(10, 16);
cout << char(199) << string(23, char(196)) << char(182) << endl;
gotoxy(10, 17);
cout << char(186) << setw(24) << char(186) << endl;
gotoxy(10, 18);
cout << char(200) << string(23, char(205)) << char(188) << endl;
while (nhnhn != 13){
SetColor(bgbgb0, vfvfv0);
gotoxy(11, 13);
SetColor(bgbgb1, vfvfv1);
cout << string(3, ' ') << "fdf fdf" << string(13, ' ');
gotoxy(11, 15);
SetColor(bgbgb2, vfvfv2);
cout << string(3, ' ') << "dfdf fdfdfdfdf df" << string(3, ' ');
gotoxy(11, 17);
SetColor(bgbgb3, vfvfv3);
cout << string(3, ' ') << "df" << string(18, ' ');
gotoxy(11, 19);
cout << Option Selected: ";
nhnhn = getche();
if(nhnhn == 80 && jjmjm != 3){
jjmjm++;
}
else if(nhnhn == 72 && jjmjm != 1){
jjmjm--;
}
bgbgb0 = bgbgb1 = bgbgb2 = bgbgb3 = 15;
vfvfv0 = vfvfv1 = vfvfv2 = vfvfv3 = 0;
if(jjmjm == 1){
swap(bgbgb1, vfvfv1);
}
else if(jjmjm == 2){
swap(bgbgb2, vfvfv2);
}
else if(jjmjm == 3){
swap(bgbgb3, vfvfv3);
}
}
}