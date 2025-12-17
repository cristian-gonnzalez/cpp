/** STL std::string, char*, const char*, and string literals in C++ | Modern Cpp Series Ep. 112
 */

#include <iostream>
#include <string>

// Keep in mind, passing strings by reference 
void print_string( const std::string& s)
{
    std::cout << s << std::endl                             // Helloqwertyuipasdfghjklzxcvbnmqwertyuipasdfghjklzxcvbnm
              << "size_of : "<< s.size() << std::endl       // size_of : 55
              << "capacity: "<< s.capacity() << std::endl;  // capacity: 55
}


int main()
{
    
    std::string s{"Hello"};
     
    std::cout << s << std::endl                             // Hello
              << "size_of : "<< s.size() << std::endl       // size_of : 5
              << "capacity: "<< s.capacity() << std::endl;  // capacity: 15

    // lets try to grow the string                   
    s += "qwertyuipasdfghjklzxcvbnm";
    s += "qwertyuipasdfghjklzxcvbnm";
    
    std::cout << s << std::endl                             // Helloqwertyuipasdfghjklzxcvbnmqwertyuipasdfghjklzxcvbnm
              << "size_of : "<< s.size() << std::endl       // size_of : 55
              << "capacity: "<< s.capacity() << std::endl;  // capacity: 60

    // Reduces memory usage by freeing unused memory
    s.shrink_to_fit();               
    std::cout << s << std::endl                             // Helloqwertyuipasdfghjklzxcvbnmqwertyuipasdfghjklzxcvbnm
              << "size_of : "<< s.size() << std::endl       // size_of : 55
              << "capacity: "<< s.capacity() << std::endl;  // capacity: 55
    
    // Why is this important?
    //
    //      The string are how we use them or append to them can often be a cost in our program
    //      For ex: when pass-by-value into a function (copyng the whole string) or appending 
    // character can allocate more space than necesary.
    print_string( s );  // Helloqwertyuipasdfghjklzxcvbnmqwertyuipasdfghjklzxcvbnm
                        // size_of : 55
                        // capacity: 55

    return 0;
}