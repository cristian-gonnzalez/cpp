/** STL std::forward_list | Modern Cpp Series Ep. 119
 */
#include <iostream>
#include <forward_list>

/**
std::foward_list:

    Forward-lists are list that only move forward vs regular-list where we have bi-directional.

Defined in header <forward_list>
template<
    class T,
    class Allocator = std::allocator<T>
> class forward_list;


What is the advantanges to only move forward?

    It comes down to space efficiency.  

        - Much lower memory overhead per node (only one pointer instead of two).
        - Cheaper pointer updates during insert/erase.
        - Ideal when only forward traversal is needed.

- Performance:

     Supports 'fast insertion and removal' of elements from anywhere in the container. 

     Fast random access is not supported. It is implemented as a singly-linked list. 
    
        - O(1) insertion and removal 'after a given iterator'
                * Member functions only takes iterator: insert_after, erase_after.
        - O(n) traversal to reach an insertion/removal point ().
                * We need non-member function: std::advance(), std::distance()
        - No random access and no size() (lightweight structure).

- Implementation:

                                    singly-linked list
                         node                                                     
    std::forward_list      [ ]  ->  [ ]   ->  [ ]   ->  [ ]   ->  [ ]        
                            ^    ^
                            |    |
                            |   pointer
                           head

    Observe, that we only have a head pointer and I dont have a pointer to the end (tail). 
In thta way, we dont have push_back

        It is more ligthweight and efficient than a list (if we are just traversing fowards)

        As it is a ligthweight list, it does not have the size and all the methods of std::list 

        Provides special functions: before_begin(), insert_after(), erase_after(), etc.
 
 */


int main()
{
	return 0;
}