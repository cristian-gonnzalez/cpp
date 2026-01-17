#pragma once

#include <list>
#include <map>
class IObserver; // <-- Forward declaration, we will include IObserver.h in the implementation of ISubject


enum class EventType
{
    UncommingMovies,
    NewSeries,
    NewMovies
};    

// Interface (abstract class)
class ISubject
{
    public:
        ISubject(){};
        // we always need to define virtual ~destructor when
        // defining hierarchy 'Base class'
        virtual ~ISubject();

        virtual void add_oberver(EventType type, IObserver* obs);
        virtual void remove_oberver(EventType type, IObserver* obs);

        virtual void notify_all();
        virtual void notify(EventType type);

    private:
        // aggregate
        std::map< EventType, 
                  std::list<IObserver*> > _observers{};
};



// Concrete subject
class Netflix : public ISubject
{
    public:
        
};


