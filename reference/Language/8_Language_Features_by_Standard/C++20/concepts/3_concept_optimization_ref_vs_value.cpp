/* C++ 20 Concepts - concept for optimization (ref vs value)

*/
#include <iostream>
#include <concepts>
#include <vector>


/**
 *  Concepts definitions
 */
template< typename T >
concept SmallDataConstantExpression = sizeof(T) <= 8;

// So you can negate your concepts
template< typename T >
concept BigDataConstantExpression = !SmallDataConstantExpression<T>;



/**
 *  Template specializations
 */
template< typename T >
requires SmallDataConstantExpression<T>
void print(T value)
{
    std::cout << "small value is: " << value << std::endl;
}

/*
// Version 1:
// I define a template specialization to work with big data
template< typename T >
void print(T value)
{
    std::cout << "big value is: " << sizeof( value ) << ": [";
    for(auto& e: value)
        std::cout << e << ", ";
    std::cout << "]\n";
}
*/

//
/* 

// Version 2:
// if we are working with big types, we probably want to pass a reference.
// But we notice that we are getting an error where 'print(int&)' is ambiguous -> print(i)
template< typename T >
void print(const T& value)
{
    std::cout << "big value is: " << sizeof( value ) << ": [";
    for(auto& e: value)
        std::cout << e << ", ";
    std::cout << "]\n";
}

<source>:73:10: error: call of overloaded 'print(int&)' is ambiguous
   73 |     print(i);                                              // small value is: 7
      |     ~~~~~^~~
<source>:73:10: note: there are 2 candidates
<source>:18:6: note: candidate 1: 'void print(T) [with T = int]'
   18 | void print(T value)
      |      ^~~~~
<source>:46:6: note: candidate 2: 'void print(const T&) [with T = int]'
   46 | void print(const T& value)
      |      ^~~~~

*/

// Version 3
// So, we need to be more specific by adding a constraints (new concept) to work with big data 
// types
template< typename T >
//requires (!SmallDataConstantExpression<T>)     // this is equivalent if we dont want to create a new concept
requires BigDataConstantExpression<T>
void print(const T& value)
{
    std::cout << "big value is: " << sizeof( value ) << ": [";
    for(auto& e: value)
        std::cout << e << ", ";
    std::cout << "]\n";
}


int main() 
{
    int i = 7;
    std::cout << "size of i: " << sizeof(i) << std::endl;  // size of i: 4
    print(i);                                              // small value is: 7  

    std::vector v{1,2,3,4,5,6};
    std::cout << "size of v: " << sizeof(v) << std::endl;  // size of v: 24 
    // Note: if we dont have a template specialization 
    // we would get an error:
    //
    /*
    print(v);
    
    constraints not satisfied
    required for the satisfaction of 'SmallDataConstantExpression<T>' [with T = std::vector<int, std::allocator<int> >]
<source>:9:49: note: the expression 'sizeof (T) <= 8 [with T = std::vector<int, std::allocator<int> >]' evaluated to 'false'
    9 | concept SmallDataConstantExpression = sizeof(T) <= 8;
    */

    print(v); // big value is: 24: [1, 2, 3, 4, 5, 6, ]
    
    return 0;
}