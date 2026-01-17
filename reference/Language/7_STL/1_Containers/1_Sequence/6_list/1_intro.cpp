/** STL std::list | Modern Cpp Series Ep. 118
 */

#include <iostream>
#include <list>

/*

    Lists are another useful data-structure when we dont want to use vector.

std::list: 
                           
    Fast random access is not supported that because it is usually implemented as a doubly-linked list where each 
node has pointers to the next and previous nodes.                                   ~~~~~~~~~~~~~~~~~~
                                                                                        ^
                       node                                                     This means we can traverse
        std::list      [ ]  ->  [ ]   ->  [ ]   ->  [ ]   ->  [ ]             forwards or backwards
                            <-        <-        <-        <-  
                            ^
                            |
                        pointers
                        (We're able to connect those nodes with pointers)

    Each node is really anywhere in memory locations. It is a linear data-structure (SequenceContainer)

    Compare with a vector or array which stores elements in contiguous memory locations, being able to 
randomly access

        std::vector    [  ,   ,   ,   ,   ,   ]
                        0   1   2   3   4   5

	It is a non-contiguos container that supoort  constant time insertion and removal of elements from anywhere in the container. 
	But fast random access is not supported.


- Think about where Im doing my insertions? 

                  Inserting an element in the middle of a std::list involves two operations:
                    - Finding an element: O(n)
                            If you're searching by value, you need to traverse to a specific position: O(n)
                        since no random-access, so you must walk the list node by node.
                    - Inserting with iterator: O(1)
                            Only a few pointer updates — no shifting or memory copying
                                    ^       
                                    |
                                    |  
    std::list ___   [ ]  ->  [ ]   ->  [ ]   ->  [ ]   ->  [ ]  ___           forwards or backwards
               ^     ^   <-        <-        <-        <-   ^    ^
               |    head                                  tail   |
               |                                                 | 
            Inserting an element at the beginning or end of a std::list is O(1).
            The container maintains pointers to both: the head and tail, so inserting 
        at either end only involves updating a few pointers, with no need to shift or 
        copy other elements.
*/

int main()
{

}