#include <iostream>

/*
 * Aproach:
 * Overloading the function to get the result we want for each type we use: an int, double and float
 *

int square(int input) {
    return input*input;
}

double square(double input) {
    return input*input;
}

float square(float input) {
    return input*input;
}

*/

/**
 *  Templates (generics)
 *  -> Avoid copy and paste
 *  -> Serve as a blueprint for the compiler to generate the code for us.

 */

// The type name can be whatever we want but by convention we usually use T
// The compiler will generate the function with the type we need for each call
template<typename T>
T square(T input) {
    return input*input;
}

/* Compiler will generate these functions
template<>
int square<int>(int input)
{
  return input * input;
}

template<>
double square<double>(double input)
{
  return input * input;
}

template<>
float square<float>(float input)
{
  return input * input;
}

*/

int main()
{
    std::cout << square(5) << std::endl;
    std::cout << square(5.5) << std::endl;
    std::cout << square(5.5f) << std::endl << std::endl;

    // if we want we can specify the type version explicity that we want to use with template parameter
    std::cout << square<int>(5) << std::endl;
    std::cout << square<double>(5.5) << std::endl;
    std::cout << square<float>(5.5f) << std::endl << std::endl;

    std::cout << square<int>(5) << std::endl;
    std::cout << square<int>(5.5) << std::endl;
    std::cout << square<int>(5.5f) << std::endl << std::endl;

    return 0;
}

/**
OUTPUT:
25
30.25
42.25

25
30.25
42.25

25
25
36
 */
