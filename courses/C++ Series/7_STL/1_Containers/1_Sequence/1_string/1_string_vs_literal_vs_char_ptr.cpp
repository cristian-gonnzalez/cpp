/** STL std::string, char*, const char*, and string literals in C++ | Modern Cpp Series Ep. 112
 */

#include <iostream>
#include <string>
/*
Strings library

    The std::string is a container of characters.

    The C++ strings library includes support for three general types of strings:

        - std::basic_string - a templated class designed to manipulate strings of any character types.
        - std::basic_string_view (C++17) - a lightweight non-owning read-only view into a subsequence of a string.
        - Null-terminated strings - array of characters terminated by a special null character.
        
std::basic_string:
-----------------
    The class template std::basic_string generalizes how sequences of characters are manipulated and stored. 
String creation, manipulation, and destruction are all handled by a convenient set of class methods 
and related functions.

    Several specializations of std::basic_string are provided for commonly-used types:

Defined in header <string>

    Type	                        Definition
    std::string	                    std::basic_string<char>
    std::wstring	                std::basic_string<wchar_t>
    std::u8string (since C++20)	    std::basic_string<char8_t>
    std::u16string (since C++11)	std::basic_string<char16_t>
    std::u32string (since C++11)	std::basic_string<char32_t>


std::string s = ['H','e','l','l', 'o', \0 ]
                ~~~~~~~~~~~~~~~~~~~~~~~~~~
                It is basically an array of characters with the nul terminating character that
                indicates the last character of a string
    The stl actually gives us is a way to manupulate or operate or find substring within the string


template<
    class CharT,
    class Traits = std::char_traits<CharT>,
    class Allocator = std::allocator<CharT>
> class basic_string;


*/
int main()
{
    // Note: String literal
    //      A string literal is a series of characters for ex: "Hello World\0" and it does
    // have the null terminating character.
    //
    //  const char*           ['H','e','l','l', 'o', \0 ]
    //  ~~~~~     ^
    //        Pointer to an amount of characters and it is not changing
    //
    //      That's differaten than if I have a 'char*' which is pointer to a series of character.
    //                                          ~~~~~
    //                                        Remember that a pointer stores an address
    //   
    //     Also know as a 'string constant' is created by enclosing a seuqence of characters with " "'s.
    // The null byte ("\0") at the end, is automatically included.
    //      
    //      The reason that string literals are not modifiable, is beacause the compiler will
    // generate assemby code (and eventually a binary from the assembly), which stores the 
    // 'string lieral' in read-only region of the executable binary.
    // 
    
    
    // When we are constructing this string, we are able to implicity convert this string literal 
    std::string s{"Hello"};
          //      ~~~~~~
          // "Hello" is actually call a 'const char*' or string literal 
    
    std::cout << s << std::endl; // Hello

    // A string is a series of charactes so it is essentially wrapping around an array of characters   
    
    
    return 0;
}