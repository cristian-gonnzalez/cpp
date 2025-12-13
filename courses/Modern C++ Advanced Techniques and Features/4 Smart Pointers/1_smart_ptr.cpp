/** Smart pointers
 *
 *      These are objects that thinks they are pointers. It behaves like pointers (we can use deference operator like *, ->)
 */
#include <iostream>
#include <memory>  // smart pointer

// Smart pointer follow the RAII pattern
//                          ~~~~~~~~~~~~
//                              ^
//      You create an object that owns a resource and when the object goes out of scope, its destructor will be called and 
//  its destructor deletes the resource.
//
//
// The memory labrary oofers the following types of smart pointers:
//
//      std::shared_ptr:    Object ownership shared among multiple pointers. It is a reference counter of shared-pointer to an object
//                          When a shared-pointer is destroyed, the reference count is decremented. Whern the last remaing 
//                          shared-pointer goes away, the reference count becomes zero and it triggers disposal of the object.
//
//      std::weak_ptr  :    Non-owning observers of shared object. It is kind of closely related to shared-ptr except that a 
//                          weak-pointer does not contribute to the reference count.
//
//      std::unique_ptr:    Single owner of shared resource. IT doesnt support copy construtctor.
//
//
//  All of these pointers assume that the object is being created on the heap region of memory.
//

//
// Typical use of smart pointers:
//  

// - Exception safety
void f1()
{
    // Creates a raw pointer
    int* p = new int;

    // if an exception occurs here, you will never get to the end of the function
    // The pointer does go out of the scope, so that a memory leak. The code isnt exception-safe

    delete p;
}

void f2()
{
    std::unique_ptr<int> p(new int);

    // if an exception occurs here, you will never get to the end of the function
    // but The pointer is destructor will be invoked and can delete the object that it points to. 
    // The code is exception-safe

}

//
//
//      - Ensures client code releases dynamic resources, without a proliferation of 'try/catch' statements in every function


int main()
{   
    return 0;
}