/** Multiple Inheritance: Diamond Problem
 */
#include <iostream>
#include <memory>

/*  

Diamond Problem:

  The goal is to model this hierarchy:

            ┌───────────┐
            │  Entity   │         
            └───────────┘         
                  ↑
             _____|______     'is-a' relation                
            |            |       
    ┌─────────┐       ┌────────┐
    │ Warrior │       │ Goblin │   <- Multiple Inheritance
    └─────────┘       └────────┘
            ↑            ↑ 
            |____________|     'is-a' relation                
                   |                   
              ┌────────┐
              │ Player │         
              └────────┘         

 
*/

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

  This duplication causes ambiguity: the compiler cannot know which Entity subobject
you mean when converting Player to Entity or when calling a Entity method.


*/

    std::cout << mario._x << std::endl;
    //                 ^~
    // error: request for member '_x' is ambiguous
    //
    // note: candidates are: 'int Entity::_x' (Warrior)
    //         int _x{4}, _y{5};
    // note:                 'int Entity::_x' (Goblin)

    std::cout << mario._y << std::endl;
    //                 ^~
    // error: request for member '_y' is ambiguous
    //
    // note: candidates are: 'int Entity::_y' (Warrior)
    //         int _x{4}, _y{5};
    // note:                 'int Entity::_y' (Goblin)


    std::cout << mario._power << std::endl;
    //                 ^~~~~~
    // error: request for member '_power' is ambiguous
    // note: candidates are: 'int Warrior::_power'
    //          int _power{10};
    // note:                 'int Goblin::_power'
    //          int _power{7};
      |    


    return 0;
}