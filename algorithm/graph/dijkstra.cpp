#include <iostream>
#include <vector>
#include <forward_list>
#include <set>
#include <algorithm>
#include <initializer_list>

namespace graph
{

#define DISTANCE_UNKNOWN  99999

    /** Defining an array to holds the nodes with each distance
     *  Using a min_heap to have the min distance at the top 
     */
    class DijkstraArray
    {
        private:
            // The vector holds the pair (node, distance) as element
            std::vector< std::pair<int, int> > m_data;

        public:
            DijkstraArray(std::initializer_list< std::pair<int, int> > list)
            : m_data{ list }
            {
            }

            bool empty() const
            {
                return m_data.empty();
            }

            int& front()
            {
                return m_data.front().first;
            }
            
            void move_min_at_front()
            {
                std::make_heap( m_data.begin(), m_data.end(), 
                                [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs )
                                {
                                        return (lhs.second > rhs.second);
                                } );
            }

            void pop()
            {
                m_data.erase( m_data.begin() );
            }

            std::vector< std::pair<int, int> >& data()
            {
                return m_data;
            }

            int& operator[](int node)
            {
                for(auto& e: m_data)
                    if(e.first == node)
                        return e.second;
                m_data.push_back( {node, DISTANCE_UNKNOWN} );
                return m_data.back().second;
            }
    };


    /*  Finds the shortest path from the start using dijkstra algorithm (Depth-First Search structure)
     *
     *  /param  adj     The adjacent list
     *  /param  start   The start node
     * 
     *  /return Returns the shortest path (vector) from thr start in order to each node and the distances (vector< pair<node, distance> >) to each node
     * 
     *  NOTE: The param 'adj' is an array where the index 'i' represent the 'node i', 
     *        and each elem is a list with the adjacent nodes to 'node i':  
     *
     *        adj = [ node_0 -> [(node, distance), (node, distance), ... ],
     *                node_1 -> [(node, distance), (node, distance), ... ],
     *                ...
     *                node_n -> [(node, distance), (node, distance), ... ] ] 
     */
    std::pair<
        std::vector< int >,                /* path from the start to each node */
        std::vector< std::pair<int, int> > /* distance to each node as (node, distance) */
    > dijkstra( std::vector< std::forward_list< std::pair<int, int > > > &adj, int start)
    {   
        // holds the visited nodes
        std::set<int> visited;
        // holds the unvisited nodes
        DijkstraArray q{ {start, 0} };
        // holds the distances from the start -> node
        DijkstraArray distances{ {start, 0} }; 
        // holds the shortest path from the start to others nodes
        std::vector< int > path; 

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if( visited.contains(cur) )
                continue;
            
            visited.insert(cur);
            path.push_back( cur );

            try
            {
                for(auto [neighbour, n_distance ]: adj.at(cur) )
                {
                    int dist = distances[neighbour];
                    int new_dist = distances[cur] + n_distance;
                    if( new_dist < dist)
                    {
                        distances[neighbour] = new_dist;
                        q[neighbour] = new_dist;
                    }
                    else 
                    {
                        q[neighbour] = dist;
                    }
                }
            }
            catch(const std::out_of_range& ex)
            {
            }

            q.move_min_at_front();
        }
        
        return {path, distances.data()};
    }
}


int main()
{
                                                                       // node -> {node, distance}, ..., {node, distance}  
    std::vector< std::forward_list< std::pair<int, int > > > adjacent{ /* 0 */ {          {1, 10},         {3, 30}, {4,100} },
                                                                       /* 1 */ {                   {2, 50}                  },
                                                                       /* 2 */ {                                    {4, 10} },
                                                                       /* 3 */ {                   {2, 20},         {4, 60} },
                                                                       /* 4    {                                            }*/ };

    int start = 0;
    auto [path, distances] = graph::dijkstra(adjacent, start);
    
    std::cout << "start: " << start << std::endl; 
    std::cout << "path: [ "; 
    for(const auto& node: path)
        std::cout << node << " -> ";
    std::cout << "]\n"; 
    
    std::cout << "distances: ["; 
    for(const auto& [node, distance]: distances)
        std::cout << "(node: " << node << ", distance: " << distance << "), ";
    std::cout << "]\n"; 

    /*
    OUTPUT:

    start: 0
    path: [ 0 -> 1 -> 3 -> 2 -> 4 -> ]
    distances: [(node: 0, distance: 0), (node: 1, distance: 10), (node: 3, distance: 30), (node: 4, distance: 60), (node: 2, distance: 50), ]
      
    */
    return 0;
}