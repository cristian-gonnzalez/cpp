/** Functions: ambiguous call 
 */
#include <iostream>


// Forward declaration: provides the function signature.
// int add(int a, int b); // equivalent
int add(int, int);

// Declared + defined version for float
float add(float a, float b)
{
    std::cout << "float add(float, float): ";
    return a+b;
}

int main()
{ 
    std::cout << add(1, 2) << std::endl; // int add(int, int): 3
    
    // ERROR: ambiguous call
    // std::cout << add(1.2, 2.1) << std::endl;
    // Both arguments are double by default, so:
    //      - candidate 1: 'int add(int, int)'      : converting double -> int requires narrowing
    //      - candidate 2: 'float add(float, float)': converting double -> float also requires narrowing
    // No overload is better → ambiguous

    std::cout << add(1.2f, 2.1f) << std::endl; // float add(float, float): 3.3
                    //  ^     ^
                    // we need to specify or cast the value static_cast<float>(2.1)

    // float version chosen}
    std::cout << add(1.2f, 2.1) << std::endl; // float add(float, float): 3.3
    std::cout << add(1.2, 2.1f) << std::endl; // float add(float, float): 3.3
    
    // ERROR: ambiguous call
    // std::cout << add(1, 2.1f) << std::endl;
    // Both overloads require exactly one conversion.
    //      - candidate 1: 'int add(int, int)'
    //      - candidate 2: 'float add(float, float)'
    
    std::cout << add(static_cast<float>(1), 2.1f) << std::endl; // float add(float, float): 3.1

    return 0;    
}

// Definition of int overload
int add(int a, int b)
{
    std::cout << "int add(int, int): ";
    return a+b;
}