/** std::range
 *
 */

#include <iostream>
#include <vector>

//
// A range is a pair of iterators
//
//  template<tyepname T>
//  struct rante {
//    T start;
//    T sentinel;  
//      ~~~~~~~~
//      it means the end
//  }; 
//
//
//  In C++20, we also got concepts, which helped make possible the range API.
//      - A range thus can be defined with a concept that has a 'begin' and 'end'
//
//  template<typename T>
//  concept range = requiries(T& t)
//  {
//      ranges::begin(t);
//      ranges::end(t);
//  };
//
// ranges work effectively with:
//      - All of the containers (array, vector, map, etc) are ranges.
//      - All of the container adaptors (queue, stack, etc) ara ranges.
//      - And 'non-owning' or 'borrowed' containers like (std::strin_view, std;;span, are 'borrowes ranges')

int main()
{

    // We still use iterators with rages
    // Iterators don'go completely away, we still use them, and we build ranges on top of iterators.
    
    std::vector data{3,9,7,5,1};
    if( auto iter = std::ranges::find_if(data, 
        //   ~~~~
        //   Observe even with ranges, sometimes 
        //   we still return an iterator
                                     [](int i)
                                     {
                                        return i==1;
                                     }); 
                                     iter != std::ranges::end(data) )
    {
        std::cout << "I found 1!!! " << *iter << std::endl; // I found 1!!! 1
    }
    
    std::string dna = "GCTCATC";
    auto dna_iter = std::ranges::find(dna, 'T');
    if( dna_iter != std::ranges::end(dna) )
    {
        std::cout << "I found T!!! " << *dna_iter << std::endl; // I found T!!! T
    }

    // Here is an 'old-style' for-loop with ranges::begin and ranges::end jsut to show it works
    std::vector old{1,2,4,8,12,14};
    for(auto start = std::ranges::begin(old); 
             start != std::ranges::end(old);
             start++ )
    {   
        std::cout << *start << ", ";
    } // 1, 2, 4, 8, 12, 14, 

    return 0;
}
