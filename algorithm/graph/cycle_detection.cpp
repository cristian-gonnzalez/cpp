#include <iostream>
#include <set>
#include <memory>

template<typename T>
struct Node
{
    void add_edge(std::shared_ptr< Node<T> > node)
    {
        _adjacent_nodes.insert(node);
    }

    friend std::ostream& operator<<(std::ostream& os, const Node<T>& rhs)
    {
        os << rhs._data << " -> [";
        for( const auto& e: rhs._adjacent_nodes)
            os << e->_data << ", ";
        os << "]\n";
        return os;
    }

    // If we want to use Node as a Key in std::map/std::set, 
    // we need to overload the less_than operator
    bool operator<(const Node<T>& rhs) const {
        return _data < rhs._data;
    }

    bool operator==(const Node<T>& rhs) const {
        return _data == rhs._data;
    }

    // The data of the node
    T                                     _data;
    // Holds the adjacent nodes 
    std::set< std::shared_ptr< Node<T> > >  _adjacent_nodes;
};


struct CycleDetection
{ 
    enum class GraphType
    {
        directed,
        undirected
    };
    GraphType _type;

    
    /** Calculates the shortest path from the start to all nodes
     *
     **/
    bool operator()( const std::shared_ptr< Node<char> > start, GraphType type )
    {
        _type = type;
        std::set< std::shared_ptr< Node<char> > > visited;
        return _has_cycle(nullptr, start, visited);
    }


    private:
        
        /** Traverse the graph throuth dfs to find cylces
         *
         **/
        bool _has_cycle( const std::shared_ptr< Node<char> > caller, // only used for undirected graphs
                         const std::shared_ptr< Node<char> > node, 
                         std::set< std::shared_ptr< Node<char> > >& visited )
        {
            std::cout << node->_data << "->";
  
            if( visited.contains(node) )
            {   
                std::cout << ": Cycle detection in node " << node->_data << std::endl;
                return true;
            }
             
            visited.insert(node);
            
            for(auto& neighbour: node->_adjacent_nodes)
            {
                // if the neighbour is our parent, we ommit this
                if( _type == GraphType::undirected && 
                    caller != nullptr && *caller == *neighbour )
                    continue;

                if( _has_cycle( node, neighbour, visited ) )
                    return true;
            }
            return false;
        }

};


int main()
{
    std::shared_ptr< Node<char> > a = std::make_shared< Node<char> >('A');
    std::shared_ptr< Node<char> > b = std::make_shared< Node<char> >('B');
    std::shared_ptr< Node<char> > c = std::make_shared< Node<char> >('C');
    std::shared_ptr< Node<char> > d = std::make_shared< Node<char> >('D');
    std::shared_ptr< Node<char> > e = std::make_shared< Node<char> >('E');
   
    a->add_edge(e);
    a->add_edge(c);
   
    // building a cycle
    c->add_edge(d);
    d->add_edge(b);
    b->add_edge(c);
  
    std::cout << *a << *b << *c << *d << *e << std::endl;
    CycleDetection detector;

    std::cout << std::boolalpha
              << detector(a, CycleDetection::GraphType::directed ) << std::endl;

    /* Output:

        A -> [C, E, ]
        B -> [C, ]
        C -> [D, ]
        D -> [B, ]
        E -> []

        A->C->D->B->C->: Cycle detection in node C
        true   
    */

    return 0;    
}