/** Raw array (C-style arrays) 
 */
#include <iostream>

/*
 Array:
    An array stores its elements contiguously in memory.
*/

int main()
{ 
    // The local variable ids allocates space for 100 integers on the stack and it points to the start of
    // the array
    int ids[100];
    //     ^~~~^
    //      Number of elements in brackets
    //
    //  We decide the size of our array at compile-time. 
    //  This is a 'fixed-size' array

    //  The array is created contiguosly in memory. There is no guarantee what is in the array 
    // when created. It is created with garbage data
    //
    // ids = [?, ?, ?, ?, ..., ?]
    //        0  1  2  3       99
    //
    //  We need to actually initialize our array.


    // Compute number of elements:
    size_t num_elems = sizeof( ids ) / sizeof(int);

    std::cout << "[";
    for( size_t i=0; i< num_elems; ++i )
        std::cout << ids[i] << ", ";
    std::cout << "]\n"; // [9, 32365, 724165464, 32365, 724165424, 32365, 724165464, 32365, 8, 0, 8, 0, 6, 0, 6, 0, 4, 0, 4, 0, 2, 0, 2, 0, 16449785, 16711933, 0, 0, 16646394, 0, 16711931, 0, 0, 0, 0, 0, 0, 0, 0, 0, 656, 0, 41, 0, 39, 0, 717899997, 32365, 0, 0, 0, 0, 719432928, 32365, 719432928, 32365, 0, 0, 0, 0, 719432928, 32365, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ]

    // random-access: O(1)
    ids[0] = 12345;
    std::cout << "ids[0]: " << ids[0] << std::endl; // ids[0]: 12345

    // Initialize the array manually.
    for( size_t i=0; i< num_elems; ++i )
        ids[i] = i;

    std::cout << "[";
    for( size_t i=0; i< num_elems; ++i )
        std::cout << ids[i] << ", ";
    std::cout << "]\n"; // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, ]

    
    // SEGFAULT
    // ids[10000] = 9; // ERROR 
    //     ~~~~~
    // There is no check boundaries if we access out of bounds in the array

    return 0;    
} 