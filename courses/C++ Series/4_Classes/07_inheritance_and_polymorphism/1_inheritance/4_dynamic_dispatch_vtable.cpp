/** Dynamic dispatch: VTable (Virtual Table)
 */
#include <iostream>
#include <memory>

/*
  The vtable (Virtual Table) is a table of function pointers generated
by the compiler when a class contains at least one virtual function.

  The compiler adds a hidden pointer as member of the class called the vptr  
to point to the vtable.

  The vtable has one entry per virtual function accessible to the class.
Each entry points to the most-derived override function that should be called
for that object at run-time.

  Dynamic dispatch works by:
    1. Reading the object's vptr
    2. Indexing into the vtable
    3. Calling the correct function (Base or Derived)
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
        {
            std::cout << "Base::func()\n";
        }

    // Implicity generated                                                   vtable Base
    //                                                                    ---------------  
    // private:           ---------------------------------------------> | Base::~Base() | 
    //    vtable* _vptr{ * };                                            | Base::func()  |
    //            ^~~~~                                                   ---------------
    //    It is a hidden pointer that is added by the compiler            
    // as a member of the class to point to the VTable of that class
    // _vptr  is added only if the class has or inherits a virtual 
    // function.

/*
    (gdb) p base_obj
$1 = {_vptr.Base = 0x555555557d48 <vtable for Base+16>}

    (gdb) info vtbl base_obj
    vtable for 'Base' @ 0x555555557d48 (subobject @ 0x7fffffffdd80):
[0]: 0x555555555308 <Base::~Base()>
[1]: 0x555555555342 <Base::~Base()>
[2]: 0x555555555372 <Base::func()>
*/

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
        void func() override
        {
            std::cout << "Derived::func()\n";
        }
        
    // Implicity generated                                                vtable Derived
    //                                                                  --------------------- 
    // private:          |-------------------------------------------> | Derived::~Derived() |
    //    vtable* _vptr{ * };                                          | Derived::func()     |
    //                                                                  --------------------- 
/*                                        
    (gdb) info vtbl *up
    vtable for 'Base' @ 0x555555557d20 (subobject @ 0x55555556b6c0):
[0]: 0x555555555408 <Derived::~Derived()>
[1]: 0x55555555544e <Derived::~Derived()>
[2]: 0x55555555547e <Derived::func()>

    (gdb) p *up
    $2 = {_vptr.Base = 0x555555557d20 <vtable for Derived+16>}
*/
};


int main()
{
    {
       // Create a Base* that can point to 'Base' or 'Derived', anythhing
       // that 'is-a'.
       // We also have a vtbl taht is created for the class of object
       std::unique_ptr<Base> up{std::make_unique<Derived>()}; // Base()
                                                              // Derived()

        // When we call a member function, the vtal points us to the correc
        // member function
        //
        // Dynamic dispatch:
        //      up->_vptr -> Derived vtable -> Derived::func()
        up->func();                                          // Derived::func()
       
    }// ~Derived() 
     // ~Base()   

    {
       std::unique_ptr<Base> up{std::make_unique<Base>()}; // Base()
     
       // Note:
       //   Since the dynamic type is also Base, the Base vtable is used
       // and Base::func() is called.
       //
       // Dynamic dispatch:
       //       up->_vptr -> Base vtable -> Base::func()
       up->func();                                          // Base::func()
       
    }// ~Base()   

    return 0;
}