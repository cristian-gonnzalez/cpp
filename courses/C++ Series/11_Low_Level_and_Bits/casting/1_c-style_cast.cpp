/** C style cast (run-time)
 */
#include <iostream>
#include <iomanip>

/*
  Cast:
    Treats a set of bits as a certain data type

  T1 x = 5;
  
  (T2) x;
  ~~~~~~
  C-style cast happens at 'run'-time and tells how we want to represent or interpret
these specific bits
*/

int main()
{
    std::cout << std::fixed
              << std::setprecision(6) // floating point: decimal places is 6
    //      (long)/(long)
              << 7/5 << std::endl        // 1
    //           ^~~                        ^
    // The result should be a float (or double) number but it gets truncated to integer
    // so we are lossing precision   
              << (float)7/(float)5 << std::endl        // 1.400000
    //           ^~~~~~~  ^~~~~~~
    // In order to get the result we need to cast each value  
              << (float)7/5 << std::endl;        // 1.400000
    //                    ^
    //                 (implicity cast) 
    //      5 gets promoted so that it can be treated as a floating point 
    //    value so we are dividing two floats

    int result = 5;
    short sh = result;

    std::cout << "size_of result: " << sizeof(result) << " bytes\n" // size_of result: 4 bytes
              << "size_of sh    : " << sizeof(sh) << " bytes\n"     // size_of result: 2 bytes
              << "result: " << result << std::endl                  // result: 5
              << "sh    : " << sh << std::endl;                     // sh    : 5

    //   result: 00000000 00000000 00000000 00000101  4 bytes
    //   sh    :                   00000000 00000101  2 bytes
    //
    //   When we are casting different data types, we must know if we have enougth bytes
    // to fill that data
    
    result = 50000;
    sh = result;
    std::cout << "result: " << result << std::endl                  // result: 50000
              << "sh    : " << sh << std::endl;                     // sh    : -15536

    //  The other thing we have to consider is the sign.
    //  For example: this scenario where we have enougth bytes to store 50000
    //
    //   result: 00000000 00000000 11000011 01010000 
    //   sh    :                   11000011 01010000
    //                             ^
    //                         sign bit (0: positive -- 1: negavite) 
    //
    //   This is where we have to be very caferfull with how we are converting or storing
    // number 
    std::cout << "result: " << (short)result << std::endl           // result: -15536
                  //           ^~~~~~~
                  //   Treats this as short  
              << "result: " << (unsigned short)result << std::endl; // result: 50000
                            //  ^~~~~~~~~~~~~~                
                  //   This is actual Ok since the bit is not used as a sign
    
    result = 5;
    unsigned char c = result;
    std::cout << c << std::endl            // 
                                           // ^
                                           // Ascii character 'enquiry'
              << (int)c << std::endl;      // 5
             //  ^~~~~
             // Treats this as int
    result = 65;
    c = result;
    std::cout << c << std::endl            // A
                                           // ^
                                           // Ascii character 'A'
              << (int)c << std::endl;      // 65
     
     return 0;
}