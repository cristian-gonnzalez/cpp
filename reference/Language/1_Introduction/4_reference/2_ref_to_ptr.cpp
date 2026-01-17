/** References to pointer: ILLEGAL
 */
#include <iostream>

int main()
{    
    int* x = nullptr;
//  ~~~^
// Pointer — stores the address of an object (or nullptr)

    {
        // error: invalid conversion from 'int*' to 'int' [-fpermissive]
        //int& ref = x;
        //           ^
        //         int* → not an int object
        
        // Explanation:
        //   int& means 'reference to an int'. But x is an int* — a pointer, not an int.
        //
        //   A reference must bind to an existing object of the correct type.
        //
        //   The compiler sees:
        //
        //       int&   ref = x
        //              int =  int*
        //    mismatched types → invalid conversion.
    }   
    {
        // This should not be allowed but it compiles. 
        // Although this is ILLEGAL: https://isocpp.org/wiki/faq/references#refs-not-null 
        int*& ref = x;

        // Explanation:
        //   int*& means “reference to a pointer to int”.
        //   The full type of ref is: (int*)
        //
        //   The compiler sees:
        //
        //      int*&   ref =    x
        //             int* =  int*
        //       Type match → C++ allows the binding.
        //
        //   The types match → reference binds successfully.
        //
        //   ref now becomes an alias for x (the pointer itself).
    }   
}