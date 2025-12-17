/** Write secure code with assertion (assert and static_assert)
 *  
 */
#include <iostream>
#include <cassert>   // assert C-style

constexpr int add(int a, int b)
{
    return a+b;
}

int main()
{
    {
        int age = -7;

        // Assert C-style:
        //         Errors that can be caught at run-time
        //
    //    assert( age >= 0 && "age was less than 0" ); // int main(): Assertion `age >= 0 && "age was less than 0"' failed.
        //               ^^  ~~~~~~~~~~~~~~~~~~~
        //                 we can add a custom message
        //                        (trick)    
    }    
    
    // Modern C++
    //
    //  static_assert (C++11)
    //      Performs compile-time assertion checking.
    //
    // static_assert( bool-constexpr , unevaluated-string )     
    // static_assert( bool-constexpr )                         (C++17)
    //

    {   
        // In this example, static_assert failed since we need a const value as parameter. }The actual syntax code is wrong
        
        int age = -7;

        // We get an error. This has to be a constant value
    //    static_assert( age > 0, "age was less than 0" ); 
        //              ~~~~^~~
        // error: non-constant condition for static assertion
        // error: the value of 'age' is not usable in a constant expression
        // note: 'int age' is not const
        //         int age = -7;
    }

    {
        // Using constexpr since we need a constant value to pass to static_assert
        constexpr int age = -7;
        //~~~~~~~~~
        // static_assert is being evaluated at compule-time

    //    static_assert( age>0, "age was less than 0" ); 
        //               ~~~^~
        // error: static assertion failed: age was less than 0
        // note: the comparison reduces to '(-7 > 0)'
        
    }

    //
    // Real-world example
    //

    // Checking system architecture
    {
        static_assert( sizeof(int) == 4, "int is 4 bytes" );
    }

    // Unit test
    {
        static_assert( add(4, 4) == 8, "add(4, 4) == 8" );
    }

    return 0;
}