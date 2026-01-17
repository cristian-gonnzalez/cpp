/** Recursive Functions: Stack overflow
 */
#include <iostream>

/*
Stack Memory:

   The stack is where our 'temporary' (e.g. local variables) memory is stored. 

   The stack also stores information like where a function was called from (so we know where to
return) and other things like function arguments.

- Stack overflow:

    Call stack:
        Every time we call a function, a new stack frame is created.
        It stores information such as:
            - the return address (where to continue after the function returns)
            - function parameters (e.g., the current value of n)
            - local variables

    With deep recursion, the stack can grow until it collides with another
    memory region (such as the heap), resulting in a crash.

        High memory addresses
        ┌──────────────────────────────────────────┐
        │                  Stack                   │  <-- grows downward
        │ ┌──────────────────────────────────────┐ │
        │ │ countdown(500000) frame              │ │
        │ ├──────────────────────────────────────┤ │
        │ │ countdown(499999) frame              │ │
        │ ├──────────────────────────────────────┤ │
        │ │ countdown(499998) frame              │ │
        │ │                  ...                 │ │
        │ │                  ...                 │ │
        │ ├──────────────────────────────────────┤ │
        │ │ countdown(998) frame                 │ │
        │ ├──────────────────────────────────────┤ │
        │ │ countdown(998) frame (base case)     │ │
        │ └──────────────────────────────────────┘ │
        └──────────────────────────────────────────┘
                            ↓ (stack grows down)      <---- We crash with another section of memory
                            ↑ (heap grows up)
        ┌──────────────────────────────────────────┐
        │                  Heap                    │  <-- dynamic memory (new/malloc)
        │            expands upward                │
        └──────────────────────────────────────────┘
        ┌──────────────────────────────────────────┐
        │              Global / Data               │
        │   Global variables, static variables     │
        │   .data, .bss                            │
        └──────────────────────────────────────────┘
        ┌──────────────────────────────────────────┐
        │                Text / Code               │
        │      Compiled machine instructions       │
        └──────────────────────────────────────────┘
        Low memory addresses

    The stack has a fixed size, so it is not unlimited space for function calls.
    Deep recursion risks stack overflow.

- What exactly is inside a stack frame?

    Every recursive call creates a new frame, which typically holds:

            Stack frame for countdown(n):
        ┌────────────────────────────────────────┐
        │ return address                         │  <-- where to continue when function ends
        ├────────────────────────────────────────┤
        │ saved base/frame pointer (RBP/EBP)     │
        ├────────────────────────────────────────┤
        │ function parameter n                   │  <-- countdown receives n
        ├────────────────────────────────────────┤
        │ local variables (if any)               │
        └────────────────────────────────────────┘
*/

long countdown(long n)
{
    //std::cout << n << std::endl;

    // 1.Base case
    if( n == 0 )
        return 0;

    // Recursive case
    return countdown( n-1 );
}

int main()
{ 
    countdown(500000);
    /*
Program returned: 139
Program stderr
Program terminated with signal: SIGSEGV
    */
    return 0;    
}
