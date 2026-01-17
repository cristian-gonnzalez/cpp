/** Copy semantics
 */
#include <iostream>
#include <cstring>

// Inefficiencies of copy semantics
// 
// If you are copying from an object that you know is about to be destroyed, rather than copying the data from
// the original object into your-self, why dont you just steal the data and have it inmediately? 
//
// This is the concept of move behaviour or move semantics 
//      -> It only applies when you hace rvalues (an object which is a temporary basically and isnt going to need 
//      its data afterwards). Rather than copying this data, you can move ownership into you. It's an efficiency 
//      mechanism.    
//
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
    //
    // We are creating the object from another object.
    //
    // i.g:
    //
    // Widget w2 = w1;
    //
    // or
    //
    // Widget w2(w1);
    Widget(const Widget& other)
    //           ~~~~~~~~~~~~~  lvalue reference
    {
        std::cout << "Calling Widget(const Widget& other)\n";
        _deep_copy(other);
    }

    // 2. Copy assigment operator
    // Object is already constructed, we are just making a copy later 
    // (e.g. w1 = w2)
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

    private:

        void _deep_copy(const Widget& other)
        {
            this->_data =  new int[other._data_len];
            memcpy(_data, other._data, other._data_len*sizeof(int) );
        }


    int* _data{nullptr};          // deep copy for dyamically allocated memory
  //~~~~
  // Anytime you are using new/malloc ot any memory allocation function, you need to make a deep copy  
    int  _data_len{0};
};


Widget makeWidget()
{
    Widget w; // Calling Widget()
    return w;
}   


int main()
{
    Widget w1;               // Calling Widget() -> w1
    std::cout << std::endl;

    // Inefficiences if Copy Semantics:
    //      1. makeWidget returns a temporary Widget ('w')
    //      2. The assignment operator clones it into w1
    //      3. The temporary Widget ('w') is then descarded
    
    w1 = makeWidget();      // Calling Widget()  -> This is w inside the makeWidget();
                            // Calling copy assigment operator
                            // Calling ~Widget() -> temporary Widget 'w' (prvalue)

    std::cout << "This is a line to show that rvalue only lives in the sentence that is called\n\n";   // This is a line to show that rvalue only lives in the sentence that is called

    return 0;
}                           // Calling ~Widget() -> w1

/*
stdout
Calling Widget()               -> w1

Calling Widget()               -> w
Calling copy assigment operator
Calling ~Widget()              -> w
This is a line to show that rvalue only lives in the sentence that is called

Calling ~Widget()              -> w1
*/