#include <iostream>
#include <string>

using namespace std;

class memberType{

    string name;
    string memberId;
    int numberOfBooksBought;
    double amount;

    public:

    memberType(){

    }

    memberType(string _name,string _memberId,int _numberOfBooksBought,double _amount){

        name = _name;
        memberId = _memberId;
        numberOfBooksBought = _numberOfBooksBought;
        amount = _amount;

    }

    void setName(string _name){name = _name;}
    void setmemberId(string _memberId){memberId = _memberId;}
    void setNumberOfBooksBought(int _numberOfBooksBrought){numberOfBooksBought = _numberOfBooksBrought;}
    void setAmount(double _amount){amount = _amount;}

    string getName(){

        return name;
    }

    string getMemberId(){

        return memberId;
    }

    int getNumberOfBooksBought(){

        return numberOfBooksBought;
    }

    double getAmount(){

        return amount;
    }

    void modifyName(string _name){

        name = _name;
    }

    void modifyMemberId(string _memberId){

        memberId = _memberId;
    }

    void modifyNumberOfBooksBought(int _numberOfBooksBought){

        numberOfBooksBought = _numberOfBooksBought;
    }

    void modifyAmount(double _amount){

        amount = _amount;
    }
};

int main(void){

    string name;
    string memberId;
    int numberOfBooksBought;
    double amount;
    int count = 1;
    int choice;

    memberType ob;

    while(count ==1){

        cout << "Enter 1 to Set Name,Id,Books Bought,Amount Spent " <<endl;
        cout << "Enter 2 to Modify Data " <<endl;
        cout << "Enter 3 to Show Data " <<endl;
        cout << "Enter 0 to Quit" <<endl;

        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter Name: " <<endl;
                cin >> name;

                ob.setName(name);

                cout << "Enter MemberId: " <<endl;
                cin >> memberId;

                ob.setmemberId(memberId);

                cout << "Enter Books Bought: " <<endl;
                cin >> numberOfBooksBought;
                
                ob.setNumberOfBooksBought(numberOfBooksBought);

                cout << "Enter Amount: " <<endl;
                cin >> amount;

                ob.setAmount(amount);

                break;

            
            case 2:
                cout << "Enter Modified Name : " <<endl;
                cin >> name;

                ob.modifyName(name);

                cout << "Enter Modified MemberId: " <<endl;
                cin >> memberId;

                ob.modifyMemberId(memberId);

                cout << "Enter Modified Books Bought: " <<endl;
                cin >> numberOfBooksBought;
                
                ob.modifyNumberOfBooksBought(numberOfBooksBought);

                cout << "Enter Modified Amount: " <<endl;
                cin >> amount;

                ob.modifyAmount(amount);

                break;

            
            case 3:
                cout << "The Data is: " <<endl;
                cout << "Person Name: " << ob.getName() <<endl;
                cout << "MemberId: " << ob.getMemberId() <<endl;
                cout << "Amount of Books Bought: " << ob.getNumberOfBooksBought() <<endl;
                cout << "Total Price: " << ob.getAmount() <<endl;

                break;

            case 0:
                count = 0;
                break;

            default:
                cout << "Invalid Input" <<endl;
                break;
        }
    }
}

