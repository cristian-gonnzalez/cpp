/** The rule of 3
 */

#include <iostream>
#include <string>

/*
The rule of 3:
  This rule basically states that if a class defines one (or more) of the following, 
it should explicitly define all three, which are:

    1. destructor
    2. copy constructor
    3- copy assignment operator


- Why do you need to override one of these?              trivial copy
                                                        ~~~~~~~~~~~~           
  The default constructors and assignment operators do 'shallow-copy' and we must create our own 
constructor and assignment operators when we need to perform a 'deep-copy' (For example when a class 
contains pointers pointing to dynamically allocated resources).

class T
{
    public:

    private:

        float _fvar;   | These are trivially copyable 
        int   _ivar;   |

        int*  _data_ptr; ->  This need a deep-copy
                             A shallow copy (just assigning variables) will end up with
                           two or more pointers pointing to the same piece of memory.

                             So this is a non-trivial type so we need to use the rule of
                           3.
}

  In conclusion, if your class manages something manually (e.g. new, malloc, file handles, sockets, 
mutexes), and you implement one of these three, you almost certainly must implement the other two 
to avoid:

    - double deletes
    - memory leaks
    - shared ownership of raw pointers
    - inconsistent state


Important: This is a consequence from the rule of 3
     
    Although we are not using 'move semantics'. It is important to know that:

    If a class declares any of the following (include = default or = delete declared): 
     
          – copy constructor 
          – copy assignment operator 
          – destructor 
     
    Then the compiler does NOT implicitly generate:
          – move constructor
          – move assignment operator
    
    Declaring a copy constructor does NOT suppress the copy assignment operator.
    Declaring a copy assignment operator does NOT suppress the copy constructor.

    The compiler still implicitly declares (and defines) the other copy operation,
but marks it as deprecated because only half of the copy semantics is user-defined.

*/

class Array
{
  public:
    //
    // Special member functions
    //

    // 1. Constructor
    Array();
    // 2. Destructor                                                  // By rule of 3
    ~Array();
    // 3. Copy semantics: Copy constructor & Copy assigment operator  // By rule of 3
    // 3. Copy constructor
    Array(const Array& other);
    // (3 or 4). Copy assigment operator
    Array& operator=(const Array& rhs);
    
    // Other member functions
    void print() const;
    void set_data(size_t index, int value);

  private:
    size_t _len;   // built-in type: long
    int*   _data;  // built-in type: pointer owning a heap array -> Non-trivial type
                   //                                               Needs a deep copy
                   //                                             So must implement the 
                   //                                             rule of 3:                                       
};


// 1. Constructor
Array::Array()
: _len(10), _data(new int[10])
{
    for(size_t i=0; i<_len; i++)
        _data[i] = i*i;
}
// 2. Destructor
Array::~Array()
{
    delete[] _data;
}

// 3. Copy constructor
Array::Array(const Array& other)
: _len(other._len), _data(new int[other._len])
{
    for(size_t i=0; i<_len; i++)
        _data[i] = other._data[i];
}

// (3 or 4). Copy assigment operator
Array& Array::operator=(const Array& rhs)
{
    // Checks that Im not copying myself
    if(this != &rhs)
    {
        // Deletes old data
        delete[] _data;

        // depp copy
        _len = rhs._len;
        _data = new int[_len];
        
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

