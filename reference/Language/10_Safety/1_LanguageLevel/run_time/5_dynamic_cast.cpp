/** C++ Safety part 1 of n - Language Level Safety
 *  Run-Time
 */

#include <print>
#include <vector>

/*
dynamic_cast

    - Useful to show explicity when you need to cast within hierarchy
    - Note:
        * More safely converts pointers and references to classes in inheritance
        hierarchy
        * Probably better thatn reinterpret_cast
        * Safely converts pointers and references to classes up, down, and sideway along
        the inheritance hierarchy

https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c146-use-dynamic_cast-where-class-hierarchy-navigation-is-unavoidable

*/
struct Base
{
    virtual ~Base() = default;
};

struct Derived: Base
{
};

int main()
{
//    Base* b = new Base;
    Base* b = new Derived;

    Derived* pd = dynamic_cast< Derived* >(b);
    if( pd != nullptr)
    {
        std::println("cast to derived succesfully"); // cast to derived succesfully
    }  
    else {
        std::println("cast to derived failure");
        
    }

  return 0;
}