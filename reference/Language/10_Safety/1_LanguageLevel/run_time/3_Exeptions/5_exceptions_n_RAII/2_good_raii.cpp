/** Constructor Exceptions and RAII
 */

#include <iostream>
#include <memory>
#include <stdexcept>

struct GoodIntScoped
{
    GoodIntScoped()
    : _i{ std::make_unique<int[]>(10) }  // Resource acquired by RAII member
    {
        std::cout << "GoodIntScoped\n";
        throw std::runtime_error("Constructor failed!");
    }

    std::unique_ptr<int[]> _i{nullptr};
//  ^~~~~~~~~~~~~~~
//  std::unique_ptr is a fully constructed member. No manual destructor needed. 
//
//  If constructor throws:
//          1. _i has already been constructed.
//          2. Stack unwinding begins.
//          3. _i's destructor runs automatically.
//          4. Memory is released safely.
};


int main()
{
    try
    {
        // If a constructor throws:
        // 
        // ❌ The destructor of that object is NOT called.
        // ✅ Fully constructed members ARE destroyed.
        // ✅ Fully constructed base classes ARE destroyed.
        // 
        // Therefore:
        //     - Never own raw pointers directly.
        //     - Use RAII types like:
        //           std::unique_ptr / std::shared_ptr
        //           std::vector / std::string / std::array
        // 
        // Golden Rule:
        //   Resource ownership must belong to a fully constructed subobject.
        //   This guarantees exception safety during stack unwinding.
        // 
        GoodIntScoped good;  // GoodIntScoped
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << "\n"; // Caught: Constructor failed!
    }

    return 0;
}

