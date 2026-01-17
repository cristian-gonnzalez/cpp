/** Classes: Default copy construtctor and copy assigment operator
 */

#include <iostream>
#include <string>

/*
  Copy constructor:
    A copy constructor is a special member function that is called when an instance
  of an object is cretaed from another object of the same type.

    If you dont provide one, the compiler will provide defaults for you doing a trivial
  copy of member variables.
  
*/


class Vector
{
  // The compiler provides these defulats if no decalred of 'special member functions'

  //   Implicit generated  
  // Vector()                                  1. Default constructor
  // ~Vector()                                 2. Destructor

  // Vector::Vector(const Vector&)             3. Copy constructor           (FOCUS IN THIS)
  // Vector& operator=(const Vector&);         4. Copy assignment operator   (FOCUS IN THIS)

  // Vector::Vector(Vector&&)                  5. Move constructor
  // Vector& operator=(Vector&&);              6. Move assignment operator 

  public:
    float _x, _y, _z; // Trivial types: we can use the default constructor and destructor
                      // to initializes those.
                      //
                      // built-in types: leaves _x, _y, _z uninitialized (garbage)
};


int main()
{
   // If we want to pass param, we need to define a custom constructor 
   //Vector mike(1.0f,2.0f,3.0f);
   //            ^~~~~~~~~~~~~~
   // error: no matching function for call to 'Vector::Vector(float, float, float)'
 
    Vector v1;
    std::cout << v1._x << " " << v1._y << " " << v1._z << std::endl; // 4.23 2.12 21.3
                                                                     // Garbage
    v1._x = 1.0f;
    v1._y = 2.0f;
    v1._z = 3.0f;

    Vector v2 = v1;
    //        ^
    //   Calls the copy constructor
    //
    // Note: 
    //      The constuctor use smember initializer list cecause the object is being created, 
    // and data members must be initialized, not assigned.
    //
    //      Vector(const Vector& other)
    //      : _x(other._x), _y(other._y), _z(other._z)
    //      {}

    std::cout << v1._x << " " << v1._y << " " << v1._z << std::endl; // 1 2 3
    std::cout << v2._x << " " << v2._y << " " << v2._z << std::endl; // 1 2 3

    Vector v3;

    //   The default copy assignment just assign each variable:
    // 
    // _x = other._x
    // _y = other._y
    // _z = other._z
    //
    //  Which is exactly what you want for trivial types.

    v3 = v1;
    // ^
    // Calls the copy assigment operator since v3 is already constructed
    std::cout << v3._x << " " << v3._y << " " << v3._z << std::endl; // 1 2 3


    return 0;
}

