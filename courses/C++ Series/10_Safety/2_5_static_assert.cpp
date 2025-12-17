/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
#include <cassert>
/*
Safety in C++ Programming: Lenguage Level Features -- compile-time

    This is an improvement of 'assert'.

    It has a cost since we are paying more compile time

- static_assert
    
    - Check what you can at compile-time
    
    - In your test-suite, use static_assert as much as necessary
    
    - Can be useful for thins like:
        
        static_assert( sizeof(int) == 4, "int has 4 bytes")
    
*/

constexpr int add(int a, int b)
{
    return a+b;
}

int main()
{
    // Works with constexpr, checked at compile-time 
    static_assert( add(2, 2) == 4,       "2 + 2 = 4" );
    // Works with types, checked at compile-time
    static_assert( sizeof(int) == 4,     "int is 4 bytes on this architecture" );
    // Endorce fized-width types at compile-time
    static_assert( sizeof(int32_t) == 4, "int32_t is always 4 bytes" );
    
   return 0;
}