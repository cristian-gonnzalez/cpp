/** C++ Safety part 1 of n - Language Level Safety
 *  Compile-time
 */

#include <iostream>
#include <cassert>
/*
Safety in C++ Programming: Lenguage Level Features -- compile-time

- consttexpr, const_init, const_eval:

    - When is the best time to catch bugs? 
        Compile-time

    - C++11 first added constexpr
        - 'constexpr' are things that allows for compile-time evaluations
        - And refuces opportunity for UB 
        
    - C++20 addes a few more handy tools that directly require being 
    evaluable or initializable at compile-time.
        - consteval and constinit.

See https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con5-use-constexpr-for-values-that-can-be-computed-at-compile-time

*/

constexpr int constexpr_add(int a, int b)
{
    return a+b;
}

int runtime_add( int a, int b)
{
    return a+b;
}

int main()
{
    {
        // This can be caught at compile-time
        static_assert( constexpr_add(7, 16) == 24, "caught at compile-time" );
        
        /*
<source>:38:45: error: static assertion failed: caught at compile-time
   38 |         static_assert( constexpr_add(7, 16) == 24, "caught at compile-time" );
      |                        ~~~~~~~~~~~~~~~~~~~~~^~~~~
<source>:38:45: note: the comparison reduces to '(23 == 24)'
        */
    }
    {
        // This cannot be caught at compile-time because that functions is 
        // non-constexpr
        static_assert( runtime_add(7, 16) == 24 && "not caught at compile-time" ); 
        
        /*
<source>:50:49: error: non-constant condition for static assertion
   50 |         static_assert( runtime_add(7, 16) == 24 && "not caught at compile-time" );
      |                        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
<source>:50:35: error: call to non-'constexpr' function 'int runtime_add(int, int)'
   50 |         static_assert( runtime_add(7, 16) == 24 && "not caught at compile-time" );
      |                        ~~~~~~~~~~~^~~~~~~
<source>:29:5: note: 'int runtime_add(int, int)' declared here
   29 | int runtime_add( int a, int b)
      |     ^~~~~~~~~~~
        */       
    }
    {
        // This will be caught at run-time when running the function
        assert( runtime_add(7, 16) == 24 && "caught at run-time only" );
    }
   
   return 0;
}