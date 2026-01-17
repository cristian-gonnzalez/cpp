/** STL std::unordered_set (std::algorithm generate_n for creation of sets) | Modern Cpp Series Ep. 122
 */
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>


void print_data(const std::unordered_set<int>& s)
{
    std::cout <<  "[";
    for(const auto& e: s)
        std::cout << e << ", ";
    std::cout <<  "]\n";
}

int gen()
{
    static int i=0;
    return ++i;
}

int main()
{
    std::unordered_set<int> s{1,2,3,4,5,6};
                        
    std::cout << "bucket_count: " << s.bucket_count() << std::endl; // bucket_count: 13
    std::cout << "load_factor : " << s.load_factor() << std::endl;  // load_factor : 0.461538
      
    print_data( s ); // [6, 5, 4, 3, 2, 1, ]

    // insert: 
    //      Inserts element(s) into the container, if the container does 
    // not already contain an element with an equivalent key.
    //
    // std::pair<iterator,bool> insert( const value_type& value );
    //
    //      Average case: O(1), 
    //      worst case  : O(size()).
    s.insert(12);
    
    // It doesnt change anything since it is duplicated
    s.insert(6);

    std::cout << "bucket_count: " << s.bucket_count() << std::endl;  // bucket_count: 13
    std::cout << "load_factor : " << s.load_factor() << std::endl;   // load_factor : 0.538462
                                                                        //              ~~~~~~
                                                                        //      The load factor has
                                                                        //    changed   

    // contains: (C++20)
    //      Checks if the container contains element with specific key
    //
    // Another way to check if the key is duplicated before inserting is calling contains()
    if( !s.contains(13) )    
        s.insert(13);

    // it doesnt insert 6 since it is duplicated
    if( !s.contains(6) )    
        s.insert(6);
        
    std::cout << "bucket_count: " << s.bucket_count() << std::endl;  // bucket_count: 13
    std::cout << "load_factor : " << s.load_factor() << std::endl;   // load_factor : 0.615385

    print_data( s ); // [13, 12, 6, 5, 4, 3, 2, 1, ]

    // begin(size_type)/
    // cbegin(size_type):   Returns an iterator to the beginning of the specified bucket
    // end(size_type)/
    // cend(size_type):     Returns an iterator to the end of the specified bucket
    // max_bucket_count:    Returns the maximum number of buckets
    // bucket_size:         Returns the number of elements in specific bucket
    // bucket:              Returns the bucket for specific key
/*
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(11);
    s.insert(22);
    s.insert(33);
    s.insert(44);
    s.insert(55);
    
    
    std::cout << "avarage number of elems per bucket:" << s2.load_factor() << std::endl;

    s2.insert(6);
    s2.insert(12);
    
    if(s2.contains(12))
        std::cout << "12 is in the container\n";
    
    print_data(s2);

    for(int i=0; i<s2.bucket_count(); i++)
        std::cout << "Size in bucket " << i << ": " << s2.bucket_size(i) << std::endl;

    std::cout << "s: ";
    print_data(s);
    s2.merge(s);
    std::cout << "s2.merge(s): ";
    print_data(s2);
    std::cout << "s: ";
    print_data(s);

    if( s2.erase(11) == 1)
        std::cout << "we removed 11\n";
    if( s2.erase(99) == 1)
        std::cout << "we removed 99\n";
    
    std::unordered_set<int> s3;

    std::generate_n(std::inserter(s3, s3.begin()), 10, gen);
    std::cout << "s3: ";
    print_data(s3);
*/
    return 0;
}