/* A closer look at contant-ness

    constrexpr: 

    consteval (c++20)

    constinit (c++20)
*/

#include <iostream>

// constrexpr functions
//
// This function may be (or may be not) computed at compile-time. This means that the compiler will try to evaluate and 
// resolve at compile-time but the consexpre keyword could be ignored if the compiler cant resolve.
constexpr int multiply(int x, int y)
{
    return x*y;
}

int main()
{
    // constrexpr variables
    // Indicates the variable must be initialized at compile-time
    // constexpr variables are implicity 'const'. The advantages of this, that compiler will fail if it cannot evaluate the expresion
    const int b=10;
    constexpr int val = multiply(5, b);
    /* ~~~~~~
        ^ 
    Using 

    main.cpp: In function ‘int main()’:
main.cpp:27:38: error: the value of ‘b’ is not usable in a constant expression
   27 |     constexpr int val = multiply(5, b);
      |                                      ^
main.cpp:26:9: note: ‘int b’ is not const
   26 |     int b=10;
      |         ^
      */
    return 0;
}