/** C++ Ranges (Part 3 of n) - views and adaptors (lazy evaluation, ranges::to)
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <print>
#include <ranges> // std::views

// Range adaptors:
//      All range adpaters does turn a range into a view and then we can use those particular views

//
// template< ranges::viewable_range R, class Pred >
// constexpr ranges::view auto filter( R&& r, Pred&& pred );
//           ~~~~~~~~~~~~              ^      ~~~~
//       The return type is            |    Predicate means that returns true or false 
//      another view           Range passed by universal forwadding
//
//     A range adaptor that represents view of an underlying sequence with only the elements that satisfy the predicate.

int main() {

    {
        std::vector v{1,11,5,7,9,3};
        std::println("{}", v);  // [1, 11, 5, 7, 9, 3]

        // Example 1
        auto greater_than_5 = [](auto& elem)
                            {
                                return elem > 5; 
                            };
        std::cout << "[";
        for(auto& e: v | 
                    std::views::filter( greater_than_5 ) )
            std::cout << e << ", ";
        std::cout << "]\n"; // [11, 7, 9, ]

    }

    
    {
        std::vector<std::string> strings{"Mike", "Bob", "Joel", "Igor", "Mary"};

        auto greater_than_3 = [](auto& s)
                            {
                                return s.size() > 3; 
                            };
        auto start_with_M = [](auto& s)
                            {
                                return s.at(0) == 'M'; 
                            };
        
        // Remember your other C++ tools
        namespace rv = std::ranges::views;
        
        // Example 2 -- When you are constantly processing data over and over again (e.g. a game loop, or real-time system)
        // where you don't need to store the results, just process that frame.
        std::cout << "[";
        for(auto& e: strings | rv::filter( greater_than_3 ) )
            std::cout << e << ", ";
        std::cout << "]\n"; // [Mike, Joel, Igor, Mary, ]

        // Example 3 -- For when you want to save the results
        // 'std::ranges::t' saves the result, sort of like a output iterator.
        decltype(strings) filetered_strs = strings | rv::filter( greater_than_3 ) |
                                                     rv::filter( start_with_M ) |
                                                     std::ranges::to<std::vector<std::string> >();
        
        std::println("filetered_strs: {}", filetered_strs);  // filetered_strs: ["Mike", "Mary"]


    }    

    return 0;
}