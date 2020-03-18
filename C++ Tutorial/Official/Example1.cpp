// ---------- C++ Tutorial Example 1 ----------
 
/* 
 * Multi-line Comment
 */
 
// These are called preprocessor directives
// They load the files which contain premade functions 
// for your use
 
// Contains functions for converting from 1 data type to
// another, random number generation, memory management,
// searching, math, sorting and other general purpose functions
#include <cstdlib>
 
// Provides functions for performing input and output operations
#include <iostream>
 
// If used you can type cout instead of std::cout
// By using this though you may have conflicts if you define
// functions that share a name with the std namespace
// using namespace std;
 
// You could define you only want to use part of a namespace like
// using std::cout;
// Which would allow you to use cout instead of std::cout
 
// Execution of code starts in the main function
// argc and argv is optional data that could be passed
// to the program if it was executed in a terminal
// argc : Number of arguments passed
// argv : Array pointers to strings
int main(int argc, char* argv[]) {
     
    // Outputs the string Hello World to the screen followed by a newline
    // cout is your console or screen
    // << : Stream insertion operator which puts the string
    // into the cout stream to display it
    std::cout << "Hello World" << std::endl;
    
    // If you compile the code into an executable program in the terminal
    // g++ main.cpp
    // And execute it : ./a.out I Love C++
    // You'd see how to work with passed arguments
    
    // If no arguments are passed argc has a value of 1
    // We check that with if to skip printing values if none were passed
    if(argc != 1){
    
        // You can also create a newline with \n
        std::cout << "You entered " << argc << " arguments\n";
    
        // Cycles through all the values in the argc array and prints them
        // We access the values by using their index number starting at
        // 0 
        for(int i = 0; i < argc; ++i){
        
            // We access each string passed by putting its index between []
            // called the subscript operator
            std::cout << argv[i] << "\n";
        }
    }
    
    // When 0 is returned that signals that the program executed without 
    // an error and -1 signals an error occurred 
    return 0;
}
 
// ---------- End of C++ Tutorial Example 1 ----------