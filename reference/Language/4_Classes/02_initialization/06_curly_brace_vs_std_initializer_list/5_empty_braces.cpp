/** List-initialization {} vs std::initializer_list<T>:
 */ 
#include <iostream>
#include <string>
#include <vector>

/* 
  {} and std::initializer_list are two different things.

    - std::initializer_list<T> is a type (a class template)
            - {} can trigger an std::initializer_list constructor
            if the type has one. Each element of the initializer-list 
            is list-initialized,

    - {} is syntax (list-initialization).           
            - {} braces apply special initialization rules, such as:
                * Preventing narrowing conversions
*/

int main()
{
    //
    // Initialization
    //

    //
    // 5. Empty braces
    //
    
    std::vector<int> v{};  // default constructor → empty vector
//    std::vector<int> v2(); // function declaration!  Not a vector


    return 0;
}
