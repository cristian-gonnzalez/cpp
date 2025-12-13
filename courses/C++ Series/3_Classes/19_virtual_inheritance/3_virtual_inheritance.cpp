/** Multiple Inheritance: Diamond Problem
 */
#include <iostream>
#include <memory>

/*
  Virtual base classes are used in virtual inheritance in a way of preventing 
multiple "instances" of a given class appearing in an inheritance hierarchy 
when using multiple inheritances. 

        ┌───┐     ┌───┐
        │ A │     │ A │         
        └───┘     └───┘        
          ↑         ↑
        ┌───┐     ┌───┐
        │ B │     │ C │ 
        └───┘     └───┘
          ↑         ↑ 
          |_________|                     
               |                      
             ┌───┐
             │ D │         
             └───┘         

  To resolve this ambiguity when class A is inherited in both class B and class C, 
it is declared as virtual base class by placing a keyword virtual as : 

Syntax 1: 
class B : virtual public A  
{
}; 
Syntax 2:                           virtual can be written before or after the public.
class C : public virtual A 
{ 
};

 Now only one copy of data/function member will be copied to class C and class B 
and class A becomes the virtual base class

            ┌───┐   
            │ A │            
            └───┘           
           ___↑_____                     
          |         |
        ┌───┐     ┌───┐
        │ B │     │ C │ 
        └───┘     └───┘
          ↑         ↑ 
          |_________|                     
               |                      
             ┌───┐
             │ D │         
             └───┘         
Note:

class D : public B, public C  
{                ^   
};             The copy of entity we get is the first in the inheritance list
             In this case we get <B> = {<Entity> = { _x = 4, _ = 5}}


 Virtual base classes offer a way to save space and avoid ambiguities in class 
hierarchies that use multiple inheritances. When a base class is specified as a 
virtual base, it can act as an indirect base more than once without duplication 
of its data members. A single copy of its data members is shared by all the base 
classes that use virtual base. 

*/


struct Entity
{
        virtual ~Entity() = default;
        
        int _x{4}, _y{5};
};

struct Warrior : virtual public Entity
{
        virtual ~Warrior() = default;
        
        int _power{10};
};

struct Goblin : virtual public Entity
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
            ┌───────────┐    
            │  Entity   │      This is the virtual base       
            └───────────┘     
             ___↑_______                     
            |           |
        ┌─────────┐   ┌────────┐
        │ Warrior │   │ Goblin │ 
        └─────────┘   └────────┘
            ↑            ↑ 
            |____________|                     
                   |                      
              ┌────────┐
              │ Player │         
              └────────┘          

  Now Warrior and Goblin both inherit from Entity , a Player
contains 'one Entity subobjects'.
*/
    std::cout << mario._x << std::endl;  // 4
    std::cout << mario._y << std::endl;  // 5

//    std::cout << mario._power << std::endl;
    //                 ^~~~~~
    // error: request for member '_power' is ambiguous
    // note: candidates are: 'int Warrior::_power'
    //          int _power{10};
    // note:                 'int Goblin::_power'
    //          int _power{7};

    std::cout << mario.Warrior::_power << std::endl; // 10
    std::cout << mario.Goblin::_power << std::endl; // 7
    
    return 0;
}