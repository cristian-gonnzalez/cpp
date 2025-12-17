/** Inheritance: Qualified name lookup
 */
#include <iostream>
#include <memory>


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
};



int main()
{
    {
       std::unique_ptr<Base> up{std::make_unique<Derived>()}; // Base()
                                                              // Derived()

        up->func();                                          // Derived::func()
        up->Base::func();                                    // Base::func()
        //      ^^
        //   If we use qualified name lookup (scope resolution operator) 
        // then virtual function call is suppressed (resolved at compile-time) 

        // qualified name lookup only work with static types since it is done 
        // at compile-time
        up->Derived::func();   // ERROR
        //   ^~~~
        // error: 'Derived' is not a base of 'Base'
       
    }// ~Derived() 
     // ~Base()   

    return 0;
}