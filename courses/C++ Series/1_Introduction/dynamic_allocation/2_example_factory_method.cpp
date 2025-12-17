/** Dynamic Memory: Example with factory method
 */
#include <iostream>

// The goal is that we can allocate memory inside a function and return
// that memory to the caller.
//
// Important: 
//   Returning a raw pointer means the caller is responsible for calling delete. 
//
// Note: 
//   This is error-prone and should be avoided in real modern C++ (use std::unique_ptr 
// instead or RAII tecnique).
//
// NOTE:
//   This is a factory method. Another name could be allocate_integer(). 
// The function has a single responsibility: it allocates an int on the heap 
// and returns a pointer to it. It also hides implementation (hides new call)
int* make_integer()
{
    return new int;
}

int main()
{
    // Note that the scoping rules start to matter because I have allocated memory in a different
    // block scope. So Im responsible to delete it
    int* x =  make_integer();

    *x = 9;
 
    std::cout << "x          : " << *x << std::endl;    // x          : 9
    std::cout << "x points to: " << x << std::endl;     // x points to: 0x1ae252b0

    delete x;
    x = nullptr;  // avoid dangling pointer

    return 0;
}