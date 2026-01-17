#include "IObserver.h"
#include <iostream>


// Note: RAII
//    We will automatically register our Whacher to a subject
//    when we create it
Whatcher::Whatcher(const std::string& name, ISubject& subject)
//                                                  ~
//                                          Im passing this in by reference so that is has
//                                       to be something that is created
:_name{std::move(name)}, _subject(subject)
{
    _subject.add_oberver(shared_from_this());
}

// Note: RAII
//    We will automatically remove our Whacher from the subject
//    that is observing
Whatcher::~Whatcher()
{
    _subject.remove_oberver(shared_from_this());
}

void Whatcher::on_notify()
{
    std::cout << _name << " say hello!\n"; 
}
