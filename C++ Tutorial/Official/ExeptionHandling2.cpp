// ----- EXCEPTION HANDLING EX 2 -----

#include <iostream>

int main(){
    
    try {
        std::cout << "Throwing exception\n";
        
        // Another way to throw an exception
        throw std::runtime_error("Error Occurred");
        
        // This point is never reached
        std::cout << "Can you print me?\n";
    }
    
    // All exceptions are based on std::exception
    catch(std::exception &exp){
        
        // what() Prints an explanatory string
        std::cout << "Handled Exception : " << 
                exp.what() << "\n";
    }
    
    // If exceptions aren't caught any place else 
    // this will catch it
    catch(...){
        std::cout << "Default exception catch\n";
    }
 
}

// ----- END OF EXCEPTION HANDLING EX 2 -----