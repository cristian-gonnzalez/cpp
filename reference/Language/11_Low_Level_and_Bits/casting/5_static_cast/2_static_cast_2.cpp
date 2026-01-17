/** C++ Casting: static_cast with object slicing
 */
#include <iostream>

/*
  This example demonstrates static_cast with objects declared by value
and highlights object slicing and lack of polymorphism.

Terminology clarification:

  Concrete type (informal term):
    Refers to an object declared by value (not through a base pointer or reference),
  where behavior is resolved at compile time and no virtual dispatch occurs.

        Base b;        // Declared by value
        Derived d;

  Concrete class
    A concrete class is a class that is not abstract so it can be instantiated

        struct A {
            virtual void f() = 0; // abstract
        };

        struct B : A {
            void f() override {}  // concrete
        };

        struct C : B {            // also concrete
        };

    Both B and C are concrete classes, even though only C is at the bottom
    of the inheritance hierarchy.

*/

struct Base
{
    int _bdata{1};

    Base() 
    : _bdata{11}
    {
    }
    void func()
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
    void func()
    {
        std::cout << "Derived::func() " << _ddata << std::endl;
    }
};


int main()
{

    {
        // Objects declared by value
        //
        //   Using static_cast on objects declared by value causes object slicing.
        //
        // Note:
        //   This is NOT polymorphism because all behavior is resolved using static types.
        Derived d;
        Base b;

        d.func(); // Derived::func() 22
        b.func(); // Base::func() 11

        // Treat 'd' as a Base 
        ( static_cast<Base>(d) ).func();  // Base::func() 11
        // Object slicing occurs:
        //   - A temporary Base object is copy-constructed
        //   - The Derived part (_ddata) is discarded
        //   - No dynamic dispatch is involved


        // Treating 'base' as derived not safe though
        // We need pointers for this (and polymorphism)
    //    ( static_cast<Derived>(b) ).func();  // Base::func() 11
        //                     ^ 
        // no matching function for call to 'Derived::Derived(Base&)'
    
    }
    {
        // STILL NOT POLYMORPHISM:
        //   Even though pointers are used, there are no virtual functions,
        // so function calls are resolved at compile time.

        // Note:
        //   Allowable with pointers to do a static_cast, but no run-time checks to see
        // if this is sth we should be able to do.    
        Base* b = new Base;
        Derived* d = new Derived;

        // ❌ Undefined behavior:
        // static_cast performs no runtime check.
        
        // These classes are not polymorphic (i.e. concrete classes without vtable)
        // then we have some undefined behavior...
        // b does not actually point to a Derived object.
        ( static_cast<Derived*>(b) )->func();  // Base::func() 0
        d->func();                             // Derived::func() 22

        delete b;
        delete d;
    }
      
     return 0;
}