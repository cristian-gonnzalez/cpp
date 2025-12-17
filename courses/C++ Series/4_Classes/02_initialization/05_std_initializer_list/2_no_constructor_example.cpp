/** std::initializer_list:
 */ 
#include <iostream>
#include <vector>
#include <initializer_list>

/*
std::initializer_list

        Defined in header <initializer_list>
        template< class T >
        class initializer_list;

  It is a lightweight object with an array of objects of type const T. 
  
  It provides member functions like a size(), begin(), end(), and constructors.
  
  It is constructed when:
        1. a {...} is used to 'list-initialize' an object that has a constructor taking 
        std::initializer_list as a parameter
        2. a {...} is used as the right operand of assignment or as a function call argument, 
        and the corresponding assignment operator/function accepts an std::initializer_list 
        parameter.
        3. a {...} is bound to auto, including in a ranged for loop.

Posible implementataion:

/// initializer_list
  template<class _E>
    class initializer_list
    {
    
    private:                                 [ , , , , ]
      iterator			_M_array; ------------^
      size_type			_M_len; 
     ....
     };

*/

struct UDT
{
    // Remeber, as we provide an overload UDT(int, int, int), the compiler
    // deoes not generate the default constructor, so we need to privied this
    UDT()
    {
        std::cout << "UDT()\n";
    }
    UDT(int a, int b, int c)
    : _data({a,b,c})
    {
        std::cout << "UDT(int, int, int)\n";
    }
  
    void print_data()
    {
        std::cout << "[";
        for(auto& e: _data)
            std::cout << e << ", ";
        std::cout << "]\n";
    }

    private:
        std::initializer_list<int> _data;
};


int main()
{

//    UDT u{1,2,3,4,5,6,7}; // UDT(std::initializer_list<int>)
    //    ^
    // error: no matching function for call to 'UDT::UDT(<brace-enclosed initializer list>)'
    // note: candidate 1: 'UDT::UDT(int, int, int)'}
    // note: candidate 2: 'constexpr UDT::UDT(const UDT&)'
    // note: candidate 3: 'constexpr UDT::UDT(UDT&&)'

    // Because we use the list_initializer syntax, this prevent the narrawing of each element 
//    UDT u2{1, 2.5, 3};    
    //        ^~~
    // error: narrowing conversion of '2.5e+0' from 'double' to 'int' [-Wnarrowing]
    
    UDT u3{1,2,3};                       // UDT(int, int, int)
    
    UDT u4{};             // UDT()

    return 0;
}
