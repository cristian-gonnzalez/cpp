/** Const-correctness: Functions with const parameters
 */
#include <iostream>
#include <vector>
#include <algorithm>


// We add 'safety' to the code by making read-only argument
void pass_by_ref(const std::vector<int>& v)
//               ^~~~~
{
    std::cout << "address_of v (ref): " << &v << std::endl;
    
    // error: assignment of read-only location '(& v)->std::vector<int>::operator[](0)'
    // v[0] = 99; 
}

int main()
{
    std::vector<int> v(10);
    std::fill( std::begin(v), std::end(v), 0);
    
    pass_by_ref( v );                                 // address_of v (ref): 0x7ffd7277f910
    std::cout << "v[0] : " << v[0] << std::endl;      // v[0] : 0

    return 0;
}