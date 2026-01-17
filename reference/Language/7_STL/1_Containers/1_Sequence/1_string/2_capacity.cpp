/** STL std::string, char*, const char*, and string literals in C++ | Modern Cpp Series Ep. 112
 */

#include <iostream>
#include <string>

int main()
{
    
    std::string s{"Hello"};
          //      ~~~~~~
          // "Hello" is actually call a 'const char*' or string literal 
     
    // Capacity section:
    std::cout << s << std::endl                            // Hello
              << "size_of : "<< s.size() << std::endl;      // size_of : 5
                             //   ~~~~
                             // returns the number of characters (It is not counting te null 
                             // terminating character)
    std::cout << "capacity: "<< s.capacity() << std::endl;  // capacity: 15
                             //  ~~~~~~~~~
                             // returns the number of characters that can be held in 
                             // currently allocated storage
    
    // Reduces memory usage by freeing unused memory
    //
    // Note: 
    //      It is a non-binding request to reduce capacity() to size(). It depends on the 
    // implementation if the request is fulfilled.
    //
    //      If (and only if) reallocation takes place, all pointers, references, 
    // and iterators are invalidated.
    s.shrink_to_fit();
    std::cout << "capacity: "<< s.capacity() << std::endl;  // capacity: 15
    
   
    
    return 0;
}