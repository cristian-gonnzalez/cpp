/** Template Metaprogramming - Type traits - part 1 of n
 *  
 *  Metaprograming: This is a set of tools that facilatates compile time programming.
 *  This is a type of code that we want to execute at compile time and the type of code
 *  we want to generate at compile time.
 *
 *  For ex: static_assert, ifdef, define, concepts, templates ... these are all different 
 *  thinds that we are fetermining at compile time and then generating or metagramming new code
 *  to do sth new
 *
 *  Typetraits: helps us define at compile time usually to query some property of the 
 *  parameter that we are passing in some templated function, struct, class, etc. 
 *  Type traits give us information at compile-time and then we make decisions about are we going
 *  to use this particular function or struct.
 */
#include <print>
#include <type_traits>
#include <cmath>

struct Monster
{
    int strengh;
    int health;  
};

// Creating a new trait
// So I need the 'false_type' and the 'true_type'

// False condition
template<typename T>
struct is_monster : std::false_type{};  
// True condition
template<>
struct is_monster<Monster> : std::true_type{};  


int main()
{

    std::println( "float: {}", std::is_floating_point<float>::value ); // float: true
    // This is the same as bellow
    // template< class T >
    // constexpr bool is_floating_point_v = is_floating_point<T>::value;
    std::println( "float: {}", std::is_floating_point_v<float> );      // float: true

    float f{0.0f};
    // std::println( "f: {}", std::is_floating_point_v<f> ); 
    //                                                 ^
    //                        this fails since we need to pass a type
    //
    // we can figure out what is the declaration type of f wiith decltype()
    std::println( "f: {}", std::is_floating_point_v< decltype(f) > );  // f: true

    
    int i{0};
    std::println( "int; {}", std::is_floating_point<int>::value );     // int: false
    std::println( "int: {}", std::is_floating_point_v<int> );          // int: false
    std::println( "i: {}", std::is_floating_point_v< decltype(i) > );  // i: false

    Monster m;
    std::println( "m: {}", is_monster< decltype(m) >::value );          // m: true
    std::println( "i: {}", is_monster<int>::value );                    // i: false


    return 0;
}
