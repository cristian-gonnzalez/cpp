/** const correctness
 *  
 */
#include <iostream>


// const correctness:
//
//  This idea that we want some values to be changed and some not
//
//  - read-only variables
//  - read-only parameters
//  - In a class, make getters const (read-only members variables)


void set_value( const float number)
//              ~~~~~~~~~~~~~~~~~~
//               read-only (inmutable) parameter
{
    //number = 72.0f;
    /*
    <source>:10:12: error: assignment of read-only parameter 'number'
   10 |     number = 72.0f;
      |     ~
    */
}

class UDT
{
    public:

        void set_value(int value)
        {
            _value = value;
        }

        int get_value() const
        //              ~~~~~
        //            member variables cannot be changed
        {
           // for some reason, everytime we get the value, we have to compute 
           //compute();
           /*
            <source>: In member function 'int UDT::get_value() const':
            <source>:39:19: error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
             39 |            compute();
                |            ~~~~~~~^~
            <source>:48:14: note:   in call to 'void UDT::compute()'
             48 |         void compute()
                |   
           */

           return _value;
        }

    private:
        int _value;


        void compute()
        {
            // some code 

            // at some moment we update _value
            // maybe by mistake
            _value = 10;
        }
};

int main()
{
    {
        // read-only (inmutable) variable 
        const float number = 2.4f;

        //number = 3.5f;
        /*
        <source>:13:12: error: assignment of read-only variable 'number'
     13 |     number = 3.5f;
        |     ~~~~~~~^~~~~~
        */
    }

    {
        UDT u1;

        u1.set_value(200);
        std::cout << "U1 { value = " << u1.get_value() << " }\n";  // U1 { value = 10 }
    }
    return 0;
}