/** STL std::pair (and also a peek at std::ref and std::get) | Modern Cpp Series Ep. 125
 */
#include <iostream>
#include <utility>    // std::pair
#include <string>
#include <vector>
#include <functional> // std::ref


int main()
{
    //
    // Non-member functions
    //
    {
        // make_pair: 
        //      Creates a std::pair object, deducing the target type 
        // from the types of arguments. (function template)    
        
        // You might want to be carefull with make_pair deduction and auto since
        // it can deduce sth different 
        auto np1 = std::make_pair(5, "hello");  //    std::pair<int, const char *> np1 = std::make_pair(5, "hello");
    
        // Try to be explicit to avoid wrong deduction 
        auto np2 = std::make_pair(100L, 10.0f);   // std::pair<long, float> np2 = std::make_pair(100L, 10.0F);

    }

    {
        long value = 100L;
        auto pair = std::make_pair( value, 19.0f ); // std::pair<long, float> pair = 
                                                    //    std::make_pair(value, 19.0F);
        
        // std::ref:
        //      We can build a pair with a reference type. Then if 
        // we modify the value, it will be updated
        auto ref_pair = std::make_pair( std::ref(value), 19.0f ); // std::pair<long &, float> ref_pair = 
                                                                  //    std::make_pair(std::ref(value), 19.0F);
        
        // If I modify the value, it is updated in the pair since it is a reference to value
        value = 230L;
        std::cout << ref_pair.first << " -> " << ref_pair.second << std::endl; // 230 -> 19

        // Since value is a copy, it is not modified
        std::cout << pair.first << " -> " << pair.second << std::endl; // 100  -> 19
    }
    
    {
        // get(std::pair): 
        //      Accesses an element of a pair (function template)
        //
        //      Extracts an element from the pair using tuple-like interface.
        
        auto np = std::make_pair( 50L, 2.5f );
        std::cout << std::get<0>(np) << " -> " << std::get<1>(np) << std::endl; // 50 -> 2.5
        //                    ^
        //             The index-based:
        //                      0 - first
        //                      1 - second
        std::cout << std::get<long>(np) << " -> " << std::get<float>(np) << std::endl; // 50 -> 2.5
        //                    ~~~~                            ~~~~~
        //                type-based                          type-based  
        //
        //  The type-based overloads fail to compile if the types first and second are the same.
    }

    return 0;    
}