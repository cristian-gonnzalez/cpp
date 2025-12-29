/** NULL vs nullptr
 */

#include <cstddef>
#include <iostream>
 
/*
  nullptr is safer than NULL, especially in templates or type-deduction contexts.


    nullptr is type-safe and works consistently in templates.
    NULL is unsafe in generic code because it is just an integer literal.

 */

// Generic clone function: returns a copy of its argument
template<class T>
constexpr T clone(const T& t)
{
    return t;
}
 
void g(int*)
{
    std::cout << "Function g called\n";
}
 
int main()
{
    // Works fine: nullptr is always a null pointer constant
    g(nullptr);        // Fine
    g(NULL);           // Fine
    g(0);              // Fine
 
    g(clone(nullptr)); // clone(nullptr) returns std::nullptr_t

    // error: invalid conversion from 'long int' to 'int*' [-fpermissive]
//    g(clone(NULL));    // ERROR: non-literal zero cannot be a null pointer constant
//      ~~~~~^~~~~~
//      long int
    
    // Note:
    //   NULL(0) loses its null-pointer property when copied in a template since
    // clone(NULL) returns a variable of type long, not a null pointer
    // So the following line will fail:
    //
 
    // Again: clone(0) returns a variable of type long, not a null pointer
    // 
    // error: invalid conversion from 'long int' to 'int*' [-fpermissive]
//  g(clone(0));       // ERROR: non-literal zero cannot be a null pointer constant

}