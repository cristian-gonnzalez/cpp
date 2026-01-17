// -std=c++20
/**  Fold expression in variadic templates
 *
 */
#include <iostream>

// C++ supports variadic templates. This means that can take arbitrary number and types of parameter


template< typename... T >
void func(T... args)
{

}

// We have 'fold expression' to unpack variadoc args
//
//  (args * ...) // becomes (args0 * (args1 * args2) )
//
//  (... * args) // becomes ((args0 * args1) * args2 )
//
//  (args * ... * 1) // becomes (args0 * (args1 * (args2 * 1) ) )
//
//  (1 * ... * args) // becomes ( ( (1 * args0) * args1 ) * args2) )

template< typename... T >
auto product(T... nums)
{
    return (nums * ...);
}

/*
template<>
int product<int, int, int, int>(int __nums0, int __nums1, int __nums2, int __nums3)
{
  return __nums0 * (__nums1 * (__nums2 * __nums3));
}
*/


template< typename... T >
void echo(T... args)
{
    (std::cout << ... << args );
}
/*
template<>
void echo<const char *, int, const char *, int, const char *, const char *>(const char * __args0, int __args1, const char * __args2, int __args3, const char * __args4, const char * __args5)
{
  std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout, __args0).operator<<(__args1), __args2).operator<<(__args3), __args4), __args5);
}

*/

int main()
{
    std::cout << "product(10, 20, 30, 40): " << product(10, 20, 30, 40) << std::endl; // product(10, 20, 30, 40): 240000
    
    echo("Hello ", 3, " World ", 0, " !!!", "\n"); // Hello 3 World 0 !!!
    // (std::cout << "hello " ) << "3" ) << " World " ) << 0 ) << "!!!" ) << "\n" )
    
    return 0;
}