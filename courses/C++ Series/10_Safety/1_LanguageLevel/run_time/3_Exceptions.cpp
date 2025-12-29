/** C++ Safety part 1 of n - Language Level Safety
 *  Run-Time
 */

#include <iostream>
#include <exception>
#include <print>
#include <expected>  // std::logic_error exception

/*
Exceptions (and try/catch)

- C++ provides exception handling with try/catch blocks and throw
    * As a library feature, we also have the 'std::exception' as a parent class to
    derive and create other exeptions.
- The try/catch block helps us separate error handling routines from actual logic of the program.
- Exceptions for handling 'exceptional circumstances'
    * Probably a better way to state that is, they offer an organized way report and potentially 
    handle error state in your program 


    We can be able to recover from the exception if posible or at least log the exception and 
terminate the program in an safe manner with some information recovered about what actually caused
the mistake.

    Exeption can pay some performance costs 
*/


int main()
{   
    int i = 0;
    std::cout << "Enter a positive number or I will throw an exception:";
    std::cin >> i;

    try{
        if( i == 42)
        {
            throw std::runtime_error("some type of exception");
        }
        else if( i<0)
        {
            // A more specific exception
            // Prehaps 'invalid argument' is a more useful exception?
            // Maby we could handle this logic in code otherwise
            throw std::logic_error("This could be a logic error on human");
        }
        else if(i == 0)
        {
            throw "Is zero positive?";
        }

    
    }
    // Note: We usually catch as 'const' to avoid mutatetion
    //     ^~~~~
    catch( const std::logic_error& e)
    //                           ^
    //               Usually pass by reference
    {
        std::println("(logic_error) error handling {}", e.what());
    }
    catch( const std::exception& e)
    {
        std::println("(exception) sth else {}", e.what());
    }
    catch(...)
    {
        std::println("(catch ...) sth else");     
    }
   return 0;
}