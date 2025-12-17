/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <iostream>
#include <array>

/*
    Since we are working with templetas that measn we are generating code. This means 
that the type and size must match when passing into a function

*/

void print_std_array_mismatch( std::array<int, 5>& data )
//                             ~~~~~~~~~~~~~~~~^~~
//                                       Size does not match
{
} 


int main()
{
    std::array<int, 4> data;
                //  ^ 

    // Im goint to get an error if the size is not the same
    //print_std_array_mismatch(data);
    //                         ^~~~ 
    //   invalid initialization of reference of type 'std::array<int, 5>&' 
    // from expression of type 'std::array<int, 4>'

    return 0;
}
