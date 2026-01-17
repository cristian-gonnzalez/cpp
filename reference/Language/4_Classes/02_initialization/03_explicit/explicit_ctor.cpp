/** Explicit ctor
 */
#include <iostream>

/*
 explicit specifier:
    Specifies that a constructor or conversion function (casting) or deduction guide -- CTAD -- (since C++17) 
  is explicit, that is, it cannot be used for implicit conversions and copy-initialization.

    For ex: adding to your constructors, it forbids 'implicit conversion' when constructing the object
                                                     ^~~~~~~~~~~~~~~~~~~       ^~~~~~~~~~~~

  Note: 
      explicit works with Direct-initialization (construct using constructor signature).

          UDT o(arg); // Direct call

      Copy-initialization (uses operator = when constructing) requires 'implicit conversion'.

          UDT o = arg;  -> The compiler makes an 'implicit conversion' to 
                        direct-initialization  UDT o(arg);       
*/

class UDT
{
    public:
        explicit UDT(int);
     // ~~~~~~~~     ^~~
     // The explicit is not protecting against implicit conversion in the constructor's params
     // (i.e. UDT u2(500.123f); )


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
    //  Direct-initialization
    UDT u1(500);        // var: 500
    
    UDT u2(500.123f);   // var: 500  
    //    ~~~~~~~~~~
    //  explicit is not protecting against conversion in this sentence
    //
    // Note: 
    //  explicit only blocks implicit conversion to the class type.
    //  It does NOT block: implicit conversions of the constructor’s parameters
    //
    //  In this line, you are 'explicitly calling the constructor'.

    {
        
        // Using 'copy-initialization' 
        UDT u4 = 500.123f;
        //       ^~~~~~~~
        // error: conversion from 'float' to non-scalar type 'UDT' requested

        //   This fails since we are not calling the constructor explicity as:
        //
        //      UDT u4( 500.123f )
        //
        //   Using copy-initizalization (T u = param), the compiler tries to implicity convert 
        // from float to UDT: 
        //
        //                           (Direct-initialization)
        //      UDT u4 = 500.123f  ->  UDT u4(500.123f)
        //               ^~~~              ^~~~~~~~~~~~
        //               float     to        UDT
        //
        //   But it is not failing becuase of the float type, it is failing since conversions
        // are forbidden.  
            
    }
     
    {
        UDT u5 = 500;
        //       ^~~
        // error: conversion from 'int' to non-scalar type 'UDT' requested
    
        //   Again, since you are not calling directly the constructor, UDT u5(500)
        // it fails since the compiler tryies to implicit convert from copy-initialization
        // to direct-initialization
        //
        //                         (Direct-initialization)
        //      UDT u5 = 500;   ->     UDT u5(500)
        //               ^~~~              ^~~~~~~
        //               int     to         UDT
        //                
        //   'explicit' is protecting from conversion from int to UDT 
    
    }

    {
        // Note: List-initialization 
        //   Also know as 'uniform initialization' (informal name).
        //
        //   It means initializing an object using braces {} prevents narrowing conversion.
        
        //   Using direct-initialization works since we are explicity calling the constructor but
        // as we are using 'uniform-initialization', it fails 
        UDT u3{500.123f};
        //    ^        ^
        // error: narrowing conversion of '5.00122986e+2f' from 'float' to 'int' [-Wnarrowing]   
    }
    
    return 0;
}