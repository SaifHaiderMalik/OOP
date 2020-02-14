#include <iostream>

using namespace std;

class BMI{
    double weight, height, bmi;
    string status;

    public:
    void getInput(){
        cout << "Enter weight in Pounds: ";
        cin >> weight;
        cout << "Enter height in Inches: ";
        cin >> height;
    }

    double calculateBMI(){
        bmi = weight / (height * height) * 703;
        return bmi;
    }

    string findStatus(double bmi){
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

    void printStatus(){
        //bmi = calculateBMI();
        //sta
        cout << "Your BMI is: " << calculateBMI() << endl << "Your status is: " << findStatus(bmi);
    }
};

int main(){
    BMI bmi;
    bmi.getInput();
    bmi.printStatus();
    return 0;
}