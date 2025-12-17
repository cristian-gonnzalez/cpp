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
	std::forward_list<int> mylist{1,2,4};

    print_list(mylist); // [1, 2, 4, ]

    //
    // Modifiers
    //

    // insert_after:
    //      Inserts elements after an element.
    //
    // iterator insert_after( const_iterator pos, const T& value );
    //                                       ~~~
    //                          If I have the actual iterator, it is a
    //                     constant time O(1)  

    // Lets insert sth after the begining
	auto pos = begin(mylist);
    mylist.insert_after( pos, 5 ); 

    print_list(mylist);  // [1, 5, 2, 4, ]
                         //     ^

    // Lets insert sth two position after
	// pos = begin(mylist) + 2;
    //                  ^ ~~
    //         No match for 'operator+' 
    
    std::advance( pos, 2 );
    mylist.insert_after( pos, 3 ); 
    
    print_list(mylist);  // [1, 5, 2, 3, 4, ]
                         //           ^

	return 0;
}