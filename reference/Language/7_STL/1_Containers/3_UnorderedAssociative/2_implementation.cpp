#include <iostream>

/*
Unordered associative containers: (since C++11)
--------------------------------

Implementation:
--------------
    Any time we want fast lookup, we usually use an array-based data structure.
                                                    ~~~~~~~~~~~~~~~~~~~~~~~~~
                                                                 ^
                                                      Lookup in an array is just a constant
                                                    time operation O(1)

                      hash-table           ->  Allows us to identify a 'key' quickly and finds
                 [   ,   ,   ,   ,   ]        its position in constant time O(1) in the average
     buckets <---  0   1   2   3   4          case
       ^
   Internally, the elements are not 
 sorted in any particular order, but 
 organized into buckets. 
 

    For ex, let's say I want to insert the keys: [ 1, 2, 7, 10, 11 ] with an array of 5 buckets
                                                                 ^
                                    Try to figure out in which bucket an element is placed into 
                                 depends entirely on the hash of its value

             This allows fast access to individual elements, since once  
        a hash is computed, it refers to the exact bucket the element is placed into.
                          ^ 
                          |
                     Hash-function
                   ( hash(k) = k % 5 )    
                       ---------                            hash-table
            11  ----->| 11 % 5  | = 1               [   , 11 ,   ,   ,   ]            
                       ---------    |                  0   1   2   3   4 
                          ^         -----------------------^
                          |
          To know in which bucket I store the key 11,
       it will go through the hash-function                               
              ( key % bucket_total )              

                     Hash-function    
                       ---------                            hash-table
            10  ----->| 10 % 5  | = 0               [ 10, 11 ,   ,   ,   ]            
                       ---------    |                  0   1   2   3   4 
                                    -------------------^
                          
                     Hash-function    
                       ---------                            hash-table
            7   ----->| 7 % 5   | = 2               [ 10, 11 , 7 ,   ,   ]            
                       ---------    |                  0   1   2   3   4 
                                     --------------------------^
    
    NOTE: a hash-table usually is implemented wiht an array where each bucket is a linked-list.
    (See the next section).
*/

int main()
{
    return 0;
}