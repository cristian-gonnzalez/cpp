/** Shared pointer
 *
 */
#include <iostream>
#include <memory>  // std::shared_ptr

//  std::shared_ptr is a non-exclusive pointer to a dynamically allocated object ()
//
//      - Uses a reference counter (RC) internally
//      - Ownership of an object can be shared by any number of other shared pointers
//      - The shared object is not released until the last shared pointer referencing the object is destroyed
//      - std::shared_ptr supports copying semantics.

// When to use std::shared_ptr
//
//  - Use std::shared_ptr whenever you want reference counting
//


int main()
{

    // Important methods
    //
    // - Modifier methods:
    //      operator = ()
    //      reset
    //      swap
    //
    // - Query method
    //      use_count()
    //      unique()
    //      operator bool()
    //
    // - Objet-access methods
    //      get()
    //      operator*()
    //      operator->()
    //
    
    std::shared_ptr<int> p1{ new int(10) };

    std::cout << "RC: " << p1.use_count() << ", " <<
                    "Am I the only owner?:  " << p1.unique() << std::endl; // RC: 1, Am I the only owner?:  1
            
    std::shared_ptr<int> p2;
    {  // Copy
                
        // operator=() : assigment operator
        // p1 and p2 share the resource
        p2 = p1;

        std::cout << "{ "
                  << "p1: " << *p1 << ", "
                  << "p2: " << *p2 << " }\n";   // { p1: 10, p2: 10 }
        
        std::cout << "RC: " << p1.use_count() << ", " <<
                     "Am I the only owner?:  " << p1.unique() << std::endl; // RC: 2, Am I the only owner?:  0
    }

    {  // Reset

        // reset() : relaces the managed object.
        // Now p2 points to a new resource meanwhile p1 still pointing the old resource
        p2.reset( new int(20) );
        
        std::cout << "{ "
                << "p1: " << *p1 << ", "
                << "p2: " << *p2 << " }\n";   // { p1: 10, p2: 20 }

        std::cout << "RC: " << p1.use_count() << ", " <<
                    "Am I the only owner?:  " << p1.unique() << std::endl; // RC: 1, Am I the only owner?:  1
    }

    std::shared_ptr<int> p3{p1};
    std::shared_ptr<int> p4{p2};

    { // Swap

        std::cout << "{ "
                << "p1: " << *p1 << ", "
                << "p2: " << *p2 << ", "
                << "p3: " << *p3 << ", "
                << "p4: " << *p4 << " }\n";   // { p1: 10, p2: 20, p3: 10, p4: 20 }
    
        std::cout << "RC: " << p1.use_count() << ", " <<
                     "Am I the only owner?:  " << p1.unique() << std::endl; // RC: 1, Am I the only owner?:  1

    
        // swap()
        // swaps the resources
        p2.swap(p3);


        std::cout << "{ "
                << "p1: " << *p1 << ", "
                << "p2: " << *p2 << ", "
                << "p3: " << *p3 << ", "
                << "p4: " << *p4 << " }\n";   // { p1: 10, p2: 10, p3: 20, p4: 20 }

    }
 
    // Checks if *this stores a non-null pointer, i.e. whether get() != nullptr.
    if( p1 ) // equivalent .> p1.bool()
        std::cout << "p1 is not nullptr\n"; // p1 is not nullptr

    *p1 = 500;
    *p3 = 800;
    
    std::cout << "{ "
            << "p1: " << *p1 << ", "
            << "p2: " << *p2 << ", "
            << "p3: " << *p3 << ", "
            << "p4: " << *p4 << " }\n";   // { p1: 500, p2: 500, p3: 800, p4: 800 }

    return 0;
}