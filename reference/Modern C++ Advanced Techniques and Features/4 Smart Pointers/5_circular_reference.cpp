/** std::weak_tr
 *
 *      You can also use std::weak_ptr to prevent circular references between 'std::shared_ptr's
 */
#include <iostream>
#include <memory>  // std::shared_ptr/std::weak_ptr

struct Car;

struct Person
{
    std::shared_ptr<Car> _car;

    void add_car( std::shared_ptr<Car> car )
    {
        _car = car;
    }
};

struct Car
{
    std::shared_ptr<Person> _owner;
    
    void add_owner(    std::shared_ptr<Person> owner )
    {
        _owner = owner;
    } 
};


int main()
{
    { // Circular references problem
        
        // Creates a person that has no car yet
        auto person{ std::make_shared<Person>() };

        std::cout << "rc (person): " << person.use_count() << std::endl;       // rc (person): 1
        std::cout << "rc (car)   : " << person->_car.use_count() << std::endl; // rc (car)   : 0

        {
            // Creates a car and add to the person
            auto car{ std::make_shared<Car>() };
            car->add_owner( person );
            person->add_car( car );


            std::cout << "rc (person): " << person.use_count() << std::endl; // rc (person): 2
            std::cout << "rc (car)   : " << car.use_count() << std::endl;    // rc (car)   : 2
        } // car should be disappeared

        // The person should not have car but as we keep a shared_ptr, objects are not destroyed
        std::cout << "rc (person): " << person.use_count() << std::endl;       // rc (person): 2
        std::cout << "rc (car)   : " << person->_car.use_count() << std::endl; // rc (car)   : 1

    }



    return 0;
}