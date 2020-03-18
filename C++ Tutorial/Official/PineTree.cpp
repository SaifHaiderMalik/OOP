// ----- PROBLEM DRAW A PINE TREE -----
// For this problem I want you to draw a pine 
// tree after asking the user for the number 
// of rows. Here is the sample program
 
/*
 How tall is the tree : 5
    #
   ###
  #####
 #######
#########
    #
 */
 
/*
I know that this is the number of spaces 
and hashes for the tree
4 - 1
3 - 3
2 - 5
1 - 7
0 - 9
Spaces before stump = Spaces before top
 
So I need to
1. Decrement spaces by one each time through 
the loop
2. Increment the hashes by 2 each time through 
the loop
3. Save spaces to the stump by calculating 
tree height - 1
4. Decrement from tree height until it equals 0
5. Print spaces and then hashes for each row
6. Print stump spaces and then 1 hash
*/
#include <iostream>
#include <vector>

std::vector<int> Range(int start, int max, int step);

int main(){
    std::cout << "How tall is the tree : ";
 
    // The top of the tree starts with 1 hash
    int treeHeight = 0, spaces = 0, hashes = 1,
            stumpSpaces = 0; 
    
    std::cin >> treeHeight;
    
    // Starting spaces = treeHeight - 1
    spaces = treeHeight - 1;
    
    // Spaces before stump = tree height - 1
    stumpSpaces = treeHeight - 1;
    
    // while there are more rows to print keep going
    while(treeHeight != 0){
        
        // Print spaces before hashes
        for(auto x: Range(1, spaces, 1))
            std::cout << " ";
        
        // Print the hashes
        for(auto x: Range(1, hashes, 1))
            std::cout << "#";
        
        // Newline after each row
        std::cout << "\n";
        
        // Spaces decremented by 1 each time
        spaces -= 1;
        
        // Hashes incremented by 2 each time
        hashes += 2;
        
        // Decrement treeHeight so loop ends
        treeHeight -= 1;
        
    }
    
    // Print spaces befor stump
    for(auto x: Range(1, stumpSpaces, 1))
            std::cout << " ";
    
    // Print stump
    std::cout << "#";
    
    return 0;
}
 
std::vector<int> Range(int start, int max, int step){
    
    // Every while statement needs an index 
    // to start with
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
 
// ----- END PROBLEM DRAW A PINE TREE -----