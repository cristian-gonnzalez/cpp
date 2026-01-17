/*
  Type punning
    this is a way to get away the type system.

    It is a prgrammyng tecnique that subverts the type system

*/

#include <iostream>
#include <bit>  // algorithms
#include <bitset>
#include <cstdint>
#include <cstddef>

using binary_cast32 = std::bitset<32>;

int main()
{
    //unsigned int data = 255;
    unsigned int data = 0XFF'0B'FD'0A;

    std::cout << binary_cast32(data) << std::endl; // 11111111 00001011 11111101 00001010

    /*
        uint (uint32_t)  [ 1111 1111 , 0000 1011, 1111 1101, 0000 1010 ]
             4 bytes       8 bits      8 bits     8 bits     8 bits
                                                              ^
                                                              |
                                                            int8_t  
                                               (Use this as a "per-byte" iterator )
    */


    // "Type punning"
    // Allows us to access the data using a different type.
    // Recommendation is to use a Modern C++ style cast to do 
    // this style of type-punning.
    uint8_t* byte = reinterpret_cast<uint8_t*>(&data);
    std::cout << std::format("{:0>8b}", byte[0]) << std::endl  // 00001010
              << std::format("{:0>8b}", byte[1]) << std::endl  // 11111101
              << std::format("{:0>8b}", byte[2]) << std::endl  // 00001011
              << std::format("{:0>8b}", byte[3]) << std::endl << std::endl; // 11111111


    // One small improvement to show intention is to use std::byte
    /*
        std::byte   <cstddef> (C++17)

        enum class byte : unsigned char {};

        It is not a character type and is not an arithmetic type. std::byte is a 
        collection of bits, supporting bitshift operations with an integer, and 
        bitwise and comparison operation woth another std::byte
    
    */   
    std::byte* byte2 = reinterpret_cast<std::byte*>(&data);
    std::cout << std::format("{:0>8b}", (uint8_t)byte2[0]) << std::endl  // 00001010
              << std::format("{:0>8b}", (uint8_t)byte2[1]) << std::endl  // 11111101
              << std::format("{:0>8b}", (uint8_t)byte2[2]) << std::endl  // 00001011
              << std::format("{:0>8b}", (uint8_t)byte2[3]) << std::endl; // 11111111
   
    return 0;
}