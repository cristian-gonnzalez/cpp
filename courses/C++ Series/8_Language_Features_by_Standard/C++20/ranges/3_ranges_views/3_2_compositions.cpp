/** C++ Ranges (Part 3 of n) - views and adaptors (lazy evaluation, ranges::to)
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <print>
#include <ranges> // std::views



int main() {

    std::vector<std::string> strings{ "Mike","Bob","Miguel","Marissa","Mary" };

    auto start_with_M = [](std::string& s) { return s[0] == 'M'; };
    auto longer_than_4 = [](std::string& s) { return s.length() > 4; }; 

    // Composition with range views
    std::cout << "[";
    for(auto& e: strings | 
                    std::views::filter( start_with_M ) | 
                    std::views::filter( longer_than_4 ) )
        std::cout << e << ", ";
    std::cout << "]\n"; // [Miguel, Marissa, ]
    

    std::vector<std::string> collect = strings | 
                    std::views::filter( start_with_M ) | 
                    std::views::filter( longer_than_4 ) |
                    std::ranges::to<std::vector>();
    //              ~~~~~~~~~~~~~~~
    // Sometimes we may want to 'save the result' into a collction 
    // (This is similar to where we used 'back_inserter' for the output iterators)
    //
    // For that purpose we have std::ranges::to. This writes out the value (in this case, a push_back)
    // to the vector of strings.
    
    std::println("collected: {}", collect);                  // collected: ["Miguel", "Marissa"]
   

    return 0;
}