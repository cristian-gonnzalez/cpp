#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

template<typename T>
struct Vertex
{
    T _data;

    // If we want to use Vertex as a Key in std::map/std::set, 
    // we need to overload the less_than operator
    bool operator<(const Vertex& rhs) const {
        return _data < rhs._data;
    }

    // Overloading equality operator to compare with vertex objects
    //
    // Note:
    //   If we want to use Vertex as a Key in std::unordered_map/std::unordered_set, 
    //   we need to overload the equality operator
    bool operator==(const Vertex& rhs) const {
        return _data == rhs._data;
    }
};

/*
// Note:
//      We need a partial template specialization of std::hash with Vertex class 
//      to use it as a Key in std::unordered_map/std::unordered_set      
template<>
struct std::hash<Vertex<int>>
{
    std::size_t operator()(const Vertex<int>& s) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(s._data);
        return h1;
    }
};
*/


struct BreadthFirstSearch
{ 
    // stores the visited nodes in the order these are traversed
    std::vector< Vertex<int> > _visited;

    void operator()( const Vertex<int>& start, 
                     std::map< Vertex<int>, 
                               std::vector< Vertex<int> > >& adjacency_list )
    {
        _visited.clear();
        std::queue< Vertex<int> > neigbours;
        neigbours.push(start);
        
        while(!neigbours.empty())
        {
            Vertex<int> current = neigbours.front();
            neigbours.pop();

            if(was_visited( current ))
                continue;
            
            _visited.push_back(current);
            
            for( const auto& neighbour: adjacency_list[current])
                neigbours.push(neighbour);
            
        }
    }

    void traverse()
    {
        std::cout << "[";      
        for( const auto e: _visited)
            std::cout << e._data << " ";
        std::cout << "]\n";
    }

    private:
        bool was_visited(const Vertex<int>& c)
        {
            for( const auto e: _visited)
                if( e == c)
                    return true;
            
            return false;
        }
        
};


int main()
{
    Vertex<int> a(0), b(1), c(2), d(3), e(4), f(5), g(6);

    std::map< Vertex<int>, 
              std::vector< Vertex<int> > > adjacency_list{
        {a, { b, f, g } },
        {b, { d } },
        {f, { e } },
        {e, { c, g } },
        {g, { a } }
    };

    BreadthFirstSearch bfs;

    bfs( a, adjacency_list);
    bfs.traverse();

    return 0;    
}