/** Inheritance: Dynamic dispatch
 */
#include <iostream>
#include <memory>

/*    
virtual function specifier: 

  The virtual keyword marks a non-static function as 'virtual function', meaning that this 
behavior can be override in derived classes and calling it will invoke a dynamic-dispatch. 

Dynamic dispatch:

  Also know as virtual function call (virtual call), virtual dispatch or runtime dispatch.
 
  A dynamic dispatch is to be able at run-time to choose the correct function to call. if a Derived 
object is handled using pointer or reference to Base class, a call to a Base virtual function will 
invoke the behavior defined in the Derived class. 

*/

class Base
{
    public:
        Base()
        {
            std::cout << "Base()\n";
        }
        virtual ~Base()
        {
            std::cout << "~Base()\n";
        }
        virtual void func()
    //  ^~~~~~~
    // This member function can be overridden in Derived.
    // Calls through Base* or Base& will use dynamic dispatch.
        {
            std::cout << "Base::func()\n";
        }
};


class Derived : public Base
{
    public:
        Derived()
        {
            std::cout << "Derived()\n";
        }
        ~Derived()
        {
            std::cout << "~Derived()\n";
        }
       // void func() override
        //          ^~~~~~~~ 
        //        We want this function to override in Base class and take
        //      precedent over this member function
        //
        // Note: optional
        //   It is not mandatory to mark a function override but it checks 
        // at compile time that a virtual function with a matching signature 
        // exists in Base. 
        //{
        //    std::cout << "Derived::func()\n";
        //}
};



int main()
{
    {
       std::unique_ptr<Base> up{std::make_unique<Derived>()}; // Base()
//                     ^~~~~                                  // Derived()
//               static type Base

        up->func(); // Derived::func()
        //  ^~
        // At compile time:
        //   - The compiler sees the static type of 'up': Base
        //   - It finds Base::func() and sees if it is virtual
        //   - Because it is virtual, the compiler generates code for dynamic dispatch
        //
        // At run time:
        //   - The program looks up the correct function in the vtable
        //   - It finds Derived::func() and calls it. Otherwise, calls Base::func()


       up->Base::func(); // Derived::func()
 

    }// ~Derived() 
     // ~Base()
      
    // When 'up' goes out of scope, delete Base* is called.
    // The compiler checks Base::~Base() and sees that it is virtual.
    // Therefore dynamic dispatch is used (see up->func).
    //  
    // At run time:
    //   - The program looks up the correct function in the vtable
    //   - It finds Derived::~Derice() and calls it. 
    

    return 0;
}