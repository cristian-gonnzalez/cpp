/** noexcept and Move Constructors
 */

#include <iostream>
#include <vector>
#include <stdexcept>

/*
  If a move constructor is marked noexcept and it throws,
std::terminate() is called immediately.

  There is no stack unwinding beyond that function.

- The rule:
  noexcept is a contract. When the standard library sees:

    T(T&&) noexcept

  it assumes:
    - Moving cannot fail.
    - No exception handling logic is needed.
    - It can use fast paths.
    - It can provide strong exception guarantees.

  If this contract is broken, the only safe option is 
termination.

*/

struct MoveNoexceptThrow
{
    MoveNoexceptThrow() = default;

    MoveNoexceptThrow(const MoveNoexceptThrow&)
    {
        std::cout << "Copy constructor\n";
    }

    MoveNoexceptThrow(MoveNoexceptThrow&&) noexcept
    //                           ^~~~~~~~
    //                   noexcept is a contract:
    //            If an exception escapes → std::terminate().
    {
        std::cout << "Move constructor (noexcept)\n";
        throw std::runtime_error("Move failed");
    //  ^~~~~~~~~
    // warning: 'throw' will always call 'terminate' [-Wterminate]
    }
};

int main()
{

    try
    {
        std::vector<MoveNoexceptThrow> v;
        v.reserve(1);
        v.emplace_back();

        // Force reallocation and calls move constructor
        v.emplace_back(); // terminate called after throwing an instance of 'int'
                        // Program terminated with signal: SIGSEGV
        // NOTE: What happens?
        //   1. Move constructor is called.
        //   2. It throws.
        //   3. Because it is noexcept:
        //         -- std::terminate() is called immediately.
        //   4. The catch block in main is NEVER reached.
    }
    catch (...)
    {
        std::cout << "Caught\n";
    }
    
    return 0;
}

