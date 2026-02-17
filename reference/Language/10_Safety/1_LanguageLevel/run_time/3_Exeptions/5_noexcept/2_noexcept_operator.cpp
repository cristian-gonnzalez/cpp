/** noexcept operator
 */
#include <iostream>
#include <stdexcept>
#include <utility>

void may_throw()
{
}

void wont_throw() noexcept
//                ^~~~~~~~
//             noexcept specifier
{
}

int main()
{
    // NOTE: noexcept operator (C++11)
    //   Performs a compile-time check that returns true if an 
    // expression is declared to not throw any exceptions.
    std::cout << std::boolalpha 
              << "may_throw() is mark noexcept? : "
              << noexcept( may_throw() ) << std::endl   // may_throw() is mark noexcept? : false
              << "wont_throw() is mark noexcept?: "
              << noexcept( wont_throw() ) << std::endl; // wont_throw() is mark noexcept?: true
    //           ^~~~~~~~

    return 0;
}
