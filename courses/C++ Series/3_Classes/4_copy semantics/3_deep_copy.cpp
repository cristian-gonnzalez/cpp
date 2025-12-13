/** Default copy semantics: Deep copy
 */

#include <iostream>
#include <string>

/*
Deep copy: (dor dynamically allocated memory)
   A deep copy creates a new object along with a complete, independent copy 
of all the resources owned by the original, ensuring they do not share internal 
state. In other words, to clone.

    So everytime you are using new/malloc or any memory allocation function typically
you must write you own copy semantics.

*/ 


class Array
{
  public:
    // 1. Constructor
    Array()
    : _data(new int[10]), _len(10)
    {
        for(size_t i=0; i<_len; i++)
            _data[i] = i*i;
    }
    // 2. Destructor
    ~Array()
    {
        delete[] _data;
    }

    // 3. Copy constructor
    //
    //  Array a2(a1);
    //
    //  Array a2 = a1;    
    Array(const Array& other)
    : _len(other._len), _data(new int[other._len])
    {
        std::cout << "Copy constructor\n";

        for(size_t i=0; i<_len; i++)
            _data[i] = other._data[i];
    }

    // 4. Copy assigment operator
    //      Object is already constructed, we are just makeing a copy later
    //
    //  Array a2;
    //  Array a2 = a1;
    Array& operator=(const Array& rhs)
                             //   ^~~~
                             // Rigth hand-side
    {
        std::cout << "Copy assigment operator\n";
        // Checks that Im not copying myself
        // Note:
        //   'this' is almost always placed first in idiomatic C++ (but this is style only)
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
    
    void print() const
    {
        std::cout << "[";
        for(size_t i=0; i<_len; i++)
            std::cout << _data[i] << ", ";
        std::cout << "]\n";
    }

    void set_data(size_t index, int value)
    {
        _data[index] = value;
    }

  private:
    size_t _len;   // built-in type: long
    int*   _data;  // built-in type: pointer owning a heap array
};


int main()
{
    {
        Array a1;
        a1.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

        a1.set_data(0, 1000000);
        a1.print(); // [1000000, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

        Array a2 = a1;  // Copy constructor
        //       ^
        //  Calls the copy constructor.

        a2.print(); // [1000000, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
    } 
    {
        Array a1;
        a1.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

        Array a2;        
        a2 = a1;  // Copy assigment operator

        a1.set_data(0, 72);

        a1.print(); // [72, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
        a2.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
    } 
    return 0;
}

