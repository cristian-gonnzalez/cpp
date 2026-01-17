/** STL std::deque | Modern Cpp Series Ep. 120
 */
#include <iostream>
#include <deque>

/*
std::deque (double-ended queue): 

Defined in header <deque>

template<
    class T,
    class Allocator = std::allocator<T>
> class deque;

    std::deque is an 'double-ended queue'.
                      ~~~~~~~~~~~~~~~~~~

            Queue:
                        °  °  °  °  °            The idea of a queue is that the first person     
                 <---   |  |  |  |  |          in the line if the first person out (FIFO)         
                        0  1  2  3  4
                        ^           ^ 
                      front        back  

        
Double-Ended Queue:
                        °  °  °  °  °            We extend a regular queue where the person      
                 <---   |  |  |  |  |  --->    at the back of the line can also be the first          
                        0  1  2  3  4          person out (FIFO/LIFO)
                        ^           ^ 
                      front        back  

    
    It is a SequenceContainer that allows fast insertion and deletion at the begin or its end. 
                                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
    The elements of a deque are not stored contiguously.
    
    Insertion and deletion at either end of a deque never invalidates pointers or references
to the rest of the elements.                        ~~~~~~~~~~~~~~~~~~~~~~~~~~

        - Random access - constant O(1).
        - Insertion or removal of elements at the end or beginning - constant O(1).
        - Insertion or removal of elements - linear O(n).

    One way to visualize the std::deck is as a doulble-linked list where each node is a fixed-size array.

                        (chuncks)
                    fixed-size array
                           ^
                         node                                                     
     std::dequeue      [ , , ]  ->  [ , , ]   ->  [ , , ]    ->  [ , , ]    ->  [ , , ] 
                          ^     <-            <-             <-             <-     ^
                          |                    ^                                   |  
                        front                  |                                  back   
                                            pointers
                                        (We're able to connect those nodes with pointers)

    The expansion of a deque is cheaper than std::vector because it does not involve copying 
all the elements to a new memory location. It only creates a new node againts std::vecrot we have
to duplicate the entire size.

    The STL implementation use an array (at least of 8 elements) and named this map (has nothing 
to do with std::map). Each index is a different chunck (node)

       
       map          node
                  (chuncks)
      back       fixed-size array 
     -----  ______ [  1,  2,  3]
    |-----| ______ [  4,  5,  6]             If I access sth (for ex: 4), I have to find my
    |-----| ______ [  7,  8,  9]          position in map and then dereference again to get
    |-----| ______ [ 11, 22, 33]          4. It is still a constant time lookup but it is 
    |-----| ______ [ 44, 55, 66]          derefering two pointers
    |-----| ______ [ 77, 88, 99] 
    |-----| ______ [ 12, 13, 14]
    |-----| ______ [ 15, 16, 17]
     -----
     front
       ^
It also can grow in both direction
(back/front) 

*/


int main()
{
    std::deque<int> dq1{1,2,3,4};
    return 0;
}