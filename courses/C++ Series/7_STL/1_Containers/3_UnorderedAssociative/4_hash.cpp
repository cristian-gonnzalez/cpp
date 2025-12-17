#include <iostream>

/*
Unordered associative containers: (since C++11)
--------------------------------

- Hash:
  -----
        std::size_t operator()(const S& s) const noexcept
        ~~~~~~~~~~~
    The hash function returns a number (unsigned integer). It is usually a big number and 
then based on the number of buckets we have, we determine the index of the bucket to place 
in the hash table 


             Hash-function                               
              ---------                            hash-table
 Object ---> | 176290  | ----> 176290 % bucket_count() = 4           [ [],  [],  [],  [], [Object] ]            
              ---------        ~~~~~~~~~~~~~~~~~~~~~~~   |              0   1    2    3      4 
                ^                          ^              -----------------------------------^
                |                          | 
          The hash function         It gets modded by the  
      could produce a huge      bucket count and it produce
      number                    the index of the array

Changing the Hash:
-----------------

template<
    .....
    class Hash = std::hash<Key>,   -> signature: std::size_t operator()(const S& s) const noexcept          
    ......
> 

The Hash function object (functor) can be customized by supplying a custom Hash 
'functor' or 'function object' as the Hash template parameter:

    struct MyHash {
        std::size_t operator()(const int& a) const noexcept {
            return a * a;   // example hash
        }
    };

    std::unordered_set<int, MyHash> s;


	IMPORTANT: For user-defined types, we must provide our own hash function object.

*/

int main()
{
    return 0;
}