/** sizeof
 */
#include <iostream>
#include <vector>

int main()
{
    // sizeof()
    //   The compiler figures out the size at compile-time

    int x = 7;                 // Local variable (primitive type)
    int* px = &x;              // Pointer
    int array[] = {1,3,5,7,9}; // A stack allocated array
    int* pdynamic_array = new int[5];  // A heap allocated array
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};


    std::cout << "size_of x             : " << sizeof(x) << " bytes\n"               // size_of x             : 4 bytes
              << "size_of px            : " << sizeof(px) << " bytes\n"              // size_of px            : 8 bytes
                                            //        ^~~
                                            // This is a pointer that points to an address in the stack memory
                                            // An address is 8 bytes in a 64-bit architecture
              << "size_of array         : " << sizeof(array) << " bytes\n"           // size_of array         : 20 bytes
                                            //        ^~~~~
                                            //   This is an array of int. The compiler know since it is allocated 
                                            // in the stack
                                            // sizeof(int) * num_elems = 4 bytes * 5 elements = 20 bytes 
              << "size_of pdynamic_array: " << sizeof(pdynamic_array) << " bytes\n" // size_of pdynamic_array: 8 bytes
                                            //        ^~~~~~~~~~~~~~
                                            // This is a pointer that points to a block of heap memory

              << "size_of v             : " << sizeof(v) << " bytes\n"; // size_of pdynamic_array: 24 bytes
                                            //        ^~~~~~~~~~~~~~
                                            //   This is a container (data-structure). The size is the
                                            // size of the data-strucure, not the number of elements
                                            //
                                            //   To kwnon the number of elements of v, we call 'c.size()'

    return 0;
}