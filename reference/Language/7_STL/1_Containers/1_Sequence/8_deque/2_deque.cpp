/** STL std::deque | Modern Cpp Series Ep. 120
 */
#include <iostream>
#include <deque>
#include <algorithm> // std::for_each
#include <cstdio>    // std::fputs

void print_data(const std::deque<int>& data)
{
    std::cout << "[";
    std::for_each(std::begin(data), std::end(data),
                  [](const int& n)
                  {        
                           // put string    
                           // ~~~^
                        std::fputs( std::to_string(n).c_str(), stdout );
                                    //   ~~~~~~~~~~~
                                    // convert int to string   
                        std::fputs(", ", stdout );   
                  });
                  
    std::cout << "]\n";
}

int main()
{
    std::deque<int> dq{1,2,3,4};
 
    print_data(dq);  // [1, 2, 3, 4, ]

    {
        // operator[]
        //      Access specified element
        //      Random access - constant O(1).        
        std::cout << "dq[0]: "<< dq[0] << std::endl;  // dq[0]: 1
    }

    // IMPORTANT:
    //      std::dequeue has no reserve() such as std::vector, we cant pre-allocate the
    // memory since std::dequeue is a pretty-efficient data-structure that manages expansion
    {
        // insert:
        //      Inserts elements
        //
        // iterator insert( const_iterator pos, T&& value );
        //

        // The below is equivalent: std::deque<int>::iterator it
        auto it = dq.begin(); 
        
        // Moves two position
        it++;
        it++;
        
        dq.insert( it, 500 );
            //   ~~  ~~~
            //  pos  value     
        print_data(dq);  // [1, 2, 500, 3, 4, ]
    }
    
    //    - Insertion or removal of elements - linear O(n).
    {   
        auto it = dq.begin() + 2; 
        auto end = dq.end();
        
        // calculate the distance between the current and the end iterators
        int distance = std::distance(it, end);
        
        // Reset the it iterator and advance it whatever distance is 
        it = dq.begin();
        std::advance(it, distance);
        
        dq.insert(it, 7);
        
        print_data(dq); // [1, 2, 500, 7, 3, 4, ]
    }
 
    //    - Insertion or removal of elements at the end or beginning - constant O(1).
    {       
        dq.push_back(123);
        dq.push_front(999);

        print_data(dq); // [999, 1, 2, 500, 7, 3, 4, 123, ]
    }

    return 0;
}