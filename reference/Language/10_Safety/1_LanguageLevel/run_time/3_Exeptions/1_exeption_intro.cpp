/** Exceptions
 */

#include <iostream>
#include <vector>

/*
see: https://cppreference.com/w/cpp/language/exceptions.html

Exception:
    How to handle bad behaviour (errors) in our program at run-time.

    We are going to have a object exception where we have different types
representing different types of errors. This is an object we can pass it
around 

    Evaluating a 'throw' expression will throw an 'exception'. The way we create
an exception object is with throw.

    In order for an exception to be caught, the throw expression has to be 
inside a try block, and the try block has to contain a handler that matches 
the type of the exception object.

*/

double f(double d)
{
    return d > 1e7 ? throw std::overflow_error("too big") : d;
}

int main()
{
    // throw must be within a try/catch. Otherwise, the program terminates and
    // crashes.
    //
    // This means that if an exception is thrown and no matching handler is found,
    // std::terminate() is called.
    //
//    throw 123;
//    ^~~~~~~~~    
// terminate called after throwing an instance of 'int'
// Program terminated with signal: SIGSEGV
    
    // Try will execute
    try
    {
        // throwing a new exception 123
        throw 123;
        //    ^~~
        // Some object type will be created with this throw
    }
    catch (...) 
    //     ^~~
    // catch all exceptions (default handler)
    {
      //   This will execute if an 'exception is thrown'.
      // Our error handling code i put and organized here.
      // And -- we can also 'transfer or forward' our exception
      // elsewhere.

      // NOTE: The catch block
      //   Sometimes we have errors in our program like logic errors 
      // but it does not necessarily take down our program. So we have 
      // to decide now how to handle these errors.
      //   This is the error handling code what to actually do to not
      // crash a program
      //
      //  This is the advantages of exception to segregate the code 

      // respond (partially) to exception 123
//      throw; // pass the exception to some other handler
    }       


    try
    {
        //std::string("abc").substr(10); // throws std::out_of_range
        //                        ^~
        //                   try to access a larger ranges outside the size
    }
    //            generic type 
    //           ^~~~~~~~~~~~~~ 
    catch (const std::exception& e)
    //                           ^
    //                        object
    {
        //std::cout << e.what() << '\n';
//      throw e; // copy-initializes a new exception object of type std::exception
//      throw;   // rethrows the exception object of type std::out_of_range
    }

    try
    {
        std::cout << f(1e10) << '\n';
    }
    //          catching specific type
    //           ^~~~~~~~~~~~~~~~~~~  
    catch (const std::overflow_error& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}