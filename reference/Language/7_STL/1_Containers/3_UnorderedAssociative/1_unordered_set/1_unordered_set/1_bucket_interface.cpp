/** STL std::unordered_set (std::algorithm generate_n for creation of sets) | Modern Cpp Series Ep. 122
 */
#include <iostream>
#include <unordered_set>

/*
std::unordered_set:
    It is an associative container that stores a set of unique objects of type Key. 

    Search, insertion, and removal have average constant-time complexity O(1).
*/

int main()
{
    // std::unordered_set<int> s(5);
                             // ~~~
                             // We can intizilize it to have some amount
                             // of space     
    std::unordered_set<int> s;

    // reserve:
    //      We can call reserve to reserve space for at least 
    // the specified number of elements and regenerates the 
    // hash table
    s.reserve(5);

    std::unordered_set<int> s2{1,2,3,4,5,6};
                        //      ~~~~~~~~~~
                        //  Construct with std::initializer-list
    
    //
    // Bucket interface
    //
    {
        // bucket_count:        
        //      Returns the number of buckets
        std::cout << "bucket_count s : " << s.bucket_count() << std::endl;  // bucket_count s : 5 
        std::cout << "bucket_count s2: " << s2.bucket_count() << std::endl; // bucket_count s2: 13

        // load_factor: (Hash policy)
        //      Returns average number of elements per bucket
        //
        // load_factor = size() / bucket_count()
        //
        std::cout << "load_factor s  : " << s.load_factor() << std::endl;    // load_factor s  : 0  
        std::cout << "load_factor s2 : " << s2.load_factor() << std::endl;   // load_factor s2 : 0.461538
  
    }
    
    print_data( s2 ); // [6, 5, 4, 3, 2, 1, ]

    return 0;
}