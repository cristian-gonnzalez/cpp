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
 
    return 0;
}