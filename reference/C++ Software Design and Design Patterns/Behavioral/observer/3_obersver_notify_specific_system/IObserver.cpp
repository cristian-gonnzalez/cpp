#include "IObserver.h"
#include <iostream>


// Note: RAII
//    We will automatically register our Whacher to a subject
//    when we create it
Whatcher::Whatcher(const std::string& name, ISubject& subject, EventType type )
:_name{name}, _subject(subject), _type{type}
{
    _subject.add_oberver(_type, this);
}

// Note: RAII
//    We will automatically remove our Whacher from the subject
//    that is observing
Whatcher::~Whatcher()
{
    _subject.remove_oberver(_type, this);
}

void Whatcher::on_notify()
{
    std::cout << _name << " say hello!\n"; 
}
