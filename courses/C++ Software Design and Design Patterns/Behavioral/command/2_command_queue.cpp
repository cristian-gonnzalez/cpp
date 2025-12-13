/** Behavioral pattern - Command Pattern Explanation and Implementation in C++
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
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

        With this idea, we could have a queue of commands.


    std::vector<Command *> commands [ c1, c2, c3, c4 ]

    for( Command* c: commands)
    {
        c.execute();
        c.undo();
    }


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
        virtual void execute(Character* c) = 0;
        // This is the oposite of whatever execute call is
        virtual void undo(Character* c) = 0;

};

class Move : public Command
{
    public:
        void execute(Character* c) override
        {
            // saves the current position to undo
            _x = c->_x;
            _y = c->_y;

            // moves 1 position
            c->move(_x + 1, _y + 1);
            
            std::cout << c->_name << " moved " 
                      << c->_x << " " << c->_y << std::endl;
        }
        void undo(Character* c) override
        {
            c->move(_x, _y);
            std::cout << c->_name << " undo move " 
                      << c->_x << " " << c->_y << std::endl;
        }

    private:
        // I need to save the position to undo
        // That's why I need these variables
        int _x{0}, _y{0};

        // Maybe you migth want to have a pointer (std::weak_ptr) to the character 
        //std::weak_ptr<Character> _ref;
};

int main()
{
    Character c{"Mario"};

    std::unique_ptr<Move> m1 = std::make_unique<Move>();
    std::unique_ptr<Move> m2 = std::make_unique<Move>();
    std::unique_ptr<Move> m3 = std::make_unique<Move>();
    std::unique_ptr<Move> m4 = std::make_unique<Move>();

    // History of commands
    // NOTE: we could use std::stack as better option
    std::vector< std::unique_ptr<Command> > command_queue;
    command_queue.push_back(std::move( m1 ));
    command_queue.push_back(std::move( m2 ));
    command_queue.push_back(std::move( m3 ));
    command_queue.push_back(std::move( m4 ));
    
    std::cout << "Move foward\n";
    for(size_t i=0; i<command_queue.size(); i++)
        command_queue[i]->execute(&c);
    /*
    Move foward
    Mario moved 1 1
    Mario moved 2 2
    Mario moved 3 3
    Mario moved 4 4
    */

    std::cout << "Undo move\n";
    for(ssize_t i=command_queue.size() -1; i > -1; i--)
        command_queue[i]->undo(&c);
    /*
    Undo move
    Mario undo move 3 3
    Mario undo move 2 2
    Mario undo move 1 1
    Mario undo move 0 0
    */

    return 0;
}