/** C++ STL std::stack (a container adaptor) | Modern Cpp Series Ep. 131
 */ 
#include <iostream>
#include <stack>
#include <vector>
#include <list>

/*
std::stack:

    The container adaptor must be a SequenceContainer and provide the following functions:


    back(), e.g., std::vector::back(),
    push_back(), e.g., std::deque::push_back(),
    pop_back(), e.g., std::list::pop_back().


    For ex: std::vector, std::deque and std::list satisfy these requirements. 

*/


void view_stack( auto copy )
{
    int r;
    std::cout << "[";
    while(!copy.empty())
    {
        r = copy.top();
        copy.pop();

        std::cout << r << ", ";
    }
    std::cout << "]\n "; 
}

int main()
{
    // The container we choose will change the performance of the stack
    {
        std::stack<int, 
                std::vector<int> // if your insertions into the stack immediately at the very
                                 // start, std::vector mught be the best option
                > s({-3,-2,1,0 /*, 2.3 */});
        //                        ~~~~~
        // narrowing conversion of '2.2999999999999998e+0' from 'double' to 'int

        view_stack(s); // [0, 1, -2, -3, ]

    }
    {
        std::stack<int, 
                std::list<int>   // if your insertions into the stack ara done frequently or sometimes
                                 // std::list mught be the best option
                > s({-3,-2,1,0 /*, 2.3 */});
        //                        ~~~~~
        // narrowing conversion of '2.2999999999999998e+0' from 'double' to 'int

        view_stack(s); // [0, 1, -2, -3, ]
    }
    return 0;
}