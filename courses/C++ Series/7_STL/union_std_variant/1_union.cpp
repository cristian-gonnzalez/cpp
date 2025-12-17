/** Unions in C++
 */
#include <iostream>
#include <memory>

/*
Unions (in C++):

  A union in C++ is a special class type that can hold
only ONE of its non-static data members at a time.

  Unions are class types, but with strong restrictions:
    - No base classes
    - No virtual functions
    - No reference data members
    - At most one member may have a default initializer
    - Only one member may be active at a time

  IMPORTANT:
    Reading a member different from the one most recently written
    results in undefined behavior.
*/

// Creating a Union is similar to a class or struct
union U
{
    // variant members
    int   i;       // 4 bytes
    short s;       // 2 bytes
    float f;       // 4 bytes
    // Unions differst from a struct in that it only holds the largest type
    // 
    // Size is at least the size of the largest member and may include padding 
    // for alignment:
    //
    //          sizeof( U ) = sizeof( max(i, s, f) ) + sizeof( padding )
    //
    // Note:
    //   The space is the same (same address is shared between variant members) but
    // each member variable treats value different

    // member function
    void print()
    {
        // ❌ Undefined behaviour unless the active member is known
        // since only the active union member may be read.
        std::cout << "{ "
        //          << "i: " << i << ", "
        //          << "s: " << s << ", "
        //          << "f: " << f 
                  << " }\n";
    }
};

// Creating a Union is similar to a class or struct
union Us
{
    // Creates member variables
    short s;       // 2 bytes
};

int main()
{
    U u1;

    std::cout << "size_of int  : " << sizeof(int) << " bytes\n";   // size_of int  : 4 bytes
    std::cout << "size_of short: " << sizeof(short) << " bytes\n"; // size_of short: 2 bytes
    std::cout << "size_of float: " << sizeof(float) << " bytes\n"; // size_of float: 4 bytes
    std::cout << "size_of U    : " << sizeof(U) << " bytes\n";     // size_of U    : 4 bytes
    std::cout << "size_of Us   : " << sizeof(Us) << " bytes\n";    // size_of Us   : 2 bytes


    // Only the active union member may be read.
    //
    // Activate member 'i'
    u1.i = 50;

    std::cout << u1.i << std::endl; // 50

    // Reading s after writing i is undefined behavior, even if it “works” on your machine.
    //              ^
//    std::cout << u1.s << std::endl; // 50

    u1.i = 50000;
    std::cout << u1.i << std::endl; // 50000

    u1.print(); // { i: 50000, s: -15536, f: 7.00649e-41 }

   return 0;
}