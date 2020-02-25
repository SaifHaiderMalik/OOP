#include <iostream>
#include <iomanip>
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

    cout << "Enter Movie Name: ";
    getline(cin, movieName);

    cout << "Enter Adult Ticket Price: ";
    cin >> adultTicketPrice;

    cout << "Enter Child Ticket Price: ";
    cin >> childTicketPrice;

    cout << "Enter Number of Adult Ticket Sold: ";
    cin >> numberOfAdultTicketSold;

    cout << "Enter Number of Children Ticket Sold: ";
    cin >> numberOfChildTicketSold;

    cout << "Percentage of gross amount to be donated to charity: ";
    cin >> percentage;

    grossAmount = (numberOfChildTicketSold * childTicketPrice) + (numberOfAdultTicketSold * adultTicketPrice);

    donated = (grossAmount * percentage/100);

    netAmount = grossAmount - donated;

    cout << fixed << setprecision(2); //Format output with two decimal places

    cout << "Movie Name: " << movieName << endl;

    cout << "Number of Tickets Sold: " << numberOfAdultTicketSold + numberOfChildTicketSold << endl;

    cout << "Gross Amount: $" << grossAmount << endl;

    cout << "Percentage of Gross Amount Donated: " << percentage << "%" << endl;

    cout << "Amount Donated: $" << donated << endl;

    cout << "Net Sale: $" << netAmount;

}