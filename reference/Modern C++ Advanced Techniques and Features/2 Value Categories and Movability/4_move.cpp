/** Move semantics:
 */
#include <iostream>
#include <cstring>

// - ¿When do I have to implement Move semantics?
//
//   You would tipically implement 'copy behaviour' when you have an lvalue (an object that´s going to live long)
// You can't steal this data, you have to clone it.
//
//   The move behaviour refers to an rvalue reference (a temporary object) which its going to disappear. In that
// case, you dont clone the data, you steal it (owershop moves into you).

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
    // Note: move semantic 'steal' the valu of the incoming object...
    
    // 1. Move constructor
    // Moves owernership of some temporary object into you 
    Widget(Widget&& rvalue) noexcept  // noexcept tells the compiler: this constructor will not throw exceptions.                         
    //     ~~~~~~~~~~~~~~~            // If an exception escapes a noexcept constructor, std::terminate() is called.
    //     rvalue reference (temporary object)
    {
        std::cout << "Calling Widget(Widget&& rvalue)\n";
        _move(rvalue);
    }

    // 2. Move assignment operator
    // Moves owernership of some temporary object into you 
    Widget& operator=(Widget&& rvalue) noexcept
    //                ~~~~~~~~~~~~~~~  rvalue reference
    {
        std::cout << "Calling move assigment operator\n";
        // Checking that Im not assignig sth to my self
        if(this != &rvalue)
        {
            // Delete the old data from our object
            delete[] _data;
            _data_len = 0; // just to demostrate that after delete, 
                           // we should set len 0 as good practice. Not necesary in this case

            // Acquire the other objercts data
            _move(rvalue);
        }
    
        return *this;
    }

    private:

        void _move(Widget& rvalue)
        {
            // Stealing data (in this case, just copy pointers)
            this->_data =  rvalue._data;           // Whenever the other object is pointing to, Im going to point the same address
            this->_data_len =  rvalue._data_len;

            // Leaving rvalue in a valid state
            // Important:
            //     You have to stop the other object from owning that data
            rvalue._data = nullptr;
            rvalue._data_len =  0;
        
            // Note:
            //
            // this->_data =  rvalue._data; 
            // rvalue._data = nullptr; 
            //
            //  Equivalent:
            //
            // _data = std::exchange(other.data, nullptr);
            
            // Now you have move owernship from TEMPORARY OBJECT
            // into you rather than copying it. You'have acquired owernship of the 
            // original data.
            //
            // Efficient:
            //   At some point, the temporary object will be destroyed and 
            // the destructor is not going to do anything because it has a nullptr.
            // 
        }
        
        void _deep_copy(const Widget& other)
        {
            this->_data =  new int[other._data_len];
            memcpy(_data, other._data, other._data_len*sizeof(int) );
        }
        

    int* _data{nullptr};
    int  _data_len{0};
};


// A function that returns a value is an rvalue (prvalue)
// ^
Widget makeWidget()
{
    Widget w; // Calling Widget()
    return w;  
}                


int main()
{
    Widget w1;              // Calling Widget() -> w1

    std::cout << std::endl;  
    //
    // Example of move semantics
    //
    { 
        // makeWidget() is rvalue, so this statement can use 'move semantics'
        //      1-   makeWidget returns a temporary Widget w
        //      2-   The assignment operator moves it into w1
        //      3-   The temporary Widget w is then descarded
        
        w1 = makeWidget();               // Calling Widget()        -> temporary Widget w
        // ^  ~~~~~~~~~~~~               // Calling move assigment operator
        // | temporary Widget w          // Calling ~Widget()       -> temporary Widget w
        // |
        // Because of the return of makeWidget is rvalue, thenit will invoke the move
        // assigment operator  
        std::cout << "This is a line to show that rvalue only lives in the sentence that is called\n";   // This is a line to show that rvalue only lives in the sentence that is called

    }
    std::cout << std::endl;
    

    return 0;
}                           // Calling ~Widget() -> w1
                            

/*stdout

Calling Widget()   -> w1

Calling Widget()   -> w
Calling move assigment operator
Calling ~Widget()  -> w
This is a line to show that rvalue only lives in the sentence that is called

Calling ~Widget()  -> w1
*/