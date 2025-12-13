#pragma once

#include <list>

/*

                  -------------------------------                                         -----------------                                                        
                 |  ISubject                     | observers                              |  IObserver     |          
                 |-------------------------------|-------------------------------------->O|----------------|
         virtual | + add_observer( Observer )    |                            virtual = 0 | + on_notify()  |   
         virtual | + remove_observer( Observer ) |                                         ---------------- 
                 |                               |                                                ^
         virtual | + notify()                    | <-- for( auto& o: observers)                   |
                  -------------------------------         o->update();                            | 
                          ^                                                                       | 
                          |                                                                       |
                  ----------------------                                         ---------------------                                                        
                 |  ConcreteSubject     |                                        |  ConcreteObserver  |          
                 |----------------------|                                        |--------------------|
                 |                      |                                        | + on_notify()      |   
                 |                      |                                        |                    |   
                 |                      |                                        | - subject          |  
                 |                      |                                         --------------------         
                  ----------------------                                                                       

*/


class IObserver; // <-- Forward declaration, we will include IObserver.h in the implementation of ISubject

class ISubject
{
    public:
        // we always need to define virtual ~destructor when
        // defining hierarchy 'Base class'
        virtual ~ISubject();

        virtual void add_oberver( std::shared_ptr<IObserver> obs );
        virtual void remove_oberver( std::shared_ptr<IObserver> obs );

        void notify_all();

    private:
        // aggregate
        std::list<std::weak_ptr<IObserver>> _observers{};
};


class ConcreteSubject : public ISubject
{
    public:
        
};


