#include <iostream>
#include <string>
#include <map>

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

    // If we want to use Edge as a Key, we need to overload the less_than operator
    // to compare keys.
    bool operator<(const Edge& rhs) const {
        return v1+v2 < rhs.v1+rhs.v2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};


int main()
{
    Edge e1(1,1);
    Edge e2(2,2);
    Edge e3(3,3);
    Edge e4(4,4);
    Edge e5(5,5);


    std::map<Edge, std::string> mymap{  {e4, "edge4"},
      /*     ~~~~       */              {e1, "edge1"},
      /*   Key = UDT    */              {e3, "edge3"},
                                        {e2, "edge2"}
                                    };

    std::cout << "[";
    for(const auto& [key, value]: mymap)
        std::cout << key << " -> " << value << ", ";
    std::cout << "]\n";  // [(1, 1) -> edge1, (2, 2) -> edge2, (3, 3) -> edge3, (4, 4) -> edge4, ]

    if( mymap.contains( e3 ) )
        std::cout << "Contains e3\n"; // Contains e3

    if( !mymap.contains( e5 ) )
        std::cout << "NOT contain e5\n";  // Contains e3
    
    return 0;    
}