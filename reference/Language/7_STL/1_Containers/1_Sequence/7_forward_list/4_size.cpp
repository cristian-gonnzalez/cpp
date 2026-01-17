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

void push_back(std::forward_list<int>& list, int value)
{
    // Again, the iterator library provides another method called distance
    //
    // distance:
    //      Returns the distance between two iterators
    //
    // Defined in header <iterator>
    //
    //      template< class InputIt >
    //      typename std::iterator_traits<InputIt>::difference_type
    //                                  distance( InputIt first, InputIt last );
    //
    auto pos = begin(list);

    // We use std::distance to calculate the actual size.
    // Consider that we are walking the entire list O(N)
    int size = std::distance( begin(list), end(list) );
    std::advance( pos, size - 1 );

    list.insert_after( pos, value ); 
}


int main()
{
	std::forward_list<int> mylist{1,2,4};

    print_list(mylist); // [1, 2, 4, ]
  
    // Lets insert at the end (push_back)
    //my_list.insert_after( end(mylist), 5 ); 
                        //  ~~~~~~~~~~
                        //
                        //    [1]  ->  [2]  ->  [4]   _    5
                        //                            ^    ^ 
                        //                          end()  |
                        //                         We cannot insert after the end
                        //                              SEGFAULT

    //my_list.insert_after( end(mylist)-1, 5 ); 
    //                      ~~~~~~~~~~~~~
    //                     We cannot move back

    //auto pos = begin(mylist);
    // Lets try to advance to the last element
    //std::advance( pos, mylist.size() - 1 );
    //                          ~~~~~
    //                 has no member named 'size'

    // WARNING: You might just want to use a std::list, but
    //          this is good practice, showing how ligthweight
    //          forwards list is.
    push_back( mylist, 5 );
    push_back( mylist, 6 );

    print_list(mylist); // [1, 2, 4, 5, 6, ]

    push_back( mylist, -7 );
    push_back( mylist, -5 );

    print_list(mylist); // [1, 2, 4, 5, 6, -7, -5, ]

    return 0;
}