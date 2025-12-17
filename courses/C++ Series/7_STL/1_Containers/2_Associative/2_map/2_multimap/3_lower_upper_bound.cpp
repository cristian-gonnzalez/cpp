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

    {
        // Something we can to do to create a range within out serts is take the
        // lower bound and upper bound
        //
        // lower_bound
        //     returns an iterator to the first element not less than the given key
        //                                              ~~~~~~~~~~~~~
        //                                                T >= K (greater than or equal to key)
        // upper_bound
        //     returns an iterator to the first element greater than the given key
        //                                              ~~~~~~~~~~~~
        //                                                T > K    
        
        // [ (mike -> 100),  (mike -> 101),  (mike -> 102),  (mike -> 103),  (mike -> 103),  (mike -> 103),  (nick -> 107),  (tomoki -> 117), ]
        //    ~~~~                                                                            ~~~~            ^^^^                                                                                                 
        //    first_entry                                                                    T > "mike"     last_entry
        //    T >= "mike"                                                                    

        auto first_entry = mymap.lower_bound("mike");
        auto last_entry = mymap.upper_bound("mike");  

        std::cout << "lower_bound - T >= 'mike': (" 
                << first_entry->first  << " -> " 
                << first_entry->second << ")\n"; // lower_bound - T >= 'mike': (mike -> 100)
        std::cout << "upper_bound - T > 'mike' : (" 
                << last_entry->first   << " -> "
                << last_entry->second  << ")\n";  // upper_bound - T > 'mike' : (nick -> 107)

    
        std::cout << "[";
        for( ; first_entry != last_entry; first_entry++)
            std::cout << "(" << first_entry->first << " -> " << first_entry->second << "), ";    
        std::cout << "]\n";
        // [(mike -> 100), (mike -> 101), (mike -> 102), (mike -> 103), (mike -> 103), (mike -> 103), ]
    }
    
    return 0;
}