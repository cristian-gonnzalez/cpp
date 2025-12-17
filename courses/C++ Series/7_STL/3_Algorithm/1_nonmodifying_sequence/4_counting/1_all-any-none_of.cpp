/** C++ STL algorithm - counting (all_of, any_of, none_of)
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//   checks if a predicate is true for all, any or none of the elements in a range (function template)
//                                              

// template< class InputIt, class UnaryPred >
// bool all_of( InputIt first, InputIt last, UnaryPred p );
//
//
// template< class ExecutionPolicy, class ForwardIt, class UnaryPred >
// bool all_of( ExecutionPolicy&& policy,
//              ForwardIt first, ForwardIt last, UnaryPred p );
//


//
// Complexity: std::all_of: O(N)
//



int main()
{
    // Checks if unary predicate p returns true for all elements in the range [first, last).
    {
        std::vector v1{1,3,5,7};

        bool r = std::all_of( v1.begin(), v1.end(), 
                     [](int i)
                     {
                        return i > 0;
                     } );
        std::cout << std::boolalpha << "all_of > 0: " << r << std::endl; // all_of > 0: true 
    }

    // Checks if unary predicate p returns true for at least one element in the range [first, last).
    {

        std::vector v1{-1,-3,5,7};

        bool r = std::any_of( v1.begin(), v1.end(), 
                     [](int i)
                     {
                        return i > 0;
                     } );
        std::cout << std::boolalpha << "any_of > 0: " << r << std::endl; // any_of > 0: true
    }
    
    // Checks if unary predicate p returns true for none of the elements in the range [first, last).
    {
        std::vector v1{-1,-3,5,7};

        bool r = std::none_of( v1.begin(), v1.end(), 
                     [](int i)
                     {
                        return i > 0;
                     } );
        std::cout << std::boolalpha << "none_of > 0: " << r << std::endl; // none_of > 0: false
    }
    return 0;
}


