/** std::array (Modern C++)
 */
#include <iostream>
#include <numeric>   // std::iota
#include <iterator>  // std::begin, std::end
#include <array>

int main()
{ 
    // The STL lobrary provides a class template (std::array) that wraps a C-style array 
    // with the benefits of a standard container such as knowing its own size,
    // random access, etc.

    {
        std::array<int, 100> ids;
        //         ^~~  ^~~
        //        Type  Size (known at compile time)
        //          (fixed-size)  
        
        // Initialize array with increasing values starting at 0
        std::iota(std::begin(ids), std::end(ids), 0);

        // .at() 
        //   Performs bounds checking.
        //   If the index is out of range, std::out_of_range is thrown.
        try
        {        
            ids.at(100000) = 9;     // Out of bounds
        }
        catch( const  std::out_of_range& e)
        {
            std::cout <<  e.what() << std::endl; // array::at: __n (which is 100000) >= _Nm (which is 100)

        }

        // Using iterators to show the contents
        std::cout << "[";
        for (auto it = std::begin(ids); it != std::end(ids); ++it)
            std::cout << *it << ", ";
        std::cout << "]\n"; // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, ]
    }
    {
        // Sintax for creating a few elements
        std::array<int, 5> arr = {1,2,3,4,5};
    
        std::cout << "[";
        for (size_t i=0; i < arr.size(); ++i)
        //                       ^~~~
        //                      We know the size
            std::cout << arr[i] << ", ";
        std::cout << "]\n";  // [1, 2, 3, 4, 5, ]
    }
    
    return 0;    
}
