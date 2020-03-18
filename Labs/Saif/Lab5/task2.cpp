#include<iostream>
#include<string>
using namespace std;


class RentCalculator{

    const double rentperday;
    const string customerName;
    int numberOfDays;
    double customerRent;

    public:
    
    RentCalculator(string name,int days):rentperday(1000.85),customerName(name)
    {
        numberOfDays = days;

    }


    double RentWithDiscount(){

        int discountDays = (numberOfDays%7);

        customerRent = (numberOfDays * rentperday) - (1*rentperday);

        return customerRent;
    }

    double RentWithoutDiscount(){

        customerRent = numberOfDays * rentperday;

        return customerRent;
    }

    void DisplayRent() const{

        cout << "Name of Customer:" << customerName <<endl;
        cout << "Days: " << numberOfDays <<endl;
        cout << "Rent: " << customerRent <<endl;
        
    }


};

int main(void){

    string name;
    int days;

    cout <<"Enter Name of Customer: " <<endl;
    cin >> name;

    cout << "Enter Number of Days: " <<endl;
    cin >> days;

    RentCalculator ob1(name,days);

    if(days <=7 && days>=0){

        ob1.RentWithoutDiscount();
    }

    else
    {
        ob1.RentWithDiscount();
    }

    cout <<"Enter Name of Customer: " <<endl;
    cin >> name;

    cout << "Enter Number of Days: " <<endl;
    cin >> days;

    RentCalculator ob2(name,days);

    if(days <=7 && days>=0){

        ob2.RentWithoutDiscount();
    }

    else
    {
        ob2.RentWithDiscount();
    }

    ob1.DisplayRent();
    ob2.DisplayRent();
}
