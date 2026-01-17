/** Function object: real example
 */

#include <iostream> 
#include <vector> 
#include <algorithm>  //   std::sort

struct Goblin
{
    int    _health{0};
    float  _strength{0.0f};

    // Needs to overload operator< to use in std::sort
    bool operator<(const Goblin& rhs)
    {   
        return _health < rhs._health;
    }
};


struct StrengthComparator
{
    bool operator()(const Goblin& lhs, const Goblin& rhs) const
    {
        return lhs._strength < rhs._strength;
    }
};

struct HealthComparator
{
    bool operator()(const Goblin& lhs, const Goblin& rhs) const
    {
        return lhs._health < rhs._health;
    }
};

int main()
{
    std::vector<Goblin> goblins {
                                    Goblin(5, 25),
                                    Goblin(3, 52),
                                    Goblin(100, 1)
                                };

    // so far, I can sort by overloading operator < in Goblin class
    // But if I want to sort by strengh, I can not overload again
    std::sort( std::begin(goblins), std::end(goblins) );

    std::cout << "[";
    for(auto& e: goblins)
        std::cout << e._health << ", ";
    std::cout << "]\n";  // [3, 5, 100, ]


    // Now I can have different behaviour using sort by creating function objects
    
    std::sort( std::begin(goblins), std::end(goblins), StrengthComparator() );

    std::cout << "[";
    for(auto& e: goblins)
        std::cout << e._health << ", ";
    std::cout << "]\n";  // [100, 5, 3, ]

    
    std::sort( std::begin(goblins), std::end(goblins), HealthComparator() );

    std::cout << "[";
    for(auto& e: goblins)
        std::cout << e._health << ", ";
    std::cout << "]\n";  // [3, 5, 100, ]


    return 0;
}