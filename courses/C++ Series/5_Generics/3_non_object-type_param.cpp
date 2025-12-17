#include <iostream> 
#include <typeinfo> 

//        Object type     non-object type 
//            ^                  ^
//            |                  |
template< typename T1,     std::size_t N   >
void foo(T1 input1) {
    std::cout << typeid(input1).name() << "->" << input1 << std::endl;
    std::cout << typeid(N).name() << "->" << N << std::endl;
}

int main()
{
    foo<int, 3>(5);
    foo<int, 4>(5);
    foo<int, 5>(5);
    
    /*
      CAREFULLY: The compiler will instantiate 3 overloading of the function

      void foo<int, 3>(int)
      void foo<int, 4>(int)
      void foo<int, 5>(int)

      This can cause overhead in performance
    
     */


    return 0;
}
