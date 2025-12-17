/** Address of operator & 
 */
#include <iostream>

/*
Address-of (& operator)
    Returns the memory address of a variable or a function.
*/

// Functions have address too
void foo()
{
}

int main()
{
    int x = 42;
    float y = 72;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c'; 
    
    // NOTE:
    //   In C++, when a char is printed with std::cout, it prints the character
    // itself — not its address. Since &c is a char*, std::cout treats it as a
    // C-string. To print the actual pointer value, you must cast it to void*.

    // NOTE:
    //   A function’s name decays to a function pointer. There is no special
    // operator<< overload for function pointers, so casting to void* is the
    // standard, explicit way to print the address.

    std::cout << "Address_of x: " << &x << std::endl
              << "Address_of y: " << &y << std::endl
              << "Address_of a: " << static_cast<void*>(&a) << std::endl
               //                                       ~~  
               //                                       &c is a char*
              << "Address_of b: " << static_cast<void*>(&b) << std::endl
              << "Address_of c: " << static_cast<void*>(&c) << std::endl
              << "Address_of foo(): " << reinterpret_cast<void*>(&foo) << std::endl
              << "Address_of main(): " << reinterpret_cast<void*>(&main) << std::endl;
               //                                                ^~~~  
               //                                           &foo is a function pointer,
    return 0;    
}
