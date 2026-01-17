/** C++ Basic Bit Introduction Manipulation (Old C-Style) | Modern Cpp Series Ep. 208
 */

#include <iostream>

#include <cstdint>  // need to use fixed-with data types
#include <format> 


/* The bitwise operators are part of the arithmetic operator:

    Aritmethic operators
Operator name	        Syntax	            Prototype examples (for class T)
                                Inside class definition	            Outside class definition
Bitwise NOT	            ~a	    T T::operator~() const;	            T operator~(const T& a);
Bitwise AND	            a & b	T T::operator&(const T2& b) const;	T operator&(const T& a, const T2& b);
Bitwise OR	            a | b	T T::operator|(const T2& b) const;	T operator|(const T& a, const T2& b);
Bitwise XOR	            a ^ b	T T::operator^(const T2& b) const;	T operator^(const T& a, const T2& b);
Bitwise left shift	    a << b	T T::operator<<(const T2& b) const;	T operator<<(const T& a, const T2& b);
Bitwise right shift	    a >> b	T T::operator>>(const T2& b) const;	T operator>>(const T& a, const T2& b);

*/

int main()
{
    auto print = [](uint8_t v)
                 {
                    //      
                    // Note:
                    //      uint8_t is probably typedef to a char so we need cast the value to int.
                    std::cout <<  "dec: " << std::dec << (int)v                                  
                            << "\t hex: " << std::hex << (int)v                        
                            << "\t bin: " << std::format( "{:b}", v) << std::endl;                     
                    //                                          ~~
                    //      There is no option to print the binary format so we use format (C++20)
                 };

    uint8_t value1 = 16;
//  ~~~~~~~
//  1 byte = 8 bits

    //                 ^ 
    uint8_t value2 = 0b0111; // Number 7 (111): Group by four thats why we add and extra 0 
    //               ~~
    //     Use 0b prefix to specify as binary 
    
    // uint8_t value2 = 0b0000'0111;
    //                        ^    
    //      You can also break into sections for better reading using ' (underscore)
    //    to represent the 8 bits
    print( value1 ); // dec: 16	 hex: 10	 bin: 10000
    print( value2 ); // dec: 7	 hex: 7	 bin: 111

    
    // Bitwise left shift: Shifting 3 value to left
    value2 = value2 << 3; 
    print( value2 ); // dec: 56	 hex: 38	 bin: 111000

    // Bitwise rihgth shift: Shifting 4 value to rigth
    value2 = value2 >> 3; 
    print( value2 ); // dec: 7	 hex: 7	 bin: 111

    value2 >>= 1; 
    print( value2 ); // dec: 3	 hex: 3	 bin: 11
    //                                        ~~
    //                                we are truncating the number, we are loosing 1 bit

      
    return 0;
}