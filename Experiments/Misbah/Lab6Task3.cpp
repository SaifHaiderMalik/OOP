#include <iostream>

using namespace std;

void setMatrix(int array[][3], int N);
void transMatrix(int array[][3], int N);

int main(){
    int numRow[3];
    for(int i = 0; i < 3; i++){
        cout << "Number of Rows for Matrix No. " << (i+1) << ": ";
        cin >> numRow[i];
    }
    int array1[numRow[0]][3], array2[numRow[1]][3], array3[numRow[2]][3];

    cout << "Matrix 1:\n";
    setMatrix(array1, numRow[0]);
    cout << "Matrix 2:\n";
    setMatrix(array2, numRow[1]);
    cout << "Matrix 3:\n";
    setMatrix(array3, numRow[2]);

    /*for(int i = 0; i < numRow[0]; i++){
        for(int j = 0; j < 3; j++){
            cout << "Row " << (i+1) << ", Column " << (j+1) << ": ";
            cout << array1[i][j];
        }
    }*/

    cout << "Transpose of Matrix No. 1:" << endl;
    transMatrix(array1, numRow[0]);
    cout << "Transpose of Matrix No. 2:" << endl;
    transMatrix(array2, numRow[1]);
    cout << "Transpose of Matrix No. 3:" << endl;
    transMatrix(array3, numRow[2]);
}

void setMatrix(int array[][3], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cout << "Row " << (i+1) << ", Column " << (j+1) << ": ";
            cin >> array[i][j];
        }
    }
}

void transMatrix(int array[][3], int N){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            cout << array[j][i] << "\t";
        }
        cout << endl;
    }
}