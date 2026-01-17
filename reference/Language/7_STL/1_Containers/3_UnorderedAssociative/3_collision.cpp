#include <iostream>

/*
Unordered associative containers: (since C++11)
--------------------------------

-- Collision: Why do I get average constant-time?
   ---------

    Insert keys: 1, 2, 7, 10, 11   with 5 buckets      10 → 10 % 5 = 0 → bucket 0
    hash(k) = k % 5                                    11 → 11 % 5 = 1 → bucket 1
                                                        7 →  7 % 5 = 2 → bucket 2
                                                       21 → 21 % 5 = 1 → bucket 1 (collision → chaining)

    The reality is for ex: we insert the key 21

                 Hash-function    
                   ---------                            hash-table            Then I would have a
        21  ----->| 21 % 5  | = 1               [ 10, 11 , 7 ,   ,   ]       key that also collides     
                   ---------    |                  0   1   2   3   4         with another key in the 
                                 ----------------------^                     same location
    
        Collisions are resolved with 'chaining', we just create a 'linked-list' based-structure 
in each bucket (for ex: forward_list).

                                                      (linked-list) 
                                                          [21]
                 Hash-function                             ^
                   ---------                               |                   Now, If I want to look-up
        21  ----->| 21 % 5  | = 1      hash-table:[ [10], [11], [7],   ,   ]  a key, then I might have to          
                   ---------    |                    0     1     2   3   4    look at all the nodes in that    
                                 --------------------------^                  bucket and if the list is long 
                                                                              then that's why sometimes        
                                                                              I get O(N) time for 
                                                                              looking-up a key.  
                                                   
    So, in average case, we do a good job. It will depend on how good is my hash-function.

		Average-case lookup is O(1):  
		    compute hash → access a bucket → scan a few items.

		Worst-case lookup is O(n):  
		    all elements land in the same bucket.

    The container grows when size / bucket_count > max_load_factor().

	Rehashing invalidates iterators and causes O(n) operations occasionally.

Complexity Summary:
-------------------

	Operation                 Average       Worst-case
	----------------------------------------------------
	search                    O(1)          O(n)
	insert                    O(1)          O(n)
	erase                     O(1)          O(n)

	Worst-case occurs only when many keys collide into the same bucket.
*/

int main()
{
    return 0;
}