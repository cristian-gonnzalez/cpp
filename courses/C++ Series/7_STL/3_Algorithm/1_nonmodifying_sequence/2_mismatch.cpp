/** C++ STL algorithm - std::mismatch
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//  std::mismatch:
//      finds the first position where two ranges differ

// template< class InputIt1, class InputIt2 >
// std::pair<InputIt1, InputIt2> mismatch( InputIt1 first1, InputIt1 last1,
// ~~~~~~~~~                               ~~~~~~~~  > first container
// Returns a std::pair                     InputIt2 first2 );
//     ^                                   ~~~~~~~~  > second container
//     |
//  iterators to the first two non-equal elements
//
//     If no mismatches are found, the pairs holds last1 and the corresponding iterator from the second container.
//     The behaviour is undefined if the second container is shorter.

//  Complexity: O(N1) 


void mismatch_check(const std::vector<int>& v1, const std::vector<int>& v2)
{
    if(v1.size() > v2.size())
        return;

    auto result1 = std::mismatch(v1.begin(), v1.end(),
                                 v2.begin());

    std::cout << *result1.first << " - " << *result1.second << std::endl;
}

int main()
{
        // NOTE: we have to make sure that the second container is not shorter than the first one
    std::vector v1{1,2,3,4};
    std::vector v2{1,2,3,4};
    std::vector v3{1,2,3,99};

    mismatch_check(v1, v2);  // 0 - 0
    mismatch_check(v1, v3);  // 4 - 99

    return 0;
}


