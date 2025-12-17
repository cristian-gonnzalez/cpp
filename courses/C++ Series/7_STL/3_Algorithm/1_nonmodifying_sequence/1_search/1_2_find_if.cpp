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


int main()
{
    std::vector<int> v{1,3,5,12,7,9,10};

    //
    // std::find_if:
    //
    //      We are not really looking for a value, we are looking to see if we find 
    // something that satisfies the predicate
    //
    //      find_if searches for an element for which predicate p returns true.
    //
    // template< class InputIt, class UnaryPred >
    // InputIt find_if( InputIt first, InputIt last, UnaryPred p );
    //                                               ~~~~~^^^^
    //                                                ^   Predicate means that returns true or false
    //                                                | 
    //                                             Unary means that only takes one parameter

    //
    // Complexity: O(n)
    //

    auto is_even = [](int i) -> bool
                //              ~~~~
                //            Returns a bool
                   {
                      return i%2==0;
                   };
    if( auto result = std::find_if(v.begin(), v.end(), is_even);
    //                                                 ~~~~~~~~
    //                                                Predicate (true or false)
    //                                                    ^
    //                           This is where lambdas and functors come into placed 
             result != v.end() )
    {
        std::cout << "Could satisfy is_even: "<< *result << std::endl; // Could satisfy is_even: 12
    }
  
    return 0;
}


