// ----- DO WHILE LOOPS -----
 
	// Needed for the time function
#include <iostream>
#include <ctime>
 
    // Do while loops are guaranteed to execute at least once
    // We'll create a secret number guessing game
    
    // Generate random number from 0 - 10
    
    // We need to seed the random number generator
    // time() returns the number of seconds since 1, 1, 1970

int main(){

    srand(time(NULL));
    
    // If you divide any number it is impossible to get a 
    // remainder >= 11
    int secretNum = std::rand() % 11;
    int guess = 0;
    
    do{
        
        std::cout << "Guess the number : ";
        std::cin >> guess;
        
        if(guess > secretNum) std::cout << "To Big\n";
        if(guess < secretNum) std::cout << "To Small\n";
        
    } while(secretNum != guess);
    
    std::cout << "You guessed it\n";
    
    
    // ----- END OF DO WHILE LOOPS -----
    
    // ----- PROBLEM CREATE A DO WHILE LOOP WITH WHILE -----
    secretNum = std::rand() % 11;
    while(true){
        std::cout << "Guess the number : ";
        std::cin >> guess;
        
        if(guess > secretNum) std::cout << "To Big\n";
        if(guess < secretNum) std::cout << "To Small\n";
        
        if(guess == secretNum) break;
    }
    
    std::cout << "You guessed it\n";

}
    
// ----- END PROBLEM CREATE A DO WHILE LOOP WITH WHILE -----