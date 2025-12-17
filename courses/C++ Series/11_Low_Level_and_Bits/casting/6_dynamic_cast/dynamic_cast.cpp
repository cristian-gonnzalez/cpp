/** C++ Casting: dynamic_cast
 */
#include <iostream>

/*
    Using dynamic_cast to know if a cast if valid if I dont know if the class to convert
is part of my hieracrchy

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
    //   Typically we want a 'dynamic_cast'. This 'only works' with pointer or reference types.
    // The types thmeselves must be polymorphic, i.e. have a 'vtable' (so you need 'virtual')
    // in your class
    {
        Base* b = new Base;
        Derived* d = new Derived;

        // Allowed with static_cast (see example in static_cast) but
        // undifined-behaviour
        ( static_cast<Derived*>(b) )->func();  // Base::func() 11
        
        // Not valid -- dynamic_cast does not allowed to make the cast 
        // (prevents invalid downcasts)
        if( !dynamic_cast<Derived*>(b) )
            std::cout << "Cannot treat 'b' like Derived\n";
        
        // Valid, 'd' is-a type of Base (upcasting)
        if( dynamic_cast<Base*>(d) )
        {
            std::cout << "Treating 'd' like Base\n";

            d->func();            // Derived::func() 22
            d->Base::func();      // Base::func() 11 
            d->Derived::func();   // Derived::func() 22

            // Now that we know it's a valid cast, we could use the specific Base version
            // using static cast to 'have no runtime cost'
            //         ^~~~~~~~~~~
            Base* bp = static_cast<Base*>(d);
            bp->Base::func();
        //    bp->Derived::func();
            //  ^~~~~~~
            // error: 'Derived' is not a base of 'Base'
            

            // dynamic_cast/static_cast does not affect the virtual call
            bp->func(); // Derived::func() 22      
        }
    }
      
     return 0;
}