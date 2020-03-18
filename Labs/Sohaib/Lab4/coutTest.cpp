#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    int i = 10;
    int Index = 99999, Price = 99999, Year = 9999, Copies = 999999;
    char space = ' ', newchar = char(179);
    string mid = string(" ")+char(179)+string(" ");
    string send = string(" ")+char(179);
    //string start = char(179)+string(" ");
    string mid2 = string(" ")+char(205)+string(" ");
    string send2 = string(" ")+char(185);
    string start2 = char(204)+string(" ");
    //mid += space;
    //mid += newchar;
    //mid += space;
    string Title = "123456789012345678901234567890123456789012345", Authors = "123456789012345678901234567890123456789012345", Publisher = "123456789012345678901234567890", ISBN = "978-3-16-148410-0";
    cout << "| ##### | 123456789012345678901234567890123456789012345 | 123456789012345678901234567890123456789012345 | 123456789012345678901234567890 | 12345678901234567 | 12345 | 1234 | 123456 |" << endl;
    cout << char(201) << string(7, char(205)) << char(203) << string(47, char(205)) << char(203)
         << string(47, char(205)) << char(203) << string(32, char(205)) << char(203)
         << string(19, char(205)) << char(203) << string(7, char(205)) << char(203)
         << string(6, char(205)) << char(203) << string(8, char(205)) << char(187) << endl;
    /*cout << char(186) << " Index " << char(186) << " Title " << setw(41) << char(186) << " Authors " << setw(39) << char(186) << " Publisher " << setw(22)
         << char(186) << " ISBN " << setw(14) << char(186) << " Price " << char(186) << " Year " << char(186) << " Copies " << char(186) << endl;*/
    cout << char(186) << " Index " << char(186) << setw(26) << "Title" << setw(22) << char(186)
         << setw(28) << "Author(s)" << setw(20) << char(186) << setw(21) << "Publisher."
         << setw(12) << char(186) << setw(12) << "ISBN." << setw(8) << char(186) << " Price "
         << char(186) << " Year " << char(186) << " Copies " << char(186) << endl;
    cout << char(204) << string(7, char(205)) << char(206) << string(47, char(205)) << char(206)
         << string(47, char(205)) << char(206) << string(32, char(205)) << char(206)
         << string(19, char(205)) << char(206) << string(7, char(205)) << char(206)
         << string(6, char(205)) << char(206) << string(8, char(205)) << char(185) << endl;
    for(int i = 0; i < 5; i++){
        cout << char(179) << setw(6) << Index << mid << Title << setw(48-Title.length())
             << mid << Authors << setw(48-Authors.length()) << mid << Publisher
             << setw(33-Publisher.length()) << mid << ISBN << mid << setw(5) << Price
             << mid << setw(4) << Year << mid << setw(6) << Copies << send << endl;
        cout << char(195) << string(7, char(196)) << char(197) << string(47, char(196)) << char(197)
             << string(47, char(196)) << char(197) << string(32, char(196)) << char(197)
             << string(19, char(196)) << char(197) << string(7, char(196)) << char(197)
             << string(6, char(196)) << char(197) << string(8, char(196)) << char(180) << endl;
    }
    system("pause");
}