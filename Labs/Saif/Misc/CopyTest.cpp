#include <iostream>
#include <string>
#include <vector>

using namespace std;

class REST{
    string title;
public:
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
public:
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



int main(void){
    
    ADMIN adminOB;
    REST rest0("Rest 0");
    REST rest1("Rest 1");
    REST * rest2 = new REST;

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

    /*rest1 = adminOB.setRest(0, rest1);
    rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;*/
    return 0;
    
}
