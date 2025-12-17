/** C++ Integer and floating suffixes and using the single quote for clarity
 *  
 */
#include <iostream>

int main()
{

    //
    // Floating-point literals
    //

    auto f1 = 3.124;  // (no suffx) defines double -> double f1 = 3.1240000000000001;
    
    // f/F defines float
    auto f2 = 3.124f;  // float f2 = 3.12400007F;
    auto f3 = 3.124F;  // float f3 = 3.12400007F;
    
    // l/L defines ling double
    auto f4 = 3.124l;  //   long double f4 = 3.12399999999999999998L;
    auto f5 = 3.124L;  //   long double f5 = 3.12399999999999999998L;




    //
    // Integer literals
    //

    auto i1 = 3;  // (no suffx) defines int -> int i1 = 3;
    
    // f/F defines unsigned int
    auto i2 = 3u;  // unsigned int i2 = 3U;
    auto i3 = 3U;  // unsigned int i3 = 3U;
    
    // l/L defines long
    auto i4 = 3l;  // long i4 = 3L;
    auto i5 = 3L;  // long i5 = 3L;


    auto one_million = 1'000'000ul; //   unsigned long one_million = 1000000UL;

    
    return 0;
}