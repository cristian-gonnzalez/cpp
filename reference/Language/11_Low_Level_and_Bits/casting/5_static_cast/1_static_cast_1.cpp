/** C++ Casting: static_cast vs C-style cast
 */
#include <iostream>


int main()
{
    //
    // C-style casts are a too liberal.
    //
    {
        // This is what reinterpret_cast is doing
        int* p = 0xFFFF1234;
        //       ^~~~~~~~~~
        //              |
        //              unsigned int
        // error: invalid conversion from 'unsigned int' to 'int*' [-fpermissive]
        //                                                          ^~~~~~~~~~~~~
        //                   run this with this flag: g++ -std=c++20 -fpermissive
        //                (to avoid only for this example)

        // Cast to type big enough for pointer
        std::cout << (long)p << std::endl;   // 4294906420
    }
    //
    //  static_cast
    //
    {
        float f{3.14f};
        
        //  The compiler can make implicit conversion and get the same result.
        // So why we need static_cast?
        //
        int a = f;
        //    ~
        // Implicit conversion:
        //    - Performs narrowing
        //    - Can silently discard information
        
        // Here is a safer example of a cast using static_cast, of a type we absolutely
        // know that what we can cast.        
        int b = static_cast<int>(f);
        //      ^~~~~~~~~~~
        // Explicit conversion with static_cast:
        //    - Show intent
        //    - Makes narrowing explicit
        //    - Easier to search and review
       
        std::cout << a << std::endl;   // 3
        std::cout << b << std::endl;   // 3
                              //          ^ 
                              // fractional part is discarded     
    } 

     return 0;
}