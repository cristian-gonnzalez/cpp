/** STL std::unordered_set (std::algorithm generate_n for creation of sets) | Modern Cpp Series Ep. 122
 */
#include <iostream>
#include <unordered_set>


void print_data(const std::unordered_set<int>& s)
{
    std::cout <<  "[";
    for(const auto& e: s)
        std::cout << e << ", ";
    std::cout <<  "]\n";
}

int main()
{
    std::unordered_set<int> s{1,2,3,4,5,6};
    
    // erase
    //      Erases elements
    //
    // size_type erase( const Key& key ); 
    //
    // Number of elements removed (0 or 1).
    std::cout << "We removed " << s.erase(5) << " element\n"; // We removed 1 element
    std::cout << "We removed " << s.erase(99) << " element\n"; // We removed 0 element

    print_data(s); // [6, 4, 3, 2, 1, ]

    // iterator erase( iterator pos );
    // iterator erase( const_iterator first, const_iterator last );
    
    return 0;
}