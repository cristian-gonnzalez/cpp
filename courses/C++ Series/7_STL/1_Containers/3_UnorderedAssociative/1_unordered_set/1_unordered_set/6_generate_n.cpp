/** STL std::unordered_set (std::algorithm generate_n for creation of sets) | Modern Cpp Series Ep. 122
 */
#include <iostream>
#include <unordered_set>
#include <algorithm> // std::generate_n
#include <iterator>  // std::inserter


void print_data(const std::unordered_set<int>& s)
{
    std::cout <<  "[";
    for(const auto& e: s)
        std::cout << e << ", ";
    std::cout <<  "]\n";
}

int gen()
{
    static int i=0;
    return ++i;
}

int main()
{
    std::unordered_set<int> s;

    //                           iterator in c indicating 
    //                           the insertion position      generator function
    // Populates the set                ^                      ^
    std::generate_n( std::inserter(s, s.begin()),         10, gen  );
                  //               ^                       ^
                  //         container that supports    number of the 
                  //         an insert operation       elements to generate

    print_data(s);   // [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, ]

    return 0;
}