/** Inheritance 
 */
#include <iostream>
#include <memory>

/*    
  Inheritance models an “is-a” relationship:
                          
        ┌────────┐
        │  Base  │
        └────────┘         Derived class 'is-a' type of Base
             ↑                 
        ┌─────────┐
        │ Derived │
        └─────────┘
   
  Ex:
            ┌────────┐
            │  Dog   │
            └────────┘         Golden 'is-a' type of Dog
             ____↑_______                 
            |            | 
        ┌─────────┐  ┌───────┐
        │ Golden  │  │ Husky │
        └─────────┘  └───────┘

  Access-level change based on inheritance type:

    | Base-class member |   Public inheritance   |   Protected inheritance   |   Private inheritance   |
    | ----------------- | ---------------------- | ------------------------- | ----------------------- |
    | public            | public in derived      | protected in derived      | private in derived      |
    | protected         | protected in derived   | protected in derived      | private in derived      |
    | private           | not accessible         | not accessible            | not accessible          |
*/

class Dog
{
    public:
        void bark()
        {
            std::cout << "bark!\n";
        }
        void walk()
        {
            _x += 1;
            _y += 1;
        }
    private:
        float _x, _y;   // 8 bytes =  4 bytes (float) + 4 bytes (float)
};

class Golden : public Dog
{
    public:
        void retrieve()
        {
            std::cout << "retrieving a stick\n";
            _stick++;
        }

    private:
        float _stick;   // 12 bytes =  4 bytes (float) + 8 bytes (Dog)
};

class Husky : public Dog
{
    public:
};


int main()
{
    {
        // Creating stack objects. These behaviour are defined at compile-time
        Golden g;                        // Dog()     -> Base constructor
    //  ^~~~~~                           // Golden()  -> Derived constructor
    //  At compile-time we are saying which dog it is 
        g.walk();
        g.bark();    // bark!

        Husky h;                        // Dog()     -> Base constructor
                                        // Husky()   -> Derived constructor
        h.walk();
        h.bark();    // bark!

    } // ~Husky()        -> Derived destructor
      // ~Dog()          -> Base destructor
      //
      // ~Golden()       -> Derived destructor
      // ~Dog()          -> Base destructor

    std::cout << std::endl;

    // One of the powers of inheritance-based prgramming is that we can 
    // create a general Dog and then decide at run-time if it is a husky
    // or Golden dog 
    {
    //           At run-time we choosing Golden     
    //                         ^~~~~~~~~~  
        std::unique_ptr<Dog> d{new Golden};
    //  ^~~~~~~~~~~~~~~~~~~~
    //  At compile-time we are just a dog

        d->walk();
    }
 
    // To show that all the functionality of Dog is in Golden:
    {
        std::cout << "size_of Dog   : " << sizeof(Dog) << " bytes\n"        // size_of Dog   : 8 bytes
                  << "size_of Golden: " << sizeof(Golden) << " bytes\n";    // size_of Golden: 12 bytes
    }

    return 0;
}