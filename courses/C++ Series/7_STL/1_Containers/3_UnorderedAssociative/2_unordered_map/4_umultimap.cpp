/** STL std::unordered_multimap (C++11) | Modern Cpp Series Ep. 130
 */
#include <iostream>
#include <string>
#include <unordered_map>

/*

std::unordered_multimap:
    It is an unordered associative container that stores pairs of key values and even duplicate keys.
     
    The unordered_multimap class supports forward iterators. 
    
    Search, insertion, and removal have average constant-time complexity.

    The iteration order of this container is not required to be stable (so, for example, 
std::equal cannot be used to compare two std::unordered_multimaps)

*/


struct Edge
{
    unsigned long v1{999};
    unsigned long v2{999};

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};


int main()
{    
  auto print_map = []( const auto& map )
                     {        
                        std::cout << "[";
                        for(const auto& e: map)
                            std::cout << "(" << e.first << " -> " <<  e.second << "), ";
                        std::cout << "]\n";
                     };

    Edge e1(1,2);
    Edge e2(5,4);
    Edge e3(3,3);
    Edge e4(99,100);
                    
    //std::unordered_map<std::string, Edge> mymap{ {"s1", e1},
    std::unordered_multimap<std::string, Edge> mymap{ {"s1", e1},
                    /* ~~~~~~~~~~~  ~~~~  */          {"s2", e2},
                    /*   Key        Value */          {"s3", e3} };
    
    {
        // insert: Average case: O(1), worst case O(size())
        //      Inserts element(s) into the container
        mymap.insert( {"s4", e1} );
    
        // insert multiples keys
        mymap.insert( {"s4", e1} );
        mymap.insert( {"s4", e1} );
        mymap.insert( {"s4", e1} );
        mymap.insert( {"s4", e2} );
        mymap.insert( {"s4", e4} );
        mymap.insert( {"s4", e3} );
        mymap.insert( {"s4", e3} );
        
        //
        // Lookup
        //
    
        // WARNING:
        //      'at()' and 'operator[]' are not supported.
        //
        //      We have the ability to find element but not to access as we do with std::map or
        // std::unordered_map. 
        //
        //      If Im allowd to add multiples entries into the actual multi-map, then what does it 
        // mean whne I use operator[] or at()?. If I have duplicate keys, I need to be specific to
        // which pair Im refering to. That's why we cannot use these functions.
        //
        //try
        //{
        //     std::cout << mymap.at("s9") << std::endl;
        //}
        //catch(const std::out_of_range& e)
        //{
        //    std::cerr << "key" << " out_of_range: " << e.what() << '\n';  // edge3 out_of_range: unordered_map::at
        //}

        print_map( mymap ); // [(s3 -> (3, 3)), (s1 -> (1, 2)), (s2 -> (5, 4)), (s4 -> (1, 2)), (s4 -> (3, 3)), (s4 -> (3, 3)), (s4 -> (99, 100)), (s4 -> (5, 4)), (s4 -> (1, 2)), (s4 -> (1, 2)), (s4 -> (1, 2)), ]
    }
        
    {
        std::cout << "number of s4: " << mymap.count("s4") << std::endl; // number of s4: 8

        // equal_range: Average case linear in the number of elements with the key key, worst case linear in the size of the container.
        //      Returns a range containing all elements with the given key in the container.
        //
        // std::pair<iterator, iterator> equal_range( const Key& key );
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // std::pair containing a pair of iterators defining the wanted range:
        
        // We can do sth more efficient way to get a range containing all the elements with a given
        // key. Using lower_bound/upper_bound is a linear operation but we are doing it twice.
        // That's why equal_range is a better choise
        auto [start, last] = mymap.equal_range("s4");
        
        std::cout << "[";
        for( ; start != last; start++)
            std::cout << "(" << start->first << " -> " << start->second << "), ";    
        std::cout << "]\n";
        // [(s4 -> (1, 2)), (s4 -> (3, 3)), (s4 -> (3, 3)), (s4 -> (99, 100)), (s4 -> (5, 4)), (s4 -> (1, 2)), (s4 -> (1, 2)), (s4 -> (1, 2)), ]  
    }

    {
        auto [start, last] = mymap.equal_range("s4");
        auto copy = start;
        start++;
        // erase:
        //      Removes the element at pos.
        //
        // iterator erase( iterator pos );
        //
        // NOTE: References and iterators to the erased elements are invalidated. Other iterators 
        // and references are not invalidated.
        //
        //      This means that start is still valid after erase copy since it is pointing to other position
        // We are pointing to a list (since the range contains all the same key).
        /*
[
    .....
    1: []
    2: [  (s4 -> (1, 2)), (s4 -> (3, 3)), (s4 -> (3, 3)), (s4 -> (99, 100)), (s4 -> (5, 4)), (s4 -> (1, 2)), (s4 -> (1, 2)), (s4 -> (1, 2)), ]
    3: []   ^               ^ 
    ....   copy           start 
]
        */
        mymap.erase( copy );

        std::cout << "[";
        for( ; start != last; start++)
            std::cout << "(" << start->first << " -> " << start->second << "), ";    
        std::cout << "]\n";
        // [(s4 -> (3, 3)), (s4 -> (3, 3)), (s4 -> (99, 100)), (s4 -> (5, 4)), (s4 -> (1, 2)), (s4 -> (1, 2)), (s4 -> (1, 2)), ]  
    }

        
        
    {
        
        // erase: Average case: c.count(key), worst case: c.size().
        //      Removes all the elements (if exists) with the key equivalent to key.
        //
        // size_type erase( const Key& key );
        // ~~~~~~~~~
        // Number of elements removed.
        mymap.erase("s4");
        print_map( mymap ); // [(s3 -> (3, 3)), (s1 -> (1, 2)), (s2 -> (5, 4)), ]

        // erase: Average case: constant, worst case: c.size().
        //      Removes the element at pos.
        //
        // iterator erase( iterator pos );
        // ~~~~~~~~
        // Iterator following the last removed element.
        auto start = mymap.begin();
        mymap.erase( start );
        
        print_map( mymap ); // [(s1 -> (1, 2)), (s2 -> (5, 4)), ]


    }
    
    {
        // WARNING:
        //      'at()' and 'operator[]' are not supported.
        // operator[]: Average case: constant, worst case: linear in size.
        //          Access or insert specified element

        // Add a new entry or update an existing one
        //mymap["s2"] = e4;  // update
        //mymap["s5"] = e4;  // create
        
        // Change operatot[] by insert()
        mymap.insert( {"s2", e4} );  // Add duplicate
        mymap.insert( {"s5", e4} );  // create
    }

    {
        // contains: (C++20)
        //      Checks if the container contains element with specific key
        if(mymap.contains("s5"))
            std::cout << "we contains 's5'\n"; // we contains 's5'

        // find: Constant on average, worst case linear in the size of the container.
        //      Finds element with specific key
        if(auto it = mymap.find("s5"); it != mymap.end() )
            std::cout << "we found 's5'\n"; // we found 's5'    
    }    
    
    //
    // Bucket interface
    //
    {
        // bucket_count:        
        //      Returns the number of buckets
        std::cout << "bucket_count: " << mymap.bucket_count() << std::endl;  // bucket_count: 17
     
        // load_factor: (Hash policy)
        //      Returns average number of elements per bucket
        //
        // load_factor = size() / bucket_count()
        //
        std::cout << "load_factor : " << mymap.load_factor() << std::endl;    // load_factor : 0.235294
        
        // NOTE:
        //      We can resize the has_table by adding more buckets by rehashing.
        //      
        //      If you know that you have a lot of data, you should probably just reserve the number
        // of buckets rather than having to rehash becuase when you rehash you have to copy over your
        // entire hash table which could be an expensive operation

        // rehash:
        //    Reserves at least the specified number of buckets given and regenerates the hash table
        //
        //  void rehash( size_type count );

        // reserve:
        //      Reserves space for at least the specified number of elements and regenerates 
        // the hash table
    
        
        std::cout << "[\n";
        for(size_t i=0; i<mymap.bucket_count(); i++)
        {
            std::cout << "\t" << i << ": [";
            for( auto it = mymap.begin(i); it != mymap.end(i); ++it)
                std::cout << "(" <<it->first << " -> "<< it->second << "), ";
            std::cout << "]\n";
        }
        std::cout << "]\n";    
        /*
        
[
    0: []
    1: []
    2: []
    3: []
    4: []
    5: []
    6: [(s5 -> (99, 100)), ]
    7: [(s1 -> (1, 2)), ]
    8: []
    9: []
    10: []
    11: [(s2 -> (5, 4)), (s2 -> (99, 100)), ]
    12: []
    13: []
    14: []
    15: []
    16: []
]
        */
    }

 
    return 0;
}