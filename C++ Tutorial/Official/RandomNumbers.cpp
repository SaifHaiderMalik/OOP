// ----- 3. PROBLEM : GENERATE A RANDOM VECTOR OF NUMBERS -----
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
 
// Needed for random number generation
#include <ctime>
 
std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
 
int main()
{
    std::vector<int> vecVals = GenerateRandVec(10, 5, 50);
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