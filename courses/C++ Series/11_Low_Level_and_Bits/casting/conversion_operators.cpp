/**  User-defined conversion (conversion operators)
 * 
 *  Treats one data type as another 
 * 
 *  In this example, what we want to  be able to do is construct a Pair from a Triple.
 *  It happens sometimes that in graphics programming where you have a three-dimensional 
 *  vector and you need to go down to two-dimensional vector so you could just chop off 
 *  the third component. 
 */

#include <iostream>


// NOTE:
//  The layout mignt not exactly match by meaning that: Pair::x Pair::y are two separate variables 
//  and Triple::values are contigous chunk of memory but these are going to overlap.
struct Pair
{
    // separate variables
    float x, y;
};

struct Triple
{
    // contigous chunk of memory
    float values[3];
    
    explicit Triple()
    {
        std::cout << "Calling Triple::Triple() constructor\n";
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
    }

    explicit Triple(float x, float y, float z)
    {
        std::cout << "Calling Triple::Triple(float, float, float) constructor\n";
        values[0] = x;
        values[1] = y;
        values[2] = z;
    }

    explicit Triple(const Pair& p)
    {
        std::cout << "Calling Triple::Triple(const Pair&) constructor\n";
        values[0] = p.x;
        values[1] = p.y;
    }

    // implicit conversion
    // Note: operator gor when we are doing casting like static_cast or C-old cast 
    operator Pair() const
    {
        std::cout << "Calling Triple::operator Pair()\n";
        return Pair{values[0], values[1]};
    }
    
    /*
    // explicit conversion
    explicit operator Pair() const
    {
        return Pair{values[0], values[1]};
    }
    */
};

int main()
{

    {
        std::cout << "\n\tExample 1\n\n";
        // Basically, what we want to do is something like:
        //
        //      Pair p = t;   -> error: conversion from 'Triple' to non-scalar type Pair
        // or
        //      Pair p;
        //      p = (Pair)t;  -> error: cannot convert 'Truple' to 'float' in initialization
        //
        // But we got those error. One posible solution could be defining a copy constructor Pair::Pair( const Triple& t );
        //
        //

        Triple t{1.1f, 2.2f, 3.3f};
        
        // Calling comversion operator with explicit syntax:
        std::cout << "( (Pair)t ).x             : " << ((Pair)t).x << std::endl; 
        std::cout << "static_cast<Pair>(t).x: " << static_cast<Pair>(t).x << std::endl; 
        //                                                  ^
        //                                         Triple::operator Pair()
        //
        // Note:
        //      if we define 'explicit Triple::operator Pair()', it does not fail since we call it with conversion operator syntax
    }

    { 
        std::cout << "\n\tExample 2\n\n";

        Pair p(10.10f, 11.11f);
        
        // Note: 
        //    Constructors are related whe you are creating a new type or doing an assigment that would create a new type  
        
        Triple t1; // calling Triple() constructor
      
        t1 = static_cast<Triple>( p );        // (explicit) calling Triple(const Pair&) constructor
        Triple t2 = static_cast<Triple>( p ); // (explicit) calling Triple(const Pair&) constructor
        
        //t1 =  p ;                             // (implicit) calling Triple(const Pair&) constructor
        //Triple t2 = p;                        // (implicit) calling Triple(const Pair&) constructor
                
        std::cout << "t1 -> x: " << t1.values[0] << " y:" << t1.values[1] <<  std::endl; 
        std::cout << "t2 -> x: " << t2.values[0] << " y:" << t2.values[1] <<  std::endl; 
    }

    {
        std::cout << "\n\tExample 3\n\n";

        // Calling conversion operator with 'implicit syntax'
        // This will implicit convert 'operator=' to 'opertor Pair()' 
        //
        // Note: 
        //      If we want to avoid implicit conversion, we need to overlad as 'explicit Triple::operator Pair()'
        //      This will avoid implicit conversion and only will accetp:
        //
        //          Pair p3 = (Pair)t;
        //          Pair p3 = static_cast<Pair>( t );
        //  
        Triple t{1.1f, 2.2f, 3.3f};
        Pair p = t;  
        
        std::cout << "Pair x: " << p.x << " y:" << p.y <<  std::endl; 
    }
    return 0;

 }