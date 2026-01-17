/** Generics - Perfect Forwarding / Universal References
 *
 *      
 */

#include <iostream>

//
// Forwading references:
//
//  Forwading references are a special kind of references that perserve the value category of a function argument.
//  making it possibly to forward by measn of std::forward.
//
template<typename T>
int f( T&& x )
//     ^^^
//  x is a forwading reference
{
    return g(std::forward<T>(x)); // and so can be forwarded
}

template<class T>
int g(const T&& x); // x is not a forwarding reference: const T is not cv-unqualified
 

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

template<typename T>
void FuncWrapper(T x)
{
    std::cout << "FuncWrapper<T> -> ";
    func(x);
}

template<typename T>
void FuncWrapper2(T x)
{
    std::cout << "FuncWrapper2<T> -> ";
    func( std::forward<T>(x) );
    //    ~~~~~~~~~~~~~~~~~~
    //  this will pass as T&& using universal references (NOT THE DESIRE WE EXPECTED)
    // So, the actual type will be lost
}

// Perfect Forwading / Universal References
// 1) Templated / templated parameter
//      - templated parameter has &&
// 2) std::forward wrapping the function arguments
template<typename T>
void FuncWrapper3(T&& x)
{
    std::cout << "FuncWrapper2<T> -> ";
    func( std::forward<T>(x) );
}

int main()
{
    int x = 50;
    
    // Now these call are not ambigous
    // I was able to select the calls
    func(x);                       // func(int& x)
    func( std::move(x) );          // func(int&& x)

    {
        FuncWrapper(x);                  // FuncWrapper<T> -> func(int& x)
        FuncWrapper( std::move(x) );     // FuncWrapper<T> -> func(int& x)
        //                                                    ~~~~~~~~~~~~
        //                                                        ^
        // This is not calling the correct specialization func(int&& x) or the one we expected    
    }
             
    {
        FuncWrapper2(x);                  // FuncWrapper2<T> -> func(int&& x)
        FuncWrapper2( std::move(x) );     // FuncWrapper2<T> -> func(int&& x)
    }
    
    {
        FuncWrapper3(x);                  // FuncWrapper2<T> -> func(int& x)
        FuncWrapper3( std::move(x) );     // FuncWrapper2<T> -> func(int&& x)
    }
    


    return 0;
}
