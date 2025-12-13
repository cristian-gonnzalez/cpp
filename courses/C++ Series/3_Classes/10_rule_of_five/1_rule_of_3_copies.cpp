/** The rule of 5
 */

#include <iostream>
#include <string>
#include <utility> // std::exchange

/*
The rule of 5:
    The Rule of Big Five is an extension of the Rule of Three to include move semantics.

    This is related with the idea to avoid making copies of our objects. We just want to 
  transfer the resoruce from one object to another (steal the resource)

*/

class Array
{
  public:
    //
    // Special member functions
    //

    // The Big 3

    // 1. Constructor
    Array(std::string name);
    // 2. Destructor                                                  // By rule of 3
    ~Array();
    // 3. Copy semantics: Copy constructor & Copy assigment operator  // By rule of 3
    // 3.1 Copy constructor
    Array(const Array& other);
    // 3.2 Copy assigment operator
    Array& operator=(const Array& rhs);
    

    // Other member functions
    friend std::ostream& operator<<(std::ostream& os, const Array& rhs );
    
  private:
    std::string _name;
    size_t _len;   // built-in type: long
    int*   _data;  // built-in type:  Non-trivial type (deep copy)                                       
};


// 1. Constructor
Array::Array(std::string name)
: _name(name), _len(10), _data(new int[10])
{
    std::cout << "'" << _name << "' was constructed\n";
    for(size_t i=0; i<_len; i++)
        _data[i] = i*i;
}
// 2. Destructor
Array::~Array()
{
    std::cout << "'" << _name << "' was destroyed\n";
    delete[] _data;
}

// 3.1. Copy constructor
Array::Array(const Array& other)
: _name(other._name + " (copy)"), _len(other._len), _data(new int[other._len])
{
    std::cout << "'" << _name << "' was copy created\n";

    for(size_t i=0; i<_len; i++)
        _data[i] = other._data[i];
}

// 3.2. Copy assigment operator
Array& Array::operator=(const Array& rhs)
{
    // Checks that Im not copying myself
    if(this != &rhs)
    {
        // Deletes old data
        delete[] _data;

        // depp copy
        _name = rhs._name + " (copy)";
        _len = rhs._len;
        _data = new int[_len];
        
        for(size_t i=0; i<_len; i++)
            _data[i] = rhs._data[i];
    }

    std::cout << "'" << _name << "' was copy assigned from '" << rhs._name << "'\n";

    return *this;
}


std::ostream& operator<<(std::ostream& os, const Array& rhs )
{
    os << "'" << rhs._name << "': [";
    for(size_t i=0; i<rhs._len; i++)
        os << rhs._data[i] << ", ";
    os << "]";

    return os;
}

void foo(Array copy)
{
}

Array make_array()
{
    Array r("make_array");
    return r; 
}


int main()
{ 
    {
        Array a1("array 1");  // 'array 1' was constructed
        Array a2 = a1;         // 'array 1 (copy)' was copy created

       
      // Note:  
      // See that the order that these objects are destroyed are a reserve order
      // in which these were constructed

    } // 'array 1 (copy)' was destroyed
      // 'array 1' was destroyed

    std::cout << std::endl;
    {
        Array a1("array 1");  // 'array 1' was constructed
    
        foo(a1); // 'array 1 (copy)' was copy created
                 // 'array 1 (copy)' was destroyed
       
        std::cout << "This line is printed on purpose\n";

    } // 'array 1' was destroyed

    std::cout << std::endl;
    {
        Array a1("array 1");  // 'array 1' was constructed
        
        make_array();    // 'make_array' was constructed
                //  ^ -> // 'make_array' was destroyed
                // the object is destroyed at the en of this sentence.

        std::cout << "This line is printed on purpose\n";

    }  // 'array 1' was destroyed
    std::cout << std::endl;
 

    std::cout << std::endl;
    {
        Array a1("array 1");  // 'array 1' was constructed
        
        Array r = make_array();  // 'make_array' was constructed
        //                    ~
        //           RVO: The make_array is constructed in r (in place)     
                       
        std::cout << "This line is printed on purpose\n";

    } // 'make_array' was destroyed            
      // 'array 1' was destroyed
    std::cout << std::endl;

    return 0;
} 
  

