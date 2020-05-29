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

    string getTitle(){return title;}
    void setTitle(string _title){title = _title;}
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

    REST setRest(int i){return rests[i];
    }

    REST& setRest(int i, REST& _rest){
        _rest = rests[i];
        return _rest;
    }
};



int main(){
    ADMIN adminOB;
    REST rest1("Rest 1");
    REST rest2("Rest 2");
    adminOB.addRest(rest1);

    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;

    rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;

    rest1 = adminOB.setRest(0);
    //rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;

    rest1 = adminOB.setRest(0, rest1);
    rest1.setTitle("Rest1 > 46");
    cout << adminOB.getRestTitle(0) << endl;
    cout << rest1.getTitle() << endl;
    cout << rest2.getTitle() << endl << endl;
    return 0;
}