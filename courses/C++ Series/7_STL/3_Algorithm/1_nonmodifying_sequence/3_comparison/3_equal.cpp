/** C++ STL algorithm - comparison with std::equal
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Non-modifying sequence operations:
//      This means we are not destroying or changing our data
//

//   std::equal
//      Determines if two sets of elements are the same

//
// Complexity: O(N1)

// 
// template< class InputIt1, class InputIt2, class BinaryPred >              (7)
// bool equal( InputIt1 first1, InputIt1 last1,
//             InputIt2 first2, InputIt2 last2, 
//             BinaryPred p ); <- Element by element comparison
//             ~~~~~~^^^^
//             ^     Predicate means that returns true or false
//             | 
//    Binary means it takes two parameters

int main()
{
    {
        // NOTE: we have to make sure that the second container is not shorter than the first one
        std::vector v1{1,2,3,4};
        std::vector v2{1,2,3,4};
        
        std::cout << std::boolalpha
                << "Is equal? " << std::equal( v1.begin(), v1.end(),
                                                v2.begin() ) << std::endl;  //  Is equal? true
    }
    
    
    {
        // If the length is not the same, it returns false 
        std::vector v1{1,2,3,4};
        std::vector v2{1,2,3};
        
        std::cout << std::boolalpha
                << "Is equal? " << std::equal( v1.begin(), v1.end(),
                                                v2.begin() ) << std::endl;  //  Is equal? false
    }

    
    {
        // If we have two containers where we know that has a different size, we can just check just a range
        std::vector v1{1,2,3,4};
        std::vector v2{1,2,3};
        
        std::cout << std::boolalpha
                << "Is equal? " << std::equal( v1.begin(), v1.begin()+3,
                                               v2.begin(), v2.end() ) << std::endl;  //  Is equal? true
    }

    {
        // If we have two containers where we know that has a different size, we can just check just a range
        std::vector v1{1,2,3,4};
        std::vector v2{1,2,3};
        
        std::cout << std::boolalpha
                << "Is equal? " << std::equal( v1.begin(), v1.begin()+3,
                                               v2.begin(), v2.end(), 
                                               [](int i, int j) 
                                               {
                                                    return i==j;
                                                    //     ~~~~~
                                                    //   Here we must change if we are using a custom data-type or
                                                    // change the behaviour when comparing two element

                                               } ) << std::endl;  //  Is equal? true

        std::string s1{"hello"};
        std::string s2{"HELLO"};

         std::cout << std::boolalpha
                << "Is equal? " << std::equal( s1.begin(), s1.end(),
                                               s2.begin(), s2.end()) 
                                << std::endl                                  //  Is equal? false
                // Example where the string comparison is not case-sensitive
                << "Is equal? " << std::equal( s1.begin(), s1.end(),
                                               s2.begin(), s2.end(), 
                                               [](char i, char j) 
                                               {
                                                    return toupper(i)==toupper(j);
                                               } ) << std::endl;              //  Is equal? true

    }




    return 0;
}


