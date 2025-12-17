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
    std::multimap<std::string, int> mymap{ {"mike", 2}, 
                                           {"mike", 3} };

    //
    // IMPORTANT:
    //    Element access is not supported ('operator[]' and 'at()')
    //

    {   
        // insert:
        //      Inserts element(s) into the container.
        mymap.insert( std::pair{"mike", 101} );
        mymap.insert( std::pair{"mike", 102} );
        mymap.insert( std::pair{"mike", 103} );

        print_data( mymap ); // [ (mike -> 2),  (mike -> 3),  (mike -> 101),  (mike -> 102),  (mike -> 103), ]
    
        // count:
        //      Returns the number of elements matching specific key
        std::cout << "count 'mike': " << mymap.count("mike") << std::endl; // count 'mike': 5    
    }

    return 0;
}