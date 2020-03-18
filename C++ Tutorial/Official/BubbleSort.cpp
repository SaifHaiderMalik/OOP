// ---------- C++ TUTORIAL 8 ----------
 
// Add this to Project Properties -std=c++14
 
// ---------- BUBBLE SORT ----------
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
 
std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
 
void BubbleSort(std::vector<int>& theVec);
 
int main() {
    
    // Generate a random vector of 10 values between 1 and 50
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    
    BubbleSort(vecVals);
    
    // Output the sorted vector
    for(auto x: vecVals)
        std::cout << x << "\n";
    
    return 0;
    
}
 
std::vector<int> GenerateRandVec(int numOfNums, int min, int max){
    std::vector<int> vecValues;
    
    // Seed the random number generator
    srand(time(NULL));
    
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        // The min added on increases result based on min
        // The remainder of modulus can't be greater
        // then the divisor. We have to adjust down
        // based on the addition from min
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}
 
void BubbleSort(std::vector<int>& theVec){
    
    // ----- SORT A LIST : BUBBLE SORT -----
// The Bubble sort is a way to sort a list
// It works this way
// 1. An outer loop decreases in size each time
// 2. The goal is to have the largest number at 
// the end of the list when the outer loop 
// completes 1 cycle
// 3. The inner loop starts comparing indexes 
// at the beginning of the loop
// 4. Check if list[Index] > list[Index + 1]
// 5. If so swap the index values
// 6. When the inner loop completes the largest number is at
// the end of the list
// 7. Decrement the outer loop by 1
 
// Create the value that will decrement for the outer loop
// Its value is the last index in the list
    int i = theVec.size() - 1;
    
    while(i >= 1){
        int j = 0;
        
        while(j < i){
            printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);
            
            if(theVec[j] >= theVec[j+1]){
                std::cout << "Switch\n";
                
                int temp = theVec[j];
                theVec[j] = theVec[j+1];
                theVec[j+1] = temp;
            } else {
                std::cout << "Don't Switch\n";
            }
            j += 1;
            
            for(auto k: theVec){
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of Round\n";
        i -= 1;
    }
}
 
// ---------- END OF BUBBLE SORT ----------