#include <iostream>

/*

// Using another type defined by user as return type
template<typename ReturnT; typename T1, typename T2>
ReturnT multiply(const T1& a, const T2& b)
{
  return (a*b);
}


// Using auto to deduce the return type
template<typename T1, typename T2>
auto multiply(const T1& a, const T2& b)
{
  return (a*b);
}

 */

// Using -> decltype to deduce the return type (we need auto but we are more explicit)
template<typename T1, typename T2>
auto multiply(const T1& a, const T2& b) -> decltype(a*b)
{
  return (a*b);
}

int main()
{
    std::cout << multiply<float, int>(7.22f, 5) << std::endl;

    return 0;   
}