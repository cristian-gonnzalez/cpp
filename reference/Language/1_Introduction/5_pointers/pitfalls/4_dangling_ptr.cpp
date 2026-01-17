/** Pointer pitfalls: Dangling pointer
 */

#include <iostream>

/*
$ g++ -g -fsanitize=address -std=c++17 main.cpp -o prog 
$ ./prog
    
AddressSanitizer:DEADLYSIGNAL
=================================================================
==1==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x000000401306 bp 0x7ffe59a68ac0 sp 0x7ffe59a68ab0 T0)
==1==The signal is caused by a READ memory access.
==1==Hint: address points to the zero page.
    #0 0x000000401306 in main /app/example.cpp:19
    #1 0x78adfa029d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)
    #2 0x78adfa029e3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f) (BuildId: 4f7b0c955c3d81d7cac1501a2498b69d1d82bfe7)
    #3 0x000000401104 in _start (/app/output.s+0x401104) (BuildId: 2f46e0a349e040796a56bf6ab75eca18510a9e98)

==1==Register values:
rax = 0x0000000000000000  rbx = 0x0000000000000000  rcx = 0x00000000004040c0  rdx = 0x0000000000000000  
rdi = 0x0000000000404000  rsi = 0x0000000000000003  rbp = 0x00007ffe59a68ac0  rsp = 0x00007ffe59a68ab0  
 r8 = 0x0000000080078400   r9 = 0x0000000000000000  r10 = 0x0000000000000005  r11 = 0x0000000000000004  
r12 = 0x00007ffe59a68bd8  r13 = 0x00000000004012a7  r14 = 0x0000000000403d78  r15 = 0x000078adfad06040  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV /app/example.cpp:19 in main
==1==ABORTING 
*/

int* return_memory()
{
    int result{42};

    return &result;
    //     ^~~~~~~
    // Address of local variable 'result' returned
} // result is reclaimed when goes out of the scope


int main()
{
    int* px = return_memory(); 
    std::cout << "*px: " << *px << std::endl; 

    return 0;
}