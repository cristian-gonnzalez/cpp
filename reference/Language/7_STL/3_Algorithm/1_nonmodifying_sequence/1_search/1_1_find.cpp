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

// std::find
//      Find the existance of an element

int main()
{
    {
        std::vector<int> v{1,3,5,12,7,9,10};

        if( auto result = std::find(v.begin(), v.end(), 7); 
            result != v.end() )
        //            ~~~~~~~
        //   If we didnt find sth, it means we reach the end
        {
            std::cout << "found 7\n";  // found 7
        }

        if( auto result = std::find(v.cbegin(), v.cend(), 8);
                                //    ~~~~~~
                                //  we can use const to express we are not changing anything 
            result != v.end() )
        {
            std::cout << "found 8\n";
        }
        else {
            std::cout << "Nothing\n";  // Nothing
            
        }

    }

    {
        // Searching in a small range
        //
        // Im giving myseld this range that is 1, 3 and the iterator ends at 5
        //
        //                [-------]
        std::vector<int> v{1, 3, 5, 12, 7, 9, 10};
        //                 ^     ^
        //               begin  end 
        {
            auto result = std::find(v.begin(), v.begin()+2, 7);
                                    //   ~~~~~~~~~~~
                                    //    this is the end
            if( result != v.end() )
                    // ~~~~~~~
                    // This is not the end of the range we are searching
            {
                std::cout << "found 7\n";  // found 7
            }

            // Nothing is printed
            if( result !=  v.begin()+2 )
                    //  ~~~~~~~~~~~
                    // This is the end of the range we are searching
            {
                std::cout << "found 7\n";  
            }
        }
        
        
        // Nothing is printed since 5 is the end
        if( auto result = std::find(v.begin(), v.begin()+2, 5);
            result !=  v.begin()+2 )
            std::cout << "found 5\n";

        if( auto result = std::find(v.begin(), v.begin()+2, 3);
            result !=  v.begin()+2 )
            std::cout << "found 3\n";    // found 3
    }
    
  
    return 0;
}


