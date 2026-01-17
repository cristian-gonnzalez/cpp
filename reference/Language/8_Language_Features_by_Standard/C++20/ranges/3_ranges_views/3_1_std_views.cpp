/** C++ Ranges (Part 3 of n) - views and adaptors (lazy evaluation, ranges::to)
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <print>
#include <ranges> // std::views

// views and adaptors:
//
//      - Range adaptors turn into views.
//
//      - Range views (std::ranges::views) are 'lazy' ways to access items in a range. This means they are cheap to 
// copy and work with
//
//      What this means is when we have a lazy data structure, we are just looking at one element at a time in a 
// container or that actual range. So we lazily evaluate one thing at a time as we need it versus doing the 
// while entire collection.
//
//      Views are cheaps to work with.


int main() {

    // 
    // Eager vs lay execution
    //
    //      Range algorithms can be 'eagerly evaluated' which means to execute immediately.
    {
        std::vector v1{3,9,7,5,1};

        // Prior to ranges
        std::sort( std::begin(v1), std::end(v1) );
        std::println("{}", v1);             // [1, 3, 5, 7, 9]

        std::vector v2{3,9,7,5,1};

        // With ranges
        std::ranges::sort( v2 );
        std::println("{}", v2);             // [1, 3, 5, 7, 9]

        // The idea with lazily executed is start seeing this syntax:

        std::vector v4{1,1,1,1,5,6,7,8,9,11};

        // Ranges adaptors -- to transform ranges to views 
        auto greater_than_five = v4 | 
        //                          ^
        // The std::views allow for composition with the pip '|' syntax
                                 std::views::filter( [](int i)
                                                     {
                                                        return i > 5;
                                                     } );
        std::cout << "[";
        for(auto& e: greater_than_five)
            std::cout << e << ", ";
        std::cout << "]\n";  // [6, 7, 8, 9, 11, ]

    }
    
    return 0;
}