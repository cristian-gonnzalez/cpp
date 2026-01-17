/** References in C++ (Another use of the & symbol) 
 */
#include <iostream>

/*
References: Another use of the & symbol

    A reference is an alias — another name for an existing object or function.

    The & operator has two meanings:

        - &x      → Gets the address of a variable.
        - int& x  → Declares x as a reference ('int&' is a reference type).

    A reference does not create a new object — it is just another name for the same object.
*/

int main()
{
    int x = 42;

    std::cout << "x           : " << x << std::endl   // x           : 42
              << "address_of x: " << &x << std::endl; // address_of x: 0x7ffc7decb98c

        // References must be initialized to an existing object.
        //   ^ ~
    int& ref = x;
//     ^ 
// & after a type means that it is a reference-type.
// 'int&' is the full type, for a reference-type 

    std::cout << "ref           : " << ref << std::endl   // ref           : 42
              << "address_of ref: " << &ref << std::endl; // address_of ref: 0x7ffc7decb98c
                                                            //                 ^~~~~~~~~~~~~~
                                                            // The address is actually the same of 'x'  
    // The idea is we have another variable name 'ref' that can refer to 'x'

    // error: 'ref2' declared as reference but not initialized
    // int& ref2;
    //      ^~~~   

    // Modifies 'x'
    {
        x++;
        std::cout << "x           : " << x << std::endl       // x           : 43
                  << "address_of x: " << &x << std::endl;     // address_of x: 0x7ffc7decb98c
        std::cout << "ref           : " << ref << std::endl   // ref           : 43
                  << "address_of ref: " << &ref << std::endl; // address_of ref: 0x7ffc7decb98c   
    }   

    // Modifies 'ref'
    {
        ref = 99;
        std::cout << "x           : " << x << std::endl       // x           : 99
                  << "address_of x: " << &x << std::endl;     // address_of x: 0x7ffc7decb98c
        std::cout << "ref           : " << ref << std::endl   // ref           : 99
                  << "address_of ref: " << &ref << std::endl; // address_of ref: 0x7ffc7decb98c
    }   
}