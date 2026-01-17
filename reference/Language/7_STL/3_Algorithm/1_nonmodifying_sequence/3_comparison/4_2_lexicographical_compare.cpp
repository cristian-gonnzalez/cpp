/** C++ STL algorithm - comparison with std::lexicographical_compare
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//   std::lexicographical_compare
//      Returns true if one range is lexicographically less than another
//                                                      ~~~~~~~~
//                                                 Element are compáred using operator<
//                                              

//  
//  template< class ExecutionPolicy,
//            class ForwardIt1, class ForwardIt2, class Compare >
//  bool lexicographical_compare( ExecutionPolicy&& policy,
//                                ForwardIt1 first1, ForwardIt1 last1,
//                                ForwardIt2 first2, ForwardIt2 last2,
//                                Compare comp );
//                                        ~~~~~
//            comparison function object which returns true if the first argument is less than the second.
//            The signature of the comparison function should be equivalent to the following: 
//
//            bool cmp(const Type1& a, const Type2& b);
//  

// Lexicographical comparison is an operation with the following properties:
// - Two ranges are compared element by element.
// - The first mismatching element defines which range is lexicographically less or greater than the other.
// - If one range is a prefix of another, the shorter range is lexicographically less than the other.
// - If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
// - An empty range is lexicographically less than any non-empty range.
// - Two empty ranges are lexicographically equal.

//
// Complexity: O(min(N1,N2))
//



int main()
{
    {

        std::vector v1{1,3,5,7};
        //             | | | |
        std::vector v2{2,4,6,8};
        // Comparison are made element by element

        std::cout << std::boolalpha 
              << "v1 before v2 in dictionary?: "
              <<  std::lexicographical_compare( v1.begin(),v1.end(), 
                                                v2.begin(),v2.end() )
              << std::endl;  // v1 before v2 in dictionary?: true

    }


    {
    
        std::vector v1{2,4,5,8};
        std::vector v2{2,4,4,8};

        std::cout << std::boolalpha 
              << "v1 before v2 in dictionary?: "
              <<  std::lexicographical_compare( v1.begin(),v1.end(), 
                                                v2.begin(),v2.end() )
              << std::endl;  // v1 before v2 in dictionary?: false

    }

    return 0;
}


