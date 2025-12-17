/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
#include <cassert>
#include <cstdint> // Fixed width integer types
/*
Safety in C++ Programming: Lenguage Level Features -- compile-time

- Fixed width types
    
    - Know exactly the size of your primitive data types.
        * eg. int16_t, int32_t, etc;
    
    - Why are they better?
        * 'int' could be either 2 bytes or 4 bytes depend on the system architecture
        * We just learned about static_assert, but thar problem can otherwise be avoided
        by using fixed-width types.
        
    See https://cppreference.com/w/cpp/types/integer.html
*/


int main()
{
    static_assert( sizeof(int) == 4,     "must be a 32-bit architecture" );
    static_assert( sizeof(int32_t) == 4, "needs a 32-bit fixed width type" );
    static_assert( sizeof(int32_t) == sizeof(int), "I may wanto to safety assume a int is always 4 bytes, but I should always check!" );
    
    int primitive_int = 5;
    int32_t fixed32_int = 7;

    // When to use fixed-types? 
    // When I definitely know the range -- for ex: pixel formats.
    uint8_t red = 255;
    uint8_t blue = 5;
    uint8_t green = 0;
    uint8_t alpha = 127;
    
    std::cout << "uint8_t min: " << 0 << std::endl;             // uint8_t min: 0
    std::cout << "uint8_t max: " << UINT8_MAX << std::endl;     // uint8_t max: 255

    // If you are going to cast, prefer to use C++11 and casts such as static_cast
    //      * It is explicit, and easier to search for in your text editor
    //      * static_cast can be checked at compile-time.
    //
    // NOTE: static_cast are sometimes hidden, but that is what std::move is using
    //  to convert to a rvalue_reference
    std::cout << static_cast<short>(red) << ", "
              << static_cast<short>(blue) << ", "
              << static_cast<short>(green) << ", "
              << static_cast<short>(alpha) << std::endl; // 255, 5, 0, 127


   return 0;
}