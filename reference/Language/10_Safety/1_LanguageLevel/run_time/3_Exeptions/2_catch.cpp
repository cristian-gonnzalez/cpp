/** Exceptions
 */

#include <print>


/*
Important rule:
  Catch blocks are checked top to bottom.

  Handlers are tried in order. First matching handler is executed.

*/

int main()
{
    // Try will execute
    try
    {
        // throwing a new exception 123
        throw 123;
    }
    // NOTE:
    //   Order matters: specific handlers must appear before generic ones.
    catch (const std::exception& e) 
    //           ^~~~~~~~~~~~~~
    // This handler does not match because we threw an int,
    // and int does not derive from std::exception.
    {
        std::println( "{}", e.what() );
    }       
    catch (...) 
    {
        std::println( "defatult catch" ); // defatult catch
    }       

    // We thrown a integer. 
    // The catch block must match the type 
    try
    {
        // An exception object of type int is created and thrown.
        throw 123;
        //    ^~~
        //    int
    }
    //      This matches the type
    //           ^~~
    catch (const int& e) 
    {
        std::println( "We caught integer: {}", e ); // We caught integer: 123
    }       
    catch (...) 
    {
        std::println( "defatult catch" ); 
    }       

    return 0;
}