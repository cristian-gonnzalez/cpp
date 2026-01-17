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
    UDT(int a, int b, int c)
    : _data({a,b,c})
    {
        std::cout << "UDT(int, int, int)\n";
    }
    UDT(std::initializer_list<int> data)
    : _data(data)
    {
        std::cout << "UDT(std::initializer_list<int>)\n";
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
    UDT u{1,2,3,4,5,6,7}; // UDT(std::initializer_list<int>)
    u.print_data();       // [1, 2, 3, 4, 5, 6, 7, ]

    UDT u2{};             // UDT(std::initializer_list<int>)

    // Using parantheses, the compiler thinks it is a 'function declaration' 
    // for a function named u3 that takes no parameters and returns a UDT.
    UDT u3();
    //    ^~            
    // warning: empty parentheses were disambiguated as a function declaration [-Wvexing-parse]

    // If we pass 3 paramerer and because of the {} syntax, it prefers UDT(std::initializer_list<int>)
    UDT u4{1,2,3};                       // UDT(std::initializer_list<int>)
    
    // If we pass 3 paramerer and use (), it explicity call UDT(int,int,int)
    UDT u5(1,2,3);                       // UDT(int, int, int)

    // Because we use the list_initializer syntax, this prevent the narrawing of each element 
    // of the std::initializer-list 
//    UDT u6{1, 2.5, 3};    
    //        ^~~
    // error: narrowing conversion of '2.5e+0' from 'double' to 'int' [-Wnarrowing]
        
    return 0;
}
