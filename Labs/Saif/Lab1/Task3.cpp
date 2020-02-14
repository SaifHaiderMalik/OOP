#include <iostream>
#include <string>

using namespace std;

int main (){

    string name;
    float testScore[5];
    float averageScore;
    float totalScore = 0;
    int i;


    cout << "Enter Name and Test scores";
    cin >> name;

    for(i=0;i<5;i++){

        cin >> testScore[i];
        totalScore = totalScore + testScore[i];
    }

    averageScore = totalScore/5;

    cout << "Students Name" << name << endl;
    cout << "Test Scores";
    
    for(i=0;i<5;i++){

        cout << " " << testScore[i];
    }

    cout << endl;
    cout << "Average Score" << averageScore;




}