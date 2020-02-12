#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    string studentName;
    float testScores[5], testAverage, totalScore = 0;

    cout << "Please Enter Student Name: ";
    getline(cin, studentName);

    cout << "Please Enter 5 Test Score: ";

    for (int i = 0; i <= 4; i++){
        cin >> testScores[i];
        totalScore += testScores[i];
    }

    testAverage = totalScore / 5;

    cout << "Student name: " << studentName << endl << "Test scores:" << fixed << setprecision(2);

    for (int i = 0; i <= 4; i++){
        cout << " " << testScores[i];
    }

    cout << endl << "Average test score: " << testAverage;
    
    return 0;
}