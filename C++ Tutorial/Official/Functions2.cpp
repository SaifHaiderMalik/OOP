// ----- FUNCTIONS -----
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
 
std::vector<int> Range(int start, int max, int step);
 
int main() {
    
    // ----- PROBLEM CREATE A RANGE FUNCTION -----
    // Create a function that receives a starting value,
    // max value and an increment amount between
    // values and receive a vector in return
    
    std::vector<int> range = Range(1, 10, 2);
    
    // Cycle through the vector
    for(auto y: range){
        std::cout << y << "\n";
    }
    
    // ----- END PROBLEM CREATE A RANGE FUNCTION -----
    
    // ----- PROBLEM CALCULATE COMPOUNDING INTEREST -----
    double investment = 0.0;
    double interestRate = 0.0;
    
    std::cout << "How much to invest : ";
    std::cin >> investment;
    std::cout << "Interest Rate : ";
    std::cin >> interestRate;
    
    // Convert to a percent
    interestRate *= .01;
    
    for(auto y: Range(1,10,1)){
        investment = investment + (investment * interestRate);
    }
    
    std::cout << "Value after 10 years : " << investment <<
            "\n";
    
    // ----- END PROBLEM CALCULATE COMPOUNDING INTEREST -----
    
    return 0;
}
 
std::vector<int> Range(int start, int max, int step){
    
    // Every while statement needs an index to start with
    int i = start;
    
    // Will hold returning vector
    std::vector<int> range;
    
    // Make sure we don't go past max value
    while(i <= max){
        
        // Add value to the vector
        range.push_back(i);
        
        // Increment the required amount
        i += step;
    }
    
    return range;
    
}