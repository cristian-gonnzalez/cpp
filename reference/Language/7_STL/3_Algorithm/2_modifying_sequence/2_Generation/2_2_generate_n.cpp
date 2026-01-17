/** C++ STL algorithm - std::generate and std::generate_n
 *  
 */
#include <iostream>
#include <algorithm>
#include <vector>

//
//  Modifying sequence operations
//      This means these algorithms might modify the container
//

//    assigns the results of successive function calls to N elements in a range (function template)
//

// template< class ExecutionPolicy,
//          class ForwardIt, class Size, class Generator >
// ForwardIt generate_n( ExecutionPolicy&& policy,
//                       ForwardIt first, Size count, Generator g );
//                                                     ~~~~~~~~~
//                                                         ^
//	                             Generator function object that will be called. It could be a function or functor (lamdba)
//	                             The signature of the function should be equivalent to the following:

//	                                          Ret fun();
//                                            ~~~
//                                             ^
//	                                   The type Ret must be such that an object of type 
//                                 ForwardIt can be dereferenced and assigned a value of 
//                                 type Ret.​



//
// Complexity: O(N) Linear time
//

int f()
{
    static int i=0;
    //          ~~
    // static variables have to be initialized to sth

    return i++;
}

int g(int i)
{
    return i*2;
}


int main()
{
    auto print_v = [](auto v)
                  {
                    std::cout << "[";
                    for(auto& e: v)
                        std::cout << e << ", ";
                    std::cout << "]\n";
                  };
                
    {
        std::vector<int> ints(10);
        //                    ~~
        //            we need to explicity to say how big our collection is. Otherwise, generate will iterate 0 times.
        std::generate_n( std::begin(ints), 5, f); 
 
        print_v(ints); // [0, 1, 2, 3, 4, 0, 0, 0, 0, 0, ]
    }

    {
        std::vector<int> ints(10);
        //                    ~~
        //            we need to explicity to say how big our collection is. Otherwise, generate will iterate 0 times.
        std::generate_n( std::begin(ints), 5,
                       [n=0]() mutable
                    //  ~      ~~~~~~~
                    //  ^       We need to specify that the variable n in the capture section is not read-only making this
                    //  |       mutable
                    // read-only variable 'n'.  
                       {
                         return g(n++);
                       }); 
 
        print_v(ints); // [0, 2, 4, 6, 8, 0, 0, 0, 0, 0, ]

    }
    
   
    return 0;
}


