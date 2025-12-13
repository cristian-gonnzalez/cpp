/** Raw pointer issues
 */

#include <iostream>

int main()
{    
    // Raw pointers allow sharing.
    //
    // But this example is lacking the sense of owernship and not to mention there
    // are dangers with pointer if we forget to delete once we start allocating
    // on the heap

    // Raw pointer allow also:
    //      - Room for error: meaning forgetting to de-allocate or calling the wrong delete
    //      - Ownership: None of the pointer has exlusive ownership or share information if the
    //                   resource was deleted already
    {
        int x = 42;

        int* ptr = &x;
        std::cout << "*ptr : "  << *ptr << std::endl; // *ptr : 42

        // Creates a second pointer that points to the same value
        // In effect we are sharing
        int* ptr2 = ptr;
        std::cout << "*ptr2 : "  << *ptr2 << std::endl; // *ptr2 : 42
    }
   
    {
        // Creates a heap allocated array
        int* array = new int[100];

        size_t num_elems = sizeof(array) / sizeof(array[0]);
        for(size_t i=0; i < num_elems; i++)
            array[i] = i;


        int* ptr = array;
        std::cout << "*ptr : "  << *ptr << std::endl; // *ptr : 42

        // Creates a second pointer that points to the same value
        // In effect we are sharing
        int* ptr2 = ptr;
        std::cout << "*ptr2 : "  << *ptr2 << std::endl; // *ptr2 : 42
    
        // delete array; // 2. Anothe mistake here, we delete one element instead of the entire array

        delete[] array; 

    } // 1. We could forgotten to delete array -> Memory leak

    {
        // Creates a heap allocated array
        int* array = new int[100];
        size_t num_elems = sizeof(array) / sizeof(array[0]);
        for(size_t i=0; i < num_elems; i++)
            array[i] = i;


        int* ptr = array;
        
        delete[] array; // delete and then share

        int* ptr2 = ptr;
        //          ^~~~
        //       We have pointer that points to sth that was deleted -> Undefined behaviour
    }

   return 0;
} 