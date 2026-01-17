/** Function inlining
 *  
 */
#include <iostream>

// The intent of the 'inline' specifier is to hint for the compiler to perform optimization

__attribute__((always_inline)) inline 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~  ^^^^^^
//           ^                  The compiler can choose to ignore the inline
//           | 
// Forcing to inline this function, so that the compiler will not ignore
// the keywork
int add(int a, int b)
{
    return a+b;
}


int main()
{

    int value = add(4, 5);
    // If we look the assembly, we can see that there is a call from the function
    // add 
    /*
    add(int, int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     DWORD PTR [rbp-8], esi
        mov     edx, DWORD PTR [rbp-4]
        mov     eax, DWORD PTR [rbp-8]
        add     eax, edx
        pop     rbp
        ret
    main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     esi, 5
        mov     edi, 4
        call    add(int, int)
        mov     DWORD PTR [rbp-4], eax
        mov     eax, 0
        leave
        ret
    

        */
    // As we can see, everytime 'add' is called, there is a lot intructions
    // that are executed, overhead jumping where the add function is and 
    // copyng the return address and arguments. The inline specifier will 
    // just copy and paste the instructions that cares of 'add' funtion 
    // into the main that is where it was called, reducing the number of steps
 
    // Localily
    //  -   We can guess the next intruction easyly (Hardware)
    //  -   Other optimizations enabled
    //
    // Const
    //      - Debugginh more difficult
    //      - code size could increase

    // If te inline is applied, we see that there is no add call 
    /*
    main:
        pushq   %rbp
        movq    %rsp, %rbp
        movl    $4, -8(%rbp)
        movl    $5, -12(%rbp)
        movl    -8(%rbp), %edx
        movl    -12(%rbp), %eax
        addl    %edx, %eax
        movl    %eax, -4(%rbp)
        movl    $0, %eax
        popq    %rbp
        ret
    */   

    return 0;
}