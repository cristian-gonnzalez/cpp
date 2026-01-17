/** C++ STL std::bitset Improved bit Manipulation | Modern Cpp Series Ep. 209

std::bitset           <bitset>
===========

template <
    std::size_t N
> class bitset;

This class template represents a fixed-size sequennce of N bits.

This means we have a data structure that's not limited to just 8, 16, 32 or 64 bits. We could 
actually have as many as we want
*/

#include <iostream>
#include <bitset>  
#include <cstdint> // uint8_t


int main()
{
    uint8_t bin = 0b1010'1111;

    // to print a binary value we can just actuallit convert it to a bitset
    std::cout << std::bitset<8>(bin) << std::endl; // 10101111
                         //  ^
                         // specify the size
                         // Constructs a bitset from an unsigned integer.
    /*
    bitset( unsigned long val );
    constexpr bitset( unsigned long long val ) noexcept;
                      ~~~~~~~~~~~~~~~~~~
                      we could pass in the largest integer (64-bits)
    */

    {
        // 1) Default constructor. Constructs a bitset with all bits set to zero.
        std::bitset<100> bits;
        
        std::cout << bits << std::endl; // 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
        std::cout << sizeof( bits ) << std::endl; // 16
    
        // Sets bits to true or given value
        for(size_t i=0; i<10; i++)
            bits.set(i, true);
            //       ^
            //     position

  
        std::cout << bits << std::endl; // 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111111
        // returns the numbers the bits set to true
        std::cout << bits.count() << std::endl; // 10

    }
    
    {
        std::string mask_str = "1010101010";
        
        /*
        std::bitset<10> bit_mask{mask_str};
                    ~~~
        std::bitset<100> bits;
                    ~~~

        bits = bits & bit_mask;
        error: no match for 'operator&' (operand types are 'std::bitset<100>' and 'std::bitset<10>')
            28 |     bits = bits & bit_mask;
                |            ~~~~ ^ ~~~~~~~~
                |            |      |
                |            |      bitset<10>
                |            bitset<100>
        
        We need to be more precise
        */
        
        std::bitset<10> bit_mask{ mask_str };
                                // ~~~~~~~~~~~~~~
                                // Constructs a bitset using the characters in str.
        std::cout << bit_mask << std::endl; // 1010101010
       
        std::bitset<10> bits;
        
        for(size_t i=0; i<10; i+=3)
            bits.set(i, true);

        std::cout << bits << std::endl; // 1001001001
 
        bits = bits & bit_mask;
        std::cout << bits << std::endl; // 1000001000
        
    }
    

    return 0;
}