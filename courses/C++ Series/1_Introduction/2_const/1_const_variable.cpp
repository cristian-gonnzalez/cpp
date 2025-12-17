/** Const-correctness: const variables
 */
#include <iostream>


int main()
{    
    // 'x' is a mutable variable. It means it can mutate or cahnge
    int x = 7;
    x = 3;

    const float PI = 3.141526;
//  ^~~~~
// 'const' makes a variable immutable (read-only).

    // PI cannot change (we add safety)
    //PI = -42;
//    ~~~^~~~~
// error: assignment of read-only variable 'PI'

//   We can have some expresion or sentence to be evaluated 
// and try to resolve at compile-time
//  ^~~~~~~~~
    constexpr int epxression = 3 + 6 + 8;
    //                        ~~~~~~~~~~
    //                 The compiler can deduce that this sum is 17.
    //               'constexpr' will force the compiler to try to 
    //               resolve and paste the result as if you had wrote:
    //
    // constexpr int epxression = 17;
                                          
    return 0;    
}