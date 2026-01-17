/** STL std::list | Modern Cpp Series Ep. 118
 */
#include <iostream>
#include <list>

void print_list(const std::list<int>& list)
{
	std::cout << "[";
	for(const auto& e:list)
		std::cout << e << ", ";
	std::cout << "]\n";
}

int main()
{
	std::list<int> my_list{5,1,2,9,3,4, 0};

	// NOTE: 
  //      std::sort requires randam access iterators and so CANNOT BE USED WITH LIST.
  //      That's why std::list has sort method
  //
  //  template< class Compare >
  //  void sort( Compare comp );
  //                     ~~~~   ->  bool cmp(const Type1& a, const Type2& b);
  //                      ^
  //              You can pass-in your own comparator 
  //
  // Approximately N·log(N) comparisons using operator<.
	my_list.sort();

	print_list(my_list); // [0, 1, 2, 3, 4, 5, 9, ]

	
  // reverse:
  //      Reverses the order of the elements
	my_list.reverse();

	print_list(my_list); // [9, 5, 4, 3, 2, 1, 0, ]

  // Transverse the list using a reverse iterator
	std::cout << "[";
	for( std::list<int>::reverse_iterator it = my_list.rbegin(); 
                                          it!= my_list.rend(); 
                                          it++ )
	std::cout << *it << ", ";
	std::cout << "]\n"; // [0, 1, 2, 3, 4, 5, 9, ]

  // reverse:
	//      removes elements satisfying specific criteria
	my_list.remove_if( [](int n)
                       {
                         return n < 1;
                         //     ~~~~~~
                         //     Removes all elements less than 1 
                       } );

	print_list( my_list );  // [9, 5, 4, 3, 2, 1, ]

  return 0;
}