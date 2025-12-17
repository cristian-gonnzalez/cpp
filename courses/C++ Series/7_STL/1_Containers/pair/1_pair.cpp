/** STL std::pair (and also a peek at std::ref and std::get) | Modern Cpp Series Ep. 125
 */
#include <iostream>
#include <utility> // std::pair
#include <string>
#include <vector>
#include <functional>

/* 
std::pair: 
    It is an specialization of std::tuple but with a pair, we have only two fields.

Defined in header <utility>

template<
    class T1,
    class T2
> struct pair;

    Used in std::map as key-value.

    Member objects:

        Member name	    Type
        first	        T1             Key
        second	        T2             Value

*/

int main()
{
    using student_t = std::pair< int, std::string >;
                    //           ~~~  ~~~~~~~~~~~
                    //         first    second
    
    {
        //std::pair<int, std::string> student{1, "mike"};
        student_t student{1, "mike"};
        //               ^         ^
        //               Using {} to prevent narrowing
        //
        // std::pair has:
        //
        //     - a constructor pair(const T1&, const T2&)
        //     - NO constructor that takes std::initializer_list
        //
        // Therefore, when using {}, it does NOT use an std::initializer_list.
        // It simply calls the regular constructor using brace initialization.
        //    

        // Access
        std::cout << student.first << " -> " << student.second << std::endl;     // 1 -> mike
    }

    {
        std::vector<student_t> students;

        for(int i=0; i<5; i++)
            students.emplace_back( i, "name_" + std::to_string(i) );
        
        auto print_v = [](const auto& students)
                        {   
                            std::cout << "[";
                            for(const auto& e: students)
                                std::cout << "("<< e.first << ": " << e.second << "), ";
                            std::cout << "]\n";
                        };

        print_v(students); // [(0: name_0), (1: name_1), (2: name_2), (3: name_3), (4: name_4), ]
    }

    return 0;    
   }