#include <iostream>
#include <string>
#include <unordered_map>

struct Edge
{
    unsigned long v1{0};
    unsigned long v2{0};

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
                        
    std::unordered_map<std::string, Edge> mymap{ {"s1", e1},
                    /* ~~~~~~~~~~~  ~~~~  */     {"s2", e2},
                    /*   Key        Value */     {"s3", e3} };
    {
        // insert: Average case: O(1), worst case O(size())
        //      Inserts element(s) into the container
        mymap.insert( {"s4", e1} );
    
        
        try
        {
            // at: Average case: constant, worst case: linear in size.
            //      access specified element with bounds checking
            // create/ update     
            std::cout << mymap.at("s9") << std::endl;
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "key" << " out_of_range: " << e.what() << '\n';  // edge3 out_of_range: unordered_map::at
        }

        print_map( mymap ); // [(s4 -> (1, 2)), (s3 -> (3, 3)), (s2 -> (5, 4)), (s1 -> (1, 2)), ]

    }
        
    {
        // erase: Average case: c.count(key), worst case: c.size().
        //      Removes the element (if one exists) with the key equivalent to key.
        //
        // size_type erase( const Key& key );
        // ~~~~~~~~~
        // Number of elements removed (0 or 1).
        mymap.erase("s4");
        print_map( mymap ); // [(s3 -> (3, 3)), (s2 -> (5, 4)), (s1 -> (1, 2)), ]

        // erase: Average case: constant, worst case: c.size().
        //      Removes the element at pos.
        //
        // iterator erase( iterator pos );
        // ~~~~~~~~
        // Iterator following the last removed element.
        auto start = mymap.begin();
        mymap.erase( start );
        
        print_map( mymap ); // [(s2 -> (5, 4)), (s1 -> (1, 2)), ]

    }
    
    {
        Edge e4(99,100);

        // operator[]: Average case: constant, worst case: linear in size.
        //          Access or insert specified element

        // Add a new entry or update an existing one
        mymap["s2"] = e4;  // update
        mymap["s5"] = e4;  // create


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
        std::cout << "bucket_count: " << mymap.bucket_count() << std::endl;  // bucket_count: 13
     
        // load_factor: (Hash policy)
        //      Returns average number of elements per bucket
        //
        // load_factor = size() / bucket_count()
        //
        std::cout << "load_factor : " << mymap.load_factor() << std::endl;    // load_factor : 0.230769
        
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
            0: [(s2 -> (99, 100)), ]
            1: []
            2: [(s1 -> (1, 2)), ]
            3: []
            4: []
            5: []
            6: []
            7: []
            8: []
            9: []
            10: [(s5 -> (99, 100)), ]
            11: []
            12: []
        ]
        
        */
    }

    return 0;
}