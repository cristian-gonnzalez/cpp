/** Attributes: fallthrough
 */

// -std=c++23 -Wall -Wextra
#include <print>

/*
[[fallthrough]]:

    Must be placed immediately before the next case or default

    Cannot appear in the last case

*/

// We are getting a warning 'implicit-fallthrough' in case 1 since we have
// some code without a 'break' but this is our intended behabiour
//
// To avoid this use: attribute 'fallthrough'
//
// NOTE:
//   The compiler warns if control flow falls through to the next case
// without a break, return, throw, etc.
/*void implicit_fallthrough( int input )
{
    switch(input)
    {
        case 0:
        case 1:
            std::println("fallthrough here");
        //  ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~    
        // warning: this statement may fall through [-Wimplicit-fallthrough=]
        case 2:
        default:
            std::println("default");
    }
}
*/

void fallthrough( int input )
{
    switch(input)
    {
        case 0:
        case 1:
            std::println("fallthrough here");
        [[fallthrough]];
        //             ^
        // [[fallthrough]] is a statement attribute.
        // It must be followed by a semicolon because it applies to an empty statement.
        case 2:
        default:
            std::println("default");
    }
}

int main()
{
    return 0;
}