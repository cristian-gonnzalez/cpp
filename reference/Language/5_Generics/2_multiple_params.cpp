#include <iostream> 
#include <typeinfo> 


//        Object type   Object type 
//            ^            ^
//            |            |
template<typename T1, typename T2>
void foo(T1 input1, T2 input2) {
    std::cout << typeid(input1).name() << "->" << input1 << std::endl;
    std::cout << typeid(input2).name() << "->" << input2 << std::endl;
}

int main()
{
  /* The compiler creates the instantiated function from template

      template<>
      void foo<int, float>(int input1, float input2)
      {
        std::operator<<(std::operator<<(std::cout, typeid(input1).name()), "->").operator<<(input1).operator<<(std::endl);
        std::operator<<(std::operator<<(std::cout, typeid(input2).name()), "->").operator<<(input2).operator<<(std::endl);
      }
  */
    foo<int, float>(5, 3.14f);
    

  /* The compiler creates the another instantiated function from template since the sequence of template parameter list is diferent

      template<>
      void foo<float, int>(float input1, int input2)
      {
        std::operator<<(std::operator<<(std::cout, typeid(input1).name()), "->").operator<<(input1).operator<<(std::endl);
        std::operator<<(std::operator<<(std::cout, typeid(input2).name()), "->").operator<<(input2).operator<<(std::endl);
      }
      #endif
  */
    foo<float, int>(3.14f, 5);
    
    return 0;
}
