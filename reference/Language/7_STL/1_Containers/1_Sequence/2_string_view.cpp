/** STL std::string_view and when to use it versus std::string | Modern Cpp Series Ep. 113
 */

#include <iostream>

/*

std::string_view: (C++ 17)
  
    It is an optimized way to read an string or just display some characters. We used string view 
when we want to avoid allocation (new/delete) to optimized code.

    Remember, a std::string is just a templated version with characters

template<
    class CharT,
    class Traits = std::char_traits<CharT>,
    class Allocator = std::allocator<CharT>   // There is some memory allocation
> class basic_string

class basic_string<char>
{
	char* data; // basic string need to allocate data (use new or delete)
	...
}

    An string_views is giving us a peek in some string where we are just looking into the data 
and we promise we are not going to change it.

    A typical implementation holds only two members, a pointer to a constant CharT and a size.

class string_view
{
	const char* _data; // Points to another data that actually exists (no allocation is made)
	size_t      _size;
}

Defined in header <string_view>
template<
    class CharT,
    class Traits = std::char_traits<CharT>
> class basic_string_view;

Type	                    Definition
std::string_view (C++17)	std::basic_string_view<char>
std::wstring_view (C++17)	std::basic_string_view<wchar_t>
std::u8string_view (C++20)	std::basic_string_view<char8_t>
std::u16string_view (C++17)	std::basic_string_view<char16_t>
std::u32string_view (C++17)	std::basic_string_view<char32_t>

    We have basically the same method of std::string

*/



void print_str_by_value(std::string str)
{
    str += "some more text";
	std::cout << str << std::endl;
}

// Use reference to avoid copies and not calling constructor to avoid un-necesary allocation
void print_str_by_ref(const std::string &str)
{
	std::cout << str << std::endl;
}

// the string view avoid allocation since it is a pointer to the actual data. It is a read-only view of the string
void print_str_by_sv(std::string_view str)
//                                   ^
//   Since it's a small data type, we can pass by value
{
	std::cout << str << std::endl;
}

int main()
{

    {
        std::string s{"This is some really long string ..."};

        // Im making a copy of the string whenever I called this function
        // Even if I modify the string inside the function, Im modifying the copy
        // so that another allocation was being made 
        print_str_by_value(s); // This is some really long string ...some more text

        // If I print my string, it has his own piece of memory so the modification
        // does not affect
        std::cout << s << std::endl; // This is some really long string ...


        // To avoid copies, we could pass by reference and if I dont want 
        // to modify, I use 'const'.
        // Whener I call this function, we are referring to the original string
        print_str_by_ref(s);   // This is some really long string ...
    }

    {
        // we decided to use char* to void calling constructor of std::strings
        const char* s = "This is some really long string ...";

        // Even though, we have allocated this 'const char*', when I pass by ref, we are
        // still constructing a string so we are still doing an allocation.
        print_str_by_ref(s);

        // On the other hand, if we pass using std::string_view, no allocation is made 
        // since the class is just a pointer to the actual data. 
        print_str_by_sv(s);
    }

    {
        std::string s{"Cristian"};
        std::string_view sv{s};

        std::cout << "size_of s : " << sizeof(s) << std::endl;  // size_of s : 32
        std::cout << "size_of sv: " << sizeof(sv) << std::endl; // size_of sv: 16

        std::cout << "s.size()     : " << s.size() << std::endl;  // size_of s : 32
        std::cout << "s.capacity() : " << s.capacity() << std::endl;  // size_of s : 32
        
    }
	
}
