/** STL std::list | Modern Cpp Series Ep. 118
 */
#include <iostream>
#include <list>

/*
std::list: 
                           
 Defined in header <list>

template<
    class T,                              ->  We can sort of think of those as 
    class Allocator = std::allocator<T>    the individual nodes
> class list;

*/

void print_list(const std::list<int>& list)
{
	std::cout << "[";
	for(const auto& e:list)
		std::cout << e << ", ";
	std::cout << "]\n";
}

int main()
{
	std::list<int> my_list;

	//  An inserting at the end so that is a constant time operation O(1)
    //  We have a pointer to the tail
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);
    
	print_list(my_list); // [1, 2, 3, 4, ]
 
    //
    // Inserting with 'iterators' O(1)
    //
    
    // This is double-linked-list data-structure. The advantage is if I know
    // the position where I want to insert by having an iterator, then Im able
    // to insert in constant time O(1)                  ~~~~~~~~    
	//    
    //      [1] -> [2] -> [3] -> [4]  ___
    //       ^  <-     <-     <-       ^ 
    //       |
    //     begin()                    end()
    my_list.insert( begin(my_list), 0 );
	            //  ~~~~~~~~~~~~
                //    iterator 
	my_list.insert( end(my_list), 5 );
                 // ~~~~~~~~~~~
                 // returning after the last element
                 // position 
    
    print_list(my_list); // [0, 1, 2, 3, 4, 5, ]


    return 0;
}