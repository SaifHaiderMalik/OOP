#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
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

void feetAndInchesToMetersAndCent(int _inches, int& _centimeters){
    _centimeters = _inches * 2.54;
}

void metersAndCentTofeetAndInches(int _centimeters, int& _inches){
    _inches = _centimeters / 2.54;
}

void showChoices(){
    int feet, inches, meters, centimeters, keyPosition, keyPressed, cfg0, cbg0, cfg1, cbg1, cfg2, cbg2, cfg3, cbg3;
    keyPosition = 1, keyPressed = 0;
    cfg0 = cbg1 = cfg2 = cfg3 = 15;
    cbg0 = cfg1 = cbg2 = cbg3 = 0;

    system("cls");
    gotoxy(10, 5);
    cout << char(201) << string(47, char(205)) << char(187) << endl;
    gotoxy(10, 6);
    cout << char(186) << setw(32) << " LENGTH CONVERSION" << setw(16) << char(186) << endl;gotoxy(10, 7);
    cout << char(204) << string(47, char(205)) << char(185) << endl;
    gotoxy(10, 8);
    cout << char(186) << setw(48) << char(186) << endl;
    gotoxy(10, 9);
    cout << char(199) << string(47, char(196)) << char(182) << endl;
    gotoxy(10, 10);
    cout << char(186) << setw(48) << char(186) << endl;
    gotoxy(10, 11);
    cout << char(199) << string(47, char(196)) << char(182) << endl;
    gotoxy(10, 12);
    cout << char(186) << setw(48) << char(186) << endl;
    gotoxy(10, 13);
    cout << char(200) << string(47, char(205)) << char(188) << endl;

    while (keyPressed != 13){
        SetColor(cfg0, cbg0);
        gotoxy(11, 8);
        SetColor(cfg1, cbg1);
        cout << string(3, ' ') << char(91) << "1" << char(93) << " " << "Feet & Inches To Meters & Centimeters" << string(3, ' ');
        gotoxy(11, 10);
        SetColor(cfg2, cbg2);
        cout << string(3, ' ') << char(91) << "2" << char(93) << " " << "Meters & Centimeters To Feet & Inches" << string(3, ' ');
        gotoxy(11, 12);
        SetColor(cfg3, cbg3);
        cout << string(3, ' ') << char(91) << "3" << char(93) << " " << "Exit" << string(36, ' ');
        gotoxy(11, 14);

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
    if(keyPosition == 1){
        cout << "Enter Length in Feet & Inches: ";
        cin >> feet >> inches;
        inches += (feet * 12);
        feetAndInchesToMetersAndCent(inches, centimeters);
        cout << "Result: " << centimeters/100 << " Meters and " << centimeters%100 << " Centimeters.";
        getch();
        showChoices();
    }
    else if(keyPosition == 2){
        cout << "Enter Length in Meters & Centimeters: ";
        cin >> meters >> centimeters;
        centimeters += (meters * 100);
        metersAndCentTofeetAndInches(centimeters, inches);
        cout << "Result: " << inches/12 << " Feet and " << inches%12 << " Inches.";
        getch();
        showChoices();
    }
    else{
        system("exit");
    }
}

int main(){
    showChoices();
}