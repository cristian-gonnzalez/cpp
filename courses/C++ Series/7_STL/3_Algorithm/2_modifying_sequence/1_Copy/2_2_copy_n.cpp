/** C++ STL algorithm - std::copy_if and std::copy_n
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric> // std::iota


//
//  Modifying sequence operations
//      This means these algorithms might modify the container
//
//      In this case, std::copy does not modify the container but it copies data from one 
//  to another location


//    copies a number of elements to a new location (function template)
//

// template< class InputIt, class Size, class OutputIt >
// OutputIt copy_n( InputIt first, Size count, 
//                                      ~~~~~
//                                    How many bytes we want to copy
//                  OutputIt result );
//                  ~~~~~~~~     
//                     ^         
//                     |                 
//      We can use one of these clases to create output iterators (std::insert_iterator, 
//      std::back_insert_iterator, std::front_insert_iterator):
//
//          - std::inserter: Return a std::insert_iterator which can be used to insert elements 
//                           into the container c at the position indicated by i.
//
//                           std::inserter(container, container.end())
//
//          - std::back_inserter: returns a std::back_insert_iterator which can be used to add  
//                           elements to the end of the container c.
//
//                           std::back_inserter(container);
//
//          - std::front_inserter: returns a std::front_insert_iterator which can be used to add 
//                           elements to the beginning of the container c.
//
//                           std::front_inserter(container);
//


// NOTE:
//     Remember that there are lower level functions like std::memmmove/std::memcopy that
// are usefull when you really need to opmize things 


//
// Complexity: O(N) Linear time
//

int main()
{
    std::string s1{"HELLO my WORLD"};
    std::string s2;

    std::copy_n( s1.begin()+6, s1.size()-6,
                 std::back_inserter( s2 ) );
    std::cout << s2; // my WORLD

    return 0;
}


