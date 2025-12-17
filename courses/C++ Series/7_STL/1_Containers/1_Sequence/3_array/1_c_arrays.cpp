/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <iostream>

/*
C-arrays:

    - Fixed-size arrays: We cannot resize.
    - Stack allocated
    - Homogenous type: All elements are the same type

*/

void print_array(int data[4], size_t size )
//               ~~~~~~~~~~~         ~~~~
//                   ^             You have to say the actual size  
//                   | 
//           array function parameter 'param' 
//         will be decaying to 'int *' even if
//         Im passing it with the array size
{
    // int data[] is 'decaying' to a pointer (type 'int* data'). In a way, this is very efficent,
    // because otherwise we would have to 'pass-by-value' and 'copy' the entire array.
    // Decaying a pointer, is very efficent but we do lose the 'size' information we may have had.
    std::cout << "size_of data: " << sizeof(data) << " bytes\n";           // size_of data: 8 bytes
    std::cout << "real size_of data: " << sizeof(int)*size << " bytes\n";  // real size_of data: 16 bytes
} 


int main()
{
    // Static c-style arrays that are fixed size
    //                                ~~~~~
    //                             We cannot resize
    //
    // The local variable data allocates 4 elements (int) on the stack and it points to the start of
    // the array                                                 ~~~~~
    int data[4]; // 
    int initialized[3] = {1,2,3};

    //      Arrays arent initialized so we dont know what's actually in these memory
    //
    // data [?,?,?,?]     -> size : 4 bytes (int) * 4 = 16 bytes 
    //       0 1 2 3
    //
    //      I know exactly what those three elements are because we use a initializer-list.
    //
    // initialized [1,2,3]
    //              0 1 2
    //             |______|
    //           Homogenous type -> all elements are the same types

    std::cout << "size_of data: " << sizeof(data) << " bytes\n";  // size_of data: 16 bytes

    // What does happend if I try to check the size of the array if I pass into a function?
    print_array(data, 4); // size_of data: 8 bytes
    //          ~~~~
    // arrays decay into pointers when we pass in a functions

    return 0;
}
