/** Pointer Arithmetic
 */
#include <iostream>
#include <numeric> // std::iota

// IMPORTANT: A pointer and an array are NOT the same thing.
//
//   A pointer stores an address.
//   An array is a contiguous block of memory with a fixed size.
//
//   These are different concepts, but pointer arithmetic allows us 
// to move through an array.
//
//   We can also subtract pointers (decrement).

int main()
{
    // Creates an array statically allocated (fixed-size)
    // int array[5] = {1,3,5,7,9}; // An array is a contiguos block of memory
    int array[] = {1,3,5,7,9};     // equivalent : Leave the bracket empty and the
                                   // compiler deduces the size 
                                      
    std::cout << "address_of array: " << array << std::endl; // address_of array: 0x7ffd9d185730

    // Each of these elements is 4 bytes since it is an array of int
    //   ^  ^  ^  ^  ^ 
    // [ 1, 3, 5, 7, 9]
    //   0  1  2  3  4

    //
    // Pointer increment
    //
    {
        int* px = array; // px points to the first element of the array
     
        std::cout << "px is       : " << px << std::endl;  // px is       : 0x7ffd9d185730
        std::cout << "px points to: " << *px << std::endl; // px points to: 1

        // increment px
        px++;
        std::cout << "px is       : " << px << std::endl;  // px is       : 0x7ffd9d185734
        std::cout << "px points to: " << *px << std::endl; // px points to: 3
        // we move 4 bytes on the address when incremented even though we increment by '1'
        // Why four bytes? Because it is a 'int*' pointer to int and an int is 4 bytes 

        // Note: px++
        //   Everytime we increment a pointer, we are moving it the size of the data type
        px++;
        std::cout << "px is       : " << px << std::endl;  // px is       : 0x7ffd9d185738
        std::cout << "px points to: " << *px << std::endl; // px points to: 5
    }
    {
        // We cannot increment an array
        // array++;
        //      ^~~
        // error: lvalue required as increment operand
    } 
    //
    // C-Array de-reference
    //
    {
      // Show the array offset
      //   An array is a contiguous block of memory. Using pointer arithmetic,
      // we can offset an address and then dereference it.

      int* px = array; // px points to the first element
      
      // Instead of increment px, just add an offset
      std::cout << "*px: " << *(px + 0) << std::endl;  // px points to: 1
      std::cout << "*px: " << *(px + 1) << std::endl;  // px points to: 3
                           //        ^
                           //  offset of one integer (4 bytes)   
      std::cout << "*px: " << *(px + 2) << std::endl;  // px points to: 5
      std::cout << "*px: " << *(px + 3) << std::endl;  // px points to: 7
      std::cout << "*px: " << *(px + 4) << std::endl;  // px points to: 9
    }

    //
    // C-Array Offsets
    //
    {                               //  By default, array points to the start
                                    //   ^~~~~
      std::cout << "*(array + 0): " << *(array + 0) << std::endl;  // *(array + 0): 1
      std::cout << "*(array + 1): " << *(array + 1) << std::endl;  // *(array + 1): 3
      std::cout << "*(array + 2): " << *(array + 2) << std::endl;  // *(array + 2): 5
      std::cout << "*(array + 3): " << *(array + 3) << std::endl;  // *(array + 3): 7
      std::cout << "*(array + 4): " << *(array + 4) << std::endl;  // *(array + 4): 9

      // NOTE: brackets dereference
      //   When we use the brackets [], we are actually dereferencing a memory address 
      // with an offset (index).
      //
      // array[0] -> *(array + 0)
      //       ^               ^
      //       |---------------|
    }

    return 0;
}