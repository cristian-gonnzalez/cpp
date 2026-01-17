/** std::weak_tr
 *
 *      Use std::weak_ptr to observe an object, where you dont absolutely require it to remain alive.
 *
 *      You can also use std::weak_ptr to prevent circular references between 'std::shared_ptr's
 */
#include <iostream>
#include <memory>  // std::shared_ptr/std::weak_ptr

int main()
{
    // You can create a weak pointer from a shared pointer except that the weak pointer doesnt participate in the reference count.
    //
    // std::weak_tr is a special-case smart pointer
    //
    //      - Used in conjunction with std::shared_ptr
    //      - Doesnt participate in reference counting
    //
    std::weak_ptr<int> wp;

    {
        // First of all, you have to create a shared_ptr;
        //
        // shared-resource | 100 |
        //                 |_____|
        //              RC | 2   |         
        //                 |_____|         
        //                  ^  
        //                  |    
        //                 sp1
        auto sp1{ std::make_shared<int>(100) };         
        std::cout << "rc: " << sp1.use_count() << std::endl;  // rc: 1

        {
            // shared-resource | 100 |
            //                 |_____|
            //              RC | 2   |         
            //                 |_____|         
            //                  ^  ^
            //          ________|  |________
            //          |                   |  
            //         sp1                 sp2    
            auto sp2{ sp1 };         
            std::cout << "rc: " << sp1.use_count() << std::endl;  // rc: 2

            // The weak pointer can observe the shared-resource but it does not participate in the reference count
            //
            // shared-resource | 100 |
            //                 |_____|  <------------wp 
            //              RC | 2   |         
            //                 |_____|         
            //                  ^  ^
            //          ________|  |________
            //          |                   |  
            //         sp1                 sp2
            wp = sp1;        
            std::cout << "rc: " << wp.use_count() << std::endl;  // rc: 2
        } // sp2 goes away
    

        std::cout << "rc: " << wp.use_count() << std::endl;  // rc: 1
        
    } // sp1 goes away
    
    // the weak_ptr isnt string enought to keep the object alive so the object would be disposed
    //
    // Note: the std::weak_ptr knows if the object has gone. When a resource's reference count becomes 0, its std::weak_ptr expire
    std::cout << "rc: " << wp.use_count() << std::endl;  // rc: 0
        
    
    return 0;
}