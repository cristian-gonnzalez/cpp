/** STL std::string, char*, const char*, and string literals in C++ | Modern Cpp Series Ep. 112
 */

#include <iostream>
#include <string>



int main()
{
    
    std::string s{"Hello"};
     
    std::cout << s << std::endl                             // Hello
              << "size_of : "<< s.size() << std::endl       // size_of : 5
              << "capacity: "<< s.capacity() << std::endl;  // capacity: 15

    //
    // Element access
    //

    // c_str:
    //      If we are passing inside of a C-function because you need compatibility with
    // a C library, we do want a 'const char*' (inmmutable or non-changeable string) 
    //
    //      Returns a non-modifiable standard C character array version of the string
    std::cout << s.c_str() << std::endl;

    // operator[] 
    //      Accesses the specified character
    s[0] = 'h'; 
    
    // data:
    //      If you want a pointer to the actual data
    //      Returns a pointer to the first character of a string
    std::cout << s.data() << std::endl; // hello

    std::cout << "address_of s   : " << &s << std::endl;          // address_of s   : 0x7ffc5f4d9480
    std::cout << "address_of data: " 
              << static_cast<const void*>(s.data()) << std::endl; // address_of data: 0x7ffc5f4d9490
    //                                ~~~~~~~~~~~~
    //                operator<< for char* treats it as a C-string and 
    //                tries to print the characters.
    //                Casting to const void* forces std::cout to use the 
    //                overload that prints the pointer’s address instead.
    
    // Note that 'data' and 's' have a separate address. This is because data() returns the internal
    // array and s is the actual object
    //
    //  class basic_string
    //  {
    //        char*   _data;
    //                ~~~~~
    //              data() returns the internal array
    //  };
    //  
    //  's' holds the actual string object 
    //
    //  To see internal representation, use: gdb --silent --tui ./prog


    return 0;
}