/** STL algorithm
 *
 */

#include <algorithm>

// The algorithms library defines functions for a variety of purpose (searching, sorting, counting, manipulation) that works with
// iterator (or ranges - C++20)
//
// Categories:
//
//      - Non-modifying sequence operations
//      - Modifying sequence operations
//      - 
//
//                   Accessing the containers
//      _____________       |                          _____________
//     |             |      |                         |             |
//     |  Containers | <-------- Iterators            | Algorithms  |
//     |_____________|                                |_____________|
//                     
//   std::vector, std::list                            Take our data in the containers and transform
//   and so on...                                    it into some different form
//
//     Just having two pairs of iterators that access some container and perform some operation on data

//
// Why do we have to use algorithms?
//
//      - Well tested
//      - Basic buiding blocks
//          |
//          |-> Expresive    It express what you wnat to do, i.e, for_each, count, copy
//      - Generics (templated functions)  They are available for most of the data-structures 
//      - Reasonably performed
//          |
//          |->  Pathway to parallel (with execution-policy)
//
//

//
// Generic design and advice on using member functions 
//
//      You will see in some container we can find member functions that makes the same as the algoritm library.
// for ex: std::set has in the the Lookup section a find function and we also have a 'find' function in the algorithm
// library 
//
//     Lets compare the complexity:
//
//          - std::set<Key,Compare,Allocator>::find -> O(log n)
//          - std::find -> O(n)
//
//      Notice that there might be a more optimazed version for the particular container that you are using in the STL.
//  This is the case where std::set::find is better than the one in the algorithm library.
//
//  NOTE:
//      - Prefer container version of algorithm.
//
//     The idea with the structure of the algorithm library is we can have our container independent of the algorithms 
// (generic programming). That's why that these algorithms are tempalated functions, that way if I just have
// a function, it's not part of the actual object unless there's a specific optimized case like std::set::find. 
//      In order to perform the algorithm which is accessing the container's data, we use our iterators (or ranges).
//      So, we can create our data structure, difines iterators and we can use these algorithms 
//

int main()
{
    return 0;
}
