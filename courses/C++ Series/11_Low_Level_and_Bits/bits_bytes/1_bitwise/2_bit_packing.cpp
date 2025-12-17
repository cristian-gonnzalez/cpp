/** C++ Basic Bit Introduction Manipulation (Old C-Style) | Modern Cpp Series Ep. 208
 */

#include <iostream>

#include <cstdint>  // need to use fixed-with data types
#include <format> 


int main()
{
     // 1. Bit packing
    //             r  g  b  a    ( 8 bits each for each component)
    int pixel = 0xFF'EE'00'BB;
//  ~~~           ~~ ~~ ~~ ~~
// 4 btyes -> 32 bits

    // NOTE:
    //      1 byte can represent 2^8 = 256 different values
    //      Typically from 0 to 255 (unsigned) or from –128 to +127 (signed).
    // 
    //      Each hexadecimal digit represents 4 bits (a “nibble”).
    //
    //      R          G            B           A 
    //  _______________________________________________
    // | F    F    | E    E    | 0    0    | B    B    |
    // | 1111 1111 | 1110 1110 | 0000 0000 | 1011 1011 |  
    // |___________|___________|___________|___________|
    //      8 bits    8 bits      8 bits       8 bits        
    //   32          24          16          8    
    
    //   
    // To get FF, I have to shift right 24 bits 
    //
    // 0xFF' EE' 00' BB
    //   32  24  16  8    
    //       ~~~~~~~~~~ > Im pushing all these bits off the cliff
    // 

    uint8_t r = pixel >> 24;  // to get r, shift right 24 bits
    uint8_t g = pixel >> 16;
    uint8_t b = pixel >> 8;
    uint8_t a = pixel >> 0;
    std::cout << std::hex << "r: " << static_cast<int>(r) << std::endl  // r: ff
                          << "g: " << static_cast<int>(g) << std::endl  // g: ee
                          << "b: " << static_cast<int>(b) << std::endl  // b: 0
                          << "a: " << static_cast<int>(a) << std::endl; // a: bb

    return 0;
}