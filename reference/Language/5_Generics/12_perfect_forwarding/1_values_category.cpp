/** Generics - Perfect Forwarding / Universal References
 *
 *      
 */

#include <iostream>


int main()
{
    // Values categories: refresh

    //     50 is an rvalue
    //      ~~
    int x = 50;
    //  ^
    //  |
    // x is a lvalue

    int& ref = x;
    //   ~~~  ref is an lvalue reference

    // lvalues (x and ref) are examples -- because they have a location in memory
    std::cout << "address of x  : " << &x << std::endl             // 0x7ffee33ad8a4
            << "address of ref: " << &ref << std::endl;          // 0x7ffee33ad8a4

    // we cannot take the address of an rvalue
    // std::cout << "address of 50 : " << &50 << std::endl; 
    //                                  ^~            
    // <source>:25:41: error: lvalue required as unary '&' operand


    // If we look at, for ex: push_back method of C++ Containers library std::vector, 
    // we will see 2 different version: 
    //        
    //       void push_back( const T& value );   (1)
    //
    //       void push_back( T&& value );    (2)
    //                       ~~~
    //                     The rvalue reference	
    //    
    
    return 0;
}
