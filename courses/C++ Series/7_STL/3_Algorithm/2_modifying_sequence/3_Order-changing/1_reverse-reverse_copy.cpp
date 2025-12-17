/** C++ STL algorithm - std::reverse and reverse_copy
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>

//
//  Modifying sequence operations
//      This means these algorithms might modify the container
//

//    reverses the order of elements in a range (function template)
//

//
// template< class BidirIt >
// void reverse( BidirIt first, BidirIt last );
//               ~~~~~~~        ~~~~~~~
//      We need a bi-directional iterator such as an std::array or std::vector that has random access.
//      This means that we cannot reverse a std::forward_list
//
// Complexity: O(N/2)
// 

//
// template< class BidirIt, class OutputIt >
// OutputIt reverse_copy( BidirIt first, BidirIt last,
//                        OutputIt d_first );
//
// Complexity: O(N)
// 



int main()
{
    auto print_v = [](const auto v)
                  {
                    std::cout << "[";
                    for(auto& e: v)
                        std::cout << e << ", ";
                    std::cout << "]\n";
                  };
                
    {
        std::vector<int> ints(10);
        std::generate( std::begin(ints), std::end(ints),
                       [n=0]() mutable
                       {
                         return n++;
                       });  
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]

        std::reverse( ints.begin(), ints.end() );

        print_v(ints); // [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, ]

    }

   
    {
        std::vector<int> ints(10);
        std::generate( std::begin(ints), std::end(ints),
                       [n=0]() mutable
                       {
                         return n++;
                       });  
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]

        {            
            std::vector<int> target;
            std::reverse_copy( ints.begin(), ints.end(), std::back_inserter(target) );

            print_v(target); // [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, ]
        }

        {
            std::vector<int> target(ints.size());
                                 // ~~~~~~~~~~~
            std::reverse_copy( ints.begin(), ints.end(), target.begin() );
            //                                                  ~~~~~~
            //      If we are goint to use the iterator, we need to allocate memory before calling reverse

            print_v(target); // [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, ]
        }
    }

    {
        std::forward_list<int> ints(10);
        std::generate( std::begin(ints), std::end(ints),
                       [n=0]() mutable
                       {
                         return n++;
                       });  
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]

        // std::reverse( ints.begin(), ints.end() );
        //  Cannot call std::reverse since we dont have a random_access iterator

        ints.reverse();
        print_v(ints); // [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, ]
    }

    return 0;
}


