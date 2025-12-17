/** Chalenge:
 *      1. Find a container that have a .size() member function.
 *      2. Figure out at compile which container has a .size() member function. 
 *
 */
#include <iostream>
#include <concepts>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

/**
 * Concepts definitions:
 */
template< typename T >
concept HasSizeMemberFunction = requires( T container)
{
    container.size();
};


template< typename T >
concept IsSmallAllocation = requires( T container)
{
    requires (container.size() <= 4);
};

/**
 * Template specialization:
 */
template< typename T>
requires HasSizeMemberFunction<T> && IsSmallAllocation<T>
void print( const T& container )
{
    std::cout << "The size is: " << container.size();
    
    std::cout << " -> [";
    for(auto& e: container )
        std::cout << e << ", ";
    std::cout << "]\n";
}


int main()
{
    std::vector v{1,2,3,4};
    std::array<int, 4> small_arr{1,2,3,4};
    std::array<int, 5> big_arr{1,2,3,4,5};
    std::list l{1,2,3,4};
    std::deque dq{1,2,3,4};
    std::forward_list fl{1,2,3,4};

    print( small_arr );            // The size is: 4 -> [1, 2, 3, 4, ]
    //print( big_arr );              // constraints not satisfied
    //print( v );
    //print( l );
    //print( fl );  // fails since it does not have list member
    //print( dq );

    return 0;
}
