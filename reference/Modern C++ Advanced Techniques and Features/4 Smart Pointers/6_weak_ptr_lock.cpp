/** std::weak_tr
 *
 */
#include <iostream>
#include <memory>  // std::shared_ptr/std::weak_ptr


int main()
{
    auto sp{ std::make_shared<int>() };
    std::cout << "rc: " << sp.use_count() << std::endl;       // rc: 1

    // Creates a weak pointer to observe the object maintainer by a shared_ptr
    std::weak_ptr wp{sp};
    std::cout << "rc: " << sp.use_count() << std::endl;       // rc: 1

    // The lock() creates a properly shared_ptr using the weak_ptr. If the shared-resourse we observe was deleted, nullptr 
    // is returned
    // 
    // Note: When ready to access observed object, updgrade to a shared_ptr. The shared_ptr will be empty if the 
    // object has actually expired.
    auto sp2 = wp.lock();
    if(sp2)
    {
        // Here, sp2 points to the object originally pointed by wp.
        // We own the object now, so it wont disappear hereafter.

        std::cout << "rc: " << sp.use_count() << std::endl;       // rc: 2
    }
    
    std::cout << "expired: " << wp.expired() << std::endl;       // expired: 0

    // There is no object-access methods (*, ->)
    //*wp;
    //~~~
    // error: no match for 'operator*' (operand type is 'std::weak_ptr<int>')


    return 0;
}