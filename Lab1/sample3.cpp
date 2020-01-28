//Program to read a 2D array of size 3x3 find the sum for each row,
//print the sum line by line.

#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int item[3][3]; //Declare an array of size 3x3
    int sum = 0;
    int row, col;

    cout << "Enter array elements: " << endl;


    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            cin >> item[row][col];
            sum = sum + item[row][col];
        }

        cout << "The sum of row " << row << " : " << sum << endl; 
    }

    cout << endl;
    getch();
    return 0;
}