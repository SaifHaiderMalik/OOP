#include <iostream>

using namespace std;

double calculateBMI(double w, double h){
    return w/(h*h)*703;
}

string findStatus(double bmi){
    string status;

    if(bmi < 18.5){
        status = "Underweight";
    }
    else if(bmi < 25.0){
        status = "Normal";
    }
    else{
        status = "Overweight";
    }

    return status;
}

int main(){
    double bmi, weight, height;
    string status;
    cout << "Enter weight in Pounds: ";
    cin >> weight;
    cout << "Enter height in Inches: ";
    cin >> height;
    bmi = calculateBMI(weight, height);
    cout << "Your BMI is: " << bmi << endl << "Your status is: " << findStatus(bmi);
}