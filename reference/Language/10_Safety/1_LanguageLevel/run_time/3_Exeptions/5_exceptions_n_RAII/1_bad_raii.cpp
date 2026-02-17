/** Constructor Exceptions and RAII
 */
#include <iostream>
#include <memory>
#include <stdexcept>

/* 
Topic:
       - What happens if a constructor throws?
       - Is the destructor called?
       - Can this cause memory leaks?
 
Key Rule:
   If a constructor throws, the destructor of that object
is NOT called because the object was never fully constructed.

   However, all fully constructed base classes and members
ARE destroyed during stack unwinding.

   Therefore:
       Owning raw pointers inside a constructor body is dangerous.

   Proper RAII requires resource ownership to belong to
a fully constructed subobject.

*/

struct BadIntScoped
{
    BadIntScoped(size_t size)
    : _i{ new int[size] }
//    ^~
// (1) Heap memory allocated
    {
        std::cout << "BadIntScoped()\n";
        std::cout << "Memory allocated\n";

        throw std::runtime_error("Constructor failed!");  // (2) Exception thrown
    }

    ~BadIntScoped()
    {
        std::cout << "~BadIntScoped\n";
        delete[] _i;  // ❌ This will NEVER run if constructor throws
    }

    int* _i{nullptr};
};

/*
What happens here?

1. Memory for BadIntScoped object is allocated.
2. _i is initialized and allocates heap memory.
3. Exception is thrown.
4. Object is NOT fully constructed so destructor ~BadIntScoped() is NOT called.
5. The allocated array is leaked.

Important:
    The language only destroys fully constructed subobjects.    
    A raw pointer is not a resource-managing object.
*/

int main()
{
    try
    {
        BadIntScoped bad(10);  // BadIntScoped
                               // Memory allocated

    } // ❌ Destructor is not called when object goes out of scope since it was not fully 
      // constructed but we allocated memory that was not freed. We have a memory leak
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << "\n"; // Caught: Constructor failed!

    }

    return 0;
}
