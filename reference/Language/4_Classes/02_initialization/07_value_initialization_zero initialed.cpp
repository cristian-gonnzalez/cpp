/** Value initialization: (zero-initialization of members)
 */
#include <iostream>
#include <string>


/*

Note: user-provided
  A function is 'user-provided' if it is user-declared and not explicitly defaulted
or deleted on its first declaration.

    // If a default constructor is defaulted on its first declaration,
    // then it is NOT user-provided
    struct Entity
    {
        Entity() = default;
    };

    struct Entity
    {
        Entity(); // first declaration
    };

    // not defaulted on the first declaration,
    // it IS user-provided and is defined here
    Entity::Entity() = default;


Value-initialization ({}):
  If a class type T with a default constructor that is neither user-provided nor deleted,
then during value-initialization the object is first zero-initialized, and then the default 
constructor is called.

*/


struct Entity
{
    std::string _name;     // class types are initialized by their own constructors
    int* _ptr;             // built-in types are not initialized by default: garbage
    int _x, _y;            //       

//  Entity();              //  Implicitly-defined (not user-provided)
}; 

struct Entity2
{
    Entity2()              // User-defined default constructor
    {
        // does not initialize built-in members
    }
    std::string _name;     // class types are initialized by their own constructors
    int* _ptr;
    int _x, _y;
};

struct Entity3
{
    Entity3() = default;   // Explicitly defaulted (not user-provided)

    std::string _name;
    int* _ptr;
    int _x, _y;
};

int main()
{
    {
        Entity e;                             // default-initialization
        std::cout << "e { "  
                  << "name: " << e._name << ", "
                  << "ptr: " << e._ptr << ", "
                  << "x: " << e._x << ", " 
                  << "y: " << e._y << "}\n";  // e { name: , ptr: 0x7ffc8824f748, x: 1104804440, y: 30053}
    }
    
    // value-initialization: implicit default constructor
    {
        Entity e{};    
        //      ^~
        // zero-initializes built-in members, then calls default constructor
        std::cout << "e { "  
                  << "name: " << e._name << ", "
                  << "ptr: " << e._ptr << ", "
                  << "x: " << e._x << ", " 
                  << "y: " << e._y << "}\n"; // e { name: , ptr: 0, x: 0, y: 0}
    }
         
    // value-initialization: user-provided default constructor
    {
        Entity2 e{};    
        //      ~~
        //  If we have a constructor, the ctor is responsable to initialize the variables. 
        // As we are asigning our data fields we get garbage
        std::cout << "e { "  
                  << "name: " << e._name << ", "
                  << "ptr: " << e._ptr << ", "
                  << "x: " << e._x << ", " 
                  << "y: " << e._y << "}\n"; // e { name: , ptr: 0x7ffe5ffe4f18, x: 1739381336, y: 29847}
    }

    // default-initialization: explicitly defaulted default constructor
    {
        Entity3 e;    
        std::cout << "e { "  
                  << "name: " << e._name << ", "
                  << "ptr: " << e._ptr << ", "
                  << "x: " << e._x << ", "  
                  << "y: " << e._y << "}\n";  // e { name: , ptr: 0x7ffc2b022748, x: -723277224, y: 31883}
    }
    
    // value-initialization: explicitly defaulted default constructor
    {
        Entity3 e{};    
        //      ^~
        // zero-initializes built-in members, then calls default constructor  
        std::cout << "e { "  
                  << "name: " << e._name << ", "
                  << "ptr: " << e._ptr << ", "
                  << "x: " << e._x << ", "  
                  << "y: " << e._y << "}\n";  // e { name: , ptr: 0, x: 0, y: 0}
    }
    return 0;
}
