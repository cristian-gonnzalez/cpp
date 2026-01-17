/** C++ Casting: dynamic_cast
 */
#include <iostream>

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

struct Unrelated
{
    float _udata{3.14f};
    Unrelated()
    : _udata{33.1414f}
    {
    }
    
    void func()
    {
        std::cout << "Unrelated::func() " << _udata << std::endl;
    }
};


int main()
{
    Derived* d = new Derived;

    // C-Style casts are a little wild.
    // You really have to be sure of what you are doing.
    // You migth actually want to do this when using void* for instance
    // but generally, this style cast or reinterpret_cast is when the 
    // programmer really knows what they are doing above the compiler
    ((Unrelated*)d)->func(); // Unrelated::func() 5.88905e-39
    //                                            ^~~~~~~~~~~
    //                                            Undefined behaivour
    ( reinterpret_cast<Unrelated*>(d) )->func(); // Unrelated::func() 5.88905e-39

  
 //   ( static_cast<Unrelated*>(d) )->func();
    // ^~~~~~~~~~~~~~~~~~~~
    // error: invalid 'static_cast' from type 'Derived*' to type 'Unrelated*'

    if( !dynamic_cast<Unrelated*>(d)  )
        std::cout << "Cannot treat 'd' like Unrelated\n"; // Cannot treat 'd' like Unrelated
  
    delete d;
      
    return 0;
}