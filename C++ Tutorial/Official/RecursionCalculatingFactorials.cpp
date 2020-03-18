// ---------- RECURSION CALCULATING FACTORIALS ----------

#include <iostream>

uint64_t Factorial(uint64_t number);
 
int main() {
    
    // A recursive function is one that calls itself
    // You must have an exit condition or you'll have 
    // an infinite loop
    // GetFactorial(3) = 3 * 2 * 1
    uint64_t num;
    std::cout << "Enter Number to Find its Factorial: ";
    std::cin >> num;
    std::cout << "Factorial " << num << " = " << Factorial(num) << "\n";
    
    return 0;
}
 
// 1. 3 * Factorial(2) (2) = 6
// 2. 2 * Factorial(1) (1)
// 3. 1 Return 1
 
 
uint64_t Factorial(uint64_t number){
    if(number == 1){
        return 1;
    } else {
        uint64_t result = number * Factorial(number - 1);
        return result;
    }
}    
 
// ---------- END RECURSION CALCULATING FACTORIALS ----------