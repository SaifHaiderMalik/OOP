#include <iostream>
#include <string>

using namespace std;

struct playerDetails{

    string name;
    int homeRun;
    int hit;
};

int main(void){

    playerDetails player[10];

    int choice;
    int i;
    string _name;
    int _hit;
    int _homeRuns;
    int index;
    int count = 1;

    while (count == 1){
        
        cout << "Menu" << endl;
        cout << "Press 1 to Enter New records" << endl;
        cout << "Press 2 to Modify Records" << endl;
        cout << "Press 3 to Display Records" << endl;
        cout << "Press 4 to Search Index" << endl;
        cout << "Press 0 to quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice){

            case 1:

                for(i=0;i<10;i++){
                    if(player[i].name.length() != 0){
                        if(i == 9){
                            cout << "Database Full" << endl;
                        }
                        continue;
                    }

                    cout << "Enter Player Name: ";
                    cin.ignore(); //Clears cin buffer so getline(cin, _name) can work
                    getline(cin, _name);
                    cout << "Enter Home Runs: ";
                    cin >> _homeRuns;
                    cout << "Enter Number of Hits: ";
                    cin >> _hit;

                    player[i].name = _name;
                    player[i].homeRun = _homeRuns;
                    player[i].hit = _hit;
                    break;
                }
                break;

            case 2:
                cout << "Enter Index of Player: ";
                cin >> index;
                if(player[index].name.length() == 0){
                    cout << "No Record found! Enter New Data:" << endl;
                }
                cout << "Enter Player Name: ";
                cin.ignore();
                getline(cin, _name);
                cout << "Enter Home Runs: ";
                cin >> _homeRuns;
                cout << "Enter Number of Hits: ";
                cin >> _hit;

                player[index].name = _name;
                player[index].homeRun = _homeRuns;
                player[index].hit = _hit;                
                break;

            case 3:
                for(int j=0;j<10;j++){
                    if(player[j].name.length() == 0){
                        continue;
                    }
                    cout << "Index: " << j << endl;
                    cout << "Player Name: " << player[j].name << endl;
                    cout << "Player Home Runs: " << player[j].homeRun << endl;
                    cout << "Player Hits: " << player[j].hit << endl << endl;
                }
                break;
            
            case 4:
                cout << "Enter Player Name: ";
                cin.ignore();
                getline(cin, _name);
                for(int n = 0; n < 10; n++){
                    if(player[n].name == _name){
                        cout << "Player '" << _name << "' is on Index " << n << endl;
                    }
                }
                break;

            case 0:
                count = 0;
                break;

            default:
                cout << "Error" << endl;
                break;
        }
    }
}