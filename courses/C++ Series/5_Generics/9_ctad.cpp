/** Class Template Argument Deduction (CTAD) (C++17)
 *  
 */
#include <iostream>
#include <vector>

// CTAD:
//  It is the ability to figure out what the arguments are of a template without actually having to type them in


template<typename Key, typename Value>
struct Entry 
{
    Entry(Key key, Value value)
    : _key{key}, _value{value}
    {
        std::cout << "Entry()\n";
    }
    Key _key;
    Value _value;
};

/*
// The compiler intansiates these template specializations

template<>
struct Entry<int, int>
{
  inline Entry(int key, int value)
  : _key{key}
  , _value{value}
  {
    std::operator<<(std::cout, "Entry()\n");
  }
  
  int _key;
  int _value;
};

template<>
struct Entry<int, float>
{
  inline Entry(int key, float value)
  : _key{key}
  , _value{value}
  {
    std::operator<<(std::cout, "Entry()\n");
  }
  
  int _key;
  float _value;
};


*/


int main()
{
   // Entry<int, int> e{5, 100}
   //       ~~~~~~~~~
   //   CTAD implies that we dont have to provide these parametrs here. The compler has some way that it can figure out what the
   //  types are, we just dont have to specify
   Entry e{5, 100};

   std::cout << "Entry { " 
             << "key: " << e._key << ", "
             << "value: " << e._value << " }\n"; // Entry { key: 5, value: 100 }

    
   Entry e2{5, 100.1f};

   std::cout << "Entry { " 
             << "key: " << e2._key << ", "
             << "value: " << e2._value << " }\n"; // Entry { key: 5, value: 100.1 }


    std::vector v1{100,200,300}; // std::vector<int> v1{100,200,300};

    // Now this does cause a problem because the compiler needs me to make a decision. Basically. deciding what is the actual type.
    // std::vector v2{100, 2.5f, 300}; 
    //                 ^   ~~~~   ^
    //                int  float  int
   
   
    std::vector v2{100.0f, 2.5f, 300.0f};  // std::vector<float> v2{100.0f, 2.5f, 300.0f}; 
    
   return 0;
}