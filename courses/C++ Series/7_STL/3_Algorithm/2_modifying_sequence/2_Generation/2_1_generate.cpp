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

//    assigns the results of successive function calls to every element in a range (function template)
//

// template< class ForwardIt, class Generator >
// void generate( ForwardIt first, ForwardIt last, Generator g );
//                                                 ~~~~~~~~~
//                                                     ^
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


int main()
{
    auto print_v = [](auto v)
                  {
                    std::cout << "[";
                    for(auto& e: v)
                        std::cout << e << ", ";
                    std::cout << "]\n";
                  };
                
    // This portion code can be replace using std::generate
    // NOTE: 
    //      There is a handy function for this particular case called std::iota from the 'numeric' library
    {
        std::vector<int> ints;
        
        // ---------
        ints.reserve(10);
        for(size_t i=0; i<10; i++)
            ints.push_back(i); 
        // ---------
        
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
    }
    {
        std::vector<int> ints(10);
        //                    ~~
        //            we need to explicity to say how big our collection is. Otherwise, generate will iterate 0 times.
        std::generate( std::begin(ints), std::end(ints), f); 
 
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
    }

    {
        std::vector<int> ints(10);
        //                    ~~
        //            we need to explicity to say how big our collection is. Otherwise, generate will iterate 0 times.
        std::generate( std::begin(ints), std::end(ints), 
                       [n=0]() mutable
                    //  ~      ~~~~~~~
                    //  ^       We need to specify that the variable n in the capture section is not read-only making this
                    //  |       mutable
                    // read-only variable 'n'.  
                       {
                         return n++;
                       }); 
 
        print_v(ints); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
    }
    
   
    return 0;
}


