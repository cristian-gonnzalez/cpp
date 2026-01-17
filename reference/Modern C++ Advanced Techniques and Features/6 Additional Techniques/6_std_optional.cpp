// -std=c++20
/**  std::optionañ
 *
 */
#include <iostream>
#include <optional> // std::optional

// std::optional is a way of specifyng a possibly empty value, similar to a nullable column in a database table
// It is usefull if you have a function that may return a value or maybe doesnt return a value
std::optional<int> getQuotient(int n, int d)
{
    if( d!= 0)
        return n/d;
    else
        return {};
        //     ~~~
        // It will create an std::optional object with no value
        //
        //  std::optional<int>()
}


int main()
{   
    std::optional<int> result = getQuotient(10, 2);

    if( result )
    //  ~~~~~~~~  if the optional object contains sth
        std::cout << "Int value: " << *result << std::endl; // Int value: 5
        //                            ^
        //                        access the object
    else
        std::cout << "No int value: " << std::endl;
    
    return 0;
}