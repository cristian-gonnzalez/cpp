/** Struct in C++
 */

#include <iostream>

/*
Class declaration:

  In C++, 'class' and 'struct' both define user-defined types.
  
  The default access is:

      class A
      {
        // private:
      };

      struct A
      {
        // public:
      };

  This also holds for inheritance.  

class A 
{
};

struct B : <public> A      If Derived is struct, the default 
{                        inheritance is public.
};


class C : <private> A      If Derived is class, the default
{                        inheritance is private.
};


  Everything else is identical: constructors, methods,
encapsulation, overloading… are all allowed in both.

  Note: C code compatibility
    The keyword 'struct' comes from the C language, where a struct
was simply a block of data (POD: 'Plain Old Data' or 'Piece Of Data'). 
In C:

    - a struct can only contain data members
    - functions that operate on this data are written separately
    - there are no constructors, no methods, no access control

  C++ kept 'struct' for backward compatibili ty, but expanded it
to class functionality.
*/

struct UDT
{
    // Public by default (because this is a struct)
    UDT()
    : _x(0)
    {
    }

    float _x;
};

int main()
{
    UDT u;   // OK: constructor is public
    return 0;
}
