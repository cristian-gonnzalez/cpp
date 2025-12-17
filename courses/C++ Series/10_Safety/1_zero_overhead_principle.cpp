/** C++ Zero-Overhead Principle 
 *  Modern Cpp Series Ep. 232
 */

#include <print>
#include <vector>
/*
Safety in C++ Programming:

cppreference-> Language -> Idioms

Zero-overhead principle
    The zero-overhead principle is a C++ design principle that states:

        * You don't pay for what you don't use.
            - If you dont use a featyre, you should not pay for it
        * What you do use is just as efficient as what you could reasonably write by hand.
            - And if you use some feature, it is what you would probably write,
            what the default is or maybe what the compiler can give you overall
            meaning that it can generate relatively efficient code

    In general, this means that no feature should be added to C++ that would 
impose any overhead, whether in time or space, greater than a programmer would 
introduce without using the feature.

    The only two features in the language that do not follow the zero-overhead principle 
are runtime type identification and exceptions, and are why most compilers include 
a switch to turn them off.
            ~~~~~~~~~~~~~
    g++ -std=c++23 main.cpp -o prog -fno-rtti -fno-exceptions
                                    ~~~~~~~~~~~~~~~~~~~~~~~~~


Why is this important in the context of C++?

    C++ is a language that does have safety features:

        - Libraries where you can have safety
        - The compiler can enforce safety
        - There is lots of static and dynamic analysis tools for safety
    
    The deafult is C++ lets do anything. This is a great powers of C++ but again, if you
are trying to know all the safety rules so that why we need libraries, tooling to help.

    C++ is a language that lets you choose the level of safety that you need as a programmer
and you enforce it. Other languages like Rust enforce safety from the compiler doing static analisys
or D-language that have garbage collection for instance and the language restruct some of the things
you can do by default.

 

*/

int main()
{
    std::vector v{0,1,2,3,4,5,6};

    // out of range:
    //    This line sometimes is printed although it shouldnt. Maybe the compiler 
    // is not good enougth and access the index
    v[8] = 8;
    std::println("This might actually print if capacity is large enough!");
    std::println("{}", v[7]);

    std::println("This however will always throw an error");
    // As a programmer you could implement some bound checked version like this
    int temp = v.at(7);

   return 0;
}