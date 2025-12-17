/** Pointer: Dereferencing a pointer
 */
#include <iostream>

/*
    How to visualize a pointer?

    Even if you are an experienced programmer, it is often helpful to draw pointers 
  to actually 'see' what is happening rather than trying to mentally track raw 
  memory addresses. We draw boxes to represent memory locations.

    Draw line by line to instantiate these variables:

    int x = 7;

            int
     x |      7       |       This box represents an int, and this one is 'x'.
       └──────────────┘     'x' lives at some memory address
        0x7ffe5999099c      and it stores the value 7.
     
    int* px = &x;            The next line creates a pointer 'px'.
                             'px' has its own memory location and stores
                             the *address* of x.
            int*
     px|0x7ffe5999099c|
       └──────────────┘
        0x7ffc7b88d000
                       

     Since It is pointing to 'x', rather than storing the address, we can think as
   just having an arrow to x (or inside x)

            int 
     x |      7     <───┐
       └──────────────┘ │
        0x7ffe5999099c  │     Dereferencing means: follow this arrow and
                        │   access the box it points to.
            int*        │ 
     px |      •────────┘     *px = *(0x7ffe5999099c)  →  7
       └──────────────┘       ^
        0x7ffc7b88d000       we can read or write the value in the box.
*/

int main()
{
    int x = 7;
    int* px = &x;

    std::cout << "x stores      : " << x << std::endl    // x stores      : 9
              << "dereference px: " << *px << std::endl; // dereference px: 9
                                //     ^
                                //   We dereference by putting an asterik '*' in front of
                                // the pointer
                                //
                                // Derefering: Access the address we point to  
                               
    // Update the value of x
    x = 9;
    std::cout << "x stores      : " << x << std::endl    // x stores      : 9
              << "dereference px: " << *px << std::endl; // dereference px: 9
    
    *px = 42;
    std::cout << "x stores      : " << x << std::endl    // x stores      : 42
              << "dereference px: " << *px << std::endl; // dereference px: 42

    return 0;
}