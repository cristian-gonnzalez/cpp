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
    std::set<int> set1{4,6,8,10,12,14,16};
                    // ~~~~~~~
                    // std::initializer-list

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

    //        ~              ~~
    // [4, 6, 8, 10, 12, 14, 16, ]
    //        ^           ^  
    //       >=           >
    //      lower        upper
    auto lb = set1.lower_bound(8);
    auto ub = set1.upper_bound(14);

    std::cout << "lower_bound - T >= 8: " << *lb << std::endl; // lower_bound - T >= 8: 8
    std::cout << "upper_bound - T >  8: " << *ub << std::endl; // upper_bound - T >  8: 16

    std::cout << "range: [";
    for( auto it = lb; it != ub; it++ )
        std::cout << *it << ", ";
    std::cout << "]\n";                    // range: [8, 10, 12, 14, ]

    return 0;
}