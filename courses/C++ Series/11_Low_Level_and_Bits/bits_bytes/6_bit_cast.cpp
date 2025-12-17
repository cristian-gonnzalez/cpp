/*
    std::bit_cast     <bit>      (C++20)
    =============
        It is another way to convert data from one type to another type. It is safer than reinterpret_cast

    template<
        class To,
        class From
    >
    constexptr To bit_cast( const From& from)
        ^
        |
     This means that it happends at compile-time.

*/

#include <iostream>
#include <bit>  // algorithms
#include <bitset>

void double_to_bin(double d)
{
    char *p = (char *)&d;
    std::cout << "bits (" << sizeof(d) << " bytes): ";
    for(ssize_t i=7; i>-1; --i)
        std::cout << std::bitset<8>(p[i]) << " ";
    std::cout << std::endl;
}

int main()
{
    
    { /*
        // If we use c-style casting, we will get a truncated value
        //      
        //  constexpr long l = 255L;
        //  constexpr float d = (float)l; 
    
        // We get more protection at compile-time with this type of casting.
        constexpr long l = 255L;
        constexpr float d = std::bit_cast<float>(l); // error (sizeof(_To) == sizeof(_From))
                                                    // the size are different so we get a compile error
      */            
    }
    {
        constexpr long l = 255L;
        
        // bit_cast is effectively a safe-way to 'memcpy
        // But -- it is just that -- it can happen at compile-time, and it otherwise has some
        // safety checks
        constexpr double d = std::bit_cast<double>(l); 

        std::cout << "l is " << l << std::endl  // l is 255
                  << "d is " << d << std::endl; // d is 1.25987e-321
        double_to_bin(d); // bits (8 bytes): 00000000 00000000 00000000 00000000 
                          //                 00000000 00000000 00000000 11111111 
    }

    { /*
        long l = 255L;
        // does not work, need reference/pointer type
        double d = reinterpret_cast<double>(l);  // error: invalid cast from type 'long int' to type 'double'
      */
    }
    
    { 
        long l = 255L;
        char *c = std::bit_cast<char*>(&l); 
    
    }
    
    return 0;
}