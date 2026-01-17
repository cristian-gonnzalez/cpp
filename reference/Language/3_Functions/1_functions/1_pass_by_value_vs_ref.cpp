/** Functions: Pass-by-value vs Pass-by-reference 
 */
#include <iostream>
#include <vector>
#include <algorithm>

// We pass a copy (inefficient on large objects)
void pass_by_value( std::vector<int> v )
{
    std::cout << "address_of v (copy): " << &v << std::endl;
    v[0] = 99; // modifies only the copy
}

// Using reference is more efficient; no copy is made
void pass_by_ref(std::vector<int>& v)
//                                ^
// A reference is an alias — not a separate object.
{
    std::cout << "address_of v (ref): " << &v << std::endl;
    v[0] = 99; // modifies the original vector
}

int main()
{
    std::vector<int> v(10);
    std::fill( std::begin(v), std::end(v), 0);
    
    std::cout << "address_of v: " << &v << std::endl; // address_of v: 0x7ffd7277f910

    pass_by_value( v );                               // address_of v (copy): 0x7ffc99299d70
    std::cout << "v[0] : " << v[0] << std::endl;      // v[0] : 0

    pass_by_ref( v );                                 // address_of v (ref): 0x7ffd7277f910
    std::cout << "v[0] : " << v[0] << std::endl;      // v[0] : 0

    return 0;
}