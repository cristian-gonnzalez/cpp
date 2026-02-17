/** Attributes: nodiscard
 */

#include <iostream>

/*
Attributes are used to provide additional information to the compiler.
They can enforce or suggest certain compiler behavior.

Syntax

    [[ attribute-list ]]  c++11
    [[ using attribute-namespace : attribute-list ]]  c++17

see: https://cppreference.com/w/cpp/language/attributes.html

- nodiscard:

    Since C++20, [[nodiscard]] can contain a message:

        [[nodiscard("This value must be used")]]

    nodiscard affects usage behavior.
*/

// This attributes generates this compiler warning
//
//  warning: ignoring return value of 'int generate_meaningful_value()', declared 
// with attribute 'nodiscard' [-Wunused-result]
//
//^~~~~~~~~
[[nodiscard]]
int generate_meaningful_value()
{
    return 42;
}


int main()
{
    generate_meaningful_value();
//  ^~
//   We are not storing the result and the compiler does not warn about that
// even though we use -Wall, -Wno-result, -Wunused-result
//
//   To avoid this, use 'nodiscard' 
//
// NOTE: Werror
//   -Werror turns all warnings into compilation errors.


    return 0;
}