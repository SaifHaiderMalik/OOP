#include <iostream>
#include <string>

using namespace std;

int main(){

    string movieName;

    float adultTicketPrice;
    float childTicketPrice;
    int numberOfAdultTicketSold;
    int numberOfChildTicketSold;
    float percentage;
    float grossAmount;
    float netAmount;
    float donated;

    cout << "Enter Movie Name";
    //cin >> movieName;
    getline(cin, movieName);

    cout << "Enter Adult Ticket Price";
    cin >> adultTicketPrice;

    cout << "Enter Child Ticket Price";
    cin >> childTicketPrice;

    cout << "Enter Number of Adult Ticket Sold";
    cin >> numberOfAdultTicketSold;

    cout << "Enter Number of Children Ticket Sold";
    cin >> numberOfChildTicketSold;

    cout << "Percentage of gross amount to be donated to charity";
    cin >> percentage;

    grossAmount = (numberOfChildTicketSold * childTicketPrice) + (numberOfAdultTicketSold * adultTicketPrice);

    donated = (grossAmount * percentage/100);

    netAmount = grossAmount - donated;

    cout << "Movie Name ........................." << movieName << endl << "Number of Tickets Sold" << numberOfAdultTicketSold + numberOfChildTicketSold << endl; 

    cout << "Gross Amount" << grossAmount << endl;

    cout << "Percentage of gross amount to be donated" << percentage << endl;

    cout << "Amount Donated" << donated << endl;

    cout << "Net Amount" << netAmount;

}