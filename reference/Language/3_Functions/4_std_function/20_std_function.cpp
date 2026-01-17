/** std::function
 */

#include <iostream>
#include <functional>

/*
    We have a way to create function pointer with std::function (modern C++)

std::function:

    It is a general-purpose polymorphic function wrapper. 
    
        Defined in header <functional>
        template< class R, class... Args >
        class function<R(Args...)>;

    It is a way to wrap sth that is callable -- functions pointer, lambda expressions, bind expressions, 
or other function objects, as well as pointers to member functions and pointers to data members.

*/

int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int main()
{       
    //           function signature
    //             ~~~~~~~~~~~~~
    std::function< int (int,int) > op;
    //             ^~~ ^~~~~~~~~     
    //              |   Arguments                  
    //         return type 

    op = add;   
    std::cout << "2 + 2 = " << op(2,2) << std::endl;       // 2 + 2 = 4

    op = multiply;
    std::cout << "7 * 5 = " << op(7,5) << std::endl;       // 7 * 5 = 35

    return 0; 
}
 