/** C++ Ranges (Part 4 of n) - transform and drop_while | Modern Cpp Series Ep. 229
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <print>
#include <ranges> // std::views


// transform:
//      a view of a sequence that applies a transformation function to each element

// Call signature:
// 
//  template< ranges::viewable_range R, class F >
//  constexpr ranges::view auto transform( R&& r, F&& fun );
//                                                    ~~~
//                                               Function call
// 
//  template< class F >
//  constexpr /*range adaptor closure*/ transform( F&& fun );
// 

// drop_while: 
//      a view consisting of the elements of another view, skipping the initial subsequence 
// of elements until the first element where the predicate returns false
//
// Call signature:
// 
//  template< ranges::viewable_range R, class Pred >
//  constexpr ranges::view auto drop_while( R&& r, Pred&& pred );
// 
//  template< class Pred >
//  constexpr /*range adaptor closure*/ drop_while( Pred&& pred );
//

int main() {

    std::vector v{1,1,1,1,3,4,5,7,8};
    std::println("{}", v);  // [1, 1, 1, 1, 3, 4, 5, 7, 8]
    

    // we can define our lambda function in the same line just to show that it works
    // NOTE: this is hard to read 
    {
        std::cout << "[";
        for(auto e: v | std::views::transform( [](auto e)
                                                {
                                                   return e*2; 
                                                } ) )
            std::cout << e << ", ";
        std::cout << "]\n";  // [2, 2, 2, 2, 6, 8, 10, 14, 16, ]
    }



    auto double_value_f = [](auto e)
                          {
                            return e*2; 
                          };

    std::cout << "[";
    for(auto e: v | std::views::transform( double_value_f ) 
                  | std::views::transform( double_value_f ) )
        std::cout << e << ", ";
    std::cout << "]\n";  // [4, 4, 4, 4, 12, 16, 20, 28, 32, ]



    auto less_than_2 = [](auto e)
                        {
                            return e < 2;
                        };                       

    
    // [1, 1, 1, 1, 3, 4, 5, 7, 8]
    //  ^  ^  ^  ^
    // we are going to drop these elems
    
    std::cout << "[";
    for(auto e: v | std::views::drop_while( less_than_2 ) 
                  | std::views::transform( double_value_f ) )
        std::cout << e << ", ";
    std::cout << "]\n";  // [6, 8, 10, 14, 16, ]




    return 0;
}