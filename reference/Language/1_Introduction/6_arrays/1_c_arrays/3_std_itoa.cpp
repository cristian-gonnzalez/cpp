/** Raw array (C-style arrays): Initialize with std::iota
 */
#include <iostream>
#include <numeric>   // std::iota
#include <iterator>  // std::begin, std::end


int main()
{ 
    {
        int ids[100];

        // Initialize array with increasing values starting at 0
        std::iota(std::begin(ids), std::end(ids), 0);

        // Using iterators to show the contents
        std::cout << "[";
        for (auto it = std::begin(ids); it != std::end(ids); ++it)
            std::cout << *it << ", ";
        std::cout << "]\n";  // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, ]
    }
    
    {
        // Sintax for creating a few elements (fixed-size of 5 elements)
        int arr[] = {1,2,3,4,5};
    
        std::cout << "[";
        for (auto it = std::begin(arr); it != std::end(arr); ++it)
            std::cout << *it << ", ";
        std::cout << "]\n";  // [1, 2, 3, 4, 5, ]
    }
}
