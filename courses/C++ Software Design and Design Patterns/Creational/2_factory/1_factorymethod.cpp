/** Creational Patterns - Factory Method Pattern Explanation and Implementation in C++
 */

#include <iostream>
#include <memory>
#include <string>

/*
The 'Factory Method' pattern provides a generalized way 
to create intances of an object and can be a great way 
to hide implementation details for derived clases


GameObject* obj = new ConcreteObject; ❌  -> This is exactly what we want to avoid
                  ~~~~~~~~~~~~~~~~~~
                  Determinate at runtime what the type is of this 
                  object

    We dont want clients of our interface or implemeter who are working on our code to make 
this decision and be allocation our objects.

    Instead what we want is some function where we can provide an input and get the correct output

        ----------------
  ---> | Factory method |  ---> ConcreteObject
        ----------------

 
   Inheritance-based polymorphims
 
    Interface
        ^
     ___|_____
    |        |
  Plane    Boat

     
  Interface* make_object(ObjectType type)   <--- factory method or function

    Pros                    | Cons
        Single responsability                       |
            It gives you a particular type of objects from some hierarchy.
            You dont have to know how to instanciate an object
        Easy to update and it is extensible
    
    Const:
        You have to do at least to update to the code: 
            The enum class and the factory method
        You need a factory method per hierarchy

*/

// Interface
class IGameObject
//    ~
//  Interface
{
    public:
        virtual ~IGameObject(){};
        virtual void update() = 0;
                            //~~~~
                            // Virtual pure function: anu class that we derive from must implement 
                            // this function
        virtual void render() = 0;
};

// Concrete class
class Plane : public IGameObject
{
    public:
        Plane(){ std::cout << "calling Plane()\n"; };
        void update() {};
        void render() {};
};

// Concrete class
class Boat : public IGameObject
{
    public:
        Boat(){std::cout << "calling Boat()\n";};
        void update() {};
        void render() {};
};


// Defining an enum to know what concrete class want to create
enum class ObjectType
{
    PLANE,
    BOAT
};

// Factory method : single place where to create all concrete classes
std::unique_ptr<IGameObject> makeGameObjectFactory(ObjectType type)
// ~~~~~~~~~~~~~~~~~~~~~~~~~
// Return unique_ptr because it gives clear exclusive ownership of the created object
// and makes ownership transfer explicit. It perfectly models the idea that the caller 
// receives a fresh object that nobody else owns.
//
// NOTE: You migth want to share and wnat to return a std::shared_ptr depending on the context
// or leave these unique pointer and then concert them to shared later
{
    if( type == ObjectType::PLANE)
        return std::make_unique<Plane>();
    else if( type == ObjectType::BOAT)
        return std::make_unique<Boat>();

    // deleting nullptr makes no error
    // Use nullptr instead of NULL or 0
    return nullptr;
}

int main()
{
    std::unique_ptr<IGameObject> obj1 = makeGameObjectFactory(ObjectType::PLANE); // calling Plane()
    std::unique_ptr<IGameObject> obj2 = makeGameObjectFactory(ObjectType::BOAT);  // calling Boat()

    /* 
    > gdb ./prog --tui
    > (gdb) info vtbl obj1
    vtable for 'IGameObject':
    [0]: 0x555555....4e <Plane::~Plane()>
    [1]: 0x555555....78 <Plane::~Plane()>
    [2]: 0x555555....22 <Plane::update()>
    [3]: 0x555555....2e <Plane::render()>
    > (gdb) info vtbl obj2
    vtable for 'IGameObject':
    [0]: 0x555555....f8 <Boat::~Plane()>
    [1]: 0x555555....22 <Boat::~Plane()>
    [2]: 0x555555....64 <Boat::update()>
    [3]: 0x555555....70 <Boat::render()> 
    */
    return 0;
}