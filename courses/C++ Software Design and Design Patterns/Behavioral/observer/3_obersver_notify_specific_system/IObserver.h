#pragma once
#include "ISubject.h"
#include <string>

// abstract class which we derive from 'Base class'
class IObserver
{
    public:
        virtual ~IObserver() {};
        virtual void on_notify() = 0;
};


// concrete implementation of our IObserver
class Whatcher : public IObserver
{
    public:
        // Note: RAII
        //    We will automatically register our Whacher to a subject
        //    when we create it
        explicit Whatcher(const std::string& name, ISubject& subject, EventType type = EventType::UncommingMovies);

        // Note: RAII
        //    We will automatically remove our Whacher from the subject
        //    that is observing
        ~Whatcher();

        void on_notify();

    private:
        std::string _name;
        EventType   _type;
        ISubject&   _subject;
};
