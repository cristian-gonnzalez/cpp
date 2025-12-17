/** Multiple Inheritance: Diamond Problem
 */
#include <iostream>
#include <memory>

struct Entity
{
        virtual ~Entity() = default;
        
        int _x{4}, _y{5};
};

struct Warrior : public Entity
{
        virtual ~Warrior() = default;
        
        int _power{10};
};

struct Goblin : public Entity
{
        virtual ~Goblin() = default;
        
        int _power{7};
};

struct Player : public Goblin, Warrior
//                     ^~~~~~  ^~~~~~~~~~~~
//                     Multiple Inheritance 
{
};


int main()
{
    Player mario;

/*
 However, we implement this:
    
    ┌───────────┐     ┌───────────┐
    │  Entity   │     │  Entity   │         
    └───────────┘     └───────────┘        
            ↑            ↑
            |            |       
        ┌─────────┐   ┌────────┐
        │ Warrior │   │ Goblin │ 
        └─────────┘   └────────┘
            ↑            ↑ 
            |____________|                     
                   |                      
              ┌────────┐
              │ Player │         
              └────────┘          

  Because Warrior and Goblin both inherit from Entity 'independently', a Player
contains 'two separate Entity subobjects'.
*/
    // Use qualified name lookup to be specific and not ambigous
    std::cout << mario.Warrior::_x << std::endl;  // 4
    std::cout << mario.Warrior::_y << std::endl;  // 5
    std::cout << mario.Warrior::_power << std::endl; // 10
    
    std::cout << mario.Goblin::_x << std::endl;   // 4
    std::cout << mario.Goblin::_y << std::endl;   // 5
    std::cout << mario.Goblin::_power << std::endl; // 7
    
    return 0;
}