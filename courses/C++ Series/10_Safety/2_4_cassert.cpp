/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
#include <cassert>
/*
Safety in C++ Programming: Lenguage Level Features -- run-time

    Use assert if there is some behaviour (bugs) at run-time that shouldnt be allowed in 
our develpment version: you want to be able to catch that and terminates the program since 
the behaviour is illegal and terminating is sort of the rigth thing to do.

    Of course, when you release your software, the assert will get compiled out

    NOTE: Execption may be potentially recoverable since you can log before exit at
run-time.

    Also uses assert in your unit tests.

        * For debug builds with assertions    : g++ -DDEBUG  main.cpp -S
        * For relese builds without assertions: g++ -DNDEBUG main.cpp -S

- Assert (run-time check)
    
    - Technically this is a library feature in <cassert>
        * assert is a macro that is defined when in 'debuf mode' (NDEBUG)
        * Thus this does not cost 'end-user' any time, but helps us as developer 
        enforce behaviour

    - If an assert fails, it fails because the program is exhibiting illegal 
    behaviou during development that should be corrected, and the proper 
    behavior during development tome os to crash
*/

// Compile with assertions and see the assembly
// g++ main.cpp -o prog 
//
// Compile-out the asserts and see the assembly
// g++ -DNDEBUG main.cpp -S assert.s 


constexpr int add(int a, int b)
{
    return a+b;
}

int main()
{
    // Works with constexpr, checked at run-time 
    assert( add(2, 2) == 4 && "2 + 2 = 4" );
    // Works with types, checked at run-time
    assert( sizeof(int) == 4 && "int is 4 bytes on this architecture" );
    // Checked at run-time
    assert( sizeof(int32_t) == 4 && "int32_t is always 4 bytes" );
    
   return 0;
}