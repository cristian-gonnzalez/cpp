#include <iostream>
 
 
struct MouseEvent
{
    int i;
};

struct KeyboardEvent
{
    char c;
};

/** Generic condition type. */
struct Event
{
    enum{MOUSE, KEYBOARD} type;        
    union
    {
        MouseEvent    motion;
        KeyboardEvent key;
    };

    void print()
    {
        switch(type)
        {
            case Event::MOUSE: 
                std::cout << motion.i << '\n'; 
                break;
            case Event::KEYBOARD: 
                std::cout << key.c << '\n'; 
                break;
            default:
                break;
        }
    }
};

 
int main()
{
    Event e = {
                Event::MOUSE, 
                10
              };
    e.print();
    
    e.type = Event::KEYBOARD;
    e.key.c = 'a';
    e.print();

    return 0;
}