/** Operator overloading: Inside class definition
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

    //                        
    // Arithmetic operators
    //

    // Addition	a + b
    Vector operator+(const Vector& rhs) const
                                   //   ^~~~~
                                   // member variables are read-only
    {
        Vector r( _x + rhs._x, 
                  _y + rhs._y,
                  _z + rhs._z );
        return r;
    }

    //
    // Increment operators
    //

    // pre-increment	++a	
    Vector& operator++()
    {
        ++_x;
        ++_y;
        ++_z;
        return *this;
    }

    // post-increment	a++	
    Vector operator++(int i)
    {
        Vector old = *this;
        ++(*this);
        return old;
    }

    //
    // Comparison operators
    //

    // Equal to	a == b	
    bool operator==(const Vector& rhs) const
    {
        // TODO: use fabs() for floats
        return _x == rhs._x &&
               _y == rhs._y &&
               _z == rhs._z; 
    }


    friend std::ostream& operator<<( std::ostream& os, const Vector& rhs )
    {
        os << "("<< rhs._x << ", " << rhs._y << ", " << rhs._z << ")"; 
        return os;
    }

  private:
    float _x, _y, _z;                               
};

int main()
{
    // Addition	a + b
    Vector v1(1.f,2.f,3.f);
    Vector v2(3.f,2.f,1.f);

    Vector v3 = v1 + v2;
    //          ~~ ^ ~~
    // error: no match for 'operator+' (operand types are 'Vector' and 'Vector')
    std::cout << "v3: " << v3 << std::endl; // v3: (4, 4, 4)
    
    // pre-increment
    Vector v4 = ++v3;
    std::cout << "v3: " << v3 << std::endl; // v3: (5, 5, 5)
    std::cout << "v4: " << v4 << std::endl; // v4: (5, 5, 5)

    // post-increment
    //
    // old = v3     → old = (5, 5, 5)
    // ++v3         → x = (6, 6, 6)
    // returns old  → returns (5, 5, 5) but v3 is (6, 6, 6)
    Vector v5 = v3++;
    std::cout << "v3: " << v3 << std::endl; // v3: (6, 6, 6)
    std::cout << "v5: " << v5 << std::endl; // v4: (5, 5, 5)

    std::cout << "v5 == v4: " << (v5 == v4) << std::endl; // v5 == v4: 1

    return 0;
}

