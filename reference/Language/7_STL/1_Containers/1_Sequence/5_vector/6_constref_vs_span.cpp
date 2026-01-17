/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <iostream>
#include <vector>
#include <span>


void print_data_by_constref( const std::vector<long>& param )
//                                                  ^
//                        Pass-by-ref to avoid copy of the whole vector
{
}



void print_data_span(std::span<long> param )
//                   ~~~~~~~~~
{
}

int main()
{
    std::vector<long> v;

    print_data_by_constref(v);
    // Even better, in the case we have a const reference, meaning I known Im printing the 
    // data. This means I just trying to get a view into the container.
    print_data_span(v);


    return 0;
}