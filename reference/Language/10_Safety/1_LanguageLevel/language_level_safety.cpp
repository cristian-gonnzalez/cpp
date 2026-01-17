/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
/*
Safety in C++ Programming:

What kind of safety can I buy?

There are 3 general places where I can apply safety tools. The currency may be to pay some performance

    1. Language level
    2. Library level
    3. Tooling level

 NOTE: There are probably more than 3 places: network, cloud, database, hardware, etc.

C++ Language features for safety

    Features  built into the language standard to assist us achieve our programming goals

        * Compile-time safety:
            const
            constexptr, constinit, consteval
            static_cast
            static_assert
            Fixed width types (e.g int16_t, int32_t, etc)
            Attributes (nothrow, nosidcard, fallthorugh)
            explicit constructor
        * Run-time safety
            assert
            Exceptions
            Variable initialization
            RAII
            dyanamic_cast vs reinterpret_cast or C-style cast
            thread_local

    And more:

        - Contracts (C++26)
        - type safety
        - encapsulation
        - rule of zero, rule of 3 and rule of 5
        - static_cast vs C-style cast
*/

int main()
{

   return 0;
}