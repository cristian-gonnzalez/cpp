/** C++ STL numeric Bit Manipulation Operations/Algorithms | Modern Cpp Series Ep. 210
 */

#include <iostream>
#include <bit>     // algorithms
#include <bitset>
#include <cstdint> // uint8_t

/*
  Bit manipulation  (C++20)    <bit>

    Provides several function templates to access, manipulate, and process individual 
  bits and bit sequences.

*/

int main()
{
    using binary_cast8 = std::bitset<8>; // using to print binary format

    uint8_t bin = 0b1111'0001;

    // Rotation operations
    {
        std::cout <<  binary_cast8( bin ) 
                  << " -> " << binary_cast8( std::rotl(bin, 1) ) << std::endl;  // 11110001 -> 11100011
        std::cout <<  binary_cast8( bin ) 
                  << " <- " << binary_cast8( std::rotr(bin, 1) ) << std::endl;  // 11110001 <- 11111000
    }

    {
        // Checks if x is an integral power of two -- could be useful for optimizing multiply/divide
        uint8_t pow2    = 0b0000'0100;
        uint8_t pow2not = 0b0001'1001;
                                //  ^
                                // Checking this bit we know if it is even or not
        std::cout << std::boolalpha 
                << std::has_single_bit( pow2 ) << std::endl;     // true
        std::cout << std::has_single_bit( pow2not ) << std::endl;  // false
    }
    

    {
        // std::byteswap: (C++23 feature) 
        //      Reverse the bytes in the given integer value    

        /*  This is how the architecture reorder the bytes (whether you are big-endian or 
        little-endian)

            [ FE  01  02  73 ]
               3   2   1   0
        
            [ 73  02  01  FE ]
               0   1   2   3
        
        */

        uint32_t bytes = 0xFF'DD'AA'77; 
        std::cout << std::hex 
                  << bytes << std::endl                                // ffddaa77
                  << std::byteswap(bytes) << std::dec << std::endl;    // 77aaddff
    }
    
    //endianness
    if constexpr ( std::endian::native == std::endian::big)            // Little-endian machine 
        std::cout << "Big-endian machine\n";
    else if constexpr ( std::endian::native == std::endian::little)
        std::cout << "Little-endian machine\n";
    else
        std::cout << "Mixed-endian machine\n";
    
    {
        // std::bit_width:
        //      Finds the smallest number of bits needed to represent the given value
        // UL is for an integer "unsigned type"
        std::cout << std::bit_width(325UL) << std::endl; // 9
                        //          ~~~^^ 
                        //           ^  UL is for an integral 'unisigned type'
                        //           |
                        //    Must be unsigned integer value
                        // ( unsigned char, unsigned short, unsigned int, 
                        //   unsigned long, unsigned long long, or an 
                        //   extended unsigned integer type )
    }
    
    return 0;
}