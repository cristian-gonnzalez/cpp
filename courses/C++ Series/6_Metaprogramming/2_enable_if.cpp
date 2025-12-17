/** Template Metaprogramming - std::enable_if (C++11)
 *
 *
 * Defined in header <type_traits>:
 *
 *   template< bool B, class T = void >
 *   struct enable_if;
 *
 *  if B is true, we are going to create this "struct enable_if" and be able to use it. 
 *  If B is false, we are going to create a compilation error.
 *
 *  This metafunction is a convenient way to leverage SFINAE
 *  
 */
#include <print>
#include <type_traits>
#include <cmath>


/**
 *  Overload demostration
 */

//void print(int type)
//{
//    std::println("integer version of print");
//}
//
//void print(float type)
//{
//    std::println("float version of print");
//}


/**
 *  enable_if_t
 */
//struct Monster
//{
//    // int _number_int = 0;
//    std::enable_if<true, int>::type _number_int{0};
//    // std::enable_if_t<true, int> _number_int{0}; // equivalent to the previous line
//};


// C++20 version
/*template<typename T>
requires std::integral<T>
bool is_equal(T a, T b)
{
    std::print("C++20 Integral version ");
    return a==b;
}
*/


template<
  typename T, 
  typename std::enable_if_t< 
                        std::is_integral_v<T>, 
                        T* 
                        > = nullptr  // equivalent
>
bool is_equal(T a, T b)
{
    std::print("Integral version ");
    return a==b;
}


template<
  typename T, 
  typename std::enable_if_t< 
                        std::is_floating_point_v<T>, 
                        T* 
                        > = nullptr
>
bool is_equal(T a, T b)
{
    std::print("Floating point version ");
    return std::fabs(a-b) < 0.00001;
}



int main()
{
    // Overload demostration
    
    // Selects the best match: If the float version wouldnt exists, compiler would choose
    // the integer version
//    int i{0};
//    float f{0};
//    print(i); // integer version of print
//    print(f); // float version of print

    // Demo of enable_if_t
//    std::println("Size of Monster: {}", sizeof(Monster)); // Size of Monster: 4

    std::println("(1,1)       : {}", is_equal(1,1) );            // Integral version (1,1)       : true
    std::println("(1.0f,1.01f): {}", is_equal(1.0f,1.01f) );     //  Integral version (1,1)       : true


    return 0;
}
