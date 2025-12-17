/** Pointer pitfalls: Memory leaks
 */

#include <iostream>

// Imagine that this is a function that is called frequently and it does not cause a crash
// but we are taking memory over and over again. Eventually, the memory will run out and 
// that's usually when there is a crash.

// Usefull tool to find this is:
//
//      - 'valgrind'. It weill give you a MEMORY LEAK SUMMARY
//      - Sanitazer flag in the compiler
//        

/*
$ g++ - g -fsanitize=address -std=c++17 main.cpp -o prog 
$ ./prog

ERROR: LeakSanitizer: detected memory leaks
Direct leak of 4000 byte(s) in 1 object(s) allocated from:
    #0 0x7b64e4016e2f in operator new[](unsigned long) (/opt/compiler-explorer/gcc-snapshot/lib64/libasan.so.8+0x126e2f) (BuildId: 888007dcc0f81e05dce0447ea35ff67a5ab4779f)
    #1 0x00000040115f in main /app/example.cpp:25
    #2 0x7b64e3829d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: d5197096f709801829b118af1b7cf6631efa2dcd)
*/

int main()
{
    // We forget to de-alllocate memory
    //
    // It is hard to detect beacuse it might not cause an inmediate crash
    // 
    {
        int* array = new int[1000];
    
    } // array ptr goes out the scope and the memory was not freed 

    return 0;
}