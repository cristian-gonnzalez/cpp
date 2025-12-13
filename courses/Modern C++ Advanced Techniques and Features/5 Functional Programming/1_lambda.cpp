/** Lambda
 * 
 *
 */
#include <iostream>

int main()
{

    auto hello = []() -> std::string
    //                 ^ ~~~~~~~~~~~
    //           You can explicity specify the return-type if you want to
    //          Useful when you dont want the compiler deduces the return type (i.e const char* instead of std::string)
                {
                    return "Hello";
                };

    auto world = []
    //               ^
    //           You can omit the () if empty 
                {
                    return "world";
                };

    std::cout << hello() << " " << world() << std::endl; // Hello world

 
    return 0;
}