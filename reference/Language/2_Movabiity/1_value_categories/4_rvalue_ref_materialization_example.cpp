/** rvalue references
 */

#include <iostream>

struct Foo
{
    Foo(std::string s)
    : _s{s}
    {
        std::cout << "Foo()\n";
    }
    ~Foo()
    {
        std::cout << "~Foo()\n";
    }
    Foo(const Foo& other)
    : _s{other._s}
    {
        std::cout << "Foo(const Foo& other)\n";
    }
    Foo& operator=(const Foo& other)
    {
        std::cout << "Foo copy assignment operator\n";
    
        if( this != &other )
            _s = other._s;
        
        return *this;
    }
    Foo operator+(const Foo& other)
    {
        std::cout << "Foo + operator\n";

        Foo r = _s + other._s;
        return r; // prvalue of type Foo
    }

    std::string _s{};
};

int main()
{   
    Foo f1 = std::string("mike");                    // Foo()   -> f1
    Foo f2 = std::string("a really long str");       // Foo()   -> f2
 
    // This forces temporary materialization of the prvalue returned by f1 + f2.
    Foo&& f3 = f1 + f2;                              // Foo + operator
         //    ~~~~~~~                               // Foo()    -> temp
         //  returns a prvalue Foo 
         // materializes the prvalue into a temporary object

   return 0;

}  // ~Foo() -> f1
   // ~Foo() -> f2
   // ~Foo() -> temp
 