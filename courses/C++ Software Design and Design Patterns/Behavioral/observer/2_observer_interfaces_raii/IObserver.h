#pragma once
#include "ISubject.h"
#include <string>


/*

                  ----------------------                                         -----------------                                                        
                 |  ISubject            | observers                              |  IObserver     |          
                 |----------------------|-------------------------------------->O|----------------|
         virtual | + attach( Observer ) |  (add_observer)            virtual = 0 | + on_notify()  |   
         virtual | + detach( Observer ) |  (remove_observer)                      ---------------- 
                 |                      |                                                ^
         virtual | + notify()           | <-- for( auto& o: observers)                   |
                  ----------------------           o->update();                          | 
                          ^                                                              | 
                          |                                                              |
                  ----------------------                                         ---------------------                                                        
                 |  ConcreteSubject     |                                        |  ConcreteObserver  |          
                 |----------------------|                                        |--------------------|
                 |                      |                                        | + on_notify()      |   
                 |                      |                                        |                    |   
                 |                      |                                        | - subject          |   <--- RAII: instance or referece of the actual subject 
                 |                      |                                         --------------------         We know who we are observing
                  ----------------------
                                                                                                               ConcreteObserver( ISubject& subject )
                                                                                                               : _subject( subject )  
                                                                                                               {
                                                                                                                  _subject.attach( this );  
                                                                                                               }
                                                                                                               ~ConcreteObserver()
                                                                                                               {
                                                                                                                  _subject.detach( this );  
                                                                                                               }

*/



// abstract class which we derive from 'Base class'
class IObserver
{
    public:
        virtual ~IObserver() {};
        virtual void on_notify() = 0;
};


// concrete implementation of our IObserver
class Whatcher : public IObserver, public std::enable_shared_from_this<Whatcher>
{
    public:
        // Note: RAII
        //    We will automatically register our Whacher to a subject
        //    when we create it
        explicit Whatcher(const std::string& name, ISubject& subject);

        // Note: RAII
        //    We will automatically remove our Whacher from the subject
        //    that is observing
        ~Whatcher();

        void on_notify();

    private:
        std::string _name;
        ISubject&   _subject;
};
