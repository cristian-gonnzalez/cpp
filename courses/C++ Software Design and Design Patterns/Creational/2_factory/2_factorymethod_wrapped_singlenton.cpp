/** Creational patterns - Factory Method Pattern Adding More Power to Count Allocated Objects in C++
 */

/* Factory method wrapped into a class

    We wrap the Factory method into a Singlenton class to get more power. For ex, we could add the hability 
to count all the instances created.

    Note:
        We could use a regular class instead of a singlenton




*/

#include <iostream>
#include <memory>
#include <string>

//   Inheritance-based polymorphims
// 
//    Interface
//        ^
//     ___|_____
//    |        |
//  Plane    Boat
//
//
//    


// Interface
class IGameObject
{
    public:
        virtual ~IGameObject(){};
        virtual void update() = 0;
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

class FactoryGameObjects
{
    public:

        // Factory method : single place where to create all concrete classes
        static std::unique_ptr<IGameObject> makeGameObject(ObjectType type)
        {
            if( type == ObjectType::PLANE)
            {    
                _planes++;
                return std::make_unique<Plane>();
            }
            else if( type == ObjectType::BOAT)
            {    
                _boats++;
                return std::make_unique<Boat>();
            }
            return nullptr;
        }

        static void print_counts()
        {
            std::cout << "planes : " << _planes << std::endl;
            std::cout << "boats  : " << _boats << std::endl;
        }

    private:
        // Avoid from explicity being called
        FactoryGameObjects() {};
        ~FactoryGameObjects() {};
        FactoryGameObjects(const FactoryGameObjects& other) = delete;
        FactoryGameObjects& operator=(const FactoryGameObjects& other) = delete;

        // counters
        inline static int _boats{0};
        inline static int _planes{0};
};

int main()
{
    std::unique_ptr<IGameObject> obj1 = FactoryGameObjects::makeGameObject(ObjectType::PLANE); // calling Plane()
    std::unique_ptr<IGameObject> obj2 = FactoryGameObjects::makeGameObject(ObjectType::BOAT); // calling Boat()
    std::unique_ptr<IGameObject> obj3 = FactoryGameObjects::makeGameObject(ObjectType::BOAT); // calling Boat()

    FactoryGameObjects::print_counts(); //  planes : 1
                                        // boats  : 2

    return 0;
}