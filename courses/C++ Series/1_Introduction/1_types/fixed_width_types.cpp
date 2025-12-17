#include <iostream>
#include <cstdint>  // need to use fixed-with data types

/* This is how is defined in 'cstdint'

typedef signed char     int8_t;
typedef short int       int16_t;
typedef  int            int32_t;

*/

int main()
{
    static_assert( sizeof(int) == 4, "must be a 32-bit architecture" );
    static_assert( sizeof(int32_t) == 4, "needs a 32-bit fixed width type" );
    static_assert( sizeof(int32_t) == sizeof(int), "I wanted to safely asume a int is always 4 bytes, but I was wrong" );

    int primite_int = 4;
    int32_t fixed32_int = 7;


    // When to use fixed-types?
    // When I definitely know the range -- example
    //           - Pixels: Have each compoent of a pixel (Red, Green, Blue, Alpha) from a range of 0-255.

    /*
    int8_t red = 255;
    int8_t blue = 5;
    int8_t green = 0;
    int8_t alpha = 127;

    std::cout << "int8 min: " << INT8_MIN << std::endl;
    std::cout << "int8 max: " << INT8_MAX << std::endl;
    
    // Note: needs to be casted to short since this is a typedef of an signed char
    std::cout << (short)red << ","
              << (short)blue << ","
              << (short)green << ","
              << (short)alpha << std::endl;

    // OUTPUT:
    // 
    // int8 min: -128
    // int8 max: 127
    // -1,5,0,127
    */
    // If we want a range from 0-255, makes sure that you us e the unsigned type

    uint8_t red = 255;
    uint8_t blue = 5;
    uint8_t green = 0;
    uint8_t alpha = 127;

    std::cout << "uint8 min: " << 0 << std::endl;
    std::cout << "uint8 max: " << UINT8_MAX << std::endl;
    
    // Note: needs to be casted to short since this is a typedef of an signed char
    std::cout << (short)red << ","
              << (short)blue << ","
              << (short)green << ","
              << (short)alpha << std::endl;
    
    // OUTPUT:
    // 
    // uint8 min: 0
    // uint8 max: 255
    // 255,5,0,127
    //

    return 0;
}