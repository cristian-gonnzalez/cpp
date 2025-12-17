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
 
    std::set<int> set1{4, 6, 8, 10, 12, 14, 16};
    //                       ~~~~~~~~~~~~~

    //        ~              ~~
    // [4, 6, 8, 10, 12, 14, 16, ]
    //        ^           ^  
    //       >=           >
    //      lower        upper
    auto lb = set1.lower_bound(8);
    auto ub = set1.upper_bound(14);

    std::cout << "lower_bound - T >= 8: " << *lb << std::endl; // lower_bound - T >= 8: 8
    std::cout << "upper_bound - T >  8: " << *ub << std::endl; // upper_bound - T >  8: 16
    
    print_rg( lb, ub ); // [8, 10, 12, 14, ]

    // erase: 
    //      Erases elements
    //
    // iterator erase( iterator first, iterator last );
    //                      
    set1.erase( lb, ub );

    print_data( set1 );   // [4, 6, 16, ]

    return 0;
}