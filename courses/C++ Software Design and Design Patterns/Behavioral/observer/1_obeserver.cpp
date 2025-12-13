/** The Observer Design Pattern in C++ - Part 1 of n - A simple implementation
 */

#include <iostream>
#include <string>
#include <list>

/*
Behavioral pattern:
    Most of these design patterns are specifically concerned with comunication between objects.


Observer: 
    It is a publisher/subscribe pattern, which allows a number of observer objects to see an event.

    It is a pattern in which an object, named the 'subject', maintains a list of its dependents, called
'observers', and notifies them automatically of any state changes, usually by calling on of their 
methods.

    For ex: a mouse-click trigger 1 to many events:
        When a mouse clicks (our subject) a series of events are triggered (by our observers)

    This pattern i s often used in MVC (Model View Controller) between the Model (subject) and the view 
(observers).
 
                 uses                    manipulates
          USER -----------> CONTROLLER --------------> MODEL
           ^                                             |
           |      sees                    updates        |  
           |----------------   VIEW    <-----------------|          
                

Observer pattern: 1st implementation

    We are going to have two classes:
    
        Subject: ( Publisher or Observable)
             This is the 'thing' of interest that we want to keep track of any interesting 
    state changes
            Can also think of it as a 'publisher' because it will 'notify' of interesting events.

        Observer: (Subscriber)
             These are the objects we want to react based on the subject.
             'observer' because it is waiting to be notified of something interesting.
             'subscriber' yo can think of as 'I subscribe to Netflix and am notified on my app when
        a new movie comes out. 

    -----------                 ----------------
   | Observer 1| ----------->  |   Subject 1   |
    -----------                | (I am         |
    -----------                |  interesting) |
   | Observer 2| ----------->   ---------------
    -----------                     ^ 
    -----------                     |  
   | Observer 3| -------------------|
    -----------

*/


class Observer
{
    public:
        Observer(std::string name)
        :_name{name}
        {
        }

        // This is out reaction when sth interesting happens
        void on_notify()
        {
            std::cout << _name << " say hello!\n"; 
        }

    private:
        std::string _name;
};

// This is the 'interesting thing'
class Subject
{
    public:
        void add_oberver( Observer* obs)
        {
            _observers.push_back(obs);
        }
        void remove_oberver( Observer* obs)
        {
            _observers.remove(obs);
        }

        // The subjects responsibility is to 'notify' all of the observers
        void notify_all()
        {
            for(const auto& o: _observers)
                o->on_notify();
        }

    private:
        std::list<Observer*> _observers{};
};

int main()
{
    Subject subject{};

    Observer o1{"observer 1"};
    Observer o2{"observer 2"};
    Observer o3{"observer 3"};

    // register the observers
    subject.add_oberver(&o1); 
    subject.add_oberver(&o2);
    subject.add_oberver(&o3);

    subject.notify_all();
    /*
    observer 1 say hello!
    observer 2 say hello!
    observer 3 say hello!
    */

    subject.remove_oberver(&o3);

    std::cout << "\n";
    
    subject.notify_all();
    /*
    observer 1 say hello!
    observer 2 say hello!
    */

    return 0;
}