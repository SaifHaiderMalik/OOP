// ---------- C++ Tutorial 3  ----------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Needed for std::iota
#include <numeric>

// ----- FUNCTION PROTOTYPES -----
// You define the return type and data types for functions
// using a function prototype so main knows what is to be expected
// from this function
double AddNumbers(double num1, double num2);

void AssignName();

void AssignAge(int age);

int AssignAge2(int age);

// This function receives pointers
void AssignAge3(int* pAge);

// Double values in array passed
void DoubleArray(int *arr, int size);

// ----- END OF FUNCTION PROTOTYPES -----

int main() {
    
    // ----- FUNCTIONS -----
    // Code that gets above 8 to 10 lines should be broken off
    // into a separate function to better organize your code
    // and to promote reuse
    
    double num1, num2;
    
    std::cout << "Enter Num 1 : ";
    
    // An alternative way to store a value
    std::cin >> num1;
            
    std::cout << "Enter Num 2 : ";
    std::cin >> num2;
    
    // Call the function 
    printf("%.1f + %.1f = %.1f\n", num1, num2, AddNumbers(num1, num2));
    
    // Variables in a function are local to that function
    // Undeclared identifier error
    // std::cout << name;
    
    // Variables values changed in a function don't 
    // translate globally
    int age = 43;
    AssignAge(age);
    std::cout << "New Age " << age << "\n";
    
    // You could change the value by passing it back
    age = AssignAge2(age);
    std::cout << "New Age " << age << "\n";
    
    // A Pointer stores a address in memory
    // You declare a pointer to be of the same type as the data 
    // type to which it points
    // If you are storing the address of an int then the 
    // pointer is an int
    // When you declare a pointer give it a null value
    int* pAge = NULL;
    
    // The reference operator returns the address for a 
    // variable that can be stored in a pointer
    pAge = &age;
    
    // Print the address Hexidecimal Number
    std::cout << "Address : " << pAge << "\n";
    
    // Get the value at that address with the dereference operator
    std::cout << "Value at Address : " << *pAge << "\n";
    
    // We can create a pointer to an array and cycle through
    // the data with ++ and --
    int intArray[] = {1,2,3,4};
    int* pIntArray = intArray;
    
    std::cout << "1st " << *pIntArray << " Address " << pIntArray << "\n";
    pIntArray++;
    std::cout << "2nd " << *pIntArray << " Address " << pIntArray << "\n";
    pIntArray--;
    std::cout << "1st"
            " " << *pIntArray << " Address " << pIntArray << "\n";
    
    // You can pass a pointer to a function and then the function
    // can change that variables value globally
    age = 43;
    
    // Send the address for age to the function
    AssignAge3(&age);
    
    std::cout << "Pointer Age " << age << "\n";
    
    // Create an array and double values
    int arr[] = {1,2,3,4};
    DoubleArray(arr, 4);
    for(int i = 0; i < 4; ++i){
        std::cout << "Array " << arr[i] << "\n";
    }
    
    return 0;
}

// ----- FUNCTIONS -----
// A function starts with the data type it will return or void
// if no value is returned
// You also list the data types for the parameters passed into 
// a function and you may assign them default values


double AddNumbers(double num1 = 0, double num2 = 0){
    return num1 + num2;
}

// A variable created inside a function can't be accessed 
// outside of it
void AssignName(){
    std::string name = "Derek";
}

void AssignAge(int age){
    age = 24;
}

int AssignAge2(int age){
    age = 24;
    return age;
}

// Function that receives a pointer
void AssignAge3(int* pAge){
    
    // Use dereference operator to change the value at the address
    *pAge = 22;
    
}

// Double values in array
void DoubleArray(int *arr, int size){
    for(int i = 0; i < size; ++i){
        arr[i] = arr[i] * 2;
    }
}

// ---------- End of C++ Tutorial 3  ----------