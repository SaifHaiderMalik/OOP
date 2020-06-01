#include <iostream>
#include <string>
#include <vector>

using namespace std;

class REST{
    string title;
public:
    int price;
    REST(string _title){
        title = _title;
    }

    REST(){}

    string getTitle(){return title;}
    void setTitle(string _title){title = _title;}

    /*void xyz(REST _rest){
        _rest = this;
    }*/
};


class ADMIN{
    vector<REST> rests;
protected:
    string getRestTitlePro(int i){return rests[i].getTitle();}
public:
    string getRestTitlePub(int i){return rests[i].getTitle();}

    void addRest(REST _rest){
        rests.push_back(_rest);
    }

    string getRestTitle(int i){
        return rests[i].getTitle();
    }

    REST * setRest(int i){return &rests[i];
    }

    REST& setRest(int i, REST& _rest){
        _rest = rests[i];
        return _rest;
    }
};

class ADMIN1 : public ADMIN{
getr
};

class ADMIN11 : public ADMIN1{

};
class ADMIN12 : protected ADMIN1{

};
class ADMIN13 : private ADMIN1{

};

class ADMIN2 : protected ADMIN{

};

class ADMIN21 : public ADMIN2{

};
class ADMIN22 : protected ADMIN2{

};
class ADMIN23 : private ADMIN2{

};

class ADMIN3 : private ADMIN{

};

class ADMIN31 : public ADMIN3{

};
class ADMIN32 : protected ADMIN3{

};
class ADMIN33 : private ADMIN3{

};

int main(void){
    
    ADMIN adminOB;
    REST rest0("Rest 0");
    REST rest1("Rest 1");
    REST * rest2 = new REST;

    ADMIN1 admin1;
    ADMIN11 admin11;
    ADMIN12 admin12;
    ADMIN13 admin13;

    ADMIN2 admin2;
    ADMIN21 admin21;
    ADMIN22 admin22;
    ADMIN23 admin23;

    ADMIN3 admin3;
    ADMIN31 admin31;
    ADMIN32 admin32;
    ADMIN33 admin33;


    /*rest1.setTitle("ABC");
    cout << rest1.getTitle() << endl;

    rest2 = &rest1;

    cout << rest2->getTitle() << endl;

    rest2->setTitle("HHH");
    adminOB.addRest(rest1);
    cout << adminOB.getRestTitle(0) << endl;
    adminOB.setRest(1,rest1);
    cout << adminOB.getRestTitle(0) << endl;*/

    adminOB.addRest(rest0);
    adminOB.addRest(rest1);
    //adminOB
    

    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl << endl;

    rest2->setTitle("Rest2 > 77");
    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl << endl;

    rest2 = adminOB.setRest(0);
    //rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl << endl;

    rest2->setTitle("Rest2 > 92");
    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl << endl;

    rest2 = adminOB.setRest(1);
    rest2->setTitle("Rest2 > 100");
    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl << endl;

    {REST * rest3 = new REST;
    rest3 = adminOB.setRest(1);
    rest3->setTitle("Rest3 > 109");
    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl;
    cout << rest3->getTitle() << endl << endl;}

    cout << adminOB.getRestTitle(0) << endl;
    cout << adminOB.getRestTitle(1) << endl;
    cout << rest0.getTitle() << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2->getTitle() << endl;
    //cout << rest3->getTitle() << endl << endl;

    /*rest1 = adminOB.setRest(0, rest1);
    rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;*/
    return 0;
    
}
