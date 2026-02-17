/** noexcept, Move Constructors and STL containers behavior
 */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

/*
  Topics:
    1) Are constructors affected by noexcept like normal functions?
    2) What happens if a noexcept constructor throws?
    3) Why do containers prefer noexcept move constructors?
    4) Why do containers copy instead of move if move is not noexcept?
 
  1) Constructors are functions so noexcept applies to constructors too.
     If a constructor is marked noexcept and an exception escapes it:
 
       → std::terminate() is called immediately.
 
    The exception cannot be caught.
 
    This rule applies to:
       - normal functions
       - constructors
       - move constructors
       - destructors (implicitly noexcept by default)
 */

// Move Constructor WITHOUT noexcept
struct MoveMayThrow
{
    MoveMayThrow() = default;

    MoveMayThrow(const MoveMayThrow&)
    {
        std::cout << "Copy constructor\n";
    }

    MoveMayThrow(MoveMayThrow&&)
    {
        std::cout << "Move constructor (may throw)\n";
        // Potentially throwing move
    }
};

/*
If MoveMayThrow is stored inside std::vector:

When vector reallocates:

    - It checks whether move is noexcept.
    - Since it is NOT noexcept,
      vector prefers COPY instead of MOVE.

Reason:
    To preserve the strong exception guarantee.

If moving throws during reallocation,
the container might end up partially modified.

Copying leaves the original elements unchanged.
*/

int main()
{
    std::cout << std::boolalpha 
              << "MoveMayThrow is nothrow move constructible? "
              << std::is_nothrow_move_constructible_v<MoveMayThrow>
              << std::endl; // MoveMayThrow is nothrow move constructible? false


    std::vector<MoveMayThrow> v;
    v.reserve(1);

    std::cout << "add new element\n";
    v.emplace_back();

    std::cout << "add new element\n";
    // Force reallocation
    v.emplace_back(); // Copy constructor

    return 0;
}

/*
- WHY DOES std::vector COPY INSTEAD OF MOVE?

  During reallocation:

    1. New memory is allocated.
    2. Elements are transferred.
    3. Old elements are destroyed.
    4. Old memory is freed.

  If move constructor can throw (move is NOT noexcept):

    - Some elements may already be moved.
    - Some not yet moved.
    - Container may become partially modified.

This violates the strong exception guarantee:
    "If the operation fails, the state remains unchanged."

Therefore:

    If move is NOT noexcept:
        → vector prefers copying

    If move IS noexcept:
        → vector uses move

- KEY RULES:

1. noexcept is a contract:
        If an exception escapes → std::terminate().
2. Constructors obey the same rule.
3. Move constructors should usually be noexcept.
4. Containers rely on noexcept to preserve exception guarantees.
5. If move may throw, copying is often safer than moving.

- DESIGN INSIGHT:

noexcept enables:

    - Better performance
    - Strong exception guarantees
    - Safer container behavior

Mark move constructors noexcept whenever it is logically correct.
*/
