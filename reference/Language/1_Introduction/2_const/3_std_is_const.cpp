/** std::is_const: Checks whether a type is const-qualified
 */
#include <iostream>
#include <type_traits> // is_const

/*
is_const: 
    Checks whether a type is const-qualified.

Defined in header <type_traits>
template< class T >
struct is_const;

    std::is_const is a UnaryTypeTrait.

    If T is a const-qualified type ('const' or 'const volatile'), std::is_const provides 
a member constant 'value' equal to true. Otherwise, 'value' is false.

- Helper variable template:
    
    template< class T >
    constexpr bool is_const_v = is_const<T>::value;
                                             ^~~~~
                                   Boolean member value to kown if T is 'const T'
*/

int main()
{
    const int x = 42;

    // error: assignment of read-only variable 'x'
    // x = 37;
    // ~~^~~~

    std::cout << std::boolalpha  
              << "'int' is const?       " << std::is_const_v<int> << std::endl            // 'int' is const?       false
              << "'const int' is const? " << std::is_const_v<const int> << std::endl      // 'const int' is const? true
              << "'x' is const?         " << std::is_const_v< decltype(x) > << std::endl; // 'x' is const?         true
            //                                                ~~~~~~~~~~~
            //                                                gets the declaration type of 'x'
            //                               std::is_const_v< const int > -> The compiler translate to this

    return 0;
}