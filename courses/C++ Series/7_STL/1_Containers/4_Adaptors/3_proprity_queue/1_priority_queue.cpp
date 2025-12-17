/** C++ STL std::priority_queue (a container adaptor) | Modern Cpp Series Ep. 133
 */
#include <iostream>
#include <queue>    // std::priority_queue

/*
std::priority_queue:

    It is an specialization of std::queue but with sorted order.

    The priority queue is a container adaptor 
                            ~~~~~~~~~~~~~~~~~
                            We can change the underlying storage
                        thet can impact the performance
    
    It provides constant time O(1) lookup of the largest (by default) element, 
at the expense of logarithmic log(N) insertion and extraction.

    A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> 
would cause the smallest element to appear as the top().

    A priority_queue is similar to managing a 'heap' with the benefit of not being able to accidentally 
invalidate the heap.



    [42, 75, 52, 1]

    max_priority_queue:                        (Max heap)
 
                    [73]
                   /    \
                [42]    [52]
                /
              [1]

Template parameters

Defined in header <queue>
template<
    class T,                                 // The type of the stored elements.
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

    Container:
        -   The container must satisfy the SequenceContainer, and its iterators must satisfy 
        the LegacyRandomAccessIterator. 

        it must provide the following functions:

            front(), e.g., std::vector::front(),
            push_back(), e.g., std::deque::push_back(),
            pop_back(), e.g., std::vector::pop_back().

        std::vector (not including std::vector<bool>) and std::deque satisfy these requirements.

    Compare:
        -   A Compare type providing a strict weak ordering.

        Note that the Compare parameter is defined such that it returns true if its first argument 
    comes before its second argument in a weak ordering. 
        But because the priority queue outputs largest elements first, the elements that "come before" 
    are actually output last. That is, the front of the queue contains the "last" element according 
    to the weak ordering imposed by Compare.

Member functions:

    Element access
        top: accesses the top element

    Capacity
        empty: checks whether the container adaptor is empty
        size: returns the number of elements

    Modifiers
        push: inserts element and sorts the underlying container
        emplace: constructs element in-place and sorts the underlying container
        pop: removes the top element
        swap: swaps the contents


The standard containers std::vector (not including std::vector<bool>) and std::deque satisfy these requirements.

*/

int main()
{
 
    std::priority_queue<int> q;

    // Every osuh call is a logarithmic operation since we haver to
    // restructure
    q.push(1);
    q.push(4);
    q.push(3);
    q.push(7);
    q.push(2);
    
    std::cout << "size: " << q.size() << std::endl; // size: 5
    std::cout << "top : " << q.top() << std::endl; // top : 7


    std::cout << "[";
    while(!q.empty())
    {
        int r = q.top();

        // Every remove call is a logarithmic operation since we haver to
        // restructure
        q.pop();

        std::cout << r << ", ";
    }
    std::cout << "]\n "; // [7, 4, 3, 2, 1, ]

    return 0;
}