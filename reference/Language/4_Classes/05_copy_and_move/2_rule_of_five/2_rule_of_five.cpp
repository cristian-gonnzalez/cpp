/** The rule of 5
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::exchange


class Array
{
  public:
    //
    // Special member functions
    //

    // The Big 3

    // 1. Constructor
    Array(std::string name);
    // 2. Destructor                                               
    ~Array();
    // 3. Copy semantics: Copy constructor & Copy assigment operator
    // 3.1. Copy constructor
    Array(const Array& other);
    // 3.2. Copy assigment operator
    Array& operator=(const Array& rhs);
    
    // The other 2 (in total, making 'The Big 5')

    // (4 or 5). Move semantics: Move constructor & Move assigment operator  // By rule of 3
    // 4. Move constructor
    Array(Array&& other) noexcept;
    // 5. Move assigment operator
    Array& operator=(Array&& rhs) noexcept;
    //                            ^~~~~~~~
    //      STL containers (std::vector, std::deque, std::string, std::optional, etc.)
    //   will use move operations ONLY if they are guaranteed not to throw. If 'noexcept'
    //   is missed, the container must assume they may throw, and will use copy operations 
    //   instead.
    
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

// 4. Move constructor
Array::Array(Array&& other) noexcept
: _name( std::move(other._name) ), _len( other._len ), _data( other._data )
{
    std::cout << "'" << _name << "' was move created\n";

    other._len = 0;
    other._data = nullptr;
}

// 5. Move assigment operator
Array& Array::operator=(Array&& rhs) noexcept
{
    if(this != &rhs)
    {
         //the old data from our object
         delete[] _data;

        // this->_len =  rhs._data; 
        // rvalue._len = 0; 
        //
        //  Equivalent:
         _len = std::exchange(rhs._len, 0);
         _data = std::exchange(rhs._data, nullptr);
         _name = std::move(rhs._name);
    }

    std::cout << "'" << _name << "' used move assigned\n";

    return *this;
}
    

std::ostream& operator<<(std::ostream& os, const Array& rhs )
{
    os << "'" << rhs._name << "'";
    return os;
}

void print_v(const std::vector< Array >& v)
{
    std::cout << "[\n";
    for(auto& e: v)
        std::cout << "  " << e << std::endl;
    std::cout << "]\n";
}

void _push_back_lvalue_bad_performance()
{
    std::vector< Array > v;        
    for(size_t i = 0; i<3; ++i)
    {
        Array temp( std::to_string(i) );
        v.push_back( temp );
    }
    /*        
'0' was constructed                        -> temp  
'0 (copy)' was copy created                -> This is a push_back
'0' was destroyed                          -> temp  
'1' was constructed                        -> temp
'1 (copy)' was copy created                -> This is a push_back
'0 (copy) (copy)' was copy created         -> v needs reallocation
'0 (copy)' was destroyed            
'1' was destroyed                          -> temp
'2' was constructed                        -> temp
'2 (copy)' was copy created                -> This is a push_back  
'0 (copy) (copy) (copy)' was copy created  -> v needs reallocation
'1 (copy) (copy)' was copy created
'0 (copy) (copy)' was destroyed
'1 (copy)' was destroyed
'2' was destroyed                           -> temp 
    
    */

    print_v( v );
    /*
[
'0 (copy) (copy) (copy)'  -> 0 was copied: 1 push_back + 2 reallocation
'1 (copy) (copy)'         -> 1 was copied: 1 push_back + 1 reallocation 
'2 (copy)'                -> 2 was copied: 1 push_back
]
    */

    // NOTE:
    //    Really bad performace, we only have 3 objects and a lot of allocations made 
}

void _push_back_lvalue_w_reserve_improve_performance()
{
    std::vector< Array > v;        
    v.reserve(10); // prevents reallocations
    for(size_t i = 0; i<3; ++i)
    {
        Array temp( std::to_string(i) );
        v.push_back( temp );
    }
    /*        
'0' was constructed
'0 (copy)' was copy created      -> push_back    
'0' was destroyed
'1' was constructed
'1 (copy)' was copy created      -> push_back 
'1' was destroyed
'2' was constructed
'2 (copy)' was copy created      -> push_back
'2' was destroyed
    
    */

    print_v( v );
    /*
[
'0 (copy)'
'1 (copy)'
'2 (copy)'
]
    */

    // Note:
    // We improve the performance but we still have twice allocation per push_back
    // (One for temp and one for copy)
} 

void _push_back_lvalue_w_reserve_n_force_move_good_performance()
{
    std::vector< Array > v;
    v.reserve(10);        
    for(size_t i = 0; i<3; ++i)
    {
        Array temp( std::to_string(i) );
        v.push_back( std::move(temp) );
        //           ~~~~~~~~~~~~~~
        //           force move semantics: cast temp to xvalue
    }
    /*        
'0' was constructed
'0' was move created
'' was destroyed
'1' was constructed
'1' was move created
'' was destroyed
'2' was constructed
'2' was move created
'' was destroyed
    
    */

    print_v( v );    
    /*
[
'0'
'1'
'2'
]
    */

    // Note:
    //   We improve the performance since we only have one allocation per push_back    
} 

void _push_back_rvalue_good_perfomance()
{    
    std::vector< Array > v;        
    v.reserve(10); // prevents reallocations
    for(size_t i = 0; i<3; ++i)
        v.push_back( Array( std::to_string(i) ) );
                //   ~~~~~~~~~~~~~~~~~~~~~~~~
                //   This is an expression (prvalue) so 
                // vector prefer move semantics: void push_back( T&& value ); 
    /*        

'0' was constructed
'0' was move created
'' was destroyed
'1' was constructed
'1' was move created
'' was destroyed
'2' was constructed
'2' was move created
'' was destroyed    
    */

    print_v( v );
    /*
[
  '0'
  '1'
  '2'
]
    */

}


int main()
{
    {
        Array a1("array 1");         // 'array 1' was constructed
        std::cout << a1 << std::endl; // 'array 1': [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

        Array a2 = std::move(a1);    // 'array 1' was move created
        std::cout << a1 << std::endl; // '': []
        std::cout << a2 << std::endl; // 'array 1': [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, ]

    } // 'array 1' was destroyed
      // '' was destroyed

    _push_back_lvalue_bad_performance();
    _push_back_lvalue_w_reserve_improve_performance();
    _push_back_lvalue_w_reserve_n_force_move_good_performance();
    _push_back_rvalue_good_perfomance();
    
    return 0;
} 
  

