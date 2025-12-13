/** std::make_shared
 *
 */
#include <iostream>
#include <memory>  // std::shared_ptr

// std::make_shared() allocates the dynamic object and the RC in a single allocation
//      - More efficient that allocatin them separately

int main()
{


    // This sentence create the reference counter and the shared resource in a separated bloack of memory   
    //
    //      | 1  |          | 100 |
    //      |____|          |_____|
    //        RC          shared-resource
    //
    std::shared_ptr<int> p1{new int(100)};


    // This sentence create the reference counter and the shared resource in a single block   
    //
    //                 | 100 |
    // shared-resource |     |
    //                 |_____|
    //                 |     |
    //              RC | 1   |         
    //                 |_____|         
    //
    auto p2{ std::make_shared<int>(100) };   // std::shared_ptr<int> p2{ std::make_shared<int>(100) };
                            // ^   ~~~       // auto p1 = std::make_shared<int>(100)
                            // |    ^
                            // |   This is a variatic template, so you can pass any amount of arguments
                            // |
                            // Call the constructor (i.e int) with these parameter
    return 0;
}