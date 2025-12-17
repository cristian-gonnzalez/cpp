/** Pointer pitfalls
 *
 */

#include <iostream>


// nullptr dereference
//      -> use -g to add debugin symbols
//
// > layout src

// memory leaks:
//      -> Use -fsanitize=address to search memory leaks

/*
int* return_memory()
{
    int result{42};

    return &result;
}
*/
int main()
{
    {
        // this pointers holds no address
        int* p = nullptr;

        // It is safe to call delete or delete[] on a nullptr. It does nothing.
        // the C++ standard explicitly guarantees this.

        delete p;      // safe
        delete p;      // safe
        delete[] p;    // safe
    }

    {
        // this pointers holds no address
        int* p = 0; // or using 'NULL'   C-style

        // The C++ standard explicitly does NOT guarantees this is safe althouh most of the compiler treats as 'do nothing'. 

        delete p;      // safe
        delete p;      // safe
        delete[] p;    // safe
    }

    {
        // We try to 'dereference a nullptr' we dont have access to. There is no block of memory where to store the value
        //*px = 24; // SIGSEGV

        // memory leaks
        //int* array = new int[1000];
        /*
        ERROR: LeakSanitizer: detected memory leaks
        Direct leak of 4000 byte(s) in 1 object(s) allocated from:
            #0 0x7b64e4016e2f in operator new[](unsigned long) (/opt/compiler-explorer/gcc-snapshot/lib64/libasan.so.8+0x126e2f) (BuildId: 888007dcc0f81e05dce0447ea35ff67a5ab4779f)
            #1 0x00000040115f in main /app/example.cpp:25
            #2 0x7b64e3829d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: d5197096f709801829b118af1b7cf6631efa2dcd)
        */
    }

    // Dangling pointer
    {
        //int* px = return_memory(); 

        /*
        <source>: In function 'int* return_memory()':
        <source>:21:12: warning: address of local variable 'result' returned [-Wreturn-local-addr]
        21 |     return &result;
            |            ^~~~~~~
        <source>:19:9: note: declared here
        19 |     int result{42};
            |         ^~~~~~
        */
    }

    // Double free  
    {   
        int* x = new int;
        *x = 42;

        delete x;
        delete x;

        /* =1==ERROR: AddressSanitizer: attempting double-free on 0x7acaaffe0010 in thread T0: */
    }   

    return 0;
}