/** Behavioral pattern: C++ Visitor Design Pattern - Part 1 of 4 - Programming Paradigms
 */
#include <iostream>
#include <vector>
#include <memory>

/*
Visitor pattern:
    Represent an operation to be performed on elements of an object structure. Visitor lets you 
to define new operation without changing the classes of the elements on which it opeates.

    The nature of the Visitor makes ti an ideal pattern to plug into publick APIs, this allowing 
its clients to perform operation on a class using a 'visiting' class without havinf to modify the
source.

    It is really great for extensibility or adding behaviour

*/


/*
             -----------                                                         
            |  Monster  |          
            |-----------|
virtual = 0 | + sing()  |    ->  behaviour of the monster that concrete monster must implement
             -----------   
                ^       
        ________|_________
        |                 |
    ----------             ----------                                                        
    |  Orc     |           |  Goblin  |          
    |----------|           |----------|
    | + sing() |           | + sing() |   <--- We can add own behaviour in each concrete classes
    ----------             ----------          But the member function are somewhat 'pilling up'
                                             into one single class 
                                                       - We did have to repeat some code (
                                                        DRY principle - Dont Repeat Yourself)
                  
*/

// Monster base class (for which Orc and Goblin will derive from))
struct Monster
{
    virtual ~Monster(){}
    virtual void sing() = 0;
          //            ~~~
          //  Gobling and Orcs have to sing().
          //  We have learned into some OO tools to ensure functionality
          // is supported by derived classes (pure virtual function) 
};

// Derived classes
struct Orc : public Monster
{
    // Add the constructor just to show it is being created once
    Orc()
    {
        std::cout << "Created a new Orc::Orc()\n";
    }
    void sing( ) override 
    {
        std::cout <<  "Orc::sing\n";
    }
};

struct Goblin : public Monster
{
    // Add the constructor just to show it is being created once
    Goblin()
    {
        std::cout << "Created a new Goblin::Goblin()\n";
    }
    void sing() override 
    {
        std::cout <<  "Goblin::sing\n";
    }
};


int main()
{
    std::vector< std::unique_ptr<Monster> > monsters;
    monsters.emplace_back( new Orc );   // Created a new Orc::Orc()
        //   ~~~~~~~~~~~~
        // constructing one time in place 
    monsters.emplace_back( new Goblin ); // Created a new Goblin::Goblin()
    
    for(auto& m: monsters)
        m->sing();
    /*
    Orc::sing
    Goblin::sing
    */

    return 0;
}