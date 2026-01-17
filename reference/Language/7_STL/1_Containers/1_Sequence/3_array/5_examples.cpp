/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <iostream>
#include <array>
#include <algorithm> // std::sort

/*
Element access
*/

void legacy_C_CodeBase( int* elem, size_t size )
{

}
 
int main()
{
    {
        std::array<int, 5> arr;
        arr.fill(0);

        std::cout << "[";
        for(auto& e: arr)
            std::cout << e << ", ";
        std::cout << "]\n"; // [0, 0, 0, 0, 0, ]

    }

    {
        std::array<int, 5> arr{11,2,8,4,5};
        std::sort( arr.begin(), arr.end() );

        for(auto& e: arr)
            std::cout << e << ", ";
        std::cout << "]\n"; // 2, 4, 5, 8, 11, ]
    }    

    // You might also need to interface with C code. For that, you have
    // data() direct access to the underlying contiguous storage
    {
        // We can use std::arr with legacy c-code. It is safer and performant 
        std::array<int, 5> arr{11,2,8,4,5};
        
        legacy_C_CodeBase( arr.data(), arr.size() );
    }


    return 0;
}
