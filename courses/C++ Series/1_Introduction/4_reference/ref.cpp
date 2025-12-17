#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

int main()
{
    std::string s1{"Hello"};
    std::string s2{"world"};

    
    std::cout << std::boolalpha
              << "std::string& is is reference? "
              << std::is_reference_v<std::string&> << std::endl;

    // References are not objects; they do not necessarily occupy storage
    // reference variable is an alias that is another name for an existing variable/object
    std::string& ref = s1;
    std::cout << "reference: " << ref  << " s1: " << s1 << std::endl;

              
    // Update the value of s1 using reference variable 
    ref = "Hola";
    std::cout << "reference: " << ref  << " s1: " << s1 << std::endl;

    // Update the value of s1 using reference variable 
    ref = s2;    
    std::cout << "reference: " << ref  << " s1: " << s1 << std::endl;


    // containers directly can’t store the references since it works wiht direct objects
    //std::vector<std::string&> v{ref};
    //v.push_back(ref);

    std::vector<std::reference_wrapper<std::string>> v{s1, s2};

    s1 = "Hi";
    
    for(const std::string& e: v)
        std::cout << e << std::endl;
    
}