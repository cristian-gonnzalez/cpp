/** STL std::span | Modern Cpp Series Ep. 115 (C++ 20)
 */

#include <iostream>
#include <span>
#include <array>
#include <vector>

/*
    std::span is related to string_view (C++ 20)
  
    Remeber, a string_view is a way to view into a string in a non-owning way and just be 
abe to read into that data-structure. It is sort of an optimization way to read an container. 

    Like std::string_view is a way to view (read-only) a std::string, span is a way to view containers 
that holds contiguous sequence of objects and you avoid copies.


std::span: (since C++20)

Defined in header <span>
    template<
        class T,
        std::size_t Extent = std::dynamic_extent
                    ~~~~~~
                   The number of elements in the sequence, or std::dynamic_extent if dynamic
    > class span;

    The class template span describes an object that can refer to a contiguous sequence of objects 
(std::array or vector) with the first element of the sequence at position zero. A span can either 
have a static extent, in which case the number of elements in the sequence is known at compile-time 
and encoded in the type, or a dynamic extent.

    A posible implementation, if a span has a dynamic extent, holds two members: a pointer to T and
a size. A sapn with statuc extent may have only one member: a pointer to T.

        array = [ , , , , , ]
                0 1 2 3 4 5 
                ^
                |         Span is a view into this array
               |_|
              span

        class span
        {
            T*      _ptr; // Points to another data structure that actually exists (no allocation is made)
            size_t  _size;
        }

    std::span van be use for contiguous containers. This means you could use it to look
into a string.

*/

void print_arr( const std::array<int, 4>& arr )
//                                    ^
//                                 size must match
{
	std::cout << "[";
	for(auto& e: arr)
		std::cout << e << ", ";
	std::cout << "]\n";
	
}


// Using span, we just have a view of the cotainer avoiding copies
// As it is a view class, we dont have to worry about passing by reference 
// and using const
//
// void print_container( const std::span<int>& arr )
//                       ~~~~~               ~
//                 If we pass by refenrece, we have to make it const since std::span is read-only
//                 Otherwise, it will give an error since std::span does not take ownership
void print_container( std::span<int> arr )
//                              ~~~
//                          Only we need to specify the type 
{
     if (std::dynamic_extent == arr.extent )
            std::cout << "dynamic extent ";
        else
            std::cout << "static extent = " << arr.extent << " ";

	std::cout << "[";
	for(auto& e: arr)
		std::cout << e << ", ";
	std::cout << "]\n";
}


int main()
{
	std::array<int, 4> arr{1, 2, 3, 4};

	print_arr(arr);       // [1, 2, 3, 4, ]
	print_container(arr); // dynamic extent [1, 2, 3, 4, ]
                          // ~~~~~~~~~~~~~~
                          // When passing to param by value, it is constructer with the default
                          // extent that is dynamic

    std::span span{ arr };
    if (std::dynamic_extent == span.extent )
            std::cout << "dynamic extent\n";
        else
            std::cout << "static extent: " << span.extent << " elements\n"; // static extent: 4 elements

    
    print_container(arr); // dynamic extent [1, 2, 3, 4, ]
     

	std::vector<int> vec{1,2,3,4,5,6,7};
	print_container(vec); // dynamic extent [1, 2, 3, 4, 5, 6, 7, ]

    // We dont have to pass the whole range of the container. Remember a span is just 
    // a look with a pointer into this data
	//
    // Given a subsquence of the vector
	print_container( std::span( vec.begin(), 3 ) ); // dynamic extent [1, 2, 3, ]
                         //     ~~~~~~~~~~~  ^
                         //        ^       we pass the size
                         //        |
                         //     Creating a sub-sequence of 3 elements

	return 0;
}