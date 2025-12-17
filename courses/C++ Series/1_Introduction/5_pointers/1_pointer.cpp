/** Pointer
 */
#include <iostream>

/*
    A pointer is a data type that stores a memory address.

    Note: On a 64-bit system, an address is 8 bytes.

    Pointer is a C-style way of sharing data. It is usefull if we need to be compatible with a C-API.
And it is a way to performe manual memory management on the heap (control the lifetime of objects in 
a program)     
*/

int main()
{
    // The variable x stores an integer (4 bytes) with value 7 in the memory. 
    int x = 7;
    
    // The pointer px stores the address of x
    //        ^
    int* px = &x;
//  ~~~^
//  The symbol * after the type indicates that it is a pointer (In this example, a pointer to int)

    // We say that 'px points to x'.
    std::cout << "x stores      : " << x << std::endl    // x stores      : 7
              << "address_of x  : " << &x << std::endl   // address_of x  : 0x7ffe5999099c
              << "px stores     : " << px << std::endl   // px stores     : 0x7ffe5999099c
                                                         //                 ^~~~~~~~~~~~~~
                                                         //                Address of x
              << "address_of px : " << &px << std::endl  // address_of px : 0x7ffc7b88d000
                                                         //                 ^~~~~~~~~~~~~~
                                                         //   A pointer is also a variable that has his 
                                                         // own address
              << "dereference px: " << *px << std::endl; // dereference px: 7
                                //     ^
                                // Derefering: Access the address we point to  
                               
    /*
 
       Addresses        RAM
                    ┌─────────────┐ 
     0x7ffe5999099a │             │ 
                    ├─────────────┤ 
     0x7ffe5999099b │             │ 
                    ├─────────────┤ 
     0x7ffe5999099c │  0000 0111  │  ────┐
                    ├─────────────┤      |
     0x7ffe5999099d │  0000 0000  │      |
                    ├─────────────┤      |-> x (4 bytes) stores 7      
     0x7ffe5999099e │  0000 0000  │      |
                    ├─────────────┤      |      
     0x7ffe5999099f │  0000 0000  │ ─────┘
                    ├─────────────┤ 
        .....       │             │ 
                    ├─────────────┤ 
     0x7ffc7b88d000 │    9f       │ ────┐
                    ├─────────────┤     | 
     0x7ffc7b88d001 │    09       │     |
                    ├─────────────┤     |
     0x7ffc7b88d002 │    99       │     |
                    ├─────────────┤     | 
     0x7ffc7b88d003 │    59       │     |
                    ├─────────────┤     | -> px (8 bytes) stores  0x00007ffe5999099c
     0x7ffc7b88d004 │    fe       │     |                               ~~~~~~~~~~~~
                    ├─────────────┤     |                               Address of x
     0x7ffc7b88d005 │    7f       │     |
                    ├─────────────┤     |
     0x7ffc7b88d006 │    00       │     |
                    ├─────────────┤     |
     0x7ffc7b88d007 │    00       │ ────┘
                    ├─────────────┤ 
     0x7ffc7b88d008 │             │ 
                    └─────────────┘       
    */

    return 0;
}