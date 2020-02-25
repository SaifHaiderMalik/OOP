#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

int main(){
    int numMenu, maxString, borderGap = 3, indexGap = 0, indexType, xPos = 0, yPos = 0, indexE = 0, indexB;
    char s = 254;
    string menuTitle, keyPosition, keyPressed, cfg, cbg;
    //string* menuItems = new string[5]{};
    cout << "Enter X,Y Cordinates for Menu: ";
    cin >> xPos >> yPos;
    cout << "Enter number of options you need for your Menu (<=9): ";
    cin >> numMenu;
    cin.ignore();
    cout << endl;
    string* menuItems = new string[numMenu+1]{};
    cout << "Enter Menu Title: ";
    getline(cin, menuItems[0]);
    maxString = menuItems[0].length();

    for(int i = 1; i <= numMenu; i++){
        cout << "Enter Menu Option " << i << ": ";
        getline(cin, menuItems[i]);
        if(menuItems[i].length() > maxString){
            maxString = menuItems[i].length();
        }
    }
    cout << "Do you wnat to have Number Index with Menu Options?: " << endl;
    if(tolower(getch()) == 'y'){
        indexGap = 4;
        maxString += indexGap;
        cout << "Choose Index Style 0=#, 1=" << char(124) << "#" << char(124) << ", 2='#', 3=\"#\", 4=-#-, 5==#=, 6=~#~, 7=" << char(247) << "#" << char(247) << ", 8=(#), 9={#}, 10=[#], 11=<#>, 12=" << char(174) << "#" << char(174) << ": ";
        cin >> indexType;
        if(indexType == 0){
            indexB = 32;
        }
        else if(indexType == 1){
            indexB = 124;
        }
        else if(indexType == 2){
            indexB = 39;
        }
        else if(indexType == 3){
            indexB = 34;
        }
        else if(indexType == 4){
            indexB = 45;
        }
        else if(indexType == 5){
            indexB = 61;
        }
        else if(indexType == 6){
            indexB = 126;
        }
        else if(indexType == 7){
            indexB = 247;
        }
        else if(indexType == 8){
            indexB = 40;
        }
        else if(indexType == 9){
            indexB = 123;
        }
        else if(indexType == 10){
            indexB = 91;
        }
        else if(indexType == 11){
            indexB = 60;
        }
        else if(indexType == 12){
            indexB = 174;
        }

        if(indexType > 7){
            indexE += 2;
            if(indexType == 8 || indexType == 12){
                indexE--;
            }
        }
    }

    cout << "Horizontal space between Menu Item and Border?: ";
    cin >> borderGap;
    if(borderGap < 3){
        borderGap = 3;
    }

    maxString += (borderGap * 2);

    cout << "Variable name for 'Menu Position': ";
    cin >> keyPosition;
    cout << "Variable name for 'Key Pressed': ";
    cin >> keyPressed;
    cout << "Variable name for 'Foreground Color': ";
    cin >> cfg;
    cout << "Variable name for 'Background Color': ";
    cin >> cbg;

    system("cls");
    cout << fixed;
    cout << "int " << keyPosition << ", " << keyPressed;
    for(int i = 0; i <= numMenu; i++){
        cout << ", " << cfg << i << ", " << cbg << i;
    }
    cout << ";" << endl << keyPosition << " = 1, " << keyPressed << " = 0;" << endl;
    for(int i = 0; i <= numMenu; i++){
        if(i == 1){
            cout << cbg << i << " = ";
            continue;
        }
        cout << cfg << i << " = ";
    }
    cout << "15;" << endl;
    for(int i = 0; i <= numMenu; i++){
        if(i == 1){
            cout << cfg << i << " = ";
            continue;
        }
        cout << cbg << i << " = ";
    }
    cout << "0;" << endl << "gotoxy(" << xPos << ", " << yPos << ");" << endl;
    cout << "cout << char(201) << string(" << maxString << ", char(205)) << char(187) << endl;" << endl;
    cout << "gotoxy(" << xPos << ", " << yPos + 1 << ");" << endl;
    cout << "cout << char(186) << setw(" << (maxString + menuItems[0].length()) / 2 << ") << \" " << menuItems[0] << "\" << setw(" << (maxString - menuItems[0].length() + 3) / 2 << ") << char(186) << endl;";
    cout << "gotoxy(" << xPos << ", " << yPos + 2 << ");" << endl;
    cout << "cout << char(204) << string(" << maxString << ", char(205)) << char(185) << endl;" << endl;

    for(int i = 1, j = 2; i <= numMenu; i++){
        cout << "gotoxy(" << xPos << ", " << yPos + i + j << ");" << endl;
        cout << "cout << char(186) << setw(" << maxString + 1 << ") << char(186) << endl;" << endl;
        if(i < numMenu){
            cout << "gotoxy(" << xPos << ", " << yPos + i + j++ + 1 << ");" << endl;
            cout << "cout << char(199) << string(" << maxString << ", char(196)) << char(182) << endl;" << endl;
        }
    }
    cout << "gotoxy(" << xPos << ", " << yPos + ((numMenu + 1) * 2) << ");" << endl;
    cout << "cout << char(200) << string(" << maxString << ", char(205)) << char(188) << endl;" << endl;

    cout << "while (" << keyPressed << " != 13){" << endl << "SetColor(" << cfg << "0, " << cbg << "0);" << endl << "gotoxy(" << xPos + 1 << ", " << yPos + 3 << ");" << endl;
    for(int i = 1; i <= numMenu; i++){
        cout << "SetColor(" << cfg << i << ", " << cbg << i << ");" << endl;
        cout << "cout << string(" << borderGap << ", ' ') << ";
        if(indexGap != 0){
            cout << "char(" << indexB << ") << \"" << i << "\" << char(" << indexB + indexE << ") << \" \" << ";
        }
        cout << "\"" << menuItems[i] << "\" << string(" << maxString - (borderGap + indexGap + menuItems[i].length()) << ", ' ');" << endl;
        cout << "gotoxy(" << xPos + 1 << ", " << yPos + (i*2) + 3  << ");" << endl;
    }

    cout << "cout << \"Option Selected: \";" << endl << keyPressed << " = getche();" << endl;
    cout << "if(" << keyPressed << " == 80 && " << keyPosition << " != " << numMenu <<"){" << endl << keyPosition << "++;" << endl << "}" << endl;
    cout << "else if(" << keyPressed << " == 72 && " << keyPosition << " != 1){" << endl << keyPosition << "--;" << endl << "}" << endl;
    if(indexGap != 0){
        cout << "else if(" << keyPressed << " > 48 && " << keyPressed << " < " << numMenu + 49 << "){" << endl << keyPosition << " = " << keyPressed << " - 48;" << endl << "}" << endl;
    }

    for(int i = 0; i <= numMenu; i++){
        cout << cfg << i << " = ";
    }
    cout << "15;" << endl;
    for(int i = 0; i <= numMenu; i++){
        cout << cbg << i << " = ";
    }
    cout << "0;" << endl;
    cout << "if(" << keyPosition << " == 1){" << endl << "swap(" << cfg << "1, " << cbg << "1);" << endl << "}" << endl;
    for(int i = 2; i <= numMenu; i++){
        cout << "else if(" << keyPosition << " == " << i << "){" << endl << "swap(" << cfg << i << ", " << cbg << i << ");" << endl << "}" << endl;
    }
    cout << "}" << endl;
    
    for(int i = 0; i <= numMenu; i++){
        cout << menuItems[i] << endl;
    }
    cout << numMenu << endl;
    cout << maxString << endl;
    cout << s << endl;
    
    getch();
    return 0;
}