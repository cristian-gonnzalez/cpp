/** Pointer pitfalls : nullptr de-reference
 */

#include <iostream>

// Usefeull tool to find a 'dereference of nullptr' is gdb.
//
//    Use -g to add debugin symbols
//             ^~
//      $ g++ -g -std=c++17 main.cpp -o prog 
//      $ gdb ./prog
//      (gdb) layout src
//            ^~~~~~ Layout view  
//      (gdb) r        -> Run the program
//
//      It will tell me exactly the line where mark the line where the de-reference to nullptr 
//  is occuring
//
//      (gdb) p px        
//      $1 = (int *) 0x0        


int main()
{
    int* px = nullptr;
    // We try to 'dereference a nullptr' we dont have access to. 
    // There is no block of memory where to store the value
    *px = 24; // SIGSEGV


    return 0;
}