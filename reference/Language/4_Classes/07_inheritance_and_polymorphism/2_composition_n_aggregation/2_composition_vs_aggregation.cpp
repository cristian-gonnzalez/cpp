/** Composition: "has-a"
 */ 
#include <iostream>
#include <vector>
#include <initializer_list>


/*
Composition:

        ┌───────────┐   has-a    ┌───────────┐
        │ Character │<*>----------│  Point2D  │
        └───────────┘            └───────────┘

    A Character 'has-a' (is composed by) Point2D
    
    In a composition, the lifetime of the object we has is tied-up to the object. So
the lifetime of Point2D depends of the lifetime of Character.

    The constructor of Character is responsible to initialize Point2D and the destructor
to relase.


Aggregation:

    It is also a 'has-a' relationship.

        ┌───────────┐   has-a    ┌───────────┐
        │ Character │<>----------│  Point2D  │
        └───────────┘            └───────────┘

    A Character 'has-a' Point2D
    
    The difference is that the lifetime of the object we has is NOT tied-up to the object. So
the lifetime of Point2D does not necessarily depends of the lifetime of Character.

    For ex: when we use pointer or reference as member variables.

*/

struct Point2D
{
    private:         //        Composition
        int _x, _y;  // Point2D 'has-a' x and y variables
};

struct Character : public Point2D   // Character 'is-a' Point2D
{
    Character(Point2D& ref)
    : _ref_home{ref}
    {
    }
    private:
        Point2D  _position;     // Compostion: A characer 'has-a' Point2D
        Point2D  _direction;    // Compostion: A characer 'has-a' Point2D
        Point2D& _ref_home;     // Aggregation: A characer 'has-a' Point2D 
};


int main()
{
    Point2D some_point;

    {
        Character mario(some_point);
    
    } // mario is reclaimed but some_point still exists
      // The lifetime of some_point is not tied to mario
    return 0;
}
