/** Static asserts 
 * 
 *      You can verify that a compile-time expression is true via the 'static_assert' keyword
 */
#include <iostream>


// Handy inside template classes and template functions
template<typename T>
struct Check
{
    static_assert(sizeof(int) <= sizeof(T), "T is not big enough!");
    //            ~~~~~~~~~~~~~~~~~~~~~~~~   ~~~~~~~~~~~~~~~~~~~~
    //               expresion                    error message 
}; 
 
template<typename T>
T func(T x, T y)
{
    static_assert( std::is_integral_v<T>, "Must be integral");
    return x+y;
}

int main()
{
    //Check<char> c;
    /*      
        <source>: In instantiation of 'struct Check<char>':
        required from here
        <source>:14:17:   
        14 |     Check<char> c;
            |                 ^
        <source>:9:31: error: static assertion failed: T is not big enough!
            9 |     static_assert(sizeof(int) <= sizeof(T), "T is not big enough!");
            |                   ~~~~~~~~~~~~^~~~~~~~~~~~
        • the comparison reduces to '(4 <= 1)'
    */

    Check<long> c2;

    //std::cout << func(2.0f, 2.5f);
    /*
    In instantiation of 'T func(T, T) [with T = float]':
required from here
<source>:40:22:   
   40 |     std::cout << func(2.0f, 2.5f);
      |                  ~~~~^~~~~~~~~~~~
<source>:20:25: error: static assertion failed: Must be integral
   20 |     static_assert( std::is_integral_v<T>, "Must be integral");
      |                    ~~~~~^~~~~~~~~~~~~~~~
  • 'std::is_integral_v<float>' evaluates to false
<source>:21:1: warning: no return statement in function returning non-void [-Wreturn-type]
   21 | }
      | ^
      */

    std::cout << func(2, 2) << std::endl; // 4
    
    return 0;
}