/** Parallel algorithms
 *
 */

#include <iostream>
#include <algorithm>
#include <execution>

//
// 'for_each' or 'transform' are functions of the algorithm stl library that perfoms an operation on each item in a collection
// Those algorithm are sequencial and they operate on a single thread but if you want to, you can pass in an optional
// parameter of type std::execution
//                   ~~~~~~~~~~~~~~
//                   you can specify the execution policy that will be used when iteration occurs
//
// Algorithms support an execution policy for parallelization via classes defined in the namespace std::execution:
//
//      - sequenced_policy
//      - parallel_policy
//      - parallel_unsequenced_policy
//      - unsequenced_policy
//
// For each policy class, there's a predifined instance (global objects created of each type):
//
//      - seq   -> global object of sequenced_policy class -> single thread (linear and slow)
//      - par   -> global object of parallel_policy class  -> 
//      - par_unseq  -> global object of parallel_unsequenced_policy class
//      - unseq  -> global object of unsequenced_policy class
//          
// So the idea is you can pass in one of these objects to tell the algorithm how to parallelize processing.

int main()
{
    std::vector v{100,200,300};   

    std::cout << "[";
    std::for_each( std::execution::par,   // works well if you have a really large container like 1000 or 2000 elements
                                          // 'std::execution::par' can allocate multiple threads and effectively partition your
                                          // vector into segments. And then process each of those chunks 
                   begin( v ),
                   end( v ),
                   []( int i )
                   {
                     std::cout << i << ", ";
                   } );
    std::cout << "]\n"; // [100, 200, 300, ]

    // std::execution::par
    //
    // [ , , , , |, , , , ,| , , , , |,  , , , ]
    //           |         |         |      
    // thread1      thread2  thread3  thread4
    //  ^
    // Each thread will process a segment sequencially.
    //

    
    // std::execution::par_unseq
    //
    // [ , , , , |, , , , ,| , , , , |,  , , , ]
    //           |         |         |      
    // thread1      thread2  thread3  thread4
    //  ^
    // Each thread will process a segment but there is not guarantee of the sequencial processing of the segment
    //
    return 0;

}