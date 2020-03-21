#include<iostream>
#include<string>

using namespace std;

class Birthday{

    protected:

    int year;
    int month;
    int day;

    public:

    void setYear(int _year){
        
        if(_year > 0){

            year = _year;

        }

        else {

            cout << "Incorrect Year Entered" <<endl;
        }
    }

    void setMonth(int _month){

        if(_month > 0 && _month <=12){

            month = _month;

        }

        else
        {
            cout << "Incorrect Month Entered" <<endl;
        }
        
    }

    void setDay(int _day){

        if(_day >0 && _day <=31 ){

            day = _day;

        }

        else{

            cout << "incorrect Day Entered" <<endl;
        }
        
    }

    int getYear(){

        return year;
    }

    int getMonth(){

        return month;
    }

    int getDay(){

        return day;
    }



};



class Teacher{

    protected:

    string num;
    string name;
    char sex;

    public:

    void setNumber(int number){

        num = number;
    }

    void setName(string _name){

        name = _name;
    }

    void setSex(char gender){

        sex = gender;
    }


    string getNum(){

        return num;
    }

    string getName(){

        return name;
    }

    char getSex(){

        return sex;
    }


};


class Professor : public Birthday,public Teacher{

    public:

    Professor(int _year,int _month,int _day,string _number,string _name,char _sex){

        if(_year > 0){

            year = _year;
        }

        else {

            cout << "Incorrect Year Entered" <<endl;
        }


        if(_month > 0 && _month <=12){

            month = _month;

        }

        else {

            cout << "Incorrect Month Entered" <<endl;
        }
        
        if(_day > 0 && _day <=31 ){

            day = _day;

        }

        else {

            cout << "Incorrect Day Entered" <<endl;
        }
        
       
        if(_sex == 'm' || _sex == 'M' || _sex == 'f' || _sex == 'F'){

            sex = _sex;

        }

        else{

            cout << "Incorrect Sex Entered: " <<endl;
        }


        num = _number;
        name = _name;
        

    }

    Professor()
    {

    }

};





int main(void){

    int year;
    int month;
    int day;
    string number;
    string name;
    char sex;

    cout << "Enter Number Of Professor: " <<endl;
    cin >> number;

    cout << "Enter Name Of Professor:" <<endl;
    cin >> name;

    cout << "Enter Sex Of Professor (M for Male or F for Female): " <<endl;
    cin >> sex;

    cout << "Enter Initial Birth Year of Professor: " <<endl;
    cin >> year;

    cout << "Enter Initial Birth Month of Professor: " <<endl;
    cin >> month;

    cout << "Enter Initial Birth Date of Professor: " <<endl;
    cin >> day;

    Professor ob(year,month,day,number,name,sex);

    cout << "Enter Modified Birth Year of Professor: " <<endl;
    cin >> year;

    ob.setYear(year);

    cout << "Enter Modified Birth Month of Professor: " <<endl;
    cin >> month;

    ob.setMonth(month);

    cout << "Enter Modified Birth Date of Professor: " <<endl;
    cin >> day;

    ob.setDay(day);

    cout << "Num: " << ob.getNum() << " Name: " << ob.getName() << " Sex: " << ob.getSex();
    cout << " Birthday: " << ob.getYear() << "/" << ob.getMonth() << "/" << ob.getDay() <<endl;


}