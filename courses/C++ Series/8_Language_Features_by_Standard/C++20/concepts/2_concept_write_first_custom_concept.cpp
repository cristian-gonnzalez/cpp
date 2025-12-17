/* C++ 20 Concepts - Write your first concept

    A concept is a true or false statement.

*/
#include <iostream>
#include <concepts>


// Identity 'concept'
// Concept with a 'constant expression' (that doesnt even use the T) that always evaluate to false
// Note: this concept will give a compile error since this returns false (constraint not satisfy)
template< typename T >
concept AlwaysFlase=false;
// ^       ^
// kw     concept name

// Identity 'concept'
// Concept with a 'constant expression' (that doesnt even use the T) that always evaluate to true
template< typename T >
concept AlwaysTrue=true;


/* Equivalent
template< typename T >
requires AlwaysTrue<T>
void print( T value )
{
    std::cout << "Print: " << value << std::endl;
}
*/

void print( AlwaysTrue auto value )
{
    std::cout << "Print: " << value << std::endl;
}

// This is a way to look for an interger and an unsigned integer
// Note: The idea is that we can start combining these into our own concept, for ex, a concept
// that check if sth is movable and copyable 
template< typename T >
concept UnsignedIntegrals = std::integral<T> && std::unsigned_integral<T>;

void print_unsigned_integer(UnsignedIntegrals auto value)
{
    std::cout << "Print(UL) : " << value << std::endl;
}


int main() 
{
    print(6);
    
    /* 
    // Althougth this is a positive number, the representation is signed. we need to especify with UL or declare
    // the type
    print_unsigned_integer(42);

<source>:54:27: error: no matching function for call to 'print_unsigned_integer(int)'
   54 |     print_unsigned_integer(42);
      |     ~~~~~~~~~~~~~~~~~~~~~~^~~~
<source>:54:27: note: there is 1 candidate
<source>:42:6: note: candidate 1: 'template<class auto:7>  requires  UnsignedIntegrals<auto:7> void print_unsigned_integer(auto:7)'
   42 | void print_unsigned_integer(UnsignedIntegrals auto value)
      |      ^~~~~~~~~~~~~~~~~~~~~~
<source>:42:6: note: template argument deduction/substitution failed:
<source>:42:6: note: constraints not satisfied
*/
    unsigned int fortyone = 41;
    print_unsigned_integer(fortyone);
    print_unsigned_integer(42UL);
    
    /*
    print_unsigned_integer(-42); // this is not allowed 
                                 // from our concept that we created

   constraints not satisfied
c++/15.1.0/concepts: In substitution of 'template<class auto:7>  requires  UnsignedIntegrals<auto:7> void print_unsigned_integer(auto:7) [with auto:7 = int]':
<source>:52:27:   required from here
   52 |     print_unsigned_integer(-42);
      |     ~~~~~~~~~~~~~~~~~~~~~~^~~~~
/opt/compiler-explorer/gcc-15.1.0/include/c++/15.1.0/concepts:115:13:   required for the satisfaction of 'unsigned_integral<T>' [with T = int]
<source>:36:9:   required for the satisfaction of 'UnsignedIntegrals<auto:7>' [with auto:7 = int]
/opt/compiler-explorer/gcc-15.1.0/include/c++/15.1.0/concepts:115:50: note: the expression '!(signed_integral<_Tp>) [with _Tp = int]' evaluated to 'false'
  115 |     concept unsigned_integral = integral<_Tp> && !signed_integral<_Tp>;  
*/
    return 0;
}