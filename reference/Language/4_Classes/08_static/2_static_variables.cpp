/** static variables
 */
#include <iostream>

/*
  Since C++11, the initialization of local static variables is thread-safe (Access after 
initialization is NOT thread-safe by default ).

  objdump - display information from object files

  -t
  --syms
      Print the symbol table entries of the file.

  $ objdump -t ./prog

  00000000 l    O  .bss   00000000            _ZZ3foovE10s_variable
                   ^~~~                           ^~~    ^~~~~~~~~~
                                                        symbol in the binary
*/

void foo()
{
    //  We can have others qualifiers                    ┌──────────────────────────────────────────┐                                                        
    static /* const */ int s_variable = 0;          //   │                  Stack                   │ 
//  ^~~~~~                                               └──────────────────────────────────────────┘
//    If a variable is declared as static, it gets       ┌──────────────────────────────────────────┐
// allocated for the lifetime of the for program         │                  Heap                    │  
// (It is said it have static storage duration).         └──────────────────────────────────────────┘
//                                                       ┌──────────────────────────────────────────┐
//    Static variable are initialized exactly once       │              Global / Data               │ 
//                                                       │   Global variables, static variables     │
//                                                       │   .data, .bss       ^~~~~~~~~~~~~~~~     │                                    
//                                                       └──────────────────────────────────────────┘                           
//                                                       ┌──────────────────────────────────────────┐
//                                                       │                Text / Code               │
//                                                       │      Compiled machine instructions       │
//                                                       └──────────────────────────────────────────┘
    s_variable += 1;
//  ^~~~~~~~~~
//  It can only be used in the scope where it is defined
//
//  Even if the function is called multiple times,
//  the value is preserved between calls
//
//  NOTE: This increment is NOT thread-safe

    std::cout << s_variable;
}


int main()
{
    for(size_t i=0; i<10; i++)
    {
        foo();
        std::cout << ", ";
    }  // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 

    //s_variable
//    ^~~~~~~~~~
//  error: 's_variable' was not declared in this scope

    return 0;
}