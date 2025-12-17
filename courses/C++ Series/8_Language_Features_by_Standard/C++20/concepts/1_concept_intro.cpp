/* C++ 20 Concepts introdution

Def: Concepts
    Concepts are an extension to the templates features. Concepts are "named Boolena predicates" on 
    template paramters, evaluated at compile time. 

    Concepts can be thouhgt of as a constraint so that we choose the right type that can implement
    whatever behaviour our template function or class is implementing. So concepts are used to 
    model constraints onto some type or funtion we are instantiating.
*/
#include <iostream>
#include <cmath>
#include <concepts> // provides definitions of fundamentals concepts
// Concpet is a compile-time 'predicate' (test) on our type
// to make sure that we can use our templated function

// We want a print function that only works with integral types only
template< typename T >
requires std::integral<T>  // we are using this concept to enforce the use of integral types only
//                     ^
//             My type is integral
void print(T value)
{
    std::cout << "This integral value is: " << value << std::endl;
}


template< typename T>
requires std::integral<T>
bool is_equeal(T a, T b)
{
    return a == b;
}

/*
// version 1
// Using the requires clause
template< typename T>                                   // Function template parameters
requires std::floating_point<T>                         // Concept
bool is_equeal(T a, T b)                                // Function signature
{
    std::cout << " (floating_point concept) ";
    return std::fabs(a - b) < 0.00001;
}
*/

// version 2
// Shortened syntax for our concept on 'T': using the concept on the typename is
template< std::floating_point T >
bool is_equeal(T a, T b)
{
    std::cout << " (floating_point concept) ";
    return std::fabs(a - b) < 0.00001;
}

/*
// version 3
// this is the shortest syntax: using the concept on the individual parameters
bool is_equeal(std::floating_point auto a, std::floating_point auto b)
{
    std::cout << " (floating_point concept) ";
    return std::fabs(a - b) < 0.00001;
}
*/

int main() 
{
    print(7);        // This integral value is: 7
    /*
    print("str");    // this will not work with std::integral concept
    
<source>:19:6: note: template argument deduction/substitution failed:
<source>:19:6: note: constraints not satisfied

/opt/compiler-explorer/gcc-15.1.0/include/c++/15.1.0/concepts:109:13:   required for the satisfaction of 'integral<T>' [with T = const char*]
/opt/compiler-explorer/gcc-15.1.0/include/c++/15.1.0/concepts:109:24: note: the expression 'is_integral_v<_Tp> [with _Tp = const char*]' evaluated to 'false'
  109 |     concept integral = is_integral_v<_Tp>;
    */
    std::cout << std::boolalpha 
              << "1==1: " << is_equeal(1,1) << std::endl                          // 1==1: true
              << "1.0==1.0: " << is_equeal(1.0,1.0000000000000001) << std::endl;  // 1.0==1.0:  (floating_point concept) true

    return 0;
}