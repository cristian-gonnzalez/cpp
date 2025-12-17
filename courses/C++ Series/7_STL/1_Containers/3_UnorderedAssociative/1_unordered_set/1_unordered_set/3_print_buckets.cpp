/** STL std::unordered_set (std::algorithm generate_n for creation of sets) | Modern Cpp Series Ep. 122
 */
#include <iostream>
#include <unordered_set>


void print_data(const std::unordered_set<int>& s)
{
    std::cout <<  "[";
    for(const auto& e: s)
        std::cout << e << ", ";
    std::cout <<  "]\n";
}


int main()
{
    std::unordered_set<int> s{13,1,2,3,4,5,6,14,25,27,12};
                        
    std::cout << "bucket_count: " << s.bucket_count() << std::endl;  // bucket_count: 13
    std::cout << "load_factor : " << s.load_factor() << std::endl;   // load_factor : 0.846154

    print_data( s ); // [12, 25, 6, 5, 4, 3, 2, 27, 14, 1, 13, ]

    // Lets print the number of element per bucket
    // bucket_size:         
    //      Returns the number of elements in specific bucket with index n    
    //
    // size_type bucket_size( size_type n ) const;
    //
    // n   -   the index of the bucket to examine
    //
    std::cout << "[";
    for(size_t i=0; i< s.bucket_count(); i++)
        std::cout << s.bucket_size(i) << ", ";
    std::cout << "]\n";  // [1, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, ]
    
    //
    //            1 element in each      No elements
    //          of these buckets     in these buckets
    //          ^     ^  ^  ^  ^  ^  ~~~~~~~~~~~~~
    //          |     |  |  |  |  |  ~  ~  ~  ~  ~         
    //         [1, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, ]
    // bucket   0  1  2  3  4  5  6  7  8  9 10 11 12
    //             ^                                ^  
    //          3 elements                       2 elements 
    //          in bucket 1                      in bucket 12 
    //

    // begin(n)/ cbegin(n):   
    //      Returns an iterator to the beginning of the specified bucket
    // end(n)/cend(n):     
    //      Returns an iterator to the end of the specified bucket 
    //
    // n    -   the index of the bucket to access       
    //
    std::cout << "[\n";
    for(size_t i=0; i< s.bucket_count(); i++)
    {   
        std::cout << "\t[";
        for( auto it = s.begin(i); it != s.end(i); ++it ) 
            std::cout << *it << ", ";
        std::cout << "],\n";
    }    
    std::cout << "]\n";
    // [
    // 	[13, ],
    // 	[27, 14, 1, ],
    // 	[2, ],
    // 	[3, ],
    // 	[4, ],
    // 	[5, ],
    // 	[6, ],
    // 	[],
    // 	[],
    // 	[],
    // 	[],
    // 	[],
    // 	[12, 25, ],
    // ]

    return 0;
}