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
    // Create a fordward_list which is more lightweight
    // and efficient then a list (if we are just traversing
    // fordwards)
	std::forward_list<int> mylist{1,2,4};

    print_list(mylist); // [1, 2, 4, ]

    //
    // Modifiers
    //

    // push_front:
	//      Inserts an element to the beginning is constant 
    // time operation O(1)
	mylist.push_front(0);

    print_list(mylist);  // [0, 1, 2, 4, ]

   return 0;
}l