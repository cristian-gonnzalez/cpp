/** List-initialization {} vs std::initializer_list<T>:
 */ 
#include <iostream>
#include <string>
#include <vector>


int main()
{
    //
    // 2. Using {} with classes
    //

    //   When {} initializes a class type, the compiler performs constructor
    // overload resolution.  If the class has a constructor that takes
    // std::initializer_list<T>, that constructor is preferred whenever
    // it is viable.
    
    
    // This is using std::intializer_list constructor to create this object and populate
    std::vector<int> v1{1,2,3};
    
    std::cout << "[";
    for(auto& e: v1)
        std::cout << e << ", "; 
    std::cout << "]\n";  // [1, 2, 3, ]

    // Using paranthesis is different since we are calling explicity a constructor 
//    std::vector<int> v2(1,2,3);
    //                  ^ ^ ^
    // error: no matching function for call to 'std::vector<int>::vector(int, int, int)'
    
    
    // std::vector has: 
    //       - a constructor vector( size_type count, const T& value )
    std::vector<int> v3(100, 1);  // 100 copies of 1

    // std::vector also has: 
    //       - a constructor vector( std::initializer_list<T> init )
    std::vector<int> v4{100, 1};  // {100,1} → initializer_list<int>
                                  // produces a vector containing {100, 1}

    std::cout << v3.size() << "\n"; // 100
    std::cout << v4.size() << "\n"; // 2

    // Rule:
    //   A non-empty braced-init-list prefers an initializer_list constructor
    // when such a constructor exists and is viable.


    return 0;
}
