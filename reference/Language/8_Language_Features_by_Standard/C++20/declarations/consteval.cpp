/** The motivation of constexpr, consteval and constinit is to reduce runtime overhead
 */
#include <iostream>

// constexpr (C++11) which allows you to do work potentially at compile time.
// This is allowed in 
//                  - variables definitions
//                  - function or functions template declarations
//                  - decalration of static data members of literal type
//
// consteval (C++20) we get more guarantees for compile time function execution (CFT). This ensure
// that something must be evaluated at compile-time
// This is allowed in
//                  - function or functions template declarations
//

// C++11 'constexpr'
// 'May' or 'May NOT' evaluate at compile-time
// (Also nothing to do with making the variable/function 'const')
constexpr auto add(int a, int b)
{
    return a+b;
}

// C++20 'consteval'
// - MUST evaluate at compile-time or an compilation error is thrown
// - Can work with constexpre, as long as that constexpr thing evaluated at compiletime
consteval auto add_ctfe(int a, int b)
{
    return a+b;
}

int main(int argc, char* argv[])
{   
    // constexpr
    {
        {
            auto r = add(4, 5);  // <---- this is applying constexpre
            std::cout << "result: " << r << std::endl;
        }
        {
            int n=7;
            auto r = add(4, n);  // <---- this is not applying constexpr since n is not const
            std::cout << "result: " << r << std::endl;
        }
        {
            const int n=7;
            auto r = add(4, n);  // <---- this is applying constexpr since n is const
            std::cout << "result: " << r << std::endl;
        }
    }
    
    // consteval
    {
        {
            auto r = add_ctfe(4, 5);  // <---- this is applying consteval
            std::cout << "result: " << r << std::endl;

            // I cannot mutate r if I want to conserve the constexpr evaliuation
            //r++;
        }
        
        /*
        {
            int n=7;
            auto r = add_ctfe(4, n);   // <-- error: call to consteval function 'add_ctfe(4, n)' is not a constant expression
            std::cout << "result: " << r << std::endl;
        }
        */
        {
            const int n=7;
            auto r = add_ctfe(4, n);  // <---- this is applying consteval since n is const
            std::cout << "result: " << r << std::endl;
        }
        {
            const int n=7;
            auto r = add_ctfe(4, add(4, 5)); 
            //                          ^
            //                   you can use consteval with constexpr
            std::cout << "result: " << r << std::endl;

            // I could still mutate this value.
            // 'consteval' does not have anything to do with making the resulting
            // variable that stores the 'consteval function' result inmutable 
            r++;
        }    
    }


    return 0;
}