/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <iostream>
#include <vector>
#include <span>

/*

Reserve:
    Correctly using reserve() can prevent unnecessary reallocations 

*/

int main()
{
    std::vector<long*> v1;
             // ~~~~^
             // Although you can define this, try not to store vector of pointers
             // I tend to prefer objects


    {
        // Lets say I kwnow exactly this collection is going to be about 50 elements
        std::vector<long> v2;

        // This piece of code, as we known, we are reallocating and copying the whole vector
        // everytime it reasches capacity. It can get expensive and we can make a lot of copies
        for(size_t i=0; i<v2.size(); i++)
            v2.push_back(i+1);    
    }
    
    {
        // Lets say I kwnow exactly this collection is going to be about 50 elements
        std::vector<long> v2;
        
        // reserve: 
        //      Increase the capacity of the vector to a value that's greater or equal to 
        // new_cap
        //      This is really efficien and it is a good way to get a lot of performance
        v2.reserve(50);
              //   ~~
              //  new_cap

        // Now we dont have to keep making copies continuosly as we add into the vector
        for(size_t i=0; i<v2.size(); i++)
            v2.push_back(i+1);    
    }

    // NOTE: emplace_back
    //      Constructs an element in-place at the end. This is another thing to do to optimize
 
    return 0;
}