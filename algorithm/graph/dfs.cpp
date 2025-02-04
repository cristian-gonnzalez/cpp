#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>

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


struct DepthFirstSearch
{ 
    // stores the visited nodes in the order these are traversed
    std::vector< Vertex<int> > _visited;

    void traverse( const Vertex<int>& start, 
                   std::map< Vertex<int>, 
                               std::vector< Vertex<int> > >& adjacency_list )
    {
        _visited.clear();
        
        // using an stack to add neighbours
        std::stack< Vertex<int> > unvisited;
        unvisited.push(start);
        
        while(!unvisited.empty())
        {
            Vertex<int> current = unvisited.top();
            unvisited.pop();

            if(was_visited( current ))
                continue;
            
            _visited.push_back(current);
            
            // Note: 
            //      we need to add in reverse to go depth and then backtracking
            for( auto it = adjacency_list[current].rbegin(); it != adjacency_list[current].rend(); it++)
                unvisited.push(*it);
        }
    }

    // recursive traverse
    void traverse_reverse( const Vertex<int>& start, 
                           std::map< Vertex<int>, 
                               std::vector< Vertex<int> > >& adjacency_list )
    {
        _visited.clear();
        _visited.push_back(start);
        _traverse_reverse( start, adjacency_list );
    }

    friend std::ostream& operator<<(std::ostream& os, const DepthFirstSearch& rhs)
    {
        os << "[";      
        for( const auto e: rhs._visited)
            os << e._data << " ";
        os << "]\n";
        return os;
    }

    private:
        bool was_visited(const Vertex<int>& c)
        {
            for( const auto e: _visited)
                if( e == c)
                    return true;
            return false;
        }

        void _traverse_reverse( const Vertex<int>& current, 
                                std::map< Vertex<int>, 
                                std::vector< Vertex<int> > >& adjacency_list )
        {
            for(auto& e: adjacency_list[current])
            {
                if(was_visited( e ))
                    continue;
              
                _visited.push_back(e);
                _traverse_reverse(e, adjacency_list);
            }
        }
};


int main()
{
    Vertex<int> a(0), b(1), c(2), d(3), e(4), f(5), g(6);

    std::map< Vertex<int>, 
              std::vector< Vertex<int> > > adjacency_list{
        {a, { b, f, g } },
        {b, { d, e, f } },
        {f, { e } },
        {e, { c, g } },
        {g, { a } }
    };

    DepthFirstSearch dfs;
 
    dfs.traverse( a, adjacency_list);
    std::cout << dfs << std::endl;
 
    dfs.traverse_reverse( a, adjacency_list);
    std::cout << dfs << std::endl;

    return 0;    
}