/** STL std::set | Modern Cpp Series Ep. 121
 */
#include <iostream>
#include <set>


void print_data( const std::set<int>& set )
{
   std::cout << "[";
    for(const auto& e: set)
        std::cout << e << ", ";
    std::cout << "]\n";

}

int main()
{
    auto print_rg = []( auto start, auto last )
                    {
                        std::cout << "[";
                        for( auto it = start; it != last; it++ )
                            std::cout << *it << ", ";
                        std::cout << "]\n";
                    }; 
 
    std::set<int> set1{8, 10, 12, 14,};
    std::set<int> set2{4, 6, 8, 10, 12, 14, 16};
    
    // merge (C++17)
    //      Splices (extract/transfer) nodes from another container
    //
    // template< class C2 >
    // void merge( std::set<Key, C2, Allocator>&& source );
    //
    // NOTE:
    //      If there is key equivalent to the key from source, then that element is not extracted. 
    set1.merge( set2 );
    
    print_data(set1); // [4, 6, 8, 10, 12, 14, 16, ]
    print_data(set2); // [8, 10, 12, 14, ]
                      //  ~~~~~~~~~~~~~
                      // These keys already are in set1, so they are not transfered

    return 0;
}