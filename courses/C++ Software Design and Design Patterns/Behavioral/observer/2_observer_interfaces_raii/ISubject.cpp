#include "ISubject.h"
#include "IObserver.h"

ISubject::~ISubject()
{
}
void ISubject::add_oberver( std::shared_ptr<IObserver> obs )
{
    _observers.push_back(obs);
}
void ISubject::remove_oberver( std::shared_ptr<IObserver> obs )
{
    _observers.remove_if( [&](const std::weak_ptr<IObserver>& w) 
                          {
                            return w.lock() == obs;
                            //       ~~~~~
                            // creates a shared_ptr that manages the referenced object
                          });
}

void ISubject::notify_all()
{
    // Cleanup dead observers
    _observers.remove_if( [](const std::weak_ptr<IObserver>& w) 
                          {
                                return w.expired();
                          });

    for(auto& obs: _observers)
    {
        if (auto sp = obs.lock())
            sp->on_notify();
    
    }
}