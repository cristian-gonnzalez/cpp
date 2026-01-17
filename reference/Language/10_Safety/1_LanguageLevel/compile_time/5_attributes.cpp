/** C++ Safety part 1 of n - Language Level Safety
 *  Modern Cpp Series Ep. 233
 */

#include <iostream>
/*
Safety in C++ Programming: Lenguage Level Features -- compile-time

- Attributes

    - Attributes are 'hints' to the compiler that may help define the expected behaviour or properties 
    of code
        * Use double brackets [[]].

            [[deprecated]]
            [[noreturn]]
            [[nodiscard]]

        * Thy are form of documentation -- (stronger than comments) that are explicit 
        and can help enforce behaviour

                -- Because attributes are part of the souce code, you are less likely
                to rely on the correct set of flags being set or ommited.
                -- Note: May need to turn on .Werror to treat attributes as errors
*/

[[deprecated]] // This will produce a 'warning message'
void old_way() 
{
}

void work() 
{
    std::cout << "works\n";
}

void fall_through( int input )
{
    switch(input)
    {
        case 0:
        {
            [[fallthrough]];
            break;
        }
        case 1:
        {
            std::cout << "fall is ok here too\n";
            [[fallthrough]];
            break;
        }
        case 3:
        {
            // should get a warning
            break;
        }
        default:
        {
            std::cout << "default\n";
        }
    }
}

[[nodiscard]] // More explicit than -Wunused-result
int meaningful_value_generated()
{
    return 42;
}

int main()
{
    old_way();

   meaningful_value_generated(); // Will trigger error if we dont store return value
   return 0;
}

/*
x86-64 gcc 15.2
Compiler options for execution
 -std=c++23 -Weffc++ -lpthread
Compiler stderr
<source>: In function 'int main()':
<source>:72:12: warning: 'void old_way()' is deprecated [-Wdeprecated-declarations]
   72 |     old_way();
      |     ~~~~~~~^~
<source>:28:6: note: declared here
   28 | void old_way()
      |      ^~~~~~~
<source>:74:30: warning: ignoring return value of 'int meaningful_value_generated()', declared with attribute 'nodiscard' [-Wunused-result]
   74 |    meaningful_value_generated(); // Will trigger error if we dont store return value
      |    ~~~~~~~~~~~~~~~~~~~~~~~~~~^~
<source>:65:5: note: declared here
   65 | int meaningful_value_generated()
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~
<source>: In function 'void fall_through(int)':
<source>:43:28: warning: attribute 'fallthrough' not preceding a case label or default label
   43 |             [[fallthrough]];
      |                            ^
<source>:49:28: warning: attribute 'fallthrough' not preceding a case label or default label
   49 |             [[fallthrough]];
      |                            ^
Program returned: 0

*/
