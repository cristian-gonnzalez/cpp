/** C++ STL std::queue a container adaptor | Modern Cpp Series Ep. 132
 */

#include <iostream>
#include <queue>

/*

std::queue:

Defined in header <queue>
template<
    class T,
    class Container = std::deque<T>
> class queue;

    It is a container adaptor that gives the functionality of a queue - a FIFO (first-in, first-out) data structure.
                      ~~~~~~~

                   It is called since we use another container 
                to adpat to queue 

FIFO:  first-in, first-out

          _________
      |   \________\                       back()          Peeks at the top element
   in |   \________\                       front()         Peeks at the first element
      |   \________\                       push_back()     
      |   \________\                       pop_front()  
      ↓   \________\
              
              ↓   
             out

Member functions

    Element access
        front: access the first element
        back: accesses the last element

    Capacity
        empty: checks whether the container adaptor is empty
        size: returns the number of elements


    Modifiers
        push: inserts element at the end
        emplace: constructs element in-place at the end.
            It means that the object doesnt have to be copied and then push over to the stack.
        pop: removes the first element
        swap: swaps the contents


    The container adaptor must be a SequenceContainer and provide the following functions:
        
        back(), e.g., std::deque::back(),
        front(), e.g. std::list::front(),
        push_back(), e.g., std::deque::push_back(),
        pop_front(), e.g., std::list::pop_front().


    Queues are usufull to manage events

*/

void view_queue( auto copy)
//                    ^
// Pass-by-value because to show the queue, we need to remove
// all the elements
{
    int r;

    std::cout << "[";
    while(!copy.empty())
    {
        r = copy.front();
        copy.pop();

        std::cout << r << ", ";
    }
    std::cout << "]\n ";
}


int main()
{
    {
        std::queue<int> q;

        q.push(1);
        q.push(2);
        q.push(3);

        std::cout << "size : " << q.size() << std::endl; // size : 3
        std::cout << "front: " << q.front() << std::endl; // front: 1
        std::cout << "back : " << q.back() << std::endl; // back : 3


        // pop:
        //      Removes an element from the front of the queue. Effectively calls c.pop_front().
        //
        // void pop();
        // ~~~~
        // There is no return
        //
        //      To get the pop element, you must called front before calling pop()
        int front = q.front();
        q.pop();
        
        std::cout << "front: " << q.front() << std::endl; // front: 2
        std::cout << "size : " << q.front() << std::endl; // size : 2    
    }
    
    {
        // WARNING: uniform-initialization is not supported
        //
        //                  ~                    ~    
        // std::queue<int> q{-3,-2,1,0 /*, 2.3 */};
        //
        //      I cannot use uniform-initialization or std::inizializer_list 
        // because std::queue does not have an initializer-list constructor, but 
        // it does have a constructor that takes a container.
        //
        //      explicit queue(const Container& cont);
        //      explicit queue(Container&& cont);        
        //
        //      This is the correct way to construct
        //
        // std::queue<int> queue({-3, -2, 1, 0}); 
        //
        // -- Why this version works:
        //
        //      {-3, -2, 1, 0} creates a temporary container using the adaptor: 
        //
        //  std::deque<int>{-3, -2, 1, 0}
        //
        //      That container is passed to the stack constructor:
        //
        //  std::queue<int> q(std::deque<int>{ -3, -2, 1, 0 });
        
        std::queue<int> q2({-3,-2,1,0 /*, 2.3 */});
        //                              ~~~~~
        // narrowing conversion of '2.2999999999999998e+0' from 'double' to 'int
        
        view_queue( q2 ); // [-3, -2, 1, 0, ]

    }

    return 0;
}