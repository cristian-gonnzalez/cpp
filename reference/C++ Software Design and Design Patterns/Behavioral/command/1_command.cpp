/** Behavioral pattern - Command Pattern Explanation and Implementation in C++
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*  Behavioral Pattern:
        Allow you to focus on how objets are connected and how they communicate -- simplifying control flow


    Command pattern (Also know as Action or Transaction pattern):
        It is a way to take objects and model them as commands that executes actions.

        Some uses:
            1. Objects used as callbacks.
            2. Can 'store' or 'enqueue' commands
            3. Used for Undo/Redo systems



    Lets say we have a game controller 
                                                                --------- 
                                                               | Command |
                                                                --------- 
              ---   ---   ---                                       ^
    Buttons: | x | | y | | z |                          ------------|------------
              ---   ---   ---                          |            |            |
               ^                                     ------     ---------     --------
               |------------------------            | Jump |   |  Accept |   | Enter  |   Each of these are a 
                     I press 'x'                     ------     ---------     --------    type of Command 
               we want some commands for ex
            jump, accept, enter actions 
            depending on the context that        -> We can model them as
            we are in                               Command* x = new JumpAction();
                                                    x->execute(); 
                                                      ~~~~~~~~
                                                      virtual = 0; -> mandatory in every command concrete class


*/
 
struct Character
{
    int          _x{0}, _y{0};
    std::string  _name;

    Character(std::string name)
    :_name{name}
    {
    }

    void move(int x, int y)
    {
        _x = x;
        _y = y;
    }
};

class Command
{
    public:
        virtual ~Command()
        {
        }
        virtual void execute(Character& c) = 0;
                                       //  ~~~
                                       // This must be implemented by any class derived from Command
};

class Move : public Command
{
    public:
        void execute(Character& c) override
        {
            c.move( c._x + 1, c._y + 1);
            
            std::cout << c._name << " moved " 
                      << c._x << " " << c._y << std::endl;
        }
};

int main()
{
    Move m; // this is my command
    Character c{"Mario"};
    
    m.execute( c ); // Mario moved 1 1
    m.execute( c ); // Mario moved 2 2
    m.execute( c ); // Mario moved 3 3

    return 0;
}