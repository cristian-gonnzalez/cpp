/** STL std::unordered_multiset( C++11) (and custom hash function) | Modern Cpp Series Ep. 124
 */
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

struct Custom
{
    int field1;
    int field2;

    Custom(int _field1, int _field2)
    : field1{_field1}, field2{_field2}
    {
    }

    bool operator==(const Custom& rhs) const {
        return (field1 == rhs.field1 &&
                field2 == rhs.field2);
    }

    void print() const {
        std::cout << "(" << field1 << "," << field2 << ") = " << (field1 + field2);
    }
};

struct hash{

    std::size_t operator()(const Custom& c) const noexcept 
    {
        return 0;
        //    ~~~
        // Forcing the same bucket to demostrate a bad hash-function   
        // This means that search, insertion, and removal have O(N) complexity. 
    }
};

template< typename T >
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
    
}

int main()
{
    std::unordered_multiset<Custom, hash> o_set;
    // Insert a bunch of custom elements into the set
    std::generate_n( std::inserter(o_set, o_set.begin()) , 
                     5, 
                     gen);
    // Insert another batch that produces duplicates
    std::generate_n( std::inserter(o_set, o_set.begin()),
                     5, 
                     gen_duplicates);

    std::cout << "size       : " << o_set.size() << std::endl;         // size       : 10
    std::cout << "buckets    : " << o_set.bucket_count() << std::endl; // buckets    : 13
    std::cout << "load_factor: " << o_set.load_factor() << std::endl;  // load_factor: 0.769231

    print_buckets( o_set );
    /*    
[
  0: [(5,5) = 10, (5,5) = 10, (4,4) = 8, (4,4) = 8, (3,3) = 6, (3,3) = 6, (2,2) = 4, (2,2) = 4, (1,1) = 2, (1,1) = 2, ],
  1: [],
  2: [],
  3: [],
  4: [],
  5: [],
  6: [],
  7: [],
  8: [],
  9: [],
  10: [],
  11: [],
  12: [],
]
*/
    return 0;
}

