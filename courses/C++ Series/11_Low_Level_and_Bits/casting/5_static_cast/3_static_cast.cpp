/** C++ Casting: static_cast
 */
#include <iostream>


/*
  static_cast performs compile-time checked conversions and does not use RTTI.

  It can be used with objects, pointers, and references.

  When used for downcasting pointers or references, the programmer must ensure
that the dynamic type is correct; otherwise, the behavior is undefined, since
static_cast does not check what the pointer/reference actually points to at runtime

*/

struct Base
{
    int _bdata{1};

    Base() 
    : _bdata{11}
    {
    }
    virtual ~Base() = default;
    
    virtual void func()
    {
        std::cout << "Base::func() " << _bdata << std::endl;
    }
};

struct Derived : Base
{
    int _ddata{2};

    Derived() 
    : _ddata{22}
    {
    }
    void func() override
    {
        std::cout << "Derived::func() " << _ddata << std::endl;
    }
};


int main()
{
    
    Base* b = new Base;
    Derived* d = new Derived;

    // What static_cast does here:
    //      static_cast<Derived*>(b) does not check whether b actually points to a Derived
    //      It blindly reinterprets the pointer based only on the static type Derived*
    //      This is allowed by the compiler, but not safe
    ( static_cast<Derived*>(b) )->func();  // Base::func() 11
                //          ^                
                //   The object allocated is a Base. As the Base object has a Base vtable.
                // So virtual dispatch uses the vtable of the actual object, not the 
                // pointer type. So the call resolves to: Base::func()
                //
                //   ⚠️  But this result is incidental, not guaranteed. On another compiler, 
                // optimization level, or platform could crash

    d->func();                             // Derived::func() 22


    delete b;
    delete d;
      
    return 0;
}