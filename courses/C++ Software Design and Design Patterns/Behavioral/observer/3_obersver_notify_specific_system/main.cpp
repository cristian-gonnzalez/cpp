#include <iostream>
#include "ISubject.h"
#include "IObserver.h"


int main()
{
    Netflix subject;

    Whatcher w1("Whatcher 1", subject, EventType::UncommingMovies);
    Whatcher w2{"Whatcher 2", subject, EventType::UncommingMovies};
    Whatcher w3{"Whatcher 3", subject, EventType::NewSeries};
    
    {
        Whatcher w4{"Whatcher 4", subject, EventType::NewMovies};
    
    }

    subject.notify_all(); // o3 was destroyed but we still have a pointer to it


    subject.notify(EventType::NewSeries); // o3 was destroyed but we still have a pointer to it

    return 0;
}