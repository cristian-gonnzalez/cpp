/** Exceptions
 */

#include <print>
#include <exception>
     //   ^~~~~~~~~
     // Provides the base class std::exception to handle errors        

/*
Member functions

    operator=       copies exception object
    what            returns an explanatory string

Standard exceptions
    This is the hierarchy

    exception:
        logic_error
            -- invalid_argument
            -- domain_error
            -- length_error
            -- out_of_range
            -- future_error
        runtime_error
            -- range_error
            -- overflow_error
            -- underflow_error
            -- regex_error
            -- system_error
                --- ios_base::failure
                --- filesystem::filesystem_error    (since C++17)
            -- tx_exception
            -- nonexistent_local_time
            -- ambiguous_local_time
            -- format_error     (since C++20)
        bad_typeid
        bad_cast
            -- bad_any_cast
        bad_optional_access     (since C++17)
        bad_expected_access     (since C++23)
        bad_weak_ptr
        bad_function_call
        bad_alloc
            -- bad_array_new_length
        bad_exception
        ios_base::failure   (until C++11)
        bad_variant_access  (since C++17)
*/

int main()
{
    try
    {
        throw std::exception();
    
        // NOTE:
        //  Constructore are:
        //
        //              exception() ;
        //              exception( const exception& other )
        //  
        //   This is not usefull since we cannot provide a type or message
        // to give information about the error. 
        //
        //   For meaningful diagnostics, use a derived class like std::runtime_error.
    }
    catch (const std::exception& e) 
    //           ^~~~~~~~~~~~~~  
    //    Works because of polymorphism.
    // std::exception has a virtual destructor and virtual what().
    {
        std::println( "{}", e.what() ); // std::exception
    }       
    catch (...) 
    {
        std::println( "defatult catch" );
    }       


    try
    {
        throw std::logic_error("Bad behaviour has occurred");
        //    ^~~~~~~~~~~~~~~~
        //  Throw create an object by value
    }
    // In general, we dont want to modify the exception information
    //     ^~~~
    catch (const std::exception& e) 
    //                         ^
    //                Thats why we catch this by reference
    {
        std::println( "{}", e.what() ); // Bad behaviour has occurred
    }       
    catch (...) 
    {
        std::println( "defatult catch" );
    }       

    return 0;
}