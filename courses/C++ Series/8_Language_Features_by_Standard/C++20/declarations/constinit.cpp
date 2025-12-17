#include <iostream>

// constinit  (C++20)
//
//  Only applies for variables
//  constinit pertains to static-storage variables only.
//  Pairs well with 'consteval'
//  Sometimes works with constexpr -- if constexpr expression evaluates at compile-time ... probably.
//  Variable must be initialized at comipile-time
//            - that means we need space for it
//            - So we need variable to be 'global' or 'static'
//
// Important: constinit doesnt imply const


// Maybe be evaluated at compile-time
constexpr int get_value_constexptr()
{
    return 42;
}

// Maybe be evaluated at compile-time
constexpr int get_value_constexptr2(int n)
{
    return 42 + n;
}

// MUST be evaluated at compile-time
consteval int get_value_consteval()
{
    return 43;
}

constexpr const char* get_string()
{
    return "Hello wordl";
}

constinit int gbl_var1 = 7;
 
int main()
{
    // constinit int var1 = 7; // error: 'constinit' can only be applied 
                               // to a variable with static or thread storage duration

    // MUST be evaluated at compile-time
    constinit static int var1 = 7;
    constinit static int var2 = get_value_constexptr();
    constinit static int var3 = get_value_constexptr2(7);
    constinit static int var4 = get_value_consteval();

    /*   
        <source>:37:26: error: 'constinit' variable 'var5' does not have a constant initializer
        37 |     constinit static int var5 = get_value_constexptr2(n);
            |                          ^~~~
        <source>:37:55: error: the value of 'n' is not usable in a constant expression
        37 |     constinit static int var5 = get_value_constexptr2(n);
            |                                                       ^
        <source>:36:9: note: 'int n' is not const
        36 |     int n;
        int n;
        constinit static int var5 = get_value_constexptr2(n);

    */
    const int n=2;
    constinit static int var5 = get_value_constexptr2(n);
    var5++;

    constinit static const char* var6 = get_string();

    return 0;
}