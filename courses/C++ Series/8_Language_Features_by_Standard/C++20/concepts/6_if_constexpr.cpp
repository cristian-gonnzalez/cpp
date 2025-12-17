/** C++ 20 Concepts - concepts with if constexpr 
 *
 */

#include <concepts>
#include <iostream>
#include <print>
#include <vector>

//
// Concepts
//
template <typename T>
concept Printable = requires(T obj)
//                  ~~~~~~~~
//   Requires clause is the constraint on 'T'
{
    // The code that must complite
    std::print("{}", obj);
};


/*template <typename T>
concept Streamable = requires(T obj)
{
    std::cout << obj << std::endl;
};*/

template <typename T>
concept Streamable = requires(T obj, std::ostream& o)
{
    o << obj << std::endl;
};

// Example conjuntion to 'compose' a more interesting or specific concept
// Note: Conjuntions
//      The conjuntion of two constrains is formed by using the && operator
template <typename T>
concept Outputble = Streamable<T> || Printable<T>;

//
// Templates
//

/*
// note: constraints not satisfied
template <Streamable T>
void pretty_print(T t)
{
    // Cannot print std::vector
    //std::cout << t << std::endl;

    std::print("{}", t);
}
*/

template <Outputble T>
void pretty_print(T t)
{
    if constexpr(Streamable<T>)
        std::cout << "Streamable: " << t << std::endl;
    else
        std::println("Printable: {}", t);

        
    // we can combine
    //if constexpr(!Printable<T> && Streamable<T>)
    //    std::cout << "Streamable:" << t << std::endl;

}


int main()
{
    std::vector v{1,2,3,4,5};

    pretty_print(v); // Printable: [1, 2, 3, 4, 5]
    pretty_print(1); // Streamable: 1



	return 0;
}

