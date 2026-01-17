/** Creational patterns - The Extensible Factory Pattern in C++ | Register Objects at Runtime
 */
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <functional>

/* 
The factory method allow us to hide creation implementatio through a method. The user does not know how
to instanciate the object. So far, we have

   Inheritance-based polymorphims
 
         IGameObject
             ^
     ________|_________
    |                 |
  Plane              Boat

IGamObject* obj = makeGameObject( ObjectType::PLANE );



The Extensible Factory Pattern:

     (See 'Modern C++ Design' by Andrei Alexandrescu / 
          'API C++ Design' by Martin Reddy )

    This tries to solve the problem that what if user want to create other types.

    For ex. what if our users through some plug-in system have some other game object  


         IGameObject
             ^
     ________|_________------------------
    |                 |                 |
  Plane              Boat              Ant 

    The user want to add another GameObject type called 'Ant'  


- How can we ensure that the object is also registered so that the factory will do the rigth thing 
  and give is that object?


            IGameObject
                ^
        ________|_____________----------------------
        |                    |                      |
    Plane                   Boat                   Ant 
    + static create()       + static create()      + static create()
      ~~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~         ~~~~~~~~~~~~~~~
         ^                           ^                  ^
    We have to define the 'create' method for each concrete class
    This allows us to do is then the user creates their own type and we can use this as a callback 
function that allows us to kwon how we create these types


    Then, wrap the factory_method into a class where:

      -------------------------------------
     |  FactoryObject                      |
     |-------------------------------------|
     | + register( type, create_cb )       |  
     | + unregister( type )                |
     |                                     |
     | + make_object( type )               | <-- factory method
     |                                     |
     | - std::map< type, create_cb > _cbs  |
     |                               ~~~~  |                  
      ------------------------------- ^ ---
                                      |
                              ---------------------------------
                             |   first    |  second            |
                             |------------|--------------------| 
                             |   "PLANE"  |  Plane::create()   |
                             |   "BOAT"   |  Boat::create()    |
                             |   "ANT"    |  Ant::create()     |
                              ---------------------------------

    We are able to create new types such as Ant and then add them to our factory by registering them
and storing the key as a string and then a callback function that will tell us how to actually create
that object.

    This is OPEN/CLOSE principle where we can make this extensible 

*/

/*
            IGameObject
                ^
        ________|_____________----------------------
        |                    |                      |
    Plane                   Boat                   Ant 
    + static create()       + static create()      + static create()

*/
// Interface
class IGameObject
{
    public:
        // Ensure derived classes call the correct
        // destructor (i.e., top of the chain) 
        virtual ~IGameObject()
        {
        }
        // Pure virual functions that must be
        // implemented by derived class
        virtual void update() = 0;
        virtual void render() = 0;
};


// Concrete class
class Plane : public IGameObject
{
    public:
        Plane()
        { 
            _objects_created++;
            std::cout << "calling Plane()\n"; 
        }
        void update() {}
        void render() {}
        static void print_objects_created()
        {
            std::cout << "Plane created: " << _objects_created << std::endl;
        }

        // We have to define the 'create' method for this concrete class
        static std::shared_ptr<IGameObject> create()
        {
            return std::make_shared<Plane>();
        }
    
    private:
        // we add this variable to count the objects created for this concrete class
        // this is not part of the pattern
        inline static int _objects_created{0};

};

// Concrete class
class Boat : public IGameObject
{
    public:
        Boat()
        { 
            _objects_created++;
            std::cout << "calling Boat()\n"; 
        }
        void update() {}
        void render() {}
        static void print_objects_created()
        {
            std::cout << "Boat created: " << _objects_created << std::endl;
        }

        // we have to define the 'create' method for this concrete class        
        static std::shared_ptr<IGameObject> create()
        {
            return std::make_shared<Boat>();
        }

    private:
        // we add this variable to count the objects created for this concrete class
        // this is not part of the pattern
        inline static int _objects_created{0};
};


// Concrete class
class Ant : public IGameObject
{
    public:
        Ant()
        { 
            _objects_created++;
            std::cout << "calling Ant()\n"; 
        }
        void update() {}
        void render() {}
        static void print_objects_created()
        {
            std::cout << "Ant created: " << _objects_created << std::endl;
        }

        // we have to define the 'create' method for this concrete class        
        static std::shared_ptr<IGameObject> create()
        {
            return std::make_shared<Ant>();
        }

    private:
        // we add this variable to count the objects created for this concrete class
        // this is not part of the pattern
        inline static int _objects_created{0};
};

/*
        ______________________________________ 
       | FactoryObject                        |   
       |______________________________________|
       | + register( type, create_cb )        |
       | + unregister( type )                 |  
       |                                      |
       | + make_object( type )                | <-- factory method
       |                                      | 
       | - std::map< type, create_cb > _cbs   |
       |______________________________________|

*/


// One change is that I have removed our 'enum class'
// This is because during run-time I want to be able to create different types
class FactoryGameObjects
{
    // Callback function for creating an object
    using GameObjectCreateCb_t = std::function< std::shared_ptr<IGameObject>() >;
    public:

        // create a new concrete object.
        // we also have to pass in how to 'create' an object 
        static void register_object( const std::string& type, 
                                     GameObjectCreateCb_t cb )
        {
            _cbs[type] = cb;
        }

        // unregister concrete object.
        // remove from out map
        static void unregister_object( const std::string& type )
        {
            _cbs.erase(type);
        }

        // Factory method : single place where to create all concrete classes
        static std::shared_ptr<IGameObject> makeGameObject(const std::string& type)
        {
            if( auto it = _cbs.find(type); it != _cbs.end() )
                // Call the callback function
                return it->second();
                //               ~~
            throw "Not found";
            return nullptr;
        }

    private:
        // Singlenton constructors and destructor
        FactoryGameObjects() {};
        ~FactoryGameObjects() {};
        FactoryGameObjects(const FactoryGameObjects& other) = delete;
        FactoryGameObjects& operator=(const FactoryGameObjects& other) = delete;

        // maps the concrete object type with his create callback
        inline static std::map< std::string,
                                GameObjectCreateCb_t > _cbs{};
};

int main()
{
    // register all different type
    FactoryGameObjects::register_object("PLANE", Plane::create );
    FactoryGameObjects::register_object("BOAT",  Boat::create );
    FactoryGameObjects::register_object("ANT",   Ant::create );

    std::vector< std::shared_ptr<IGameObject> > objects{};
    
    std::vector<std::string> level1{"PLANE", "PLANE", "BOAT", "BOAT", "ANT"};
    for(auto& e: level1)
        objects.push_back( FactoryGameObjects::makeGameObject(e) );
    /*
    calling Plane()
    calling Plane()
    calling Boat()
    calling Boat()
    calling Ant()
    */

    // run our game ...
    while( true )
    {
        for(auto& o: objects)
        {
            o->update();
            o->render();
        }
        break;
    }

    Plane::print_objects_created(); // Plane created: 2
    Boat::print_objects_created();  // Boat created: 2
    Ant::print_objects_created();   // Ant created: 1

    return 0;
}