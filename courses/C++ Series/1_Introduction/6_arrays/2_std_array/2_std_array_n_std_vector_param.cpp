/** std::array / std::vector parameter
 */
#include <iostream>
#include <array>
#include <vector>

void print_array( std::array<int, 5> arr )
           //                ^~~~~~~
           //     The type and size still must match
{
    std::cout << "[";
    for(size_t i=0; i< arr.size(); i++)
        std::cout << arr[i] << ", ";
    std::cout << "]\n";
}

void print_vector( std::vector<int> v )
                  // We dont need to match the size
{
    std::cout << "[";
    for(size_t i=0; i< v.size(); i++)
        std::cout << v[i] << ", ";
    std::cout << "]\n";
}

int main()
{
    // std::array is container that wrappers the c-style array. This means that
    // the c-array is inside this container so this is still a stack-allocated array.
    std::array<int, 5> array = {1,3,5,7,9};
    print_array(array); // [1, 3, 5, 7, 9, ]

    // std::vector is a container that creates dynamic size array (heap allocated).
    std::vector<int> v = {1,3,5,7,9};    
    print_vector(v); // [1, 3, 5, 7, 9, ]

    return 0;
}