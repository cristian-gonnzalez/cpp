/** Mutable
 */
#include <iostream> 

/*
Mutable:
  permits modification of the class member declared mutable even if the 
containing object is declared const

*/

struct Point
{
    // Change 'w' but maintaing the other values unmatable: x, y, z
    void change_w( float w ) const
    //                       ^~~~~ const-correctness
    //                 we dont want to change x, y and z
    //                 But const in member functions makes read-only all member variables
    //               meaning that I cannot change also 'w'
    {
    //  'const' still protects againts modification of the other variables 
    //    _x = 1.0f;
    //    ~~~^~~~~~
    //  error: assignment of member 'Point::_x' in read-only object

        _w = w;
    //  ^~
    // We are able to modify this varibale since it is mutable even though
    // this fucntion is mark as read-only
    }

    float _x{0.0}, _y{0.0}, _z{0.0};
    mutable float _w{1.0}; // used for #d perspective
//  ^~~~~~~
//  allow modification of this variable even if it is const 
};


int main()
{
    Point p{1.0f, 2.0f, 3.0f};
    p.change_w(5.0f);

    std::cout << "{"
              << p._x << ", "
              << p._y << ", "
              << p._z << ", "
              << p._w << "}\n"; // {1, 2, 3, 5}

   return 0;
}