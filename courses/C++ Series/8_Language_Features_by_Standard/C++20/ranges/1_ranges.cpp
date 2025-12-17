/** C++ Ranges (Part 1 of n) - Problems they solve (sort, ranges::for_each) (C++20)
 *
 */

// Note: RanvesV3 is a library for c++14 and beyond 

#include <ranges>
#include <print>
#include <vector>
#include <algorithm>


int main()
{
    std::vector v{1,2,3,4,7,9, 15, 11, 13};


    std::print("[");
    for(auto e: v)
    {
        std::print("{}, ", e);
    };
    std::println("]"); // [1, 2, 3, 4, 7, 9, ]


    auto print_v = [](auto e)
                  {
                    std::print("{}, ", e);
                  }; 

    // Old style algorithm way for_each
    std::print("[");
    std::for_each( std::begin( v ), std::end( v ), 
                   print_v );
    std::println("]"); // [1, 2, 3, 4, 7, 9, ]
    
    // Sorts the container (a 'container' is a range with 2 iterators)
    std::ranges::sort(v);
    std::print("[");
    std::ranges::for_each( v, print_v );
    std::println("]"); // [1, 2, 3, 4, 7, 9, 11, 13, 15, ]



	return 0;
}

