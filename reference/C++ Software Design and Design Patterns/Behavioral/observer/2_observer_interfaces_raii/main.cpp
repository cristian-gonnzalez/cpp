#include <iostream>
#include "ISubject.h"
#include "IObserver.h"


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
                 |  ConcreteSubject     |                              subject   |  ConcreteObserver  |          
                 |----------------------|<---------------------------------------|--------------------|
                 | + get_state()        |                                        | + on_notify()      |   
                 | + set_state()        |                                        |                    |   
                 |                      |                                        | - subject          |   <--- RAII: instance or referece of the actual subject 
                 |  - subject_state     |                                         -------------------- 
                  ----------------------                                                                       ConcreteObserver( ISubject& subject )
                                                                                                               : _subject( subject )  
                                                                                                               {
                                                                                                                  _subject.attach( this );  
                                                                                                               }
                                                                                                               ~ConcreteObserver()
                                                                                                               {
                                                                                                                  _subject.detach( this );  
                                                                                                               }

    This pattern is:
            Flexible : yes, e.g. notify_all, notrify(specific subsytem) we can easily derive new IObserver classes
            Maintainable: Yes, the heavy lifting is abstractedto each devivation of IObserver.
                          Subject just iterates threough the right set of observers
            Extensible: Yes, we showed this with the diferent types of IObservers

*/


int main()
{
    ConcreteSubject subject;

    //Whatcher o1("Whatcher 1", subject);
    //Whatcher o2{"Whatcher 2", subject};

    // Observers must be allocated via shared_ptr so shared_from_this() works
    auto o1 = std::make_shared<Whatcher>("Whatcher 1", subject);
    auto o2 = std::make_shared<Whatcher>("Whatcher 2", subject);

    {
        // Registration and Lifetime
        //
        // What happends if one of these observers disappears and we notify all?
        // For ex:
        //      o3 subscribe to the subject and then it is destroyed
        //      The subject notify all but it still have a pointer to o3
        //
        // So, whom is the reponsability to remove the observer from the list? 
        //
        // This start being problematic.
        {   
            // Temporary observer
            // Whatcher o3{"Whatcher 3", subject};
            auto o3 = std::make_shared<Whatcher>("Whatcher 3", subject);
        /*    
            // register the observers
            subject.add_oberver(&o1);
            subject.add_oberver(&o2);
            subject.add_oberver(&o3);
        */

        } // o3 is destroyed when it leaves the scope since it is allocated on the stack 
          // But the Subject is still holding a pointer of o3
        
        subject.notify_all(); // o3 was destroyed but we still have a pointer to it

        //subject.remove_oberver(&o3);  -> Is this ok? do we have to remove the observer    
    
        // The way we can fix this is with RAII
        // So, our subject is the resource. In this way, the responsability of lifetime of the watcher
        // is the own whatcher (we register in the constructor and remove in the destructor)
    }


    std::cout << "\n";
    
    // ownership and lifetime matters since we only want to notify objects that are still alive
    subject.notify_all();

    return 0;
}