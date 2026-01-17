/** Signed / Unsigned comparison and implicit conversions
 */
#include <iostream>
#include <utility>

/*
C++20 Utilities library 

Defined in header <utility>
    (1) template< class T, class U >
        constexpr bool cmp_equal( T t, U u ) noexcept;
    (2) template< class T, class U >
        constexpr bool cmp_not_equal( T t, U u ) noexcept;
    (3) template< class T, class U >
        constexpr bool cmp_less( T t, U u ) noexcept;
    (4) template< class T, class U >
        constexpr bool cmp_greater( T t, U u ) noexcept;
    (5) template< class T, class U >
        constexpr bool cmp_less_equal( T t, U u ) noexcept;
    (6) template< class T, class U >
        constexpr bool cmp_greater_equal( T t, U u ) noexcept;

  Compare the values of two integers t and u. Unlike builtin comparison operators, 
negative signed integers always compare less than (and not equal to) unsigned 
integers: the comparison is safe against non-value-preserving integer conversion.

    -1 > 0u; // true
    std::cmp_greater(-1, 0u); // false
    It is a compile-time error if either T or U is a non-integer type, a character type, or bool.
*/

int main()
{
    int a = -2;
    unsigned int b = 1;

    if( a > b )
        std::cout << "Sth is wrong here!\n"; // Sth is wrong here!

    if( std::cmp_greater(a, b) )
        std::cout << "Should not print!\n"; 

     return 0;
}