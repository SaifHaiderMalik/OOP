#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
//#include <dos.h>
#include <Windows.h>

using namespace std;

struct playerData{
    int playerIndex;
    string playerName;
    int playerHomeruns;
    int playerHits;
};

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
    playerData* playerDetails = new playerData[10]{};
    int keyPosition, keyPressed, cfg0, cfg1, cfg2, cfg3, cfg4, cfg5, cfg6, cfg7, cbg0, cbg1, cbg2, cbg3, cbg4, cbg5, cbg6, cbg7;

    MENU:
    keyPosition = 1, keyPressed = 0;
    cfg0 = cbg1 = cfg2 = cfg3 = cfg4 = cfg5 = cfg6 = cfg7 = 15;
    cbg0 = cfg1 = cbg2 = cbg3 = cbg4 = cbg5 = cbg6 = cbg7 = 0;
    
    system("cls");
    cout << char(201) << string(36, char(205)) << char(187) << endl;
    cout << char(186) << setw(23) << "MAIN MENU" << setw(14) << char(186) << endl;
    cout << char(204) << string(36, char(205)) << char(185) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(199) << string(36, char(196)) << char(182) << endl;
    cout << char(186) << setw(37) << char(186) << endl;
    cout << char(200) << string(36, char(205)) << char(188) << endl;

    while (keyPressed != 13){
        SetColor(cfg0, cbg0);
        gotoxy(1, 3);
        SetColor(cfg1, cbg1);
        cout << string(5, ' ') << char(174) << "1" << char(175) << " Add New Player Records" << string(5, ' ');
        gotoxy(1, 5);
        SetColor(cfg2, cbg2);
        cout << string(6, ' ') << char(174) << "2" << char(175) << " Update Player Record" << string(6, ' ');
        gotoxy(1, 7);
        SetColor(cfg3, cbg3);
        cout << string(6, ' ') << char(174) << "3" << char(175) << " Delete Player Record" << string(6, ' ');
        gotoxy(1, 9);
        SetColor(cfg4, cbg4);
        cout << string(6, ' ') << char(174) << "4" << char(175) << " Search Player Record" << string(6, ' ');
        gotoxy(1, 11);
        SetColor(cfg5, cbg5);
        cout << string(5, ' ') << char(174) << "5" << char(175) << " View All Player Record" << string(5, ' ');
        gotoxy(1, 13);
        SetColor(cfg6, cbg6);
        cout << string(7, ' ') << char(174) << "6" << char(175) << " Delete All Records" << string(7, ' ');
        gotoxy(1, 15);
        SetColor(cfg7, cbg7);
        cout << string(14, ' ') << char(174) << "7" << char(175) << " EXIT" << string(14, ' ');
        gotoxy(0,17);

        keyPressed = getche();

        if(keyPressed == 80 && keyPosition != 7){
			keyPosition++;
		}
        else if(keyPressed == 72 && keyPosition != 1){
			keyPosition--;
		}
        else if(keyPressed > 48 && keyPressed < 56){
            keyPosition = keyPressed-48;
        }

        cfg1 = cfg2 = cfg3 = cfg4 = cfg5 = cfg6 = cfg7 = 15;
		cbg1 = cbg2 = cbg3 = cbg4 = cbg5 = cbg6 = cbg7 = 0;

        if(keyPosition == 1){
			swap(cfg1, cbg1);
		}
        else if(keyPosition == 2){
			swap(cfg2, cbg2);
		}
        else if(keyPosition == 3){
			swap(cfg3, cbg3);
		}
        else if(keyPosition == 4){
			swap(cfg4, cbg4);
		}
        else if(keyPosition == 5){
			swap(cfg5, cbg5);
		}
        else if(keyPosition == 6){
			swap(cfg6, cbg6);
		}
        else if(keyPosition == 7){
            swap(cfg7, cbg7);
		}
    }
}