/** Inheritance: Static dispatch 
 */
#include <iostream>
#include <memory>

/*    
  Inheritance models an “is-a” relationship:
                          
        ┌────────┐
        │  Base  │
        └────────┘         Derived class 'is-a' type of Base
             ↑                 
        ┌─────────┐
        │ Derived │
        └─────────┘
*/

class Base
{
    public:
        Base()
        {
            std::cout << "Base()\n";
        }
        ~Base()
        {
            std::cout << "~Base()\n";
        }
        void func()
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
        void func()
        {
            std::cout << "Derived::func()\n";
        }
};



int main()
{
    // Static type
    {
        Base obj;     // Base
        obj.func();   // Base::func()

    }   // ~Base()

    // Static type
    {        
        Derived obj;  // Base()
                      // Derived()
        obj.func();   // Derived::func()

    } // ~Derived()
      // ~Base()

    
    // Static vs dynamic type
    {
//                                              Dynamic type
//                                                ^~~~~~~
        std::unique_ptr<Base> up{std::make_unique<Derived>()}; // Base()
//                     ^~~~~                                   // Derived()
//               static type Base

        up->func(); // Base::func()
    //      ^~
    // At compile time:
    //   - The compiler sees the static type of 'up': Base
    //   - It looks for Base::func() and sees if it is virtual
    //   - As Base::func is non-virtual, it makes a static dispatch 
    //   (bind call at compile.time) calling Base::func()


    } // ~Base()
//       ^~~~~~~
// At compile time:
//   - The compiler sees the static type of 'up': Base
//   - It looks for Base::~Base() and sees if it is virtual
//   - As Base::~Base is non-virtual, it makes a static dispatch 
//   (bind call at compile-time) calling only Base::~Base()
//
// IMPORTANT: Skkiping a destructor is un-defined behaviour

    return 0;
}