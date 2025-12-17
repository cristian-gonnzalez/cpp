/** C++ Ranges (Part 5 of n) - std::views::keys, values, std::views::elements| Modern Cpp Series Ep. 230
 *
 */
#include <iostream>
#include <print>  // c++23
#include <ranges> // std::views
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>

//
// These are functions of the range library that helps us navigate maps, unordered_maps, tuples, and so on ... 
// where we have keys, values and elements
//

// views::keys
// to be albe to look at something like a map or unorderd-map and able to gather those keys
//
// template< class R >
// using keys_view = ranges::elements_view<R, 0>;                    (1)
// 
// namespace views {
//     inline constexpr auto keys = ranges::elements<0>;             (2)	
// }
//
// Takes a view of tuple-like values (e.g. std::tuple or std::pair), and produces a view with a 
// value-type of the first element of the adapted view's value-type.
//


// views::values
//
//  template< class R >
//  using values_view = ranges::elements_view<R, 1>;                    (1)	(since C++20)
// 
//  namespace views {
//     inline constexpr auto values = ranges::elements<1>;
//  }                                                                   (2)	(since C++20)
// 
// Takes a view of tuple-like values (e.g. std::tuple or std::pair), and produces a view with 
// a value-type of the second element of the adapted view's value-type.
// 


// std::views::elements<N>
//
// Call signature
//    
//  template< ranges::viewable_range R >
//  constexpr ranges::view auto elements<N>( R&& r );
//                                       ^
//                                nth element to access
//
// Accepts a view of tuple-like values, and issues a view with a value type of the Nth element 
// of the adapted view's value-type.

int main() {

    std::unordered_map<std::string, std::string> dictionary{
                                                                {"Cat", "A small animal that says 'meow'"},
                                                                {"Dog", "A small animal that says 'bark'"},
                                                                {"Cow", "A big animal that says 'moo'"}
                                                            };
    
    for(auto& elems: dictionary)
        std::print("{}, ", elems); // ("Cow", "A big animal that says 'moo'"), ("Dog", "A small animal that says 'bark'"), ("Cat", "A small animal that says 'meow'"), 
    std::println();

    for(auto& [k,v]: dictionary)
        std::print("{}->{}, ", k,v); 
    std::println(); // Cow->A big animal that says 'moo', Dog->A small animal that says 'bark', Cat->A small animal that says 'meow', 

    // std::views::keys
    {
        // 
        // Ranges library version of sorting keys without modifying the container
        //
        auto keys_sorted = std::views::keys(dictionary) | 
                            // ~~~~~~~~~~~~~~~~
                            // This returns a view
                            std::ranges::to< std::vector >();
                            // change to std::vector

        std::ranges::sort(keys_sorted);
        for(auto& k: keys_sorted)
            std::print("{}, ", k); 
        std::println(); // Cat, Cow, Dog, 

        // Prints in order
        for(auto& k: keys_sorted)
            std::print("{}->{}, ", k, dictionary[k]); 
        std::println(); // Cat->A small animal that says 'meow', Cow->A big animal that says 'moo', Dog->A small animal that says 'bark',  
    }

    // std::views::values
    {
        for(auto& elem: std::views::values(dictionary) )
            std::print("{}, ", elem); 
        std::println(); // A big animal that says 'moo', A small animal that says 'bark', A small animal that says 'meow', 


    }

    {
        
        std::vector< std::tuple<std::string, std::string, int> > dictionary2{
                                                                {"Cat", "A small animal that says 'meow'", 500},
                                                                {"Dog", "A small animal that says 'bark'", 400},
                                                                {"Cow", "A big animal that says 'moo'", 450}
                                                            };

        
        for(auto& elems: dictionary2)
            std::print("{}, ", elems); 
        std::println();                  // ("Cat", "A small animal that says 'meow'", 500), ("Dog", "A small animal that says 'bark'", 400), ("Cow", "A big animal that says 'moo'", 450), 

        for(auto& [one,two,three]: dictionary2)
            std::print("[{}, {}, {}], ", one,two,three); 
        std::println();                  // [Cat, A small animal that says 'meow', 500], [Dog, A small animal that says 'bark', 400], [Cow, A big animal that says 'moo', 450], 


        
        for(auto& e: std::views::elements<0>(dictionary2) )
            std::print("{}, ", e);  
        std::println();  // Cat, Dog, Cow, 


    }        

    return 0;
}