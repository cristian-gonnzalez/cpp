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
    // 4. CTAD (Class Template Argument Deduction) with std::vector
    //
    
    // Case A: One element and Two elements
    //
    //   The compiler can deduce T = double.
    //   initializer_list<double> is viable → preferred.
    std::vector v3{3.14};     // vector<double> with one element {3.14}
    std::vector v4{3, 3.14};  // vector<double> with {3, 3.14}

    // Case C: Three or more elements
    //
    // {3, 3.14, 1.5} CTAD error: std::vector<double, double>
     std::vector v5{3, 3.14, 1.5};  // ERROR      


    return 0;
}
