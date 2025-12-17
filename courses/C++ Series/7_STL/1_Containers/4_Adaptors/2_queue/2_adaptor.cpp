/** C++ STL std::queue a container adaptor | Modern Cpp Series Ep. 132
 */

#include <iostream>
#include <queue>
#include <vector>
#include <list>

/*

std::queue:

    The container adaptor must be a SequenceContainer and provide the following functions:
        
        back(), e.g., std::deque::back(),
        front(), e.g. std::list::front(),
        push_back(), e.g., std::deque::push_back(),
        pop_front(), e.g., std::list::pop_front().
    
    std::deque and std::list satisfy these requirements.
*/

void view_queue( auto copy)
{
    int r;
    
    std::cout << "[";
    while(!copy.empty())
    {
        r = copy.front();
        copy.pop();
     
       std::cout << r << ", ";
    }
     
    std::cout << "]\n ";
}


int main()
{
    {
        // WARNING:
        //      Although we can use std::vector as an adatport. We got
        // a compile-error when calling pop since std::vector<int>' has 
        // pop_front()
        std::queue<int,
                   std::vector<int>> q;
        
        q.push(1);
        q.push(2);
        q.push(3);

        int front = q.front();
        ///q.pop(); 
        //   required from here
        //     q.pop();
        //     ~~~~~^~
        //   error: 'class std::vector<int>' has no member named 'pop_front'   
        //        c.pop_front();
        //        ~~^~~~~~~~~
    }
    {
        std::queue<int,
                   std::list<int>> q;
     
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);

        std::cout << "size : " << q.size() << std::endl;  // size : 5
        std::cout << "front: " << q.front() << std::endl; // front: 1
        std::cout << "back : " << q.back() << std::endl;  // back : 5

        int front = q.front();
        q.pop();
        
        std::cout << "size : " << q.size() << std::endl;  // size : 4
        std::cout << "front: " << q.front() << std::endl; // front: 2
        std::cout << "back : " << q.back() << std::endl;  // back : 5

        view_queue(q); // [2, 3, 4, 5, ]
    }
    
    return 0;
}