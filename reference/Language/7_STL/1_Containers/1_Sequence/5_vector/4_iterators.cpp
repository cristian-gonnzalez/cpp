/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <iostream>
#include <vector>
#include <span>

/*

Iterators

// erase:
//      Erases the specified elements from the container.
//
// 1) Removes the element at pos.
//
//      iterator erase( iterator pos );                               (1) 
//      iterator erase( const_iterator pos );   
//
// 2) Removes the elements in the range [first, last).
//
//      iterator erase( iterator first, iterator last );              (2)
//      iterator erase( const_iterator first, const_iterator last );
//
//      Iterators (including the end() iterator) and references to the 
// elements at or after the point of the erase are invalidated.

*/

int main()
{
    // using CTAD (Class Template Argument Deduction) we can figure out
    // or deduce the types in some cases
    std::vector v1{1,2,3,4};

    // 
    // Iterators:
    //     It is a pointer to a position
    // 
    //     [ 1 , 2 , 3 , 4] _  
    //       0   1   2   3
    //       ^              ^
    //     begin()        end()
    // 
    std::vector<int>::iterator start = v1.begin(); // Point at the begining of the vector
    std::vector<int>::iterator last = v1.end(); // Point at the end of the vector

    //
    //     [ 1 , 2 , 3 , 4] _  
    //       0   1   2   3
    //           ^
    //           |
    //        ~~~~~~~~~~~~~~
    v1.erase( v1.begin() + 1);


    // WHAT NOT TO DO 
    // Forces an 'iterator invalidation'
    //  I erase the beginiing element and then I print out index 0
    /*
    std::cout << "[";
    for(auto i=0; i<v1.size(); i++)
    {
        v1.erase( v1.begin() );
        std::cout << v1[i] << ", ";  // Program terminated with signal: SIGSEGV

    }
    std::cout << "]\n";  
    */

    // Range-based for-loop    
    std::cout << "[";
    for(auto& e: v)
        std::cout << e << ", ";
    std::cout << "]\n";  // [1, 3, 4, ]

    // Old C++-style
    std::cout << "[";
    for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        std::cout << *it << ", ";
        //           ^~~
        //        Because iterator are pointers, I di-reference it.
    std::cout << "]\n"; // [1, 3, 4, ]

    return 0;
}