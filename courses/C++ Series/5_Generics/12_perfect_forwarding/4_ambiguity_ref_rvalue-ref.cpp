/** Generics - Perfect Forwarding / Universal References
 *
 *      
 */

#include <iostream>



// Pass-by-reference
void func(int& x)
{
    std::cout << "func(int& x)\n";
}
// Pass-by-revalue-reference
void func(int&& x)
{
    std::cout << "func(int&& x)\n";
}

int main()
{
    int x = 50;
    
    // Now these call are not ambigous
    // I was able to select the calls
    func(x);                       // func(int& x)
    func( std::move(x) );          // func(int&& x)
             

    return 0;
}
