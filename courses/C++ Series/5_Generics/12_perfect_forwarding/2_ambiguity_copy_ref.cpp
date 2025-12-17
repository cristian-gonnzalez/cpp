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

// Pass-by-reference
void func(int& x)
{
    std::cout << "func(int& x)\n";
}


int main()
{
    int x = 50;
    
    func(x);
    // ~~~~^~~
    // call of overload func is ambigous where we defined pass-by copy and pass by reference
    // we need to change the name or just remove one

    

    return 0;
}
