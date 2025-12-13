/** using vs typedef
 */
#include <iostream>
#include <unordered_set>


// Equivalent
typedef std::unordered_set<int> IntSet;

using uIntSet = std::unordered_set<int>;


// Equivalent
typedef void (*pfn)(int);

using upfn = void (*)(int);


int main()
{
    
    return 0;
}