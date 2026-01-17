/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <vector>

/*
std::vector: (dynamic array)
===========
    A better name would be 'dynamic array' meaning that it's a data structure that can re-size.
    
    Defined in header <vector>

template<
    class T,
    class Allocator = std::allocator<T>  -> There's some sort of allocation 
> class vector;


std::vector<int> v;    ->         []    When we create a vector, it is empty
v.push_back(1)                    [1]
                                   0 
v.push_back(2)                    [1, 2, _ , _ , _ ]              capacity: 5   
                                   0  1  ^   ^   ^                size    : 2
                                         ~~~~~~~~~~
                                         Get extra storage
v.push_back(3)                    [1, 2, 3 , _ , _ ]              capacity: 5   
                                   0  1  2   3   4                size    : 3
                                                        

    Im increasing the size of my data-strucuture in every push_back. This is the basic premise 
of a vector, over time it will reallocate, copy elements into a new array (behind the scenes).

    This would get pretty inefficient if it reallocate everytime you do a push_back so we will
actually increase the capacity adding a few extra storages, I don't have to reallocate everytime
copying the entire array  

    It is a contiguos sequence of memory, meaning that each element is rigth next to the other
getting performance when accessing them

    - It is a Sequence Container
    - It is a Contiguous Container that stores objects in contiguous memory locations
    - It is "heap allocated" so that means if you need to store large collections of data.
    
Note:
    we can allocate large portion of data in the heap versus variables that's stack allocated 
where you have fixed-size stacks. 
    So if you are storing large objects, you are going to need heap allocated data-structure. 

*/

int main()
{
    return 0;
}