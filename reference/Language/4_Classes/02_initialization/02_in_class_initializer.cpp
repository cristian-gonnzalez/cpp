/** In-Class initializer
 *
 *  In general, we dont want to rely on the compiler to give us some default or otherwise the behaviour is not specify.
 *  we want to zero initalize things explicity or creating a constructor or using in-class initilization
 */
#include <iostream>

struct Entity1
{
    std::string name;
    int x;
    int y;
    int* collection;
};


std::string generate_name()
{
    return "Hello world";
}

// In-class initializer
struct Entity2
{
    std::string name{generate_name()};   // std::string name = generate_name();
                                         //                  ^
                                         //  We can use assign operator but it is better to use curly braces '{}'
    int x{1};
    int y{2};
    //   ^ ^
    // We use curly braces '{}' because It will be preventing any sort of conversion from happening (narrowing conversion)
     
    //int y(2);  -> Error - we cannot use paranthesis '()' since th compiler thnks we are doing some sort of function call
        
    int* collection{nullptr};
};

// In-class initializer
struct Entity3
{
    std::string name{"Test"};
    int x;
    int y{5};
    
    int* collection;
};


// In-class initializer
struct Entity4
{
    Entity4()
    : name{}, x{2}, y{3}, collection{nullptr}  // -> member inizialization list
    //    ^^
    // Note: we could use paranthesis here () but it is better to use {}
    {
    }
    std::string name{"Test"};
    int x;
    int y{5};
    
    int* collection;
};


int main()
{   

    {
        // default initialization
        //   We get garbage in each of the fields  
        Entity1 e;

        std::cout << "Entity1 : { "  
                << "name: " << e.name << ", "
                << "x: " << e.x << ", "
                << "y: " << e.y << ", "
                << "collection: " << e.collection << " }\n"; // Entity1 : { name: , x: -137127608, y: 32765, collection: 0x7d9086416a58 }

    }
    {
        // Value initizialization: Zero initialized
        //   We get zeros in each of the fields because we created this object with the curly braces '{}' 
        Entity1 e{};

        std::cout << "Entity1 : { "  
              << "name: " << e.name << ", "
              << "x: " << e.x << ", "
              << "y: " << e.y << ", "
              << "collection: " << e.collection << " }\n"; // Entity1 : { name: , x: 0, y: 0, collection: 0 }
    }
 
  
    {
        Entity2 e;

        std::cout << "Entity2 : { "  
              << "name: " << e.name << ", "
              << "x: " << e.x << ", "
              << "y: " << e.y << ", "
              << "collection: " << e.collection << " }\n"; // Entity2 : { name: Hello world, x: 1, y: 2, collection: 0 }
    }

    {
        // Value initizialization: Zero initialized
        Entity3 e{};

        // Since we were explicit where we initialize name{"Test"} and y{5}, the other fields will be zero initializes but
        // these fields. 
        // The precedence of order is:
        //
        //      - In-class fields
        //      - Other fields will be zero initialized 

        std::cout << "Entity3 : { "  
              << "name: " << e.name << ", "
              << "x: " << e.x << ", "
              << "y: " << e.y << ", "
              << "collection: " << e.collection << " }\n"; // Entity3 : { name: Test, x: 0, y: 5, collection: 0 }
                                                           //                            ^                    ^
                                                           //                         Only these fields were zero-initialized

    }

    
    {
        Entity4 e{};

        // We get what is in the constructor. 
        //  
        // NOTE: If I have a constructor where I dont specify default values of some filds, then it will fall back and use
        // in.class initializer and if I still dont specify default values in some fields, then it will fall back to 
        // zero-inizilization
        // 
        // The precedence of order is:
        //
        //      - Constructor
        //      - In-class fields
        //      - Other fields will be zero initialized 

        std::cout << "Entity4 : { "  
              << "name: " << e.name << ", "
              << "x: " << e.x << ", "
              << "y: " << e.y << ", "
              << "collection: " << e.collection << " }\n"; // Entity4 : { name: , x: 2, y: 3, collection: 0 }

    }

    return 0;
}