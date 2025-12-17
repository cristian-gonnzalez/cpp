
#include <iostream>
#include <cmath>
#include <type_traits>

/*

// (0) Opt into using templates
// Sometimes this is exactly the rigth thing to do,
// consider containers for instance
template<
    typename T1,
    typename T2
>
bool test_equality(T1 a, T2 b)
{
    return a==b;
}

// (1) Just write a function that is overloaded for the case you need.
//     Debuggability often improves in my code
bool test_equality(float a, float b)
{
    std::cout << "this overload was selected: ";
    return std::fabs(a-b) < 0.0001f;
}

// (2) Specialization.
//     Almost as good as the overloaded version
template<>
bool test_equality(float a, float b)
{
    std::cout << "this is the specialization was selected: ";
    return std::fabs(a-b) < 0.0001f;
}

    // OUTPUT:
    
    // (0)
    // test_equality(1, 2)   : false
    // test_equality(1, 1)   : true
    // test_equality(1, 1.7f): false
    // test_equality(1.0f, 1.00000001f): true

    // (1)
    // test_equality(1, 2)   : false
    // test_equality(1, 1)   : true
    // test_equality(1, 1.7f): false
    // test_equality(1.0f, 1.00000001f): this overload was selected: true

    // (2)
    // test_equality(1, 2)   : false
    // test_equality(1, 1)   : true
    // test_equality(1, 1.7f): false
    // test_equality(1.0f, 1.00000001f): this is the specialization was selected: true


*/

// (3) Using 'if constexpr' in templates with 'type_traits' to control the flow
template<
    typename T1,
    typename T2
>
bool test_equality(T1 a, T2 b)
{
    std::cout << "a: " << a << "\tb:" << b << " = ";
    // you can within your template instantiation add control flow
    // -- I recomend this stratagy probably the least ... beacuse it's
    // harder to follow. Just write thr specialization or free function
    if constexpr(std::is_floating_point_v<T1> && std::is_floating_point_v<T2>)
    {
        std::cout << "Doing sth with floats: ";
        return std::fabs(a-b) < 0.0001f;
    }
    return a==b;
}

int main()
{
    std::cout << std::boolalpha
              << "test_equality(1, 2)   : "<< test_equality(1, 2) << std::endl
              << "test_equality(1, 1)   : "<< test_equality(1, 1) << std::endl
              << "test_equality(1, 1.7f): "<< test_equality(1, 1.7f) << std::endl 
              << "test_equality(1.0f, 1.00000001f): "<< test_equality(1.0f, 1.00000001f) << std::endl;

    /*  (3)
        OUTPUT:
        test_equality(1, 2)   : a: 1	b:2 = false
        test_equality(1, 1)   : a: 1	b:1 = true
        test_equality(1, 1.7f): a: 1	b:1.7 = false
        test_equality(1.0f, 1.00000001f): a: 1	b:1 = Doing sth with floats: true
    */
    return 0;
}