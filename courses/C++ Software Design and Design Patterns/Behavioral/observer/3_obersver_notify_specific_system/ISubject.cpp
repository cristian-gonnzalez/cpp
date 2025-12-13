#include "ISubject.h"
#include "IObserver.h"
#include <iostream>

ISubject::~ISubject()
{
}
void ISubject::add_oberver(EventType type,  IObserver* obs)
{
    if( !_observers.contains(type) )
        _observers[type] = std::list<IObserver*>();    
    _observers[type].push_back(obs);
}
void ISubject::remove_oberver( EventType type, IObserver* obs)
{
    if( _observers.contains(type) )
    {
        // found the observer list
        _observers[type].remove(obs);
        
    }
}

void ISubject::notify_all()
{
    for(auto& [type, observer_list ]: _observers)
    {
        std::cout << "Notifying for event " << std::endl;
        for(auto& obs : observer_list)
            obs->on_notify();
    }
}


void ISubject::notify(EventType type)
{
    if( _observers.contains(type) )
    {
        std::cout << "Notifying for event " << std::endl;
        for(auto& obs : _observers[type])
            obs->on_notify();
    }
}