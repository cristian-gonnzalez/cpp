/** C++ STL algorithm - std::copy
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

//
//  Modifying sequence operations
//      This means these algorithms might modify the container
//
//      In this case, std::copy does not modify the container but it copies data from one 
//  to another location


//   copies a range of elements to a new location
//

// NOTE:
//     Remember that there are lower level functions like std::memmmove/std::memcopy that
// are usefull when you really need to opmize things 

// template< class InputIt, class OutputIt >
// OutputIt copy( InputIt first, InputIt last,
//                OutputIt d_first );
//                ~~~~~~~~
//                  ^
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


//
// Complexity: O(N) Linear time
//


int main()
{
    auto print_v = []( auto v)
                    {
                        std::cout << "[";
                        for(auto& e: v)
                            std::cout << e << ", ";   
                        std::cout << "]\n";
                    };

    std::vector v{1,3,5,7,9,11};
    {
        std::vector<int> v_copy;

        // Note: performace
        //      This will basically give us the entire block of memory vs allocating one block by one.
        v_copy.reserve( v.size() );

        std::copy( v.begin(), v.end(),
                   std::back_inserter(v_copy) );

        print_v(v_copy); // [1, 3, 5, 7, 9, 11, ]

        // We cannot use std::front_inserter since std::vector has no memeber function 'push_front'
        //std::copy( v.begin(), v.end(),
        //        std::front_inserter(v_copy) );
        //        ~~~~~~~~~~~~~~~~~~~
        //  error: 'class std::vector<int, std::allocator<int> >' has no member named 'push_front'
        //  |         container->push_front(__value);
        //  |

        // we can simulate the fron_inserter using reverse_iterators
        v_copy.clear();
        std::copy( v.rbegin(), v.rend(),
                   std::back_inserter(v_copy) );

        print_v(v_copy); // [11, 9, 7, 5, 3, 1, ]
    }
    
    {
        std::list<int> v_copy;
        std::copy( v.begin(), v.end(),
                   std::front_inserter(v_copy) );

        print_v(v_copy); // [11, 9, 7, 5, 3, 1, ]
    }

    return 0;
}


