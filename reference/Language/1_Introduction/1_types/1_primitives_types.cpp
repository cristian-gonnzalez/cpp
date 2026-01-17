/** C++ Primitive Data Types 
 */
#include <iostream>
#include <climits> // INT_MAX

/*
    C++ is a statically typed language. This means you must specify the type of a
  variable when declaring it.

        int x;
        ^^^ Type

    This gives the compiler enough information to allocate memory and enforce type safety 
  at compile-time.
*/

int main()
{    
    // I can represent this amount of intergers with int
    std::cout << INT_MIN << " <= int <= " << INT_MAX << std::endl; // -2,147,483,648 <= int <= 2,147,483,647
    
    {
        // signed x            |  Equivalent type specifier
        // signed int x        |

        // integer overflow in expression of type 'int' results in '-2147483648'
        //      ~~~~~~~~~~~^~~  -> I need a larger data type
        int x = 2147483647 + 1; 
    //  ~~~~
    // statically type -> this means that we have 
    // to specify the type when defining variable
    // 
    
        std::cout << "x: " << x << std::endl;                                // x: -2147483648
                                        //  Name/Type  
                                        //    ~~~
        std::cout << "sizeof int    : " << sizeof(int) << " bytes\n";         // sizeof int    : 4 bytes
                                //     ^~~~~~ 
                                // Tell me how many bytes this data type is
    }
    
    {
        // long int            |
        // signed long         | Equivalent type specifier
        // signed long int     |        
        long x = 2147483647;
        std::cout << "x: " << x << std::endl;                                // x: 2147483647
        std::cout << "sizeof long   : " << sizeof(long) << " bytes\n";       // sizeof long   : 8 bytes  
    }    
    
    {
        // We can specify the width we want to work with
        int64_t x = 2147483647;
    //     ~~
    //    64 bits = 8 bytes
        std::cout << "x: " << x << std::endl;                                // x: 2147483647
        std::cout << "sizeof int64_t: " << sizeof(int64_t) << " bytes\n";    // sizeof int64_t: 8 bytes
    }

    {
        bool x = true;
        std::cout << "x: " << x << std::endl;                                // x: 1
        std::cout << "sizeof bool   : " << sizeof(bool) << " bytes\n";       // sizeof bool   : 1 bytes
    }
    {
        float x = 3.14;
        // float x = 3.14f;
        //               ^
        //       Use the 'f' suffix to make the value a float 
        //     instead of a double.

 
        std::cout << "x: " << x << std::endl;                                 // x: 3.14
        std::cout << "sizeof float  : " << sizeof(float) << " bytes\n";       // sizeof float  : 4 bytes
    }
    {
        double x = 3.14125123454;
        std::cout << "x: " << x << std::endl;                                 // x: 3.14125
        std::cout << "sizeof double : " << sizeof(double) << " bytes\n";      // sizeof double : 8 bytes
    }
    {
        char x = 'a';
        std::cout << "x: " << x << std::endl;                                 // x: a
        std::cout << "sizeof char   : " << sizeof(char) << " bytes\n";        // sizeof char   : 1 bytes
    }
    {
        // A const char* is a pointer to a C-style string.
        // The pointer itself is 8 bytes on a 64-bit system, regardless of string length.
        const char* x = "abc";
        std::cout << "x: " << x << std::endl;                                 // x: abc
        std::cout << "sizeof const char*: " << sizeof(x) << " bytes\n";       // sizeof const char*: 8 bytes
    }     
   
    return 0;    
}