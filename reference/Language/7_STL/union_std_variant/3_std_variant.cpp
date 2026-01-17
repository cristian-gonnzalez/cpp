/** std::variant: C++17
 */

#include <iostream>
#include <variant> // C++ 17 and beyond


/* std::variant
       
    It is a type-safe union.

    template <
      class ... Types
    > class variant;

    These are sort of a tagged union. This is called tagged since we need to specify the type 
    to access data 


    A better way to overlay varius data types on same space
 
*/


// An union is a way to compactly put together a data
// It is a collection of bytes matching the largest data size

union U {
    int i;           // 4 bytes
    short s;         // 2 bytes
    float f;         // 4 bytes
}; 

int main()
{   
    // You must declare the types allowable in the space
    std::variant<int, short, float> data;
    // index      0     1      2
    data = 7.0f;
    
    // this is not as compact or efficient as an union if we are really to save bytes
    // but we are trading off is the type-safety
    std::cout << "sizeof U   : " << sizeof(U) << std::endl;     // sizeof U   : 4
    std::cout << "sizeof data: " << sizeof(data) << std::endl;  // sizeof data: 8


    // to retrive a value from a variant, we need a non-member function
    // You can get the value out of a variant vis std::get()
    //
    //      - std::get<type>( aVariant )
    //      - std::get<index>( aVariant )
    //
    std::cout << "data   : " << std::get<float>( data ) << std::endl;   // data   : 7
    std::cout << "data   : " << std::get<2>( data ) << std::endl;       // data   : 7

    /* This is why we say it adds a type-safety to unions since an exception is thrown

    std::cout << "data   : " << std::get<short>( data ) << std::endl;
                                           ^
                                          tagged
    
    terminate called after throwing an instance of 'std::bad_variant_access'
    what():  std::get: wrong index for variant
    Program terminated with signal: SIGSEGV
    
    std::cout << "data   : " << std::get<int>( data ) << std::endl;
    
    terminate called after throwing an instance of 'std::bad_variant_access'
    what():  std::get: wrong index for variant
    Program terminated with signal: SIGSEGV
    */

    // one way to ommit the exception is with std::get_if
    //
    // NOTE: You can get a pointer to the value via std::get_if(). Returns nullptr if value isnt that type
    if( auto attemp = std::get_if<float>(&data) ) 
    {
        std::cout << "We found a float " << std::get<float>( data ) << std::endl; // We found a float 7
        std::cout << "Also " << *attemp << std::endl; // Also 7
                          //    As it is a float*, I can dereference 
    
    }
    
    if( auto attemp = std::get_if<short>(&data); attemp ) 
        std::cout << "we found a short " << std::get<short>( data ) << std::endl;
    

    std::cout << "index : " << data.index() << std::endl; // index : 2


    /*
    stdout
        sizeof U   : 4
        sizeof data: 8
        data   : 7
        data   : 7
        We found a float 7
        Also 7
        index : 2
    */

    return 0;
}