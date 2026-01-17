/** constexpr
 */
#include <iostream>

// NOTE: A function declared 'constexpr' is implicity an 'inline' funcntion

// The constexptr specifier delcares that it is possible to evaluete the value of the function or variable at complie-time.
//     ~~~~~                                                                                                  ~~~~~~~~~~~~
//   the const gives an idea that it sth that is not mutable (read-only).                                    saves us at run-time 
//  constexpr implicity implies 'const'                                                                        performance
//
constexpr int add(int a, int b)
//~~~~~~~~
// Making this constexpr, the binary may reduce since it is evaluated at compile-time
//
// NOTE: making a function constexpr, it doesnt mean that this will be evaluated. It is a suggestion to the compiler to try to
// evaluate this 'add' function
{
    return a+b;
}

int main()
{
    {
        constexpr int i = 7+9+16;
        //                ~~~~~~
        //   The compiler can figure out that this value is 32. There is no need to store 3 values and then the add at run-time
        // Thats the idea of constexpr, we are evaluating this code as we are parsing it and to store directly in 'i' at 
        // compile-time.
        //
    }
    {
        int result = add(7,16);
             // ~~~~~~~~~
             // This is resolved at compile-time and 23 is stored directly into 'result'.
             // we can see the assembly that there is no 'add' call
    }
    {
        constexpr int result = add(7,16);
     // result++;
     // ~~~~~~
     // error: increment of read-only variable 'result'
    }

    return 0;
}