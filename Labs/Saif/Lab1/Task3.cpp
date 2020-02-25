#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main (){

    string name;
    float testScore[5];
    float averageScore;
    float totalScore = 0;
    int i;


    cout << "Enter Name: ";
    getline(cin, name);
    cout << "5 Test scores: ";

    for(i=0;i<5;i++){

        cin >> testScore[i];
        totalScore = totalScore + testScore[i];
    }

    averageScore = totalScore/5;

    cout << fixed << setprecision(2); //Format output with two decimal places
    cout << "Student's Name: " << name << endl;
    cout << "Test Scores:";
    
    for(i=0;i<5;i++){

        cout << " " << testScore[i];
    }

    cout << endl;
    cout << "Average Score: " << averageScore;

}