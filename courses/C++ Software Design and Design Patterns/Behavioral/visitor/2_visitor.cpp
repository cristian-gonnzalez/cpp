/** C++ Visitor Design Pattern - Part 3 of 4- Coding the Visitor
 */
#include <iostream>
#include <vector>
#include <memory>

/*
Behavior pattern:
    Focus on comunication between objects

Visitor:
    The key advantage of the visitor, and we are going to pay a little price in complexity for
this advantage of extensibility.

    Lets now apply the visitor pattern to our solution.
        - In a similar way -- how we moved all the 'attributes' to its own struct (pImpl pattern),
         we are going to move all the member functions t a new class.


    So, here is our current hierarchy:

             -----------                                                         
            |  Monster  |          
            |-----------|
virtual = 0 | + sing()  |    ->  Our goal is to move behaviour like sing() outside
             -----------       and make it a litle bit easier to extend the functrionality
                ^              of each monster
        ________|_________
        |                 |
    ----------             ----------                                                        
    |  Orc     |           |  Goblin  |          
    |----------|           |----------|
    | + sing() |           | + sing() |
    ----------             ----------  



    Now part of our solution is going to be to add a 'Visitor' class:
            
             -------------------                                    -------------------                                        
            |      Monster      |                                  |      Visitor      | ---> - The purpose of these 
            |-------------------|                                  |-------------------|     abstract class is to 
virtual = 0 | + accept(visitor) |                      virtual = 0 | + visit(Orc)      |     hold behaviours.
             -------------------                       virtual = 0 | + visit(Goblin)   |      - Thus we will avoid creating more member 
                         ^                                          -------------------      functions within the 'Orc' and 'Goblin'   
         ________________|____________________                             ^                 concrete classes -- new behaviors go in 
        |                                     |                            |                 the 'Visitor'. 
    --------------------             -------------------            ------------------                                               
    |  Orc              |           |  Goblin           |          |  SingMonster     | --->  Any classes derived          
    |-------------------|           |-------------------|          |------------------|     from 'Visitor' will be 
    | + accept(visitor) |<---|      | + accept(visitor) |          | + visit(Orc)     |     functional equivalent  
    --------------------     |       -------------------           | + visit(Goblin)  |     to adding a 'sing()' 
                             |                                      ------------------      member function
                                       
                    void accept( Visitor& visitor ) override  -> Monster inteface connects to the  
                    {                                           visitor classes, by implementing an
                        visitor.visit(*this);                   'accept' member function  
                    }                                             
                                                                 You can read this as:
                                                                 "I accpet some functionality from the Visitor
                                                                 hierarchy" 
    

Pros:

    Open-Closed principle:
        - This means we can 'add' new operations to existing object (open), without modifying the structure
        (closed -- Monster is not changed)
        - The algorithm (behaviour) s separated from the object
            This is a good thing if our goal is extensible software desing.
            As you can image, we can try out many different new 'Visitor' to try different behaviors. 

Neutral
    When we do have to repeat our code, at least it is in same struct/class.
        - Pure virtual functions also can ensure all classes get updated.

Cons:
    Potentially makes it harder to intriduce new types later in a project.
    Restricted to the public interface (or otherwise need to use getters to expose data)
    Performance may be negatively affected
        Lots of polymorphism (double dispatch)
        Potentially more 'heap allocations' and memory managmebt needed.
*/  

struct Orc;
struct Goblin;


/*           
                 -------------------                                        
                |      Visitor      |
                |-------------------|   
    virtual = 0 | + visit(Orc)      |  
    virtual = 0 | + visit(Goblin)   |    
                -------------------     
                       ^              
                _______|____________
               |                    |  
         ------------------     ------------------                                               
        |  SingMonster     |   |  SingMonster     |        
        |------------------|   |------------------|     
        | + visit(Orc)     |   | + visit(Orc)     |  
        | + visit(Goblin)  |   | + visit(Goblin)  |   
         ------------------     ------------------    

*/

// Our visitor 'base class' which tells us, which
// type of objects (Orc's, Goblin's) that we can 
// extend (i.e. visit)
struct MonsterVisitor
{
    virtual ~MonsterVisitor() = default;

    // For each concrete class we want to extend functionality, 
    // a visit()
    virtual void visit(const Orc& orc) const  = 0;
    virtual void visit(const Goblin& goblin) const  = 0;
};

// New functionality
struct DrawMonster : public MonsterVisitor
{
    void visit(const Orc& orc) const  override
    {
        std::cout << "Drawing orc\n";
    }

    void visit(const Goblin& goblin) const  override
    {
        std::cout << "Drawing goblin\n";
    }
};


/*
             -------------------                                                  
            |      Monster      |                
            |-------------------|                 
virtual = 0 | + accept(visitor) |                
             -------------------                  
                         ^                          
         ________________|____________________     
        |                                     |    
    --------------------             -------------------                                                 
    |  Orc              |           |  Goblin           |          
    |-------------------|           |-------------------|  
    | + accept(visitor) |           | + accept(visitor) |   
    --------------------             -------------------   
                                                        
*/

// Base class
struct Monster
{
    virtual ~Monster(){}

    // Every type of monster must implment this
    virtual void accept(const MonsterVisitor& visitor) = 0;
};

// Derived classes
// Note:
//      We move out all the functionality outside the Monster concrete classes
struct Orc : public Monster
{
    void accept(const MonsterVisitor& visitor ) override 
    {
        std::cout <<  "Orc::accept\n";
        visitor.visit(*this);
    }
};

struct Goblin : public Monster
{
    void accept(const MonsterVisitor& visitor ) override 
    {
        std::cout <<  "Goblin::accept\n";
        visitor.visit(*this);
    }
};


int main()
{
    std::unique_ptr<Monster> m1{ std::make_unique<Orc>()};

    // creating the functionality 
    DrawMonster draw_functionality;

    // I accept the draw behaviour
    // accept will add the functionality and execute it
    m1->accept(draw_functionality); // Orc::accept
                                    // Drawing orc 
    
    std::vector< std::unique_ptr<Monster> > monsters;
    monsters.emplace_back( new Orc );   // Created a new Orc::Orc()
    monsters.emplace_back( new Goblin ); // Created a new Goblin::Goblin()
    
    for(auto& m: monsters)
        m->accept( DrawMonster() );
    /*
    Goblin::accept
    Drawing goblin
    */

    return 0;
} 