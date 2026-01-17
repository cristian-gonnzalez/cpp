/** pIMPL (pointer to implementation) - More Stable APIs
 *  
 */
#include <iostream>

/*
  When changes are made to a header file, all sources including it needs to be recompiled. 
It can cause build time issues due to the fact that even when a small change to the implementation 
is made everyone has to wait some time until they compile their code. One way to solve this problem 
is by using the PImpl Idiom.

The PImpl Idiom: (Pointer to IMPLementation) 
  It is a technique used for separating implementation from the interface. It minimizes header exposure 
and helps programmers to reduce build dependencies by moving the private data members in a separate class 
and accessing them through an opaque pointer.

*/

//
// person.h
//

//   One disavangates of this actual implementation is that every modification of this file (i.e: 
// re order member fields) will cause a recompile of each cpp files where it is include

//#pragma once

#include <string>

struct Person
{
    public:
        Person(std::string s);
        std::string get_attributes() const;

    private:
        // Expose of private acess
        std::string _name{"n/a"};
        std::string _strength{"n/a"};
        std::string _speed{"n/a"};

};

//
// person.cpp
//

//#include "person.h"

Person::Person(std::string s)
: _name{s}
{
}

std::string Person::get_attributes() const
{
    return "{ " + 
           _name + ", " +
           _strength + ", " +
           _speed + " }";
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