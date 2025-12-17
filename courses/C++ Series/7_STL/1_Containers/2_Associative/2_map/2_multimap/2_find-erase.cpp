/** STL std::multimap (ordered, stable, multiple keys -trick with equal_range)|Modern Cpp Series Ep. 128
 */
#include <iostream>
#include <string>
#include <map>

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
                                           {"mike", 3}, 
                                           {"mike", 101}, 
                                           {"mike", 102}, 
                                           {"mike", 103} };

    {
        // find
        //      Finds an element with key equivalent to key.
        //
        //      iterator find( const Key& key );
        //
        //      If there are several elements with the requested key in the container, 
        // any of them may be returned.

        if( auto it = mymap.find( "mike" ); it != mymap.end() )
                // erase: constant O(1)
                //      Removes the element at pos.
                //
                //  iterator erase( iterator pos );
                //   ~~~~~~~
                // Iterator following the last removed element.
                mymap.erase( it );

        print_data( mymap ); // [ (mike -> 3),  (mike -> 101),  (mike -> 102),  (mike -> 103), ]
    }

    {
        // erase: log(c.size()) + c.count(key)
        //      Removes all elements with the key equivalent to key.
        //
        // size_type erase( const Key& key );
        // ~~~~~~~~~
        // Returns umber of elements removed.
        mymap.erase( "mike" );

        print_data( mymap ); // []
    }
    
    return 0;
}