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
    {
        std::unordered_set<int> s1{1,2,3,4,5,6};
        std::unordered_set<int> s2{1,2,3,4,5,6};
                            
        // merge: (C++17)
        //      Extract (“splice”/transfer) each element in source and insert it into calling set 
        // using the hash function and key equality predicate of calling set. 
        //
        // template< class H2, class P2 >
        // void merge( std::unordered_set<Key, H2, P2, Allocator>&& source );
        //
        // IMPORTANT:
        //      If there is an element duplicated, that element is not extracted from source.
        //
        //      Given S as size() and N as source.size():
        //
        // Average case O(N), 
        // worst case O(N·S+N).
        s1.merge(s2);

        print_data( s1 ); // [6, 5, 4, 3, 2, 1, ]
        print_data( s2 ); // [6, 5, 4, 3, 2, 1, ]

    }
    
    {
        std::unordered_set<int> s1{1,2,3,4,5,6};
        std::unordered_set<int> s2{11,22,3,4,55,66};
        
        s1.merge(s2);

        print_data( s1 ); // [11, 22, 6, 5, 4, 55, 3, 2, 66, 1, ]
        print_data( s2 ); // [4, 3, ]

    }

    return 0;
}