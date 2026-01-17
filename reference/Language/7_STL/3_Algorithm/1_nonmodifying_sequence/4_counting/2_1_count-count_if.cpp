/** C++ STL algorithm - counting (count, count_if)
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//   returns the number of elements satisfying specific criteria
//                                              

// std::count: Counts the elements that are equal to value (using operator==).
//
// std::count_if: Counts elements for which predicate p returns true.
//

//
// Complexity: O(N)
//


int main()
{
    {
        std::vector v1{1,3,4,4,5,4,7,4,4,4,4};

        int r = std::count( v1.begin(), v1.end(), 4);
        std::cout << "count 4: " << r << std::endl; // count 4: 7 
    }

    {
        std::vector v1{-1,-3,5,7};

        int r = std::count_if( v1.begin(), v1.end(), 
                     [](int i)
                     {
                        return i > 4;
                     } );
        std::cout << "count_if > 4: " << r << std::endl; // count_if > 4: 2
    }
    
    return 0;
}


