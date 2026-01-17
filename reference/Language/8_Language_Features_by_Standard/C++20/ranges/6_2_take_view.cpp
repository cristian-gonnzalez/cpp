/** C++ Ranges (Part 6 of n) — std::views::cartesian_product, views::take
 *  Modern C++ Series — Ep. 231
 */

#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include <print>
#include <algorithm> // std::ranges::shuffle
#include <random>

/*

- std::ranges::views::take, std::ranges::take_view:

    A view consisting of the first N elements of another view

Call signature:

template< ranges::viewable_range R >
    requires [ see below ]
constexpr ranges::view auto
    take( R&& r, ranges::range_difference_t<R> count );

*/

int main()
{
    // Random units in a game generator
    std::vector<std::string> names{"Mike", "Merlin", "Arthur"};
    std::vector<int>         health{10,20,30,40};
    std::vector<int>         magic{11,21,31,41};

    {
        auto random_units = std::views::cartesian_product(names, health, magic) 
                            | std::views::take(5)
                            | std::ranges::to<std::vector>();
        for(const auto& unit: random_units)
        {
            std::println( "{}", unit);
        }
        std::println();
        
        /*
        ("Mike", 10, 11)
        ("Mike", 10, 21)
        ("Mike", 10, 31)
        ("Mike", 10, 41)
        ("Mike", 20, 11)
        */

    }

    // ranges::shuffle
    //      Randomly re-orders elements in a range
    {
          std::random_device rd;
        std::mt19937 gen {rd()};

        auto all_units = std::views::cartesian_product(names, health, magic) 
                         | std::ranges::to<std::vector>();
        
        std::ranges::shuffle( all_units, gen);
        
        for(const auto& unit: all_units | std::views::take(5))
        {
            std::println( "{}", unit);
        }

        /*
 
        ("Mike", 10, 21)
        ("Mike", 10, 41)
        ("Mike", 20, 21)
        ("Arthur", 10, 31)
        ("Arthur", 40, 21)
       */
    }
    return 0;
}