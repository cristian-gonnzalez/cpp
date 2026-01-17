/** Template Metaprogramming - if_constexpr (c++17)
 *
 */
#include <print>
#include <type_traits>
#include <array>


constexpr auto square(auto input)
//  ^
// The compiler will try to evaluate the function at compile-time
{
    return input*input;
}

// Use case: Is if you have '1' specific 'logical path'
template<typename T>
auto myprint(T type)
{
    if constexpr( std::is_floating_point_v<T> )
    {
        std::println("Floating point: {}", type);
    }
    else if constexpr( std::is_integral_v<T> )
    {
        std::println("Integral: {}", type);
    }
    else if constexpr( std::is_array_v<T> )
    {
        std::println("Array: {}", type);
    }
    else
    {
        std::println("I dont know");
    }
    
}


/*

// Using template specialization to choose the correct function

template< 
          typename T, 
          typename std::enable_if<std::is_integral_v<T>,T*> = nullptr
         >
auto print(T type)
{
    std::println("Integral version");
}


template< 
          typename T, 
          typename std::enable_if<std::is_floating_point_v<T>,T*> = nullptr
         >
auto print(T type)
{
    std::println("Floating point version");
}
*/




int main()
{
    // You my have to encourage the compiler or sometimes use variables and so on 
    // to get this function to actually run
    std::println("square(4) = {}", square(4)); // square(4) = 16

  	const auto result = square(4);
  	std::println("square(4) = {}", result);    // square(4) = 16

    myprint(1L);                     // Integral: 1
    myprint(1.0f);                   // Floating point: 1

    // This lines of code will generate the logical path for calling array
     int arr[4];
    myprint(arr);                    // I dont know

    return 0;
}
