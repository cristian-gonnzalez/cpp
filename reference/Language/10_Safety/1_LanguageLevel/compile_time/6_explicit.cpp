/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
#include <vector>
/*
Safety in C++ Programming: Lenguage Level Features -- compile-time

- explicit constructor

    - The 'explicit' keyword helps avoid 'implicit' (or hidden) conversion that may occur
    when constructing an object.
        * The general recommendation is for 'single argument constructor' to mark them as 
        exolicit.

    https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rc-explicit
    https://en.cppreference.com/w/cpp/language/explicit.html

*/

struct ExplicitPoint2f
{
    explicit ExplicitPoint2f( float value )
    : _x{value}, _y{value}
    {
        std::cout << "ExplicitPoint2f(float)\n";
    }
    explicit ExplicitPoint2f( float x, float y )
    : _x{x}, _y{y}
    {
        std::cout << "ExplicitPoint2f(float, float)\n";
    }    
    explicit ExplicitPoint2f( const ExplicitPoint2f& other )
    : _x{other._x}, _y{other._y}
    {
        std::cout << "ExplicitPoint2f(const ExplicitPoint2f&)\n";
    }

    float _x, _y;
};


struct Point2f
{
    Point2f( float value )
    : _x{value}, _y{value}
    {
        std::cout << "Point2f(float)\n";
    }
    Point2f( float x, float y )
    : _x{x}, _y{y}
    {
        std::cout << "Point2f(float, float)\n";
    }
    Point2f( const Point2f& other )
    : _x{other._x}, _y{other._y}
    {
        std::cout << "Point2f(const Point2f&)\n";
    }

    float _x, _y;
};


int main()
{
    {
        // Copy-initialization allowed
        Point2f p1 = 1.0f;                       // Point2f(float)
        // Direct-initialization from constructor
        Point2f p2(1.0f);                        // Point2f(float)
        // Direct-initialization from constructor
        Point2f p3{1.0f};                        // Point2f(float)
        // Copy-list-initialization: copy-list initialization
        Point2f p4 = {1.0f, 2.0f};               // Point2f(float, float)

        std::cout << p1._x << " " << p1._y << std::endl; // 1 1
        std::cout << p2._x << " " << p1._y << std::endl; // 1 1
        std::cout << p3._x << " " << p1._y << std::endl; // 1 1
        std::cout << p4._x << " " << p1._y << std::endl; // 1 1
    }
    
    {
        // Copy-initialization: Copy-initialization not allowed
        // ExplicitPoint2f p1 = 1.0f;                       // Point2f(float)
        /*
        error: conversion from 'float' to non-scalar type 'ExplicitPoint2f' requested
            ExplicitPoint2f p1 = 1.0f;
                                 ^~~~
        */
        // Direct-initialization from constructor
        ExplicitPoint2f p2(1.0f);                        // Point2f(float)
        // Direct-initialization from constructor
        ExplicitPoint2f p3{1.0f};                        // Point2f(float)
        // Copy-list-initialization: Not allowed copy-list initialization 
        //ExplicitPoint2f p4 = {1.0f, 2.0f};               // Point2f(float, float)
        /*
        error: converting to 'ExplicitPoint2f' from initializer list would use explicit constructor 'ExplicitPoint2f::ExplicitPoint2f(float, float)'
         ExplicitPoint2f p4 = {1.0f, 2.0f};
                                         ^
        */
        //std::cout << p1._x << " " << p1._y << std::endl; // 1 1
        std::cout << p2._x << " " << p1._y << std::endl; // 1 1
        std::cout << p3._x << " " << p1._y << std::endl; // 1 1
        //std::cout << p4._x << " " << p1._y << std::endl; // 1 1
    }
 
    return 0;
}