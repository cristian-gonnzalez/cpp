// -std=c++20
/**  Concepts
 *
 */
#include <iostream>


/**
 * Concepts
 */

// Specify a type parameter must support +
template<typename T>
concept Addable = requires (T x )
                  {
                    x + x;      
                  };


/**
 *  Template specializations
 */
template< Addable T >
T add(T a, T b)
{
    return a + b;
} 


int main()
{
    std::cout << "add(10, 30): " << add(10, 30) << std::endl;
    // std::cout << "add(\"Hello\", \"World\"): " << add("Hello", "World") << std::endl; //         • constraints not satisfied


    return 0;
}