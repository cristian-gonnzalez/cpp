/** STL std::forward_list | Modern Cpp Series Ep. 119
 */
#include <iostream>
#include <forward_list>


void print_list(const std::forward_list<int>& list)
{
	std::cout << "[";
	for(const auto& e:list)
		std::cout << e << ", ";
	std::cout << "]\n";
}

int main()
{
    std::forward_list<int> list1{-7, -5, -2, 0, 0, 1, 2, 3, 4, 4, 5, 5, 6};
    
    // unique:
    //      Removes consecutive duplicate elements
    //
    //      void unique();
    //
    //      template< class BinaryPred >
    //      void unique( BinaryPred p );  Uses to compare the elements.
    //                   ~~~~~~^^^^
    //                     ^     Predicate means that returns true or false
    //                     | 
    //        Binary means it takes two parameters
    //
    //      size_type unique();                 (C++20)
    //
    //      template< class BinaryPred > 
    //      size_type unique( BinaryPred p );   (C++20)

    // The complexity is O(N-1)
    list1.unique();
    print_list(list1); // [-7, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]

    return 0;
}