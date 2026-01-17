/** C++ Casting: static_cast vs dynamic_cast
 */
#include <iostream>

/*
Which C++ 'feature' would you use to cast a pointer to class B into a derived class D? 

The answer is:
    You have to make a dynamic_cast to make a runtime check to ensure that the dynamic type 
of the object pointed to is Derived so that Derived-specific behavior can be accessed safely
    
    The cost is that you pay a cost to make tis runtime check (rtti).

    Once you are in a secure scope where you know cast is safe since you have done
dynamic_cast with an if statement, you could use static_cast to not pay that cost.

    static_cast is safe for primitive types when the developer knows the conversion is valid.
    
    The general use is to show intention. 
    
    static_cast works well with objects declared by value and some ocasion with pointer and 
refereces but you must know before hand it will work.

*/

struct Base
{
    virtual ~Base() = default;

    virtual void func()
    {
        std::cout << "Base::func()\n";
    }
};

struct Derived : Base
{
    void func() override
    {
        std::cout << "Derived::func()\n";
    }
};


int main()
{
    {
        // If b points to an object whose dynamic type is Derived, we can cast.
        // But in this case it does not point to a Derived object
        //            ^~~~
        Base* b = new Base;
        
        if( dynamic_cast<Derived*>(b) )
        {
            std::cout << "Treat 'b' like Derived\n";

            Derived* dp = static_cast<Derived*>(b);
            dp->func();
        }
        else {
            std::cout << "CANNOT treat 'b' like Derived\n"; // CANNOT treat 'b' like Derived 
        
        }
    }
    {
        // if b is points to a dynamic type for Derived, we can cast.
        // In this case it is pointing to Derived type
        //            ^~~~~~~
        Base* b = new Derived;
        
        if( dynamic_cast<Derived*>(b) )
        {
            std::cout << "Treat 'b' like Derived\n";      // Treat 'b' like Derived

            Derived* dp = static_cast<Derived*>(b);
            dp->func();                                   // Derived::func()
        }
        else {
            std::cout << "CANNOT treat 'b' like Derived\n"; 
        
        }
    }
    return 0;
}