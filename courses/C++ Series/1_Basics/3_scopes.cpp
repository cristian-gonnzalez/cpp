/** C++ Block Scope 
 */
#include <iostream>

/*
 Scope:
    Scope defines where a variable is visible and where it can be used.
*/

// This is a globally scoped variable.
// It is stored in the data section of the program.
//
// NOTE:
//   Initialized global variables → .data section
//   Uninitialized globals        → .bss section
int x = 42;

int main()
{ // Scope A
  
    { // Scope B

        // This variable is locally available inside this scope and in all inner scopes.
        // It 'shadows' the global variable 'x'.
        //
        // Note: 
        //   This varibale 'x' has his own memory location in the stack
        int x = 23;

        // I cannot access 'y' before its declaration:
        // y = 5;  // ERROR

        {   // Scope C

            // This is a new locally variable named 'x'. It shadows the 'x' from scope B.
            // It occupies its own separate memory location on the stack.
            int x = 7;
            std::cout << "x: " << x << std::endl;  // x: 7

            x = -5;
            std::cout << "x: " << x << std::endl;  // x: -5

        } // Scope C ends: this 'x' goes out of scope and its storage is released. 
        
        // A new variable 'x' inside the for-loop.
        // This also shadows the 'x' from scope B.
        std::cout  << "x: ["; 
        for(int x =0; x < 10; x++)
            std::cout  << x << ", "; 
        std::cout  << "]\n";  // x: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
        
        std::cout << "x: " << x << std::endl; // x: 23

        int y = 4; // 'y' is visible only from here to the end of scope B.

    } // scope B ends: variables 'x' and 'y' go out of scope.
    
    // Refers to the global x
    std::cout << "x: " << x << std::endl; // x: 42

    return 0;    
} 