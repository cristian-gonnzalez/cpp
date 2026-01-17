/** List-initialization {} vs std::initializer_list<T>:
 */ 
#include <iostream>
#include <string>
#include <vector>

/* 
  {} and std::initializer_list are two different things.

    - std::initializer_list<T> is a type (a class template)
            - {} can trigger an std::initializer_list constructor
            if the type has one. Each element of the initializer-list 
            is list-initialized,

    - {} is syntax (list-initialization).           
            - {} braces apply special initialization rules, such as:
                * Preventing narrowing conversions
*/

int main()
{
    //
    // Initialization
    //

    //
    // 1. Built-in types
    //
    
    //   C++ supports three basic initialization syntaxes ( =, (), and {} ):
    int a = 4.5;   // OK: narrowing allowed (a = 4)
    int b(4.5);    // OK: narrowing allowed (b = 4)
    int c{4};      // OK
    // int c{4.5}; // ERROR: narrowing is forbidden in list-initialization

    // Rule:
    //   '{}' triggers 'list-initialization', which forbids narrowing
    // when initializing arithmetic types. This can prevent some types 
    // of programming errors.

    // So far, no problem if we use 'built-in' types.
    
    return 0;
}
