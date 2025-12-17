/** Dynamic Memory allocation with new and delete (and delete[])
 */
#include <iostream>

/*
    In C++, variables created inside a scope (local variables) have
  automatic storage duration. They live on the *stack* and are destroyed
  automatically when they go out of scope.

        {
            int x = 7;   // x is a local variable that lives only inside this block
        } 
        // x is destroyed here, and its memory is reclaimed automatically.

    Stack variables are fast and convenient, but we do not directly control
their lifetime. We defined at 'compile-time'


- Heap memory: new/delete

    'new' expression:
      Creates and initializes objects with 'dynamic storage duration' (heap memory), 
    that is, objects whose lifetime is not necessarily limited by the scope in which 
    they were created.

                High memory addresses
        ┌──────────────────────────────────────────┐
        │                  Stack                   │  <-- grows downward
        │         Local variables, call frames     │
        └──────────────────────────────────────────┘
                            ↓ (stack grows down)
                            ↑ (heap grows up)
        ┌──────────────────────────────────────────┐
        │                   Heap                   │  <-- dynamic memory (new/malloc)
        │       Long-lived objects we control      │
        └──────────────────────────────────────────┘
        ┌──────────────────────────────────────────┐
        │              Global / Data               │
        │       globals, statics, .data, .bss      │
        └──────────────────────────────────────────┘
        ┌──────────────────────────────────────────┐
        │               Text / Code                │
        │      Compiled machine instructions       │
        └──────────────────────────────────────────┘
                Low memory addresses

 Example:

     int* x = new int;
     ~~~^     ^~~
     |       Allocates space on the heap for one int
     |
     This pointer variable itself lives on the stack since it is a local variable.

    delete x;
    ^~~~~~
    Frees the memory *pointed to by x*. 
    It does NOT delete the pointer variable itself.

    After delete, x becomes a dangling pointer.

    Important:

        new        → delete
        new[]      → delete[]

        Failing to delete memory allocated with new/new[] causes memory leaks.

    Note:
      Use 'new' and 'delete' together otherwse it will never reclaim the memory we have allocated 
    unless I had explicity called 'delete' and that is when the actual memory is free. This is the 
    way we control the lifetime of objects
*/

int main()
{
    // x points to a memory location in the heap
    int* x =  new int;

    *x = 9;
 
    std::cout << "x          : " << *x << std::endl;    // x          : 9
    std::cout << "x points to: " << x << std::endl;     // x points to: 0x1ae252b0

    delete x;
    //After calling delete, set pointer to nullptr to avoid dangling pointers
    x = nullptr; 

    return 0;
}