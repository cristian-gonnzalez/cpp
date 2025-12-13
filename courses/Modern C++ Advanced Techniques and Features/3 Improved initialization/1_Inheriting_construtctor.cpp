/** Inheriting construtctor
 *
 */
#include <iostream>

class B
{
    public:
        B(int b) {};
        B(const std::string& b) {};
};



class D : public B
{
    public:
        // What you normally do is to write all the constructors in your subclass which invoke the parent constructors
        //
        // Now You can indicate a derived class should inherit all constructors from the base class
        using B::B;      // Inherit all B's construct
        //~~~~~~~~          
        // It generates wrapper constructors in D that invokes B constructors like these:
        //
        // D(int i) :B(i) {};
        // D(const std::string& str) :B(str) {};
        //                  
        // NOTE: You can define additional constructor too if you want to                                    
};

/* The compiler will generate this class
class D : public B
{
  
  public: 
  inline D(int b) noexcept(false)
  : B(b)
  {
  }
  
  inline D(const std::basic_string<char> & b) noexcept(false)
  : B(b)
  {
  }
  
};


*/

int main()
{   

    D d1(42);           // Compiler generates D::D(int)
    D s2("hello");      // Compiler generates D::D(const std::string&)

    return 0;
}