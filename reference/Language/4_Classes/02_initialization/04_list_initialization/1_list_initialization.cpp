/** List-initialization: {} syntax feature 
 */
#include <iostream>

/*
List-initialization:

  Also know as: 

        - 'uniform initialization' (informal name) 
        - curly brace-initilization.

  It is a 'syntax feature' -- not to be confused with std::initializer_lit that is a 
type (a class template). 

  We can initiale an object using curly brace {} and prevent narrowing conversion when 
initializing arithmetic types.  

  List inizialization includes several forms:

        Direct list-init: T obj{arg};
        Copy list-init  : T obj = {arg};
        Value list-init : T obj{};
        Aggregate init  : T obj{1, 2, 3};


  Note:  
    With class type, it is usefull to call the constructor and prevent narrowing. If a
constructor has an std::initializer_list, this will be called.

        UDT type{1,2};  // calls UDT::UDT( std::initilizer_list& ) if exists. Otherwise, call 
                        // UDT::UDT( int, int ) and in both prevent narrowing

        UDT type(1,2);  // Calls the constructor with two parameter UDT::UDT( int, int ) and 
                        // does not prevent narrowing

        int x{5};       // Initizializes a built-in type and prevent narrowing

        std::string s{"hello"};   // Calls std::basic_string<char*>( const char* ) because std::basic_string
                                  // does not contains a constructor with std::intializer_list parameter

        std::vector<int> v{1, 2, 3};  // Calls the constructor std::vector::vector( std::intializer_list& ) 
                                      // and prevent narrowing

*/

class UDT
{
    public:
        UDT(int);
    
    private:
        int _var;
};

UDT::UDT(int i)
: _var{i}
{
    std::cout << "var: " << _var << std::endl;
}


int main()
{
    //   Float value truncated to int: 500 (narrow conversion)
    //     ^~~~~~~~
    UDT u2(500.123f);   // var: 500  
    
    // UDT u3{500.123f};   // ERROR: Calls UDT(int) and check narrowing conversion
    //    ^        ^ 
    // error: narrowing conversion of '5.00122986e+2f' from 'float' to 'int' [-Wnarrowing]
    
    return 0;
}