/** std::initializer_list
 *
 */
#include <iostream>
#include <initializer_list>
#include <vector>

// std::initializer_list stores the initilizer values in an array internally
//
// It offers these member functions, to allow you to access the values
//      -size()     - number of elems in the array
//      -begin()/end()
//



void f1(std::initializer_list<int> nums)
{
    std::cout << "[";
    for(auto n: nums)
        std::cout << n << ", ";
    std::cout << "]\n";
}




int main()
{   
    // Compiler creates std::initilizer_list
    //
    //  -> f1(std::initializer_list<int>{10, 20, 30});
    //
    f1( {10,20,30} );                           // [10, 20, 30, ]
    // Calling a function using {}, the values are automatically converted into a std::initializer_list
    
    
    //if you use {} with an auto variable, this is how the compiler deduces the type of the variable
    auto x{10};   // Deduces x as int

    // Can not provie multiples values with 'auto' because the compiler can  not deduce the type since there are multiples type
    // such as std::vector, std::list, ... that has a constructor with std::initializer_list
    //
    //auto y{10,20};
    //auto z{10,20,30};
    /*
            
        <source>:37:17: error: direct-list-initialization of 'auto' requires exactly one element [-fpermissive]
         37 |     auto y{10,20};
            |                 ^
        <source>:37:17: note: for
    
    */

    // Deduces z as std::initializer_list
    //
    //  -> std::initializer_list<int> z = std::initializer_list<int>{10, 20, 30};
    //
    auto z = {10, 20, 30};
    //     ^
    //  using the = operator



    auto print_v = [](auto v)
    {
        std::cout << "[";
        for(auto n: v)
            std::cout << n << ", ";
        std::cout << "]\n";
    };

    auto i1 = 10;    //   int i1 = 10;
    auto i2(10);     //   int i2 = 10;
    auto i3{10};     //   int i3 = {10};
    auto i4 = {10};  //   std::initializer_list<int> i4 = std::initializer_list<int>{10};

    std::vector<int>  v1(i1);
    std::vector<int>  v2(i2);
    std::vector<int>  v3(i3);
    std::vector<int>  v4(i4);
    
    print_v(v1);  // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ]
    print_v(v2);  // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ]
    print_v(v3);  // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ]
    print_v(v4);  // [10, ]



    return 0;
}