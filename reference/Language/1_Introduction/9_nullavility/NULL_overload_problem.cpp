#include <cstddef>
#include <iostream>
 
void f(int*)
{
    std::cout << "f(int*)\n";
}
 
void f(double*)
{
    std::cout << "f(double*)\n";
}
 
void f(std::nullptr_t)
{
    std::cout << "f(std::nullptr_t)\n";
}
 
int main()
{
    int* pi;
    double* pd;
 
    f(pi);      // f(int*)
    f(pd);      // f(double*)
    f(nullptr); // f(std::nullptr_t)

    // Using NULL/0 is ambiguous call: all three functions are candidates

    // error: call of overloaded 'f(int)' is ambiguous
//    f(0);    
    // note: there are 3 candidates
    // note: candidate 1: 'void f(int*)'
    // note: candidate 2: 'void f(double*)'
    // note: candidate 3: 'void f(std::nullptr_t)'
    
    // error: call of overloaded 'f(int)' is ambiguous
//    f(NULL); // ambiguous if NULL is an integral null pointer constant 
    // note: there are 3 candidates
    // note: candidate 1: 'void f(int*)'
    // note: candidate 2: 'void f(double*)'
    // note: candidate 3: 'void f(std::nullptr_t)'
}