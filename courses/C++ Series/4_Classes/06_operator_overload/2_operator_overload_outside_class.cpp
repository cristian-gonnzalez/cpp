/** Operator overloading: Outside class definition
 */

#include <iostream>
#include <memory>

/** 
Arithmetic operators: https://es.cppreference.com/w/cpp/language/operator_arithmetic.html
Increment/decrement operators: https://es.cppreference.com/w/cpp/language/operator_incdec.html
Comparison operator: https://es.cppreference.com/w/cpp/language/operator_comparison.html

*/

class Vector
{
  public:    

    Vector()                       
    : _x(0.f), _y(0.f), _z(0.f)        
    {                              
    }

    Vector(int x, int y, int z)  // As we defined this constructor, we need to define the  
    : _x(x), _y(y), _z(z)        // default constructor also  
    {                             
    } 


    friend std::ostream& operator<<( std::ostream& os, const Vector& rhs )
    {
        os << "("<< rhs._x << ", " << rhs._y << ", " << rhs._z << ")"; 
        return os;
    }

    friend bool operator==(const Vector& lhs, const Vector& rhs);
//  ~~~~~~
// I made this friend to have access to private member varibles
  
  private:
    float _x, _y, _z;                               
};



//
// Comparison operators
//

// Equal to	a == b	
bool operator==(const Vector& lhs, const Vector& rhs)
{
    // TODO: use fabs() for floats
    return lhs._x == rhs._x &&
           lhs._y == rhs._y &&
           lhs._z == rhs._z; 
}

int main()
{
    // Addition	a + b
    Vector v1(1.f,2.f,3.f);
    Vector v2(1.f,2.f,3.f);

    std::cout << "v1 == v2: " << (v1 == v2) << std::endl; // v1 == v2: 1

    return 0;
}

