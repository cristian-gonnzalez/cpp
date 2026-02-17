/** noexcept, Move Constructors and STL containers behavior
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>


// Move Constructor WITH noexcept
struct MoveNoexcept
{
    MoveNoexcept() = default;

    MoveNoexcept(const MoveNoexcept&)
    {
        std::cout << "Copy constructor\n";
    }

    MoveNoexcept(MoveNoexcept&&) noexcept
    {
        std::cout << "Move constructor (noexcept)\n";
    }
};

/*
Now std::vector can safely move elements during reallocation
because move is guaranteed not to throw.

This allows:
    - Faster reallocation
    - True move semantics
    - Strong exception guarantee preserved
*/

int main()
{
    std::cout << std::boolalpha 
              << "MoveNoexcept is nothrow move constructible? "
              << std::is_nothrow_move_constructible_v<MoveNoexcept>
              << std::endl; // MoveNoexcept is nothrow move constructible? true

    std::vector<MoveNoexcept> v;
    v.reserve(1);
    v.emplace_back();

    // Force reallocation
    v.emplace_back(); // Move constructor (noexcept)

    return 0;
}

