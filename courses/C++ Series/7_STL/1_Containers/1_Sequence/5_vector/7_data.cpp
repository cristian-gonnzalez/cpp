/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <iostream>
#include <vector>
#include <span>



void cstyle_api(int* data, size_t data_size)
{
    // ...
}


int main()
{
    // using CTAD 
    std::vector v{1,2,3};

    // If you want to interface with C library
    cstyle_api( v.data(), v.size() );
      //        ~~~~~~~~
      //       raw array
      //  Direct access to the underlying contiguous storage



    return 0;
}