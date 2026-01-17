/** Signed / Unsigned comparison and implicit conversions
 */
#include <iostream>
#include <iomanip>

/*
  Rules involved:
    - Usual arithmetic conversions
    - Signed / unsigned integer conversion
    - Integral promotions

  If one operand is unsigned and the other is signed, and both have
  the same rank (e.g. int and unsigned int), the signed operand is
  converted to unsigned.

    Use -Wall flag to prevent this operatoins

*/

int main()
{
    int a = -2;
    unsigned int b = 1;

    // a (int) is implicitly converted to unsigned int
    // -2 becomes 4294967294 (modulo 2^32 on a 32-bit unsigned int)
    if( a > b )
//      ~~^~~
// warning: comparison of integer expressions of different signedness: 'int' and 'unsigned int' [-Wsign-compare]     
        std::cout << "Sth is wrong here!\n"; // Sth is wrong here!

    std::cout << (unsigned int)a << std::endl // 4294967294
              << b << std::endl;
        
    // Bit representation (typical 32-bit two's complement):
    //   
    //     a = -2   11111111 11111111 11111111 11111110
    //     b = 1    00000000 00000000 00000000 00000001
    // 
    //  No bits change during the conversion.
    //  Only the interpretation of the bits changes.
    //
    //  As an unsigned value:
    //    11111111 11111111 11111111 11111110
    //    = 4294967294
    //
    //  Actual comparison performed:
    //    4294967294u > 1u  -> true
    //    

     return 0;
}