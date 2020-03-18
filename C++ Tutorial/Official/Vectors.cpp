#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main(){
    std::vector<int> myVec(10);
    
    // Generates incremental values starting at 0 and places
    // them in the vector provided
    
    // begin points at the 1st index and end points at the last
    // in the vector
    std::iota(std::begin(myVec), std::end(myVec), 0);
    
    // We can output the vector using a standard for loop
    for(int i = 0; i < myVec.size(); ++i){
        std::cout << myVec[i] << "\n";
    }
    
    // An abbreviated for loop is also available
    // auto determines the data type based on the value
    // y is assigned each value in the vector incrementing
    // the index by 1 each time through the loop
    for(auto y: myVec) std::cout << y << "\n";
    
    // Find if a value is even / odd with modulus
    int val = 8;
    if((val % 2) == 0){
        std::cout << val << " is Even\n";
    } else {
        std::cout << val << " is Odd\n";
    }
    
    // ----- PROBLEM : GENERATE VECTOR (1 - 10) AND PRINT EVENS ----- 
    
    std::vector<int> myVec2(10);
    std::iota(std::begin(myVec2), std::end(myVec2), 1);
    
    // We can print just even numbers with modulus
    for(auto y: myVec2){
        if((y % 2) == 0)
            std::cout << y << "\n";
    }
    
    // ----- END OF PROBLEM -----
}