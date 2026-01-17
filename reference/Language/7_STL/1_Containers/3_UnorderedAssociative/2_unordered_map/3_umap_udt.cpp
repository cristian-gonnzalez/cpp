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


// Custom hash function object
struct MyHash
{   
    // 'Edge' is the key for this hash function
    std::size_t operator()(const Edge&e) const noexcept
    {
        return e.v1+e.v2;
    }
};


// Custom specialization of std::hash can be injected in namespace std.
template<>
struct std::hash<Edge>
{
    std::size_t operator()(const Edge& s) const noexcept
    {
        std::size_t h1 = std::hash<unsigned long>{}(s.v1);
        std::size_t h2 = std::hash<unsigned long>{}(s.v2);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};


void print_stadistics( const auto& mymap)
{
    std::cout << "bucket_count: " << mymap.bucket_count() << std::endl;  // bucket_count: 13
    std::cout << "load_factor : " << mymap.load_factor() << std::endl;    // load_factor : mymap
    
    std::cout << "[\n";
    for(size_t i=0; i<mymap.bucket_count(); i++)
    {
        std::cout << "\t" << i << ": [";
        for( auto it = mymap.begin(i); it != mymap.end(i); ++it)
            std::cout << "(" <<it->first << " -> "<< it->second << "), ";
        std::cout << "]\n";
    }
    std::cout << "]\n";  
}


int main()
{
    {   // Custom specialization of std::hash
        std::unordered_map<Edge, std::string> mymap {
                                                        { {100,100 }, "s1"},
                                                        { {200,200 }, "s2"},
                                                        { {300,300 }, "s3"},
                                                        { {400,400 }, "s4"},
                                                        { {500,500 }, "s5"}   
                                                    };
            
        print_stadistics( mymap );
        /*
        bucket_count: 13
        load_factor : 0.384615
        [
            0: [((300, 300) -> s3), ]
            1: []
            2: []
            3: [((100, 100) -> s1), ]
            4: []
            5: []
            6: [((200, 200) -> s2), ]
            7: [((500, 500) -> s5), ]
            8: []
            9: []
            10: []
            11: []
            12: [((400, 400) -> s4), ]
        ]
            */
    }

    
    {
        // Custom hash function object
        std::unordered_map<Edge, std::string, MyHash> mymap {
                                                        { {100,100 }, "s1"},
                                                        { {200,200 }, "s2"},
                                                        { {300,300 }, "s3"},
                                                        { {400,400 }, "s4"},
                                                        { {500,500 }, "s5"}   
                                                    };
            
        print_stadistics( mymap );
        /*
        bucket_count: 13
        load_factor : 0.384615
        [
            0: []
            1: []
            2: [((300, 300) -> s3), ]
            3: []
            4: []
            5: [((100, 100) -> s1), ]
            6: []
            7: [((400, 400) -> s4), ]
            8: []
            9: []
            10: [((200, 200) -> s2), ]
            11: []
            12: [((500, 500) -> s5), ]
        ]
            */
    }
    
    return 0;
}