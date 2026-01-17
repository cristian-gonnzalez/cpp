/** Pointer pitfalls: Double free
 */

#include <iostream>

// Note:
//      g++ compiler detects double free by default.
//
/*
$ g++ -std=c++17 main.cpp -o prog 
$ ./prog
free(): double free detected in tcache 2
Program terminated with signal: SIGSEGV
*/


/*
$ g++ -g -fsanitize=address -std=c++17 main.cpp -o prog 
$ ./prog

=================================================================
==1==ERROR: AddressSanitizer: attempting double-free on 0x791b807e0010 in thread T0:
    #0 0x7cfb81b9769b in operator delete(void*, unsigned long) (/opt/compiler-explorer/gcc-15.2.0/lib64/libasan.so.8+0x12369b) (BuildId: 620b620e803590cdaf76f7a713f6c544a53408b6)
    #1 0x0000004011e8 in main /app/example.cpp:14
    #2 0x7cfb81429d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)
    #3 0x7cfb81429e3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)
    #4 0x0000004010a4 in _start (/app/output.s+0x4010a4) (BuildId: a31ee76ca7d80e0726e96b501fb930e50b2d122d)

0x791b807e0010 is located 0 bytes inside of 4-byte region [0x791b807e0010,0x791b807e0014)
freed by thread T0 here:
    #0 0x7cfb81b9769b in operator delete(void*, unsigned long) (/opt/compiler-explorer/gcc-15.2.0/lib64/libasan.so.8+0x12369b) (BuildId: 620b620e803590cdaf76f7a713f6c544a53408b6)
    #1 0x0000004011d2 in main /app/example.cpp:13
    #2 0x7cfb81429d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)

previously allocated by thread T0 here:
    #0 0x7cfb81b9673b in operator new(unsigned long) (/opt/compiler-explorer/gcc-15.2.0/lib64/libasan.so.8+0x12273b) (BuildId: 620b620e803590cdaf76f7a713f6c544a53408b6)
    #1 0x000000401177 in main /app/example.cpp:10
    #2 0x7cfb81429d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)

SUMMARY: AddressSanitizer: double-free /app/example.cpp:14 in main
==1==ABORTING
*/

int main()
{
    // Double free  
    int* x = new int;
    *x = 42;

    delete x;
    delete x;

    /* =1==ERROR: AddressSanitizer: attempting double-free on 0x7acaaffe0010 in thread T0: */

    return 0;
}