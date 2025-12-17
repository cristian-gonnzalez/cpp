#include <iostream>

/*
Unordered associative containers: (since C++11)
--------------------------------

	Unordered associative containers store elements into 'hash tables'.  
	They provide 'average O(1)' lookup, insertion, and deletion, and 'O(n)' worst-case time.

    With unordered data-structure in STL we are able to get some sort of performance gain
because we dont need to mantain some order. This is usually a difference between a tree-like 
strucutre for ordered-strucutres that give us logarithmic performance versus unordered-strucutures 
where we can usually improve our performance.

Types:
------

    unordered_set        – collection of unique keys, hashed by keys
    unordered_map        – collection of unique key-value pairs, hashed by key
    unordered_multiset   – collection of keys, duplicates allowed (hashed by keys)
    unordered_multimap   – collection of key-value pairs, duplicates allowed (hashed by keys)


Templates:
---------


Defined in header <unordered_set>					Defined in header <unordered_map>
template<											template<
    class Key,										    class Key,
    												    class T,
    class Hash = std::hash<Key>,					    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,			    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>			    class Allocator = std::allocator< std::pair<const Key, T> >
> class unordered_set/unordered_multiset;			> class unordered_map/unordered_multimap;


Meaning of key template parameters:
----------------------------------

    Internally, the elements are not sorted in any particular order, but organized into buckets (index of 
the array).

template<
    class Key,                                 ---> Element 
    .....
    class Hash = std::hash<Key>,               ---> Tell us in which bucket an element is placed in.
                                                    We can change this behaviour providing a 
                                                  'hash function object'.   

    class KeyEqual = std::equal_to<Key>,      ----> Equality function object to compare keys.
    class Allocator = std::allocator<Key>           Two keys are considered equivalent if key equality 
                                                  returns true when passed those keys. 

                                                    If two keys are equivalent, the hash function 
                                                   must return the same value for both keys.
>                                               

*/

int main()
{
    return 0;
}