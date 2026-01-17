/** STL std::unordered_multimap (C++11) | Modern Cpp Series Ep. 130
 */
#include <iostream>
#include <string>
#include <unordered_map>


struct Edge
{
    unsigned long v1{999};
    unsigned long v2{999};

    Edge()
    {
    }
    Edge(unsigned long _v1, unsigned long _v2)
    : v1{_v1},v2{_v2}
    {
    }

    // Equality operator is required to use this class as a Key
    bool operator==(const Edge& rhs) const 
    {
        return (v1 == rhs.v1 && v2 == rhs.v2);
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};


struct MyHash
{   
    // 'Edge' is the key for this hash function
    std::size_t operator()(const Edge&e) const noexcept
    {
        return e.v1+e.v2;
    }
};


int main()
{
    std::unordered_multimap<Edge, std::string, MyHash> mymap2;

    Edge k1{100, 100};
    Edge k2{102, 101};
    mymap2.insert( {k2, "s2"} );
    mymap2.insert( {k2, "s2_duplicated"} );
    mymap2.insert( {k1, "s1"} );
    
    for(size_t i=0; i<mymap2.bucket_count(); i++)
    {
        auto it = mymap2.begin(i);
        auto end = mymap2.end(i);
        std::cout << "bucket " << i << ": [";
        while( it != end)
        {
            std::cout << it->first << " -> "<< it->second << ", ";
            it++;
        }
        std::cout << "]\n";
    }

 
    return 0;
}