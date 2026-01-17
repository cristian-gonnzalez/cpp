/** auto: Placeholder type specifiers
 */
#include <iostream>
#include <string>
#include <vector>

/*
  'auto' keyword has been gone to a tranformation during the C++ history. Prior C++11, it 
used to mean 'automatic-storage' which was the deafault when we create a variable and 
place it on the stack so it wasnt really used and it was not useful for us because it was 
redundant than how we would use.

  Since C++11, the 'auto' keyword get repurposed in modern C++ so this means a way to 
automamatically deduce or infer a type.

  see https://google.github.io/styleguide/cppguide.html#Type_deduction

*/

int main()
{
   {
     int value{17};
     std::cout << value << std::endl; // 17
   }
   {
     auto value{72};   //  cppinsights -> int value = {72};  
//   ^~~~       ^~ 
//   The compiler is smart enough to deduce that this type is an integer 
// (or maybe a long or short) or some other type that can hold 72                          
     std::cout << value << std::endl; // 72

     //   Now this bearas a little bit of discusion beacuse maybe this 72 
     // was meant to be a char in the ASCII table since this fits in 1 byte 
     // of information.
     //
     //   This is sth we do have to be carefull of when using 'auto'

     
     auto value2{17.02};   //  cppinsights -> int  double value2 = {17.02};
     auto value3{17.02f};  //  cppinsights -> float value3 = {17.0200005F};
   }
   {   
 // We expect a std::string    
 //   ^~~~
     auto s{"This is a string"};  //  cppinsights -> const char * s = {"This is a string"};
 //         ^~~~~~~~~~~~~~~~
 //        But this is actually a literal string 'const char*' 

     //   We try to force the compiler to deduce std::string by using size() member function
     // but 'auto' is not necessarryly smart enough to guess what our intent is.
     auto s2{"This is a string"}; // cppinsights -> const char * s2 = {"This is a string"};
//     std::cout << s2.size() << std::endl;
     //                ^~~~
     // error: request for member 'size' in 's2', which is of non-class type 'const char*'
   
     auto s3{std::string("This is a string") }; // cppinsights -> std::basic_string<char> s3 = {std::basic_string<char>(std::basic_string<char>("This is a string", std::allocator<char>()))};};
   }

    std::vector ints{1,2,3,4,5};
    std::cout << "[";  
    for( auto& e: ints)  
        std::cout << e <<  ", ";  
    std::cout << "]\n";   // [1, 2, 3, 4, 5, ]

    std::cout << "[";  
	for(auto it = ints.begin(); it != ints.end(); ++it)
//       ^~~     
//   std::vector<int> iterator  
        std::cout << *it <<  ", ";  
    std::cout << "]\n";   // [1, 2, 3, 4, 5, ]
    return 0;
}