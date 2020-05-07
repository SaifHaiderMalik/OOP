#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CLASSA{
    string strA;
    int intA;
    bool boolA;

public:
    CLASSA(){
        strA = "AAA";
        intA = 111;
        boolA = true;
    }
};

class CLASSB{
    string strB;
    int intB;
    bool boolB;
    vector<CLASSA> class1;
    //vector<int> intc();

public:
    void addClassA(CLASSA _classA){
        class1.push_back(_classA);
    }

    int getClassASize(){
       return class1.size();
    }
};

int main(){
    CLASSA cla1;
    CLASSB clb1;
    cout << clb1.getClassASize() << endl;
    clb1.addClassA(cla1);
    clb1.addClassA(cla1);
    cout << clb1.getClassASize() << endl;
}