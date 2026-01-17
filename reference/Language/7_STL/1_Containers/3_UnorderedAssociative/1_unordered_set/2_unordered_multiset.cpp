/** STL std::unordered_multiset( C++11) (and custom hash function) | Modern Cpp Series Ep. 124
 */
#include <iostream>
#include <unordered_set>

/** 
std::unordered_multiset:

     It is an associative container that contains set of possibly non-unique objects of type Key. 
Search, insertion, and removal have average constant-time complexity.

    std::unordered_multiset give us same capabilities of std::unordered_set but we have duplicates
values (See std::unordered_set)
            ~~~~~~~~~~~~~~~~~~

Defined in header <unordered_set>
                   ~~~~~~~~~~~~~
template<
    class Key,                                   -> The element type
    class Hash = std::hash<Key>,                 -> tell us in which bucket an element is placed. For non-trivial types
                                                    For non-trivial types, we must provide our own hash function object 
                                                    with signature:
                                                  
                                                        std::size_t operator()(const S& s) const noexcept
                                                        
    class KeyEqual = std::equal_to<Key>,         -> tell us if two Keys are equeal.
                                                    For non-trivial types, we must provide an equality
                                                    definition using one of the following:

                                                       - In-class definition:
                                                          overload operator==
                                                      (This example uses this option.)

                                                        - Template parameter:
                                                             provide a custom equality functor
                                                          and pass it as the third template argument.

    class Allocator = std::allocator<Key>

> class unordered_multiset;


 */


int main()
{
    std::unordered_multiset<int> o_mset;
   
    return 0;
}

