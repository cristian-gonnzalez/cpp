/** C++ STL algorithm - search (find)
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//  std::search:
//  Searches for the first occurrence of the sequence of elements

int main()
{
    std::vector<int> v{1,2,3,4,5};
    std::vector<int> s{2,3,4};

    if(auto result = std::search( v.begin(), v.end(),
                              //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                              //          This is my container
            
                                  s.begin(), s.end());
                              //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                              //  This is the sequence Im looking for in my vector v
       result != v.end())
    {
        std::cout << "Found our sequence!\n";  // Found our sequence!
    }

    return 0;
}


