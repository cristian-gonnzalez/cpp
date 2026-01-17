/** Function object: function with state
 */

#include <iostream> 
#include <thread> 

/*
        Func - tor
        ^~~~   ^~~
         |    Constructor
         |   
      Function 


  A function object (also called a functor) is an object that can be called
like a function. In other words, objects that behave like functions.

    This is achieved by overloading 'operator()'(Callable). 

  The key advantage over regular functions is that function objects can
store state (data members).
    
  This is why function objects are often described as "functions with state".

  Function objects are commonly used to:
        - Customize behavior of STL algorithms and containers
            (e.g., comparison predicates, hashing, sorting)
        - Store state across multiple calls
        - Implement callable objects passed to algorithms
        - Perform computations that require local state
        - Serve as callable targets for threads
*/

struct Value
{
    int    _result1{0};
    float  _result2{0.0f};

    int operator()(int result)
    {   
        _result1 = result;
        return result;
    }

    float operator()(float result)
    {   
        _result2 = result;
        return result;
    }
};

int main()
{
    Value function_obj;

    function_obj(42);
//  ^~~~~~~~~~~~~~~~
// Looks like a function call
// The interesting thing is that we are holding 42 in our member variables

    function_obj(42.7f);

    std::cout << function_obj._result1 << std::endl    // 42
              << function_obj._result2 << std::endl;   // 42.7

    // Example the usage:
    //   This function object could be used to compute different results
    // Each overload will be store calclation in different threads
    {
        // Note:
        //   Function objects are not inherently thread-safe.
        //   If a function object is shared between threads and it mutates state,
        // synchronization (e.g., mutex) is required.
        std::mutex m;

        std::thread t1( [&]()
                        {
                            // Simulate some calculation for int...
                            int r = 450;
                            
                            std::lock_guard<std::mutex> lock(m);
                            function_obj(r);
                        } );
        std::thread t2( [&]()
                        {
                            // Simulate some calculation for float...
                            float r = 13.14f;

                            std::lock_guard<std::mutex> lock(m);
                            function_obj(r);    
                        } );
        t1.join();
        t2.join();

        std::cout << function_obj._result1 << std::endl    // 450
                  << function_obj._result2 << std::endl;   // 13.14
    }
    
    return 0;
}