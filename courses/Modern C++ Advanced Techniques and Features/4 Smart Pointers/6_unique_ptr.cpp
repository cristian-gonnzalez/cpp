/** std::unique_ptr
 *
 */
#include <iostream>
#include <memory>  // std::unique_ptr

// std::unique_ptr retains sole ownership of an object through a pointer.
//      - Destroys object when std::unique_ptr goes out of scope
//      - No two 'std::unique_ptr's can manage the same object

//
// Can be moved to a new owner, but not copied or shared
//  - Can NOT be used in STL algorithm tahn requires a copy

// There are two versions of std::unique_ptr
//
//      - One takes a pointer. 
//
//          resource       | 2   |         
//                         |_____|     
//                           ^
//                           |                                
//                           up           *up  -> we can use * operator
//
//      - The other takes an array.
//
//          resource       [ 1, 2, 3, 4, 5]              
//                           ^
//                           |                                
//                           up           up[i] -> we can use random access 
//
// Slightly different semantics for each

//
// Key methods:
//
//  - operator =()
//  - release(), reset(), swap()
//  - get(), get_deleter(), operator bool()
//  - operator *, operator ->
//
int main()
{
    {
        // Using std::make_unique<>() is more efficient
        std::unique_ptr<int> up{ new int(10) };
        
        // We dont have copy semantics
        //std::unique_ptr<int> up2{ up };
        /*  
        note: declared here
        524 |       unique_ptr(const unique_ptr&) = delete;
            |       ^~~~~~~~~~
        */

        // We have move semantics
        std::unique_ptr<int> up2{ std::move(up) };
    
        if( up2 )
        {
            if( !up )
                std::cout << "up points to nullptr\n";  // up points to nullptr
         
            std::cout << "up2 points own the resource\n";  // up2 points own the resource

            // Release example
            //
            // Releases the ownership of the managed object. The caller is responsible for cleaning up the object

            // The unique_ptr is releasing the ownership of the object
            int* ptr = up2.release();
            //  ~~~~
            // Now it is this pointer that now owns the object

            // It is really important that at some point to delete the object
            delete ptr;
        }
    }

    {
        

        //          object       | 2   |         
        //                       |_____|     
        //                           ^
        //                           |                                
        //                           up       
        std::unique_ptr<int> up{ new int(2) };

        std::cout << "*up: " << *up << std::endl;  // *up: 2


        //          object | 2   |             new object -----> | 100 |         
        //                 |_____|                               |_____|     
        //                    ^                         ____________^
        //           this is destroyed                 |                                
        //                                             up       
        //
        // The reset() will delete the old object and then owned the new object
        up.reset( new int(100) );        

        std::cout << "*up: " << *up << std::endl;  // *up: 100


    }
    return 0;
}