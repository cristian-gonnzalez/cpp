/** Generics - Perfect Forwarding / Universal References
 *
 *      
 */

#include <iostream>


// Pass-by-copy
void func(int x)
{
    std::cout << "func(int x)\n";
}

// Pass-by-revalue-reference
void func(int&& x)
{
    std::cout << "func(int&& x)\n";
}

int main()
{
    int x = 50;
    
    // Example 1: just calling func(x)
    {
        func(x);  // func(int x)
    }

    // Example 2: Calling using std::move
    {
        func(x);
        func( std::move(x) );
        //    ~~~~^~~~~~~~~~~~~~~~
        // call of overloaded 'func(std::remove_reference<int&>::type)' is ambiguous
        //
        // The compiler still rejects the call
    }
    
    return 0;
}
