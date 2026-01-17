/** Arrays: Range for-loop and std::fill
 */
#include <iostream>
#include <algorithm>   // std::fill
#include <iterator>    // std::begin, std::end
#include <array>


int main()
{ 
    std::array<int, 5> ids;
        
    // Another way to initialized an array
    std::fill(std::begin(ids), std::end(ids), 0);

    std::cout << "[";

    // Range-based for loop
    for (auto& e: ids)
        std::cout << e << ", ";
    std::cout << "]\n"; // [0, 0, 0, 0, 0, ]

    return 0;    
}
