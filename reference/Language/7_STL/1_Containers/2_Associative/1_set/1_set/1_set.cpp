/** STL std::set | Modern Cpp Series Ep. 121
 */
#include <iostream>
#include <set>

/*
std::set:
    It is an associative container that contains a sorted set of unique objects.

    Uniqueness is determined by the Compare using the equivalence relation (see 1_intro.cpp)
 */

void print_data( const std::set<int>& set )
{
   std::cout << "[";
    for(const auto& e: set)
        std::cout << e << ", ";
    std::cout << "]\n";

}

int main()
{
    std::set<int> set1{1,2,3,4};
                    // ~~~~~~~
                    // std::initializer-list

    {
        // insert: log(N)
        //      inserts elements or nodes(since C++17)
        set1.insert(5);

        // If I try to insert a duplicate element, we will only get one copy
        set1.insert(1);
        set1.insert(1);
        set1.insert(2);

        // We insert and it is preserving a sorted ordering 
        set1.insert(-4);
        
        print_data(set1);  // [-4, 1, 2, 3, 4, 5, ]

    }
    
    //
    //  Lookup: log(N)
    //
    {
        // count
        //     Returns 1 if matching specific key. Otherwise 0.
        //     Usefull to check if and element exists
        std::cout << "4 ?= " << set1.count(4) << std::endl;  // 4 ?= 1

        // contains (C++20)
        //     checks if the container contains element with specific key
        //
        // bool contains( const Key& key ) const;
        //
        std::cout << std::boolalpha 
                << "contains(4) ?= " << set1.contains(4) << std::endl;  // contains(4) ?= true

        // find
        //     finds element with specific key
        if( auto found = set1.find(4); 
            found != set1.end() )
            std::cout << "Found " << *found << std::endl;  // Found 4
    }
    
    //
    // Modifiers
    //
    {
        // erase: 
        //      Erases elements
        //
        //  iterator erase( iterator pos );       O(1)
        //                           ~~~
        //                      Since we have an iterator to the node,
        //                  it is constant time operation
        //
        if( auto found = set1.find(4); 
                found != set1.end() )
            set1.erase(found);
        
        //
        //  size_type erase( const Key& key )     log(N) + N
        //
        if( set1.contains(-4) )
            set1.erase(-4);
            //   ~~~~~
            //  Technically what it is doing is traversing the tree and
            // it is a logarithmic time operation

        print_data(set1);  // [1, 2, 3, 5, ]
    }

    return 0;
}