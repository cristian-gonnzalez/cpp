/** STL std::array (Since C++11) | Modern Cpp Series Ep. 114
 */

#include <iostream>
#include <array>

/*
Element access
*/
 
int main()
{
    std::array<int, 5> data{1,2,3,4,5};

    // at():
    {
        // Access specified element with bounds checking
        std::cout << data.at(4) << std::endl; // 5

        try{
            std::cout << data.at(8) << std::endl; 
            //                   ^
            // throwing an instance of 'std::out_of_range'

        } catch( const std::out_of_range& e)
        {
            std::cerr << e.what() << std::endl; // array::at: __n (which is 8) >= _Nm (which is 5)
        } 
    }
    
    // operator[]
    {
        // access specified element. No bounds checking is performed.
        std::cout << data[0] << std::endl; // 1

        // We get SIGSEGV. No exception is thrown
        //std::cout << data[5] << std::endl; // SIGSEGV
         
    }

    return 0;
}
