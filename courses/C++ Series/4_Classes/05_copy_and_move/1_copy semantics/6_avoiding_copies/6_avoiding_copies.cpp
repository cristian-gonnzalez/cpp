/** Copy semantics: avoiding copies
 */

#include <iostream>
#include <memory>

/** 

If you have your class and you want to avoid copies. You can

    - set private the copy contructor and copy assigment operation

class T
{
    public:

    private:
        T( const T& other );
        T& operator=( const T& rhs );
};

    - assign 'delete' the copy contructor and copy assigment operation


class T
{
    public:
        T( const T& other ) = delete;
        T& operator=( const T& rhs ) = delete;
};


  If you want to prevent a class from being copyable, there are two ways:

1. (Old C++03 style) Declare the copy constructor and copy assignment operator private:

    class T {
        private:
            T(const T& other);
            T& operator=(const T& rhs);
    };

2. (Modern C++11) Explicitly delete them:

    class T {
        public:
            T(const T& other) = delete;
            T& operator=(const T& rhs) = delete;
    };

  Using '= delete' is clearer and immediately produces a compiler error when copying 
is attempted.


*/

class Array
{
  public:
    
    Array();
    ~Array();
    
    // avoids copies
    Array(const Array& other) = delete;
    Array& operator=(const Array& rhs) = delete;
    
    void print() const;
    void set_data(size_t index, int value);

  private:
    size_t _len;                
    int* _data;                               
};

Array::Array()
: _len(10), _data(new int[10])
{
    for(size_t i=0; i<_len; i++)
        _data[i] = i*i;
}

Array::~Array()
{
    delete[] _data;
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
    // a2 = a1;  // Copy assigment operator deleted

    a1.set_data(0, 72);

    a1.print(); // [72, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
    a2.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

    return 0;
}

