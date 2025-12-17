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
	std::forward_list<int> list1{1,2,4,5,6,-7,-5,0};
	std::forward_list<int> list2{-2,0,3,4,5};

    list1.sort();
    list2.sort();

    print_list(list1); // [-7, -5, 0, 1, 2, 4, 5, 6, ]
    print_list(list2); // [-2, 0, 3, 4, 5, ]

    // merge:
    //      Merges two sorted lists.
    //                 ~~~~~~~~~~~~
    //      Merge is a destructive operation. It transfer list2 to list1 
    list1.merge(list2);

    print_list(list1); // [-7, -5, -2, 0, 0, 1, 2, 3, 4, 4, 5, 5, 6, ]
    print_list(list2); // []
   
    return 0;
}