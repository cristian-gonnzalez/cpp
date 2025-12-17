/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <array>
#include <type_traits>
#include <utility>

/*
 std::to_array(): (C++20)
    creates a std::array object from a built-in array

*/

int main()
{
    // copies a string literal
    auto a1 = std::to_array("foo");
    static_assert(a1.size() == 4);
 
    // deduces both element type and length
    auto a2 = std::to_array({0, 2, 1, 3});
    static_assert(std::is_same_v<decltype(a2), std::array<int, 4>>);

}