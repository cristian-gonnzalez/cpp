/** C++ STL algorithm - search (find)
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//  std::adjacent_find:
//  finds the first two adjacent items that are equal (or satisfy a given predicate)
//                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                     ~~~~~~~~~~
//                     two consecutive equal elements.                        ^
//                                                                            |
//                                                                   Elements are comparted using operator ==
//                                                                or using the given binary predicate  

// If you are using a custom data-type, you make sure to override the operator == or give a predicate using functors


int main()
{
    //              This two elements are equal but not consecutive
    //                     ^   ^
    std::vector<int> v{1,2,3,4,3,2,5,5,6,7,8};
    //   index         0 1 2 3 4 5 6 7 8 9 10
    //                             ^ ^
    //                     two consecutive equal elements.

    if( auto result = std::adjacent_find(v.begin(), v.end());
        result != v.end() )
    {
        std::cout << "Found an adjacent pair " << *result 
                  << " at index " << std::distance(v.begin(), result) << std::endl; 
                                    //~~~~~~~~~~~~~
    }

    return 0;
}


