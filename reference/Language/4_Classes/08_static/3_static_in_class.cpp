/** Static member variables and member functions in a Class
 */
#include <iostream>

/*
  NOTE:
    The thread-safe initialization guarantee since C++11 applies to
  local static variables inside functions, not to static class members.

*/

/* api.h */

struct API
{
    //
    // Declaration of static member variables
    //
        static int MAJOR /*= 0 */;
    //  ^~~~~~    
    //   As static varaibles have static-storage duration, static member variables 
    // are shared by all instances of the class. That' why cannot be initialized 
    // using constructors.

        // error: ISO C++ forbids in-class initialization of non-const static member   
        //                 ^~~~  
        static int MINOR /*= 0 */;   // Must be defined outside the class

        static const int SomeConstValue{105};
        //                             ^~~~~
        //    Only const static variables can be initialized in class

    //
    // Static member function
    //

        // Static member functions do not depend on an object instance.
        //
        // They can access only:
        //   - static data members
        //   - other static member functions
        //
        // Note:
        //   Static member functions cannot access the non-static data members or member functions 
        // of the class since there is no instance created. 
        static int get_major_version()
        {
            API api{}; // Local variables are allowed

        // _local = 7;
        //  ^~~~~~
        // error: invalid use of member 'API::_local' in static member function

        //  std::cout << this << std::endl;
        //               ^~~~
        //  error: 'this' is unavailable for static member functions

            return MAJOR;
        }


    // member variables:
        int _local;
};


/* api.cpp */

//
// Definition of static member variables
//

// The scope of static member variables and functions is within the class
//  ~~~~~
int API::MAJOR = 7;
int API::MINOR = 0;
//             ^~~~
//  We must initialized explicitly using the class name and scope resolution operator outside the class

int main()
{
    std::cout << "SomeConstValue: " << API::SomeConstValue <<std::endl;   // SomeConstValue: 105
    std::cout << "Major: " << API::MAJOR <<std::endl;   // Major: 7
    std::cout << "Minor: " << API::MINOR <<std::endl;   // Minor: 0
                           // ^~~~~~~~~~
                           // No instance of API is required
                           // Static members exist independently of objects

   std::cout << "Major: " << API::get_major_version() <<std::endl;   // Major: 7
 
    return 0;
}