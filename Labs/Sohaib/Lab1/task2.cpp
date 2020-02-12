#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

int main(){
    string movieName;
    int ticketsSold, ticketSoldAdult, ticketSoldChild, sizeWidth = 14;
    float grossAmount, amountDonated, netSale, ticketPriceAdult, ticketPriceChild, donationPercentage;

    cout << "Please Enter Movie Name : ";
    getline(cin, movieName);

    cout << "Please Enter Adult Ticket Price : ";
    cin >> ticketPriceAdult;

    cout << "Please Enter Child Ticket Price : ";
    cin >> ticketPriceChild;

    cout << "Please Enter Number of Adult Tickets Sold : ";
    cin >> ticketSoldAdult;

    cout << "Please Enter Number of Child Tickets Sold : ";
    cin >> ticketSoldChild;

    cout << "Please Enter Percentage of the Gross Amount to be Donated : ";
    cin >> donationPercentage;

    if(movieName.length() > 14){
        sizeWidth = movieName.length()+1;
    }

    ticketsSold = ticketSoldAdult + ticketSoldChild;
    grossAmount = (ticketSoldAdult * ticketPriceAdult) + (ticketSoldChild * ticketPriceChild);
    amountDonated = grossAmount * (donationPercentage / 100);
    netSale = grossAmount - amountDonated;

    cout << string(35+sizeWidth, '#') << endl;
    cout << "Movie Name: " << string(23, '.');
    cout << " " << movieName << endl;

    cout << "Number of Tickets Sold: " << string(11, '.');
    //cout.width(sizeWidth);
    cout << setw(sizeWidth) << ticketsSold << endl;

    cout << fixed << setprecision(2);

    cout << "Gross Amount: " << string(21, '.');
    cout.width(sizeWidth);
    cout << grossAmount << endl;

    cout << "Percentage of Gross Amount Donated: ";
    cout.width(sizeWidth-1);
    cout << donationPercentage << "%" << endl;

    cout << "Amount Donated: " << string(19, '.');
    cout.width(sizeWidth);
    cout << amountDonated << endl;
    
    cout << "Net Sale: " << string(25, '.');
    cout.width(sizeWidth);
    cout << netSale << endl;

    getch();
    return 0;
}