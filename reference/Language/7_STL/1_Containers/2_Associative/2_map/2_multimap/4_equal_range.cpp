/** STL std::multimap (ordered, stable, multiple keys -trick with equal_range)|Modern Cpp Series Ep. 128
 */
#include <iostream>
#include <string>
#include <map>

/*
std::multimap:
    It is an associative container that contains a sorted list of key-value pairs, 
while permitting duplicates entries with the same key. (see 1_asociative.cpp)

    The order of the duplicates elements is the order of insertion and does not change.
It is called a stable data-structure (see 1_asociative.cpp)

*/
void print_data( const std::multimap<std::string, int>& mymap )
{
    std::cout << "[";
    for( const auto& e: mymap)
        std::cout << " ("<< e.first << " -> " << e.second << "), ";
    std::cout << "]\n";
}


int main()
{
    // Creating a map and initilizes with an std::initializer_list
    std::multimap<std::string, int> mymap{ {"mike", 100},
                                           {"mike", 101}, 
                                           {"nick", 107},
                                           {"mike", 102}, 
                                           {"mike", 103}, 
                                           {"tomoki", 117}, 
                                           {"mike", 103}, 
                                           {"mike", 103} };

    print_data( mymap ); 
    // [ (mike -> 100),  (mike -> 101),  (mike -> 102),  (mike -> 103),  (mike -> 103),  (mike -> 103),  (nick -> 107),  (tomoki -> 117), ]
 

    // equal_range:
    //      Returns a range containing all elements with the given key in the container.
    //
    // std::pair<iterator, iterator> equal_range( const Key& key );
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // std::pair containing a pair of iterators defining the wanted range:
    
    // We can do sth more efficient way to get a range containing all the elements with a given
    // key. Using lower_bound/upper_bound is a log(N) operation but we are doing it twice.
    // That's why equal_range is a better choise
    auto [start, last] = mymap.equal_range("mike");
    
    std::cout << "[";
    for( ; start != last; start++)
        std::cout << "(" << start->first << " -> " << start->second << "), ";    
    std::cout << "]\n";
    // [(mike -> 100), (mike -> 101), (mike -> 102), (mike -> 103), (mike -> 103), (mike -> 103), ]

    return 0;
}