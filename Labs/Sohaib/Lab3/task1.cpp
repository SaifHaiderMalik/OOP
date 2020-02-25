#include <iostream>
#include <Windows.h>
#include <iterator>
#include <iomanip>
#include <conio.h>
#include <string>
#include <map>

using namespace std;

class bankAccount{
    private:
    string adminPass = "1234";
    map<uint64_t, uint64_t> accountBalance;

    public:
    float taxRate = 0.6;
    uint64_t taxableAmount = 25000;
    uint64_t minOpenDeposit = 5000;
    map<uint64_t, string> accountTitle;

    bool passCheck(string _pass){
        if(_pass == adminPass){
            return true;
        }
        else{
            cout << "Bad Password!" << endl;
            return false;
        }
    }

    uint64_t balanceCheck(string _pass, uint64_t _accountNumber){
        if(passCheck(_pass) == true){
            cout << "Account Balance: ";
            return accountBalance[_accountNumber];
        }
    }

    string titleCheck(string _pass, uint64_t _accountNumber){
        if(passCheck(_pass) == true){
            if(accountTitle[_accountNumber].length() != 0){
                cout << "Account Title: ";
                return accountTitle[_accountNumber];
            }
            else{
                cout << "Account Number '" << _accountNumber << "' does not belong to anyone";
            }
        }
    }

    void newAccount(string _pass, uint64_t _accountNumber, string _accountTitle, uint64_t _amount){
        if(passCheck(_pass) == true){
            if(accountTitle[_accountNumber].length() == 0){
                if(_amount >= minOpenDeposit){
                    accountTitle[_accountNumber] = _accountTitle;
                    accountBalance[_accountNumber] = _amount;
                    cout << "Account Created" << endl;
                }
                else{
                    cout << "Minimum Cash Deposit Required @ Account Oppening is: " << minOpenDeposit << endl;
                }
            }
            else{
                cout << "Account Number: " << _accountNumber << " is already assigned to " << accountTitle[_accountNumber] << endl;
            }
        }
    }

    void cashDeposit(uint64_t _accountNumber, uint64_t _amount){
        if(accountTitle[_accountNumber] != ""){
            accountBalance[_accountNumber] += _amount;
            cout << "Cash Deposited" << endl;
        }
        else{
            cout << "Account Number: " << _accountNumber << " does not exist." << endl;
        }
    }

    void cashWithdrawl(uint64_t _accountNumber, uint64_t _amount){
        if(accountTitle[_accountNumber] != ""){
            if(_amount > taxableAmount && accountBalance[_accountNumber] >= (_amount + _amount * taxRate)){
                accountBalance[_accountNumber] -= (_amount + _amount * taxRate);
                cout << "Cash Withdrawl Successful" << endl;
            }
            else if(accountBalance[_accountNumber] >= _amount){
                accountBalance[_accountNumber] -= _amount;
                cout << "Cash Withdrawl Successful" << endl;
            }
            else{
                cout << "Not Enought Balance" << endl;
            }
        }
        else{
            cout << "Account Number: " << _accountNumber << " does not exist." << endl;   
        }
    }

