/** C++ Casting: dynamic_cast
 */
#include <iostream>

/*
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
    // Strange scenario:
    //   We have a derived class and it does the rigth sort of thing.
    Derived* d = new Derived;

    ( static_cast<Base*>(d) )->func();  // Derived::func() 22
    //            ^~~~~  ^
    // Upcasting Derived* to Base* using static_cast (always safe).
    //
    // The static type of the expression is Base*, but func() is virtual.
    // Therefore, the call is dispatched at runtime based on the dynamic
    // type of the object.
    //
    // Since the object is actually a Derived, Derived::func() is called.
    
    delete d;
      
    return 0;
}