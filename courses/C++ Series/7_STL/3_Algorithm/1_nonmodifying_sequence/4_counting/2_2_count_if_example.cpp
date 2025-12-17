/** C++ STL algorithm - counting (count, count_if)
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//   returns the number of elements satisfying specific criteria
//                                              

// std::count: Counts the elements that are equal to value (using operator==).
//
// std::count_if: Counts elements for which predicate p returns true.
//

//
// Complexity: O(N)
//

struct Enemy
{
    int health;
    int attack;

    Enemy( int h, int a)
    : health{h}, attack{a}
    {}
};

int main()
{
    std::vector<Enemy> enemies{ {100,10}, {-10,10}, {-50,10} };

    // Play our game for a bit ... main loop

    int enemies_left = std::count_if( enemies.begin(), enemies.end(), 
                                      [](Enemy e) -> int
                                      {
                                        return e.health > 0;
                                      } );
    if(enemies_left == 0)
        std::cout << "Proceed to next level\n";
    else
        std::cout << "You have " << enemies_left << " enemies to blast away!\n"; // You have 1 enemies to blast away!
    

    return 0;
}


