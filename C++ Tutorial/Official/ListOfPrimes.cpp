// ----- 2. PROBLEM : RETURN A LIST OF PRIMES -----

#include <iostream>
#include <vector>
 
std::vector<int> Range(int start, int max, int step);
 
bool IsPrime(int num);
 
std::vector<int> GetPrimes(int maxNum);
 
int main() {
    int num = 0;
    std::cout << "Number to Check : ";
    std::cin >> num;
    
    // Shows bool values as true or false
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Is " << num << " Prime " <<
            IsPrime(num) << "\n";
    
    std::cout << "Generate Primes up to ";
    int maxPrime;
    std::cin >> maxPrime;
    
    std::vector<int> primeList = GetPrimes(maxPrime);
    for(auto x: primeList)
        std::cout << x << "\n";
    
    return 0;
    
}
 
std::vector<int> Range(int start, int max, int step){
    
    int i = start;
    std::vector<int> range;
    while(i <= max){
        range.push_back(i);
        i += step;
    }
    return range;
}
 
bool IsPrime(int num){
    for(auto n: Range(2, num - 1, 1)){
        if((num % n) == 0)
            return false;
    }
    return true;
}
 
std::vector<int> GetPrimes(int maxNum){
    
    std::vector<int> vecPrimes;
    
    for(auto x: Range(2, maxNum, 1)){
        if(IsPrime(x))
            vecPrimes.push_back(x);
    }
    
    return vecPrimes;
}
 
// ----- 2. END PROBLEM : RETURN A LIST OF PRIMES -----