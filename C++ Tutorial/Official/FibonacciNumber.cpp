// ----- PROBLEM : GENERATE FIBONACCI NUMBER -----
// Use recursion to generate the following results
// fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2,
// fib(4) = 3, fib(5) = 5, fib(6) = 8, fib(7) = 13

#include <iostream>

int Fib(int index);
 
int main() {
    int index;
    std::cout << "Get Fibonacci Index : ";
    std::cin >> index;
    printf("fib(%d) = %d\n", index, Fib(index));
    
    return 0;
    
}
 
int Fib(int index){
    if (index < 2){
        return index;
    } else {
        return Fib(index - 1) + Fib(index - 2);
    }
}
 
// ----- END PROBLEM : GENERATE FIBONACCI NUMBER -----