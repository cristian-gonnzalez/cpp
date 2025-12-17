/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <iostream>
#include <array>

/*
std::array:

Defined in header <array>
template<                            -   
    class T,              <-- Type    |   Type and size are piece of information we care about of arrays
    std::size_t N         <-- Size    |   We dont have to deal with this issue of C-style array that 
> struct array;                      -  decays to a pointer T* when pass in function  
                                        
                                        
    std::array is a container that encapsulates fixed size arrays (holding a C-style array).

    std::array combines the performance and accessibility of a C-style array with the benefits 
of a standard container (knowing size, supporting assignment, random access iterators, etc):
    
        - Fixed-size arrays: We cannot resize.
        - Stack allocated
        - Homogenous type: All elements are the same type

    std::array is a Container and satisfies the requirements of ContiguousContainer,(since C++17) 
and partially satisfies the requirements of SequenceContainer.

*/

void print_c_array(int data[4], size_t size )
{
    std::cout << "size_of data: " << sizeof(data) << " bytes\n";           // size_of data: 8 bytes
    std::cout << "real size_of data: " << sizeof(int)*size << " bytes\n";  // real size_of data: 16 bytes
} 


void print_std_array( std::array<int, 4>& data )
{
    std::cout << "size_of data: " << sizeof( data ) << " bytes\n";  // size_of data: 16 bytes
    std::cout << "size data   : " << data.size() << " elements\n";  // size data   : 4 elements
} 


int main()
{
    // Static c-style arrays that are fixed size
    // int data[4];  
    
    std::array<int, 4> data;

    std::cout << "size_of data : " << sizeof( data ) << " bytes\n";     // size_of data  : 16 bytes
    std::cout << "size data    : " << data.size() << " elements\n";      // size data    : 4 elements
    std::cout << "max size data: " << data.max_size() << " elements\n";  // max size data: 4 elements
    //                                     ~~~~~~~~~
    //              Because each std::array<T, N> is a fixed-size container, the value 
    //          returned by max_size equals N (which is also the value returned by size()).

    //print_c_array(data, 4); // size_of data: 8 bytes

    // It is not devaying into a pointer
    print_std_array(data); // size_of data: 16 bytes
                           // size data   : 4 elements
    
    return 0;
}
