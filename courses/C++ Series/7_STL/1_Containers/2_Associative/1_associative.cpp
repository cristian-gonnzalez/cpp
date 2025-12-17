#include <iostream>

/*

Associative containers:
----------------------

	Associative containers implement sorted data structures that support
Search, insertion, and removal operations wiht O(log n) complexity.

	
	Types:
	    std::set        – collection of unique keys (sorted)
	    std::map        – collection of unique key–value pairs (sorted by key)
	    std::multiset   – collection of keys, duplicates allowed (sorted)
	    std::multimap   – collection of key–value pairs, duplicates allowed (sorted by key)

Templates:
---------

	Collection of keys (set/multiset):                  Collection of key–value pairs (map/multimap):

	Defined in header <set>                             Defined in header <map>
	template<                                           template< 
	    class Key,                                          class Key,
	                                                        class T,                       // Value associated with the key  
	    class Compare = std::less<Key>,                     class Compare = std::less<Key>,
	    class Allocator = std::allocator<Key>               class Allocator = std::allocator<std::pair<const Key, T>>
	> class set/multiset;                               > class map/multimap;


Meaning of key template parameters:
----------------------------------

template<
    class Key,                                  // the key type (index into the structure)
    .....

    class Compare = std::less<Key>, //        Because of it is a sorted data-structure,
                    ~~~~~~~~~               it needs a comparison function object. Sorting 
        By default, std::less<Key>,         is done using the key comparison function object
      meaning keys are sorted in            Compare.
      ascending order 
                                       
    class Allocator = [...]
>;

*/


int main()
{
	return 0;
}
