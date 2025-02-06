#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <memory>

template<typename T>
struct Node
{
    void add_edge(std::shared_ptr< Node<T> > node, int distance)
    {
        _adjacent_nodes[node] = distance;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node<T>& rhs)
    {
        os << rhs._data << " -> [";
        for( const auto [e, dist]: rhs._adjacent_nodes)
            os << e->_data << ":" << dist << ", ";
        os << "]\n";
        return os;
    }

    // If we want to use Node as a Key in std::map/std::set, 
    // we need to overload the less_than operator
    bool operator<(const Node<T>& rhs) const {
        return _data < rhs._data;
    }

    // overloading the equality operator since we need to compare 
    // two nodes when printing the path 
    bool operator==(const Node<T>& rhs) const {
        return _data == rhs._data;
    }

    // The data of the node
    T                                        _data;
    // Holds the adjacent nodes 
    std::map< std::shared_ptr< Node<T> >,    // Adjacent node
              int >                          // distance to adjacent node 
                                             _adjacent_nodes;
};


struct Dijsktra
{ 
    // Holds the distances from the start
    std::map< std::shared_ptr< Node<char> >,  // Node  
              int >                           // distance from the start to this node 
                                              _distances;
    // Holds the path from the start to all nodes
    std::map< std::shared_ptr< Node<char> >,  // node
              std::shared_ptr< Node<char> > > // previous node
                                              _path;
    // Start node
    std::shared_ptr< Node<char> > _start;    

    /** Calculates the shortest path from the start to all nodes
     *
     **/
    void shortest_path( const std::shared_ptr< Node<char> > start )
    {
        _distances.clear();
        _path.clear();
        
        std::set< std::shared_ptr< Node<char> > > visited;   
        std::map< std::shared_ptr< Node<char> >,   // Node
                  int >                            // distance from the start to this node 
                                                  unvisited;

        _start = start;
        _distances[start] = 0;
        _path[start] = start;
        unvisited[ start ] = 0;
        
        while(!unvisited.empty())
        {
            auto [current, d] = _pop_min( unvisited );
            if( visited.contains(current) )
                continue;
            
            visited.insert( current );
            
            for( auto& [n, dist]: current->_adjacent_nodes)
            { 
                // Note:
                //    new_distance is the distance from "start->current + current->n"
                //    distance is the distance from the start->n
                int new_distance = d + dist;
                int distance = _get( _distances, n);
                if(new_distance < distance)
                {
                    _path[n] = current;
                    _distances[n] = new_distance;
                    unvisited[n] = new_distance;
                }        
            }
        }
    }

    /** Prints the path from the start to the end node
     *
     **/
    void print_path_to( std::shared_ptr< Node<char> > end )
    {
        // TODO: check for errors 
        std::stack< std::shared_ptr< Node<char> > > temp;
        temp.push(end);
        
        std::shared_ptr< Node<char> > prev = _path[end];
        if(_start != end )
        {    
            temp.push(prev);
            while(prev != _start )
            {
                prev = _path[prev];
                temp.push(prev);
            }
        }
        
        std::cout << "path: [";
        while(!temp.empty())
        {
            std::shared_ptr< Node<char> > c = temp.top();
            temp.pop();
            std::cout << c->_data << "->";
        }

        std::cout << "]: " <<  _distances[end] <<"\n";
        
    }

    /** Prints the distances from the start node to all nodes and 
     *  the path from the start to all nodes
     *
     **/
    friend std::ostream& operator<<(std::ostream& os, const Dijsktra& rhs)
    {
        os << "distances from "<< rhs._start->_data << ": [";      
        for( const auto [e, dist]: rhs._distances)
            os << e->_data << ":" << dist << " -> ";
        os << "]\n";
    
        os << "path:             [";      
        for( const auto [end, start]: rhs._path)
            os << start->_data << ":" << end->_data << " -> ";
        os << "]\n";
        return os;
    }

    private:
        
        /** Pops the min distance node
         **/
        std::pair< std::shared_ptr< Node<char> >, int > _pop_min( 
                std::map< std::shared_ptr< Node<char> >, int >& distances )
        {
            auto it = std::begin( distances );

            std::shared_ptr< Node<char> > node_min = it->first;
            int dist_min{it->second};

            for(auto& [node, dist]: distances)
            {
                if( dist_min > dist )
                {
                    node_min = node;
                    dist_min = dist;
                }
            }

            distances.erase(node_min);
            return { node_min, dist_min };
        }
        
        /** Gets the distance from the start to the 'key' node. If not found, returns infinite
         **/
        int _get( std::map< std::shared_ptr< Node<char> >, int >& map,
                  const std::shared_ptr< Node<char> > key )
        {
            try
            {
                map.at(key);
            }
            catch(const std::out_of_range& ex)
            {
                map[key] = std::numeric_limits<int>::max();
            }

            return map[key];
        }
};


int main()
{
    std::shared_ptr< Node<char> > a = std::make_shared< Node<char> >('A');
    std::shared_ptr< Node<char> > b = std::make_shared< Node<char> >('B');
    std::shared_ptr< Node<char> > c = std::make_shared< Node<char> >('C');
    std::shared_ptr< Node<char> > d = std::make_shared< Node<char> >('D');
    std::shared_ptr< Node<char> > e = std::make_shared< Node<char> >('E');
    std::shared_ptr< Node<char> > f = std::make_shared< Node<char> >('F');

    a->add_edge(b, 2);
    a->add_edge(c, 4);
   
    b->add_edge(c, 3);
    b->add_edge(d, 1);
    b->add_edge(e, 5);

    c->add_edge(d, 2);

    d->add_edge(f, 4);
    d->add_edge(e, 1);

    e->add_edge(f, 2);
   
    std::cout << *a << *b << *c << *d << *e << std::endl;
    
    /* Output: 
        A -> [B:2, C:4, ]
        B -> [C:3, D:1, E:5, ]
        C -> [D:2, ]
        D -> [E:1, F:4, ]
        E -> [F:2, ]    
    */

    Dijsktra algo;
    algo.shortest_path( a );
 
    std::cout << algo << std::endl;

    /* Output: 
        distances from A: [A:0 -> B:2 -> C:4 -> D:3 -> E:4 -> F:6 -> ]
        path:             [A:A -> A:B -> A:C -> B:D -> D:E -> E:F -> ]
    */

    algo.print_path_to(a);
    algo.print_path_to(b);
    algo.print_path_to(c);
    algo.print_path_to(d);
    algo.print_path_to(e);
    algo.print_path_to(f);

    /* Output:
        path: [A->]: 0
        path: [A->B->]: 2
        path: [A->C->]: 4
        path: [A->B->D->]: 3
        path: [A->B->D->E->]: 4
        path: [A->B->D->E->F->]: 6
    */

    return 0;    
}