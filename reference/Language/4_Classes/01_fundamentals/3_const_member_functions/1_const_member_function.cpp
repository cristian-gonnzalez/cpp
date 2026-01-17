/** Const-correctness: const with member functions
 */
#include <iostream>

/*
 const with member functions:
    Making all of the member variables in a member function read-only.   
*/

class UDT
{
    public:
        void set(int value)
        {
            _value = value;
        }

        
        // Retunrs a value       // <-- I read the comments so I know that value is not change
        int get() const
        //        ^~~~~ 
        //        Cannot modify any member variables inside this call
        {
            // By error, I add a call that modify the value in a get function
        //    compute();
            // ~~~~~~~^~
            // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
            
            return _value;
        }

        
        void compute()
        {
            // do stuff...

            // At some point, we compute this
            _value = 10;
        }
    private:
        int _value;
};


// We add 'safety' to the code by making read-only argument
void set_value(const float num)
//             ^~~~~
{
//     num = 123;
    // ~~~~^~~~~
    // error: assignment of read-only parameter 'num'
}

int main()
{    
    // 1. const variables
    {   
        const float PI = 3.141526;
    //  ^~~~~
    // 'const' makes a variable immutable (read-only).

        // PI cannot change (we add safety)
        //PI = -42;
    //    ~~~^~~~~
    // error: assignment of read-only variable 'PI'

    }

    // 2. Functions with const parameters
    {
        float num{2.5f};
        set_value(num);
    }

    // 3. const with member functions
    {
        UDT u;
        u.set( 100 );
        std::cout << u.get() << std::endl;  // 100
    }


    return 0;    
}