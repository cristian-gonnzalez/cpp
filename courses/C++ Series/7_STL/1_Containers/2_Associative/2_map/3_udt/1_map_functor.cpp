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

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};

// This is the Compare function object (functor) to 
// provide the comparison logic.
struct EdgeCompare
{
    bool operator()(const Edge& lhs, const Edge& rhs) const
    {
        return lhs.v1+lhs.v2 < rhs.v1+rhs.v2;
    }
};


int main()
{
    // Using function objecto to overload class Compare
    std::map<Edge,         // Key = UDT 
             std::string,  // Value
             EdgeCompare   // Compare function object
             > mymap3{
                        { Edge{2,2}, "_edge2" },
                        { Edge{1,1}, "_edge1" },
                        { Edge{3,3}, "_edge3" },
                    };
 
    std::cout << "[";
    for(const auto& [key, value]: mymap3)
        std::cout << "{ " 
                  << key << " -> " 
                  << value 
                  << " }, ";
    std::cout << "]\n"; // [{ (1, 1) -> _edge1 }, { (2, 2) -> _edge2 }, { (3, 3) -> _edge3 }, ]

    return 0;    
}