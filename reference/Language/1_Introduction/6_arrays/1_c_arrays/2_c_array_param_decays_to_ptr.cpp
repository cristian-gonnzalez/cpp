/** C-array parameter decays to a pointer 
 */
#include <iostream>

//      CppInsights translate this as:
//
// void print_array(int * arr)
//                ~~~~~~~~~~~
void print_array( int arr[] )
//                ~~~~^~~~~
//              array on function parameter always decays into pointer
//       This is a behaviour from C to avoid copies of array.      
{
    std::cout << "size_of arr: " << sizeof(arr) << " bytes\n";
                                 //       ~^~~~
                                 // 'arr' will return size of 'int*'
}

void print_array( int arr[], size_t size )
//                                  ^~~~~~~
//        C-libraries needs to pass-in the size      
{   
    std::cout << "[";
    for(size_t i=0; i< size; ++i)
        std::cout << arr[i] << ", ";
    std::cout << "]\n";
}


int main()
{
    int array[] = {1,3,5,7};
    
    std::cout << "size_of array: " << sizeof(array) << " bytes\n"; // size_of array: 16 bytes
    
    print_array(array); // size_of arr: 8 bytes
    
    size_t arr_size = sizeof(array) / sizeof(int);
    print_array(array, arr_size); // [1, 3, 5, 7, ]


    
    return 0;
}