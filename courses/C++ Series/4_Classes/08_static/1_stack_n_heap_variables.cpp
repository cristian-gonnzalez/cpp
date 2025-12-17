/** stack vs heap memory
 */
#include <iostream>

int main()
{
    int x = 0; // x is a local variable, this means that x scope is withing these curly
               // braces {}             
               // It also means that it is stored in the stack section of memory and 
               // when x goes out of the scope, it is automatically reclaimed and the
               // four bytes (int) is available again

    
    int* p = new int; // p is a local variable (stack allocated)          ┌───────────┐     
                      // p, points to memory allocated on the heap        │   Stack   │  local variables
                      // The memory on the heap lives until we say so.    │  | * -│---│--┐   
                      //                                                  │  └────┘   │  |
                      //                                                  │    p      │  |
                      //                                                  └───────────┘  |
                      //                                    (stack grows down)  ↓        |  
                      //                                     (heap grows up)    ↑        |
                      //                                                  ┌───────────┐  |
                      //                                                  │   Heap    │  |  
                      //                                                  │  |    │<--│--┘ 
                      //                                                  │  └────┘   │   (new/malloc)
    delete p;    // we say explicity release this memory                  └───────────┘  dynamic memory 
    p = nullptr; // p continue living but point to null
    
    return 0;
}