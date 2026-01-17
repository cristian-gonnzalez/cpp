/** C++ STL std::priority_queue (a container adaptor) | Modern Cpp Series Ep. 133
 */
#include <iostream>
#include <queue>    // std::priority_queue
#include <vector>



struct Edge
{
    int v1{999};
    int v2{999};

    Edge()
    {
    }
    Edge(int _v1, int _v2)
    : v1{_v1},v2{_v2}
    {
    }

    /* Note: uncomment this if you are not using a function object as Comparator
    bool operator<(const Edge& other) const {
        int e1sum = v1 + v2;
        int e2sum = other.v1 + other.v2;

        return e1sum < e2sum;
    }
    */
    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};

struct EdgeCompare 
{
    bool operator()(const Edge& e1, const Edge& e2) const noexcept {
        int e1sum = e1.v1 + e1.v2;
        int e2sum = e2.v1 + e2.v2;

        return e1sum < e2sum;
    }
};

void view_pq( auto copy )
{
    std::cout << "[";
    while(!copy.empty())
    {
        Edge r = copy.top();
        copy.pop();

        std::cout << r << ", ";
    }
    std::cout << "]\n ";
    
}

int main()
{
    // If we overload the operator< int our class, we do not have to
    // provide a Compare function object 
    //std::priority_queue<Edge> q;


    std::priority_queue<Edge,              // T
                        std::vector<Edge>, // Container
                        EdgeCompare        // Compare
                        > q;

    q.emplace(1,1);
    q.emplace(2,2);
    q.emplace(3,3);
    q.emplace(4,4);
    
    view_pq( q ); // [(4, 4), (3, 3), (2, 2), (1, 1), ]
    
    return 0;
}