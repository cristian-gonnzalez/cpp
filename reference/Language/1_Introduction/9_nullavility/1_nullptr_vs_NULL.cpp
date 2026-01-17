/** NULL vs nullptr
 */

#include <iostream>

/*

NULL:
   Historically defined as:
   
        #define NULL 0
  
  It's just an integer literal 0 used as a null pointer constant. It can be error-prone 
in modern C++ because it is not type-safe.

nullptr:
  It is a prvalue of type std::nullptr_t.
  
  As it is a type, it provides type-safety: can only be converted to pointer types, not integers.
  
  It is compatible with legacy NULL/0 usage.

*/

 
int main()
{
    {
        int* p;
    //  ^~~~
    // Pointer only stores address 

        // NULL is just 0 → integer literal, historically used as null pointer.
        p = 0;
        p = NULL;

        // Assigning 1 or any non-zero integer to a pointer is invalid.
        // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //    p = 1;  
        //    ^
        //    |
        //   int

        // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //    p = 1123;

        // Invalid assignments from integer variables
        int zero = 0;
        int null_value = NULL;

        // Remeber: pointer holds addresses, not values
        // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    //    p = zero;
    //    p = null_value;

        if( !p && 
            p == 0 && 
            p == NULL)
            std::cout << "p is NULL\n"; // p is NULL

        int x = 23;
        std::cout << "address_of x: " << &x << std::endl; // address_of x: 0x7ffc0571f134
        p = &x;

        if( p )
            std::cout << "p stores: " << p << std::endl;  // p stores: 0x7ffc0571f134
    }
    
    {
        int* p;
        // nullptr ensures only pointer-compatible assignments.
        p = nullptr;

        // nullptr works with old comparisons (p == 0 or p == NULL) but is safer.
        if( !p && 
            p == 0 && 
            p == NULL)
            std::cout << "p is NULL\n"; // p is NULL
    }

    return 0;
}