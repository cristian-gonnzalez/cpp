/** Composition (and aggregation)
 */ 
#include <iostream>
#include <vector>
#include <initializer_list>


/*
        ┌───────────┐
        │  Point2D  │
        └───────────┘         Character class 'is-a' type of Point2D
             ↑                 
        ┌───────────┐
        │ Character │
        └───────────┘

    If we are thinking in the desing of a game, this relationship does not really makes sense.
    
    A character is not a point in the game but we need this attributes in the character.
*/

struct Point2D
{
    private:
        int _x, _y;
};

struct Character : public Point2D   // Character 'is-a' Point2D
{
};


int main()
{
    return 0;
}
