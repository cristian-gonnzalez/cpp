/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <vector>

/*

- Think about where Im doing my insertions? 

    Inserting an element at the beginning 
takes O(n) time. This is because all existing 
elements must be shifted one position to 
the right to make space at index 0.
    Since std::vector stores elements in 
contiguous memory, this shifting requires 
touching every element after the insertion point.
          ^
          |            Inserting an element in the middle std::vector  
          | 
          |              - Finding by index: O(1)
          |                      Supports random access (e.g., vec[5])
          |              - Finding by value (linear search): O(n)
          |
          |              - Inserting (even if position is known): O(n)
          |                      Because all subsequent elements need to be shifted one place to the right
          |                      If inserting near the start, it's the worst case
          |                  ^
          |                  |
          |                  |
          _ [ 3  , 4  , 5 ,  1 ,  4 , 4  ,  3 , _  , _  , _  ] _
              0    1    2    3    4   5     6   7    8    9                                   
                                                ^              ^ 
                                                |              |  
                    Inserting an element at the end (push_back)|
                is amortized O(1). This is because vectors     |
                allocate extra capacity to avoid frequent      |
                reallocations.                                 | 
                                                |      However, when the capacity is full, inserting a new element 
                                                |   causes the vector to allocatea larger block of memory and copy 
                                                |   all existing elements, which takes O(n) time.
                
*/

int main()
{
    return 0;
}