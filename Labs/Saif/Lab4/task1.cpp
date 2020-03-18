#include<iostream>
#include<string>

using namespace std;

class dayType {

    string day[7] ={"Sun","Mon","Tue","Wed","Thu","Fri","sat"};
    int currentDay = 0;


    public:

    dayType(){

    };

    void setDay(){
        
        int setDay;
        cout << "Enter The Day: " <<endl;
        cin >> setDay;

        currentDay = setDay % 7;
        cout << "The Current Day is: " << day[currentDay] <<endl;

    }

    void printDay(){

        cout << "The Current Day is: " << day[currentDay] <<endl;
    }

    string returnDay(){

        return day[currentDay];
    }

    string returnNextDay(){

        if(currentDay == 6){

            currentDay = 0;
        }

        return day[currentDay+1];

    }

    string returnPreviousDay(){

        if (currentDay == 0){

            currentDay = 7;
        }

        return day[currentDay-1];
    }

    void addDay(){

        int add;
        int sumDay;
        cout << "Enter Days to Add in Current Days: " <<endl;
        cin >> add;

       sumDay = (currentDay + add) % 7;

       cout << "The Day is: " << day[sumDay] <<endl;
       
    }


};

int main(void){

    dayType ob;

    int choice;
    int count = 1;

    string theDay;

    while(count == 1){

        cout << "Enter 1 to Set Day" <<endl;
        cout << "Enter 2 to Print Day" <<endl;
        cout << "Enter 3 to Return the Day" <<endl;
        cout << "Enter 4 to Return the Next Day" <<endl;
        cout << "Enter 5 to Return the Previous Day" <<endl;
        cout << "Enter 6 to Add and Calculate the Day" <<endl;
        cout << "Enter 0 to Quit" <<endl;
        cin >> choice;

        switch(choice){

            case 1:
                ob.setDay();
                break;

            case 2:
                ob.printDay();
                break;

            case 3:
                cout << "The Returned Day is:" <<ob.returnDay() <<endl;
                break;
            
            case 4:
               cout << "The Next Day is: " << ob.returnNextDay() <<endl;
               break;

            case 5:
                cout << "The Previous Day is: " << ob.returnPreviousDay() <<endl;
                break;

            case 6:
                ob.addDay();
                break;

            case 0:
                count = 0;
                break;

            default:
                cout << "Error Invalid Choice: " <<endl;
                break;
            

        }
    }
}