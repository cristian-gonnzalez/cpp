/** Move semantics: Copying lvalues and moving rvalues
 */
#include <iostream>
#include <cstring>


//
// a = b;
//
//        If b is an lvalue, it will copy its data
//        if b is an rvalue, it will move its data


struct Widget
{
    Widget()
    {
        std::cout << "Calling Widget()\n";
    
        this->_data = new int[10];
        this->_data_len = 10;
    }
    ~Widget()
    {
        std::cout << "Calling ~Widget()\n";
        delete[] _data;
    }

    //
    // Copy semantics
    //

    // 1. Copy constructor
    Widget(const Widget& other)
    //           ~~~~~~~~~~~~~  lvalue reference
    {
        std::cout << "Calling Widget(const Widget& other)\n";
        _deep_copy(other);
    }

    // 2. Copy assigment operator
    Widget& operator=(const Widget& other)
    //                      ~~~~~~~~~~~~~  lvalue reference
    {
        std::cout << "Calling copy assigment operator\n";
        
        // Checking that Im not copying my self
        if( &other == this)
            return *this;

        // Since the object is already created, we need to delete its data
        if( _data )
            delete[] _data;

        _deep_copy(other);
        return *this;
    }
  
    //
    // Move semantics - receive rvalue (i.e. object can be moved)
    //

    // 1. Move constructor
    Widget(Widget&& rvalue) noexcept
    {
        std::cout << "Calling Widget(Widget&& rvalue)\n";
        _move(rvalue);
    }

    // 2. Move assigment operator
    Widget& operator=(Widget&& rvalue) noexcept
    {
        std::cout << "Calling move assigment operator\n";
        // Checking that Im not assignig sth to my self
        if(this != &rvalue)
        {
            delete _data;
            _data_len = 0; // just to demostrate that after delete, 
            _move(rvalue);
        }
    
        return *this;
    }

    private:

        void _move(Widget& rvalue)
        {
            // Stealing data (in this case, just copy pointers)
            this->_data =  rvalue._data;           
            this->_data_len =  rvalue._data_len;

            // Leaving rvalue in a valid state
            rvalue._data = nullptr;
            rvalue._data_len =  0; 
        }
        
        void _deep_copy(const Widget& other)
        {
            this->_data =  new int[other._data_len];
            memcpy(_data, other._data, other._data_len*sizeof(int) );
        }
        
    int* _data{nullptr};
    int  _data_len{0};
};


// NOTE:
//      The only way C++ implicitly turns an lvalue into a prvalue (eligible for move) is inside a return statement.

// A function that returns a value is an rvalue
// ^
Widget makeWidget()
{
    Widget w; // Calling Widget()
    return w;  
}                


int main()
{
    // Creating an lvalue
    Widget w1;                                        // Calling Widget() -> w1

    std::cout << std::endl;  
    
    //
    // Moving rvalues:
    //
    //   If the source is an rvalue:
    //      - The value can be moved, rather than copied
    //      - More efficient

    { 
        
        w1 = makeWidget();               // Calling Widget() -> temporary Widget w
        // ^ ~~~~~~~~~~~~                // Calling move assigment operator
        // |   rvalue                    // Calling ~Widget() -> temporary Widget w (prvalue)
        // |
        // Because of the return of makeWidget is rvalue, then it will invoke the move assigment operator  
       
        std::cout << "This is a line to show that rvalue only lives in the sentence that is called\n";
    }
    std::cout << std::endl;
    
    //
    // Copying lvalues:
    //    
    //   If the source is an lvalue:
    //      - The lvalue continues to exist afterwards (lvalue has long live)
    //      - So, it must be copies (to presercve the original value)

    {
        // w1 is an lvalue, so this statement must use 'copy semantics'.
        Widget w2(w1);              // Calling Widget(const Widget& other)
        //        ^~
        //   You cant steal the data from the lvalue

        // So its OK to keep using w1 here

    }   // Calling ~Widget() -> w2
    std::cout << std::endl;

    {
        Widget w3;      // Calling Widget()

        w3 = w1;        // Calling copy assigment operator
        // ^
        // w1 is an lvalue

    } // Calling ~Widget()
    std::cout << std::endl;


    return 0;
}                           // Calling ~Widget() -> w1
                            

/*stdout


Calling Widget()                     -> w1

//
// Moving rvalues:
//

Calling Widget()                     -> w
Calling move assigment operator
Calling ~Widget()                    -> w
This is a line to show that rvalue only lives in the sentence that is called

//
// Copying lvalues:
//

Calling Widget(const Widget& other)  -> w2
Calling ~Widget()                    -> w2  

Calling Widget()                     -> w3
Calling copy assigment operator       
Calling ~Widget()                    -> w3

Calling ~Widget()                    -> w1               
*/