/** The law of the big 2
 */

#include <iostream>
#include <memory>

/** The Law of the Big 2

   An amendment to the rule of 3.

   If a class uses RAII types for all nontrivial member resources,
 then the destructor can be left as default because RAII members handle 
 destruction automatically.

   However, if I still needs to perform a deep-copy, the class must implement 
the other 2 (copy semantics):

      1. Copy constructor
      2. Copy assignment operator

   In this example, std::unique_ptr deletes copying, so the compiler cannot 
generate copy semantics. Even if std::shared_ptr were used, it would copy the 
pointer (shallow copy), meaning both objects would share the same array. Since 
we need each Array object to own its own data, we must implement a deep copy.

*/

class Array
{
  public:
    //
    // Special member functions
    //

    // 1. Constructor
    Array();
    // 2. Destructor: (default — std::unique_ptr already manages destruction)
    // ~Array() = default;
    // 3. Copy semantics: Copy constructor & Copy assigment operator  // By law of the big 2
    // 3. Copy constructor  (deep-copy)
    Array(const Array& other);
    // (3 or 4). Copy assigment operator (deep-copy)
    Array& operator=(const Array& rhs);
    
    // Other member functions
    void print() const;
    void set_data(size_t index, int value);

  private:
    size_t _len;                // built-in type: long
    std::unique_ptr<int[]> _data;  // nontrivial RAII type (noncopyable)
                //  ^~~~~                Still needs to implement copy semantics
                //     |               Since I need a deep copy but std::unique_ptr  
                // nontrvial type      manages the destructor so I dont need to 
                //                     implement this (Law of the big 2)                                       
};

// 1. Constructor
Array::Array()
: _data(new int[10]), _len(10)
{
    for(size_t i=0; i<_len; i++)
        _data[i] = i*i;
}

// 3. Copy constructor (deep copy)
Array::Array(const Array& other)
: _len(other._len), _data(new int[other._len])
{
    for(size_t i=0; i<_len; i++)
        _data[i] = other._data[i];
}

// (3 or 4). Copy assigment operator (deep copy)
Array& Array::operator=(const Array& rhs)
{
    if(this != &rhs)
    {
        _len = rhs._len;
 
        // Allocate new memory and replace old allocation
        _data.reset( new int[_len] );
        
        for(size_t i=0; i<_len; i++)
            _data[i] = rhs._data[i];
    }

    return *this;
}

    
void Array::print() const
{
    std::cout << "[";
    for(size_t i=0; i<_len; i++)
        std::cout << _data[i] << ", ";
    std::cout << "]\n";
}

void Array::set_data(size_t index, int value)
{
    _data[index] = value;
}

int main()
{
    Array a1;
    a1.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

    Array a2;        
    a2 = a1;  // Copy assigment operator

    a1.set_data(0, 72);

    a1.print(); // [72, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
    a2.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

    return 0;
}

