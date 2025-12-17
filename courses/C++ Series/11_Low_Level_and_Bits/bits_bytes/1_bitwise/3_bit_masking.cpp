/** C++ Basic Bit Introduction Manipulation (Old C-Style) | Modern Cpp Series Ep. 208
 */

#include <iostream>

#include <cstdint>  // need to use fixed-with data types
#include <format> 


int main()
{
    auto print_bits = [](int filter)
                        {
                            uint8_t r = filter >> 24;
                            uint8_t g = filter >> 16;
                            uint8_t b = filter >> 8;
                            uint8_t a = filter >> 0;
                            std::cout << std::hex << "r:" << static_cast<int>(r) << "\t"
                                                  << "g:" << static_cast<int>(g) << "\t"
                                                  << "b:" << static_cast<int>(b) << "\t"
                                                  << "a:" << static_cast<int>(a) << std::endl;
                        };
    //2. Bit masking
    
    //             r  g  b  a    ( bits each for each component)
    int pixel = 0xFF'EE'00'BB;

    // I have a mask to block off some of the bits
    int mask = 0xFF'00'00'00;
    //           ~~
    //         just keeps all the bits in the R position

    {
            
        int filter = pixel & mask;
        print_bits( filter); // r:ff	g:0	b:0	a:0    
    
        // The result is 1 only if both bits are 1.
        //
        // A	B	A AND B
        // 0	0	0
        // 0	1	0
        // 1	0	0
        // 1	1	1
    }

    {
        // The result is 1 if at least one bit is 1.
        //
        // A	B	A OR B
        // 0	0	0
        // 0	1	1
        // 1	0	1
        // 1	1	1
        
        int filter = pixel | mask;
        print_bits( filter); // r:ff	g:ee	b:0	a:bb
    }
 
    {
        // The result is 1 only if the bits are different.
        // 
        // A	B	A XOR B
        // 0	0	0
        // 0	1	1
        // 1	0	1
        // 1	1	0

        // flit the bits (Xor)
        int filter = pixel ^ mask;
        print_bits( filter); // r:0	g:ee	b:0	a:bb
     }

    
    return 0;
}