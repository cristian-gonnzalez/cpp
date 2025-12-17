/** std::unique_ptr and custom deleter
 */
#include <iostream>
#include <memory>

/*

Defined in <memory>

template<
    class T,
    class Deleter = std::default_delete<T>  //   Deleter must be:
                                            //            - FunctionObject  
                                            //            - lvalue reference to a FunctionObject 
                                            //            - lvalue reference to function, 
                                            // callable with an argument of type unique_ptr<T, Deleter>::pointer.
> class std::unique_ptr;


Note:
  - std::make_unique always returns std::unique_ptr<T, std::default_delete<T>>
    and does NOT allow specifying a custom deleter.

*/


struct IntDeleter
{
    void operator()( int* int_ptr )
    {
        std::cout << "IntDeleter called " <<  ++_counter << " times\n";

        delete int_ptr;
    }

    inline static size_t _counter{0};
};

int main()
{
    // ERROR:
    //   We can NOT use std::make_unique with a custom deleter since std::make_unique<int>() 
    // returns std::unique_ptr<int, std::default_delete<int>>
    //
//   std::unique_ptr<int, IntDeleter> up{ std::make_unique<int>() };

   {
     std::unique_ptr<int, IntDeleter> up{ new int() };
 
   }// IntDeleter called 1 times

   std::cout << "This line is print to show that we are out of scope\n";

   return 0;
}