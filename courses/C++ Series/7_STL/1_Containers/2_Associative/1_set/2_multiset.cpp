/** STL std::multiset (And how to compare non-trivial types) | Modern Cpp Series Ep. 123
 */

#include <iostream>
#include <set>
#include <algorithm>


/* 
std::multiset:

    It is an associative container that contains a sorted set of objects of type Key but it 
allows duplicates elements.

    The order of the duplicates elements is the order of insertion and does not change 
(see 1_intro.cpp)

*/

void print_data( const std::multiset<int>& set )
{
   std::cout << "[";
    for(const auto& e: set)
    {
        std::cout << e << ", ";
    }
    std::cout << "]\n";

}

int main()
{
    std::multiset<int> s{1,2,5,9,9,9,10,10};

    // count: log(N)
    //      Returns the number of elements matching specific key
    std::cout << "count 9 : " << s.count(9) << std::endl; // count 9 : 3
    std::cout << "count 10: " << s.count(10) << std::endl; // count 9 : 2
    
    // erase:
    //      Removes specified elements from the container. The order 
    // of the remaining equivalent elements is preserved.
    // 
    // iterator erase( iterator pos );                   O(1)
    // iterator erase( iterator first, iterator last );  log(N) + std::distance(first, last)
    // size_type erase( const Key& key );                log(N) + c.count(key)
    //

    // contains: (C++20) log(N)
    //      Checks if the container contains element with specific key
    if( s.contains(9))
        s.erase(9);

    print_data(s); // [1, 2, 5, 10, 10, ]
    std::cout << "count 9 : " << s.count(9) << std::endl;  // count 9 : 0
    
    // Removes just one key
    if(auto it = s.find(10); it != s.end() )
        s.erase(it);
        //      ~~
        //     Just reomove the position
        
    print_data(s); // [1, 2, 5, 10, ]

    std::cout << "count 10: " << s.count(10) << std::endl; // count 10: 1
        
    return 0;
}