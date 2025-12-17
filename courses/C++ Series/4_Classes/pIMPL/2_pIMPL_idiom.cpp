/** pIMPL (pointer to implementation) - More Stable APIs
 *  
 */
#include <iostream>

/*

The PImpl Idiom: (Pointer to IMPLementation) 
  It is a technique used for separating implementation from the interface. It minimizes header exposure 
and helps programmers to reduce build dependencies by moving the private data members in a separate class 
and accessing them through an opaque pointer.


*/

// 
// person.h (Interface)
//

//   This file is more stable since it more common to modify the implementation and not
// this file so we prevent recompilation of each cpp files where it is include

//#pragma once

#include <string>
#include <memory>

class Person
{
    public:
        Person(std::string s);
        std::string get_attributes() const;

    private:

        struct pImplPerson;                      // Internal implementation class
        //     ^~~~~~~~~~~
        //  I declare: I say this exists only in the scope of Person

        std::unique_ptr<pImplPerson> _impl;     // Pointer to the internal implementation
                                                //   In terms of aligment, this is good since
                                                // it is just a pointer (see actual size of
                                                // unique_ptr)

// Note:
//   Possible increase in memory usage due to more heap allocation than with the default structure which can 
// be critical in embedded software development.
};

//
// person.cpp (Implementation)
//

//#include "person.h"

// Note: 
//   Using this as 'piece of data' but we might
// cretate constructors/methods to initialize and 
// manipulate this data
struct Person::pImplPerson
{
    std::string _name{"n/a"};
    std::string _strength{"n/a"};
    std::string _speed{"n/a"};
};


Person::Person(std::string s)
: _impl{ std::make_unique<pImplPerson>() }
{
    _impl->_name = s;
}

std::string Person::get_attributes() const
{
    return "{ " + 
           _impl->_name + ", " +
           _impl->_strength + ", " +
           _impl->_speed + " }";
}


//
// main.cpp
//

//#include "person.h"
//#include <iostream>

int main()
{
    Person p{"Mario"};
    std::cout << p.get_attributes() << std::endl; // { Mario, n/a, n/a }
 
    return 0;
}