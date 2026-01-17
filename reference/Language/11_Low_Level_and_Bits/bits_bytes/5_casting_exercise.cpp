#include <iostream>
#include <bit>  // algorithms
#include <bitset>
#include <cstdint>
#include <cstddef>

void double_binary_form(double d)
{
    std::cout << "Double has "<< sizeof(d) << " bytes\n";   // Double has 8 bytes
    
    // type punning
    {
        char* b = reinterpret_cast<char *>(&d);
        for(ssize_t i=sizeof(d)-1; i>=0; --i)
        {
            std::cout << std::bitset<8>(b[i] ) << " ";  // 01000000 01101111 11100000 00000000 
                                                        // 00000000 00000000 00000000 00000000 
        }                                   
        std::cout << std::endl;
    }

    // Using byte to show intention
    // Note: we cannot use std::bitset with std::byte
    {
        std::byte* b = reinterpret_cast<std::byte *>(&d);

        for(ssize_t i=sizeof(d)-1; i>=0; --i)
        {
            std::cout << std::format( "{:0>8b}", (uint8_t)b[i] ) << " ";  // 01000000 01101111 11100000 00000000 
                                                                        // 00000000 00000000 00000000 00000000 
        }                                   
        std::cout << std::endl;
    }
}

int main()
{
    // go to https://www.binaryconvert.com/result_double.html?decimal=050053053
    double value = 255.0;
    double_binary_form( value );

    return 0;
}