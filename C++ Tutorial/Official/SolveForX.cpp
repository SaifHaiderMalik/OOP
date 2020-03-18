#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
 
// ----- 1. PROBLEM : SOLVE FOR X -----
 
std::vector<std::string> StringToVector(std::string theString, char separator);
        
void SolveForX(std::string equation);
 
int main() {
    
    // Make a function that receives an algebraic 
    // equation like x + 4 = 9 and solve for x
    // x will always be the 1st value received 
    // and you only will deal with addition
    std::cout << "Enter an equation to solve ";
    std::string equation = "";
    getline(std::cin, equation);
    SolveForX(equation);
    
    return 0;
    
}
 
std::vector<std::string> StringToVector(std::string theString, char separator){
    
    std::vector<std::string> vecsWords;
    std::stringstream ss(theString);
    std::string sIndivStr;
    while(getline(ss, sIndivStr, separator)){
        vecsWords.push_back(sIndivStr);
    }
    return vecsWords;
}
 
void SolveForX(std::string equation){
    std::vector<std::string> vecEquation = StringToVector(equation, ' ');
    
    // Convert strings to int
    int num1 = std::stoi(vecEquation[2]);
    int num2 = std::stoi(vecEquation[4]);
    int xVal = num2 - num1;
    
    std::cout << "x = " << xVal << "\n";
 
}
// ----- 1. END PROBLEM : SOLVE FOR X -----