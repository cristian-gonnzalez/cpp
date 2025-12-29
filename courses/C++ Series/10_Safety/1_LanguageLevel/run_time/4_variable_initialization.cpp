/** C++ Safety part 1 of n - Language Level Safety
 *  Run-Time
 */

#include <iostream>
#include <vector>

/*
Variable initialization

    - You should almost always intialize your variables
    - Use curly braces initialization to avoid error
    - Can show the classic big in std::accumulate where type is inferred
    - Note:
        * The exception to the rule of 'always initialize your variables' may
        be for large storage buffer -- no need to do any work if you will just
        overwrite the data.
        * There are some PR's in C++ for '=void' which is similar to void initilization
        the D-language


https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es23-prefer-the--initializer-syntax

*/

float return_float()
{
    return 3.14f;
}

int main()
{
    int a{};
    int b{0};
//    int c{3.14}; // Not allowed
    int d(3.14);  // Allowed but implicit conversion to int silently
    int e{return_float()}; // Allowed but produce warning

//    std::vector<int> v{1.24, 3.51, 133.3}; // Not allowed, narrowing conversion
  return 0;
}