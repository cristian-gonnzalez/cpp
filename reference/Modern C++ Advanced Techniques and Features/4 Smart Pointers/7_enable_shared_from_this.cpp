/** Using enable_shared_from_this
 * 
 *     Creates a shared_ptr out of a 'this' pointer
 *
 */
#include <iostream>
#include <memory>
  
struct Widget;

void some_api( const std::shared_ptr<Widget>& sp );

// 'std::enabled_shared_from_this' is a  class that has a mehtod called 'shared_from_this()'. When you call that method, you will
// get back is a shared_ptr based on the current object.
//
// - Defines a method named shared_from_this()
// - Returns a std::shared_ptr to the current object

// Purpose:
//
//  - Imagine you have an object that is currently managed by a std::shared_ptr
//  - You can ask the object to generate an additional std::shared_ptr that shares the RC.
//
// Note: If a class uses shared_from_this(), it must only be created as part of a std::shared_ptr.
struct Widget : public std::enable_shared_from_this<Widget>
{
    void some_method()
    {
        // I cannot pass  'some_api( this )' since the som_api needs a shared_ptr
        //
        some_api( shared_from_this() );
    
    
        //  |    |
        //  |____| <--------- sp
        //   this
        //    ^
        //    |
        // This is the original Widget object,  shared_from_this() will give us back a shared_ptr sp participating in the 
        // reference counting
    
    }
};

void some_api( const std::shared_ptr<Widget>& sp )
{

}

int main()
{

    {
        // ✅ Correct: allocated and owned by shared_ptr
        auto w = std::make_shared<Widget>();
        w->some_method();   // OK

        // - enable_shared_from_this is initialized
        // - shared_from_this() returns a valid shared_ptr
        // - Reference counting works correctly
    }
    {
        // ❌ Incorrect: stack-allocated object
        Widget w;
        w.some_method();    // ❌ Undefined behavior (throws in C++17+)

        // - No shared_ptr owns w
        // - Internal weak_ptr is empty
        // - shared_from_this():
        //      -- C++17 and later → throws std::bad_weak_ptr
        //      -- Pre-C++17 → undefined behavior
    }
    {
        // ❌ Incorrect: raw new without shared ownership
        Widget* w = new Widget();
        w->some_method();   // ❌ same problem

        // Still no shared_ptr, still invalid.
    }
 
    return 0;
}