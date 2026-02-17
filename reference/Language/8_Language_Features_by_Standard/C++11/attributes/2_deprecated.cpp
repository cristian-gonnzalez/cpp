/** Attributes: deprecated
 */

#include <iostream>

/*
  Since C++14, you can provide a message:

    [[deprecated("reason")]]

  deprecated affects API lifetime

*/


// Instead of using namespaces to deprecate a function, use attribute 'deprecated' 
//
// NOTE: Using namespaces and named 'deprecated' is technically legal, but not good practice, 
// because:
// 
//     - It conflicts semantically with the attribute name.
//     - It can confuse readers.
//
//   It is common to name namespace 'legacy' instead of 'deprecated'. But a better choice is to use
// attributes
namespace deprecated {
    [[nodiscard]]
    int generate_meaningful_value()
    {
        return 42;
    }
}

// NOTE: order really does not matters but this order is clearer since nodiscard affects 
// usage behavior, while deprecated affects API lifetime
[[nodiscard, deprecated()]]
int generate_meaningful_value()
{
    return 42;
}

int main()
{
    int stored = generate_meaningful_value();
    //           ^~~~~~~~~~~~~~~~~~~~~~~~~
    // warning: 'int generate_meaningful_value()' is deprecated [-Wdeprecated-declarations]

    return 0;
}