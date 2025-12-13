/** Default copy semantics: Shallow copy
 */

#include <iostream>
#include <string>

/*
Shallow copy:
   A shallow copy means performing 'the most trivial memberwise copy':
simply copying the values of each member (including pointers).


x = other.x;
  ^
Just assign one variable to other

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

    // 3. Copy constructor: auto-generated implements shallow copy
    //
    //   Array(const Array& other)
    //   : _len(other._len), _data(other._data)
    //              ^~~~~~~~~~         ^~~~~~~~~~
    //                  |                   |
    //          copies the integer      copies the pointer
    //          (fine)                  (WRONG for owning pointers)
    //
    //   After this, both Array objects share the same underlying memory
    // and both destructors will try to delete[] the same pointer.

    // 4. Copy assigment operator: auto-generated implements shallow copy
    //
    //   Array& operator=(const Array& other)
    //   {
    //       _len = other._len;          // OK
    //       _data = other._data;        // SHALLOW COPY — WRONG
    //                                   //                Again, both objects end up 
    //                                   //              pointing to the same memory.
    //       return *this;
    //   }
    
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

        Array a2 = a1;
        //       ^
        //  Calls the default copy constructor.
        //  It seems to work since both printed the same data
        //
        //  But internally this does:
        //   a2._data = a1._data;
        //
        //   So both objects share the same memory block.
        //   That's the reason they print the same data and each object (a1 and a2) deletes its pointer 
        // with destructor getting a double-free error 

        a2.print(); // [1000000, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
 /*
Program returned: 139
Program stderr
free(): double free detected in tcache 2
Program terminated with signal: SIGSEGV

    */
    } // We got a double-free.
      // Both a1 and a2 try to delete[] the same pointer.


    {
        Array a1;
        a1.print(); // [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

        // Calling the copy constructor before setting a1 data
        Array a2 = a1;  // shallow copy again

    
        a1.set_data(0, 72);

        // Boths a1 and a2 prints the same. This confirm that they share memory.
        a1.print(); // [72, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
        a2.print(); // [72, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]
 
 /*
Program returned: 139
Program stderr
free(): double free detected in tcache 2
Program terminated with signal: SIGSEGV

    */
    } 


    
    return 0;
}

