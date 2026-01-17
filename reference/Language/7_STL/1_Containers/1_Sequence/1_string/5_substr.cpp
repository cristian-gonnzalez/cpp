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
    // Iterators
    //
    //      Because a string is just a series of characters we can iterator on it

    for( auto&e : s)
        std::cout << e << ", "; // H, e, l, l, o, 
    std::cout << std::endl;


    // find(): finds the first occurrence of the given substring
    if( auto n = s.find('l'); n != std::string::npos )
                                  //~~~~~~~~~~~~~~~~
                                  // This is a special value equal to the maximum value 
                                  // representable by the type size_type
        std::cout << s << " contains l\n"; // Hello contains l 

    // contains() (C++23)
    //      Checks if the string contains the given substring. The substring may be one of the following:
    //
    //          - A string view sv (which may be a result of implicit conversion from another std::basic_string).
    //          - A single character ch.
    //          - A null-terminated character string s.
    std::cout << std::boolalpha 
              << s.contains("ell") << std::endl // true
              << s.contains("el") << std::endl   // true
              << s.contains('l') << std::endl;  // true


    return 0;
}