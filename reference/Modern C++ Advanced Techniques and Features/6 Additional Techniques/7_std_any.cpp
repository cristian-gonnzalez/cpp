/** std::any
 *
 */
#include <iostream>
#include <any>  // std::any



int main()
{
    {
        
        // std::any is a container of any type of item
        // It knows what type it holds at the moment
        auto a{ std::any(42) };
        a = std::string("Jhon");
        a = 3.16;
        
    }
    // to access the value, you must use std::any_cast<T> (run-time check)
    {
        
        // std::any is a container of any type of item
        // It knows what type it holds at the moment
        auto a{ std::any(42) };
        std::cout << std::any_cast<int>(a) << std::endl;             // 42

        try {
            // if you cast it wrong, you will get an exception
            std::cout << std::any_cast<std::string>(a) << std::endl;
    
        }
        catch (std::bad_any_cast& e)
        {
            std::cout << e.what() << std::endl; // bad any_cast
        }
        
    }

    return 0;
}