    void closeAccount(string _pass, uint64_t _accountNumber, string _accountTitle){
        if(passCheck(_pass) == true){
            if(accountTitle[_accountNumber] == _accountTitle){
                cout << "Balance: " << accountBalance[_accountNumber] << endl;
                if(accountBalance[_accountNumber] > taxableAmount){
                    cout << "Withholding Tax Deducted: " << accountBalance[_accountNumber] * taxRate << endl;
                    accountBalance[_accountNumber] -= accountBalance[_accountNumber] * taxRate;
                }
                cout << "Return: " << accountBalance[_accountNumber] << endl;
                accountBalance[_accountNumber] = 0;
                accountTitle[_accountNumber] = "";
            }
            else{
                cout << "Account Number and Account Title do not match" << endl;
            }
        }
    }
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

void HideUnhide(int _mode){
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    if(_mode == 1){
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    }
    else{
        SetConsoleMode(hStdin, mode);
    }
}

int main(){
    string pass, accountTitle;
    uint64_t accountNumber, amount;
    bankAccount BANK;

    MENUB:
    system("cls");
    int bsPos, bsPress, bscf0, bscb0, bscf1, bscb1, bscf2, bscb2, bscf3, bscb3;
    bsPos = 1, bsPress = 0;
    bscf0 = bscb1 = bscf2 = bscf3 = 15;
    bscb0 = bscf1 = bscb2 = bscb3 = 0;
    gotoxy(2, 1);
    cout << char(201) << string(22, char(205)) << char(187) << endl;
    gotoxy(2, 2);
    cout << char(186) << setw(16) << " BANK SYSTEM" << setw(7) << char(186) << endl;gotoxy(2, 3);
    cout << char(204) << string(22, char(205)) << char(185) << endl;
    gotoxy(2, 4);
    cout << char(186) << setw(23) << char(186) << endl;
    gotoxy(2, 5);
    cout << char(199) << string(22, char(196)) << char(182) << endl;
    gotoxy(2, 6);
    cout << char(186) << setw(23) << char(186) << endl;
    gotoxy(2, 7);
    cout << char(199) << string(22, char(196)) << char(182) << endl;
    gotoxy(2, 8);
    cout << char(186) << setw(23) << char(186) << endl;
    gotoxy(2, 9);
    cout << char(200) << string(22, char(205)) << char(188) << endl;

    while (bsPress != 13){
        SetColor(bscf0, bscb0);
        gotoxy(3, 4);
        SetColor(bscf1, bscb1);
        cout << string(3, ' ') << char(60) << "1" << char(62) << " " << "Manager Menu" << string(3, ' ');
        gotoxy(3, 6);
        SetColor(bscf2, bscb2);
        cout << string(3, ' ') << char(60) << "2" << char(62) << " " << "Cashier Menu" << string(3, ' ');
        gotoxy(3, 8);
        SetColor(bscf3, bscb3);
        cout << string(3, ' ') << char(60) << "3" << char(62) << " " << "EXIT" << string(11, ' ');
        gotoxy(3, 10);
        cout << "Option Selected: ";
        bsPress = getche();

        if(bsPress == 80 && bsPos != 3){
            bsPos++;
        }
        else if(bsPress == 72 && bsPos != 1){
            bsPos--;
        }
        else if(bsPress > 48 && bsPress < 52){
            bsPos = bsPress - 48;
        }

        bscf0 = bscf1 = bscf2 = bscf3 = 15;
        bscb0 = bscb1 = bscb2 = bscb3 = 0;

        if(bsPos == 1){
            swap(bscf1, bscb1);
        }
        else if(bsPos == 2){
            swap(bscf2, bscb2);
        }
        else if(bsPos == 3){
            swap(bscf3, bscb3);
        }
    }

    switch(bsPos){
        case 1:
        goto MENUM;

        case 2:
        goto MENUC;

        case 3:
        system("exit");
    }

    MENUM:
    system("cls");
    int mmPos, mmPress, mmcf0, mmcb0, mmcf1, mmcb1, mmcf2, mmcb2, mmcf3, mmcb3, mmcf4, mmcb4, mmcf5, mmcb5;
    mmPos = 1, mmPress = 0;
    mmcf0 = mmcb1 = mmcf2 = mmcf3 = mmcf4 = mmcf5 = 15;
    mmcb0 = mmcf1 = mmcb2 = mmcb3 = mmcb4 = mmcb5 = 0;
    gotoxy(2, 1);
    cout << char(201) << string(25, char(205)) << char(187) << endl;
    gotoxy(2, 2);
    cout << char(186) << setw(18) << " MANAGER MENU" << setw(8) << char(186) << endl;gotoxy(2, 3);
    cout << char(204) << string(25, char(205)) << char(185) << endl;
    gotoxy(2, 4);
    cout << char(186) << setw(26) << char(186) << endl;
    gotoxy(2, 5);
    cout << char(199) << string(25, char(196)) << char(182) << endl;
    gotoxy(2, 6);
    cout << char(186) << setw(26) << char(186) << endl;
    gotoxy(2, 7);
    cout << char(199) << string(25, char(196)) << char(182) << endl;
    gotoxy(2, 8);
    cout << char(186) << setw(26) << char(186) << endl;
    gotoxy(2, 9);
    cout << char(199) << string(25, char(196)) << char(182) << endl;
    gotoxy(2, 10);
    cout << char(186) << setw(26) << char(186) << endl;
    gotoxy(2, 11);
    cout << char(199) << string(25, char(196)) << char(182) << endl;
    gotoxy(2, 12);
    cout << char(186) << setw(26) << char(186) << endl;
    gotoxy(2, 13);
    cout << char(200) << string(25, char(205)) << char(188) << endl;

    while (mmPress != 13){
        SetColor(mmcf0, mmcb0);
        gotoxy(3, 4);
        SetColor(mmcf1, mmcb1);
        cout << string(3, ' ') << char(60) << "1" << char(62) << " " << "New Account" << string(7, ' ');
        gotoxy(3, 6);
        SetColor(mmcf2, mmcb2);
        cout << string(3, ' ') << char(60) << "2" << char(62) << " " << "Account Title" << string(5, ' ');
        gotoxy(3, 8);
        SetColor(mmcf3, mmcb3);
        cout << string(3, ' ') << char(60) << "3" << char(62) << " " << "Account Balance" << string(3, ' ');
        gotoxy(3, 10);
        SetColor(mmcf4, mmcb4);
        cout << string(3, ' ') << char(60) << "4" << char(62) << " " << "Close Account" << string(5, ' ');
        gotoxy(3, 12);
        SetColor(mmcf5, mmcb5);
        cout << string(3, ' ') << char(60) << "5" << char(62) << " " << "BACK" << string(14, ' ');
        gotoxy(3, 14);
        cout << "Option Selected: ";
        mmPress = getche();

        if(mmPress == 80 && mmPos != 5){
            mmPos++;
        }
        else if(mmPress == 72 && mmPos != 1){
            mmPos--;
        }
        else if(mmPress > 48 && mmPress < 54){
            mmPos = mmPress - 48;
        }

        mmcf0 = mmcf1 = mmcf2 = mmcf3 = mmcf4 = mmcf5 = 15;
        mmcb0 = mmcb1 = mmcb2 = mmcb3 = mmcb4 = mmcb5 = 0;

        if(mmPos == 1){
            swap(mmcf1, mmcb1);
        }
        else if(mmPos == 2){
            swap(mmcf2, mmcb2);
        }
        else if(mmPos == 3){
            swap(mmcf3, mmcb3);
        }
        else if(mmPos == 4){
            swap(mmcf4, mmcb4);
        }
        else if(mmPos == 5){
            swap(mmcf5, mmcb5);
        }
    }

    switch(mmPos){
        case 1:
        cout << endl << "Security Password: ";
        HideUnhide(1);
        cin >> pass;
        HideUnhide(0);
        system("cls");
        cout << "NEW ACCOUNT CREATION" << endl << "Account Number: ";
        cin >> accountNumber;
        cout << "Account Title: ";
        cin >> accountTitle;
        cout << "Amount to Deposit: ";
        cin >> amount;
        BANK.newAccount(pass, accountNumber, accountTitle, amount);
        cout << "Press any Key to return" << getch();
        goto MENUM;

        case 2:
        system("cls");
        cout << "LOOKUP ACCOUNT TITLE" << endl << "Account Number: ";
        cin >> accountNumber;
        cout << BANK.titleCheck(pass, accountNumber);
    }

    MENUC:
    int cmPos, cmPress, cmcf0, cmcb0, cmcf1, cmcb1, cmcf2, cmcb2, cmcf3, cmcb3;
    cmPos = 1, cmPress = 0;
    cmcf0 = cmcb1 = cmcf2 = cmcf3 = 15;
    cmcb0 = cmcf1 = cmcb2 = cmcb3 = 0;
    gotoxy(2, 1);
    cout << char(201) << string(24, char(205)) << char(187) << endl;
    gotoxy(2, 2);
    cout << char(186) << setw(18) << " CASHIER MENU" << setw(7) << char(186) << endl;gotoxy(2, 3);
    cout << char(204) << string(24, char(205)) << char(185) << endl;
    gotoxy(2, 4);
    cout << char(186) << setw(25) << char(186) << endl;
    gotoxy(2, 5);
    cout << char(199) << string(24, char(196)) << char(182) << endl;
    gotoxy(2, 6);
    cout << char(186) << setw(25) << char(186) << endl;
    gotoxy(2, 7);
    cout << char(199) << string(24, char(196)) << char(182) << endl;
    gotoxy(2, 8);
    cout << char(186) << setw(25) << char(186) << endl;
    gotoxy(2, 9);
    cout << char(200) << string(24, char(205)) << char(188) << endl;

    while (cmPress != 13){
        SetColor(cmcf0, cmcb0);
        gotoxy(3, 4);
        SetColor(cmcf1, cmcb1);
        cout << string(3, ' ') << char(60) << "1" << char(62) << " " << "Cash Withdrawl" << string(3, ' ');
        gotoxy(3, 6);
        SetColor(cmcf2, cmcb2);
        cout << string(3, ' ') << char(60) << "2" << char(62) << " " << "Cash Deposit" << string(5, ' ');
        gotoxy(3, 8);
        SetColor(cmcf3, cmcb3);
        cout << string(3, ' ') << char(60) << "3" << char(62) << " " << "BACK" << string(13, ' ');
        gotoxy(3, 10);
        cout << "Option Selected: ";
        cmPress = getche();

        if(cmPress == 80 && cmPos != 3){
            cmPos++;
        }
        else if(cmPress == 72 && cmPos != 1){
            cmPos--;
        }
        else if(cmPress > 48 && cmPress < 52){
            cmPos = cmPress - 48;
        }

        cmcf0 = cmcf1 = cmcf2 = cmcf3 = 15;
        cmcb0 = cmcb1 = cmcb2 = cmcb3 = 0;

        if(cmPos == 1){
            swap(cmcf1, cmcb1);
        }
        else if(cmPos == 2){
            swap(cmcf2, cmcb2);
        }
        else if(cmPos == 3){
            swap(cmcf3, cmcb3);
        }
    }
}