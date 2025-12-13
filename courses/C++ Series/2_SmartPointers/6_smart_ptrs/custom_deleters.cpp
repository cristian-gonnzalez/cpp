/** std::unique_ptr and custom deleter
 *  
 */
#include <iostream>
#include <memory>

/**

Defined in header '<memory>'

template<
    class T,
    class Deleter = std::default_delete<T>              -> 
> class unique_ptr;


Deleter must be FunctionObject or lvalue reference to a FunctionObject or lvalue reference to function, 
callable with an argument of type unique_ptr<T, Deleter>::pointer.

*/


struct IntDeleter
{
    void operator()( int* int_ptr )
    {
        std::cout << "IntDeleter called " <<  ++_counter << " times\n";

        if( int_ptr )
            delete int_ptr;
    }

    inline static size_t _counter{0};
};

int main()
{
   //std::unique_ptr<int, IntDeleter> up{ std::make_unique<int>() };  //-> Error
   //                       ^           ~~~~~~~~~~~~~~~~~~~~~~~
   //                    We cant use this with std::make:unique  


   {
    std::cout << "In scope\n";
  
    std::unique_ptr<int, IntDeleter> up{ new int() };
    //                       ^           ~~~~~~~~~~~~~~~~~~~~~~~
    //                    We cant use this with std::make:unique  
 
   } // IntDeleter called 1 times


   std::cout << "Out of scope\n";

   return 0;
}