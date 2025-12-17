/** STL std::unordered_multiset( C++11) (and custom hash function) | Modern Cpp Series Ep. 124
 */
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

//
// Example of unordered_set / unordered_multiset for non-trivial types
//


// Example helper class
struct Custom
{
    int field1;
    int field2;

    Custom(int _field1, int _field2)
    : field1{_field1}, field2{_field2}
    {
    }

    // Needs an equality operator if we have unordered_set/unordered_multiset.
    // In case of unordered_set it is used to know if its an unique element 
    // but for both (unordered_set/unordered_multiset) it used to compare (lookup) 
    //
    /** Equality operator overload
     * 
     *  rhs  Right-hand side operand
     * 
     *  returns true if the lhs(left-hand side) equals rhs. Otherwise, false
     */
    bool operator==(const Custom& rhs) const {
        return (field1 == rhs.field1 &&
                field2 == rhs.field2);
    }

    void print() const {
        std::cout << "(" << field1 << "," << field2 << ") = " << (field1 + field2);
    }
};


// If you do not have the ability to modify the class,
// provide a hash functor instead.
struct hash{

    // NOTE: This must be callable, hence operator().
    // IMPORTANT: Don't forget the 'const' at the end. Hashing must not
    //            modify the object. Otherwise the compiler will error.
    //
    // The hash function determines the bucket index.

    // NOTE: In order for this to work, we need sth that's callable. Thats why we overload the operator ()
    // WARNING: Dont forget the 'const' at the end, cannot have comparision if we modify internals. Otherwise
    // an error compilation will occurs
    //
    // The hash function determines the bucket index to insert/search/remove.
    std::size_t operator()(const Custom& c) const noexcept 
    {
        return c.field1 + c.field2;
    }
};

template<
          typename T // std::unordered_set<Custom, hash>
                     // std::unordered_multiset<Custom, hash>
>
void print_buckets(const T& b)
{
    std::cout << "[\n";
    for(size_t i=0; i<b.bucket_count(); i++)
    {
        auto it = b.begin(i);
        auto end = b.end(i);
        std::cout << "  " << i << ": [";
        while( it != end)
        {
            it->print();
            it++;
            std::cout << ", ";
        }
        std::cout << "],\n";
    }
    std::cout << "]\n";
}


Custom gen()
{
    static int i=0;
    static int j=0;
    return Custom(++i, ++j);
}


Custom gen_duplicates()
{
    static int i=0;
    static int j=0;
    return Custom(++i, ++j);
}

void _test( auto& o_set )
{
    // Insert a bunch of custom elements into the set
    std::generate_n( std::inserter(o_set, o_set.begin()) , 
                     5, 
                     gen);
    // Insert another batch that produces duplicates
    std::generate_n( std::inserter(o_set, o_set.begin()),
                     5, 
                     gen_duplicates);

    std::cout << "contents: [";
    std::for_each( o_set.cbegin(), o_set.cend(),
                   []( const Custom& c)
                   {
                    c.print();
                    std::cout <<", ";
                   } );
    std::cout << "]\n";
    
    std::cout << "Has table:\n";
    
    std::cout << "\tsize       : " << o_set.size() << std::endl;
    std::cout << "\tbuckets    : " << o_set.bucket_count() << std::endl;
    std::cout << "\tload_factor: " << o_set.load_factor() << std::endl;

    print_buckets( o_set );
}

int main()
{
    std::unordered_multiset<Custom, hash> o_mset;
    std::unordered_set<Custom, hash> o_set;
    
    _test(o_mset);
    /*
contents: [(5,5) = 10, (5,5) = 10, (4,4) = 8, (4,4) = 8, (3,3) = 6, (3,3) = 6, (2,2) = 4, (2,2) = 4, (1,1) = 2, (1,1) = 2, ]
Has table:
	size       : 10
	buckets    : 13
	load_factor: 0.769231
[
  0: [],
  1: [],
  2: [(1,1) = 2, (1,1) = 2, ],
  3: [],
  4: [(2,2) = 4, (2,2) = 4, ],
  5: [],
  6: [(3,3) = 6, (3,3) = 6, ],
  7: [],
  8: [(4,4) = 8, (4,4) = 8, ],
  9: [],
  10: [(5,5) = 10, (5,5) = 10, ],
  11: [],
  12: [],
]
    
    */
    _test(o_set);
/*
contents: [(10,10) = 20, (9,9) = 18, (8,8) = 16, (7,7) = 14, (6,6) = 12, ]
Has table:
	size       : 5
	buckets    : 13
	load_factor: 0.384615
[
  0: [],
  1: [(7,7) = 14, ],
  2: [],
  3: [(8,8) = 16, ],
  4: [],
  5: [(9,9) = 18, ],
  6: [],
  7: [(10,10) = 20, ],
  8: [],
  9: [],
  10: [],
  11: [],
  12: [(6,6) = 12, ],
]

*/

    return 0;
}

