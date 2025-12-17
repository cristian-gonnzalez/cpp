/* C++ 20 Concepts - Working with containers

  Check if member exists and T::value_type

*/
#include <iostream>
#include <concepts>
#include <vector>
#include <deque>
#include <forward_list>

/**
 *  Concepts
 */

// Concept to check for 'push_back'
template< typename T >
//concept HasPushBack = requires( T container ) // this is enougth to check push back
                                                // if we want to check for specific types, the template before is not enoutgh. 
                                                // So we rewrite to check the type:  
concept HasPushBack = requires( T container, T::value_type v)  
                                          // ~~~~~~~~~~~~~
                                          //     ^
                                          // value_type is a member type defined 
                                          // in STL container and it tells us 
                                          // what we are storing
{
    // if whatever is here compiles...then it must be valid.
    //
    // Note: we cannot have loops or complicated stuff here, just true or false statements
    //                                                            ~~~~~~~~~~~~~~ 
    //       It is important to understand that this code we write here it doesnt do anything,
    //       it doesnt actually push back, this is just checking that it compiles.
    container.push_back(v);
    //container.push_back(0); This also works
};




/**
 *  Template specializations
 */

template< typename T > // T = vector, deque, etc.
requires HasPushBack<T>
void add_to(T& container, int integer)
{
    container.push_back(integer);
}


int main() 
{
    std::vector v{1,3,5,7};
    std::deque d{1,3,5,7};
    add_to(v, 9);
    add_to(d, 9);

    std::forward_list l{1,3,5,7};
    //add_to(l, 9);  // Not allowed: constraints not satisfied
                     // has no member 'push_back'

    auto print_container = [](auto& container)
                            {
                                std::cout << "[";
                                for(auto& e: container)
                                    std::cout << e << ", ";
                                std::cout << "]\n";   
                            };
    print_container(v);
    print_container(d);

/*
    stdout
    [1, 3, 5, 7, 9, ]
    [1, 3, 5, 7, 9, ]
*/
    return 0;
}