// -std=c++17 -lpthread

/** std::async()
 *
 * Calls functions asynchronously and how to control or to monitor the execution of those functions
 * 
 *
 */
#include <iostream>
#include <future>   // std::async()

int main()
{
    // You invoke std::async and you tell it what function you'd like to call asynchronously and any parameters you would
    // like to pass in.
    // It then gisves you back a future object (std::future) that will hold the function result. You can use the std::future 
    // to monitor progress.
    //
    //  std::future<T> std::async(function, argument_list)
    //              ^
    //          T specifies the result-type of the asynchronous call. You can specify 'void' if you like
    //
    // std::async will automatically grab a thread and it will invoke your function on that thread. 
    //
    // std::async returns inmediately. This future object is a bit like a promise, it is an empty box which will eventually
    // contain the result of the asynchronous function. If the function takes 10 seconds, tehn this future object will be like
    // an empty box until 10 seconds have elapsed and at that point it will contain the result

    // Getting the result from a future
    //
    //  - Call get() on the future object.
    //  - Blocks until a return is available, then grabs it. 
    //
    // Note: this could be potentially problematic for you because imagine the function takes 10 seconds, now you code will 
    // block 10 seconds until the other thread has terminated. If the another thread crashes, then the get function will never 
    // return. So calling get() directly is quite dangerous because you dont know how long you are going to have to wait.
    //
    // A better approach is t call 'wait_for()' so the process would be sth like this: 
    //      - kick off the asynchronous function, 
    //      - do sth main work on the main thread and then maybe wait for one second to see if the thread is finished. 
    //        If it hasnt, then do some more work and then wait again
    //
    // The wait_for() will not wau indefinetely, it will always return within the specified timeout so that you can then do some 
    // other work.
    //
    // if pass zero wait_for(0), it is a peak, it tracks momentarily at this moment has the thread finished, so it has the result. 
    // If not, the main thread can then do some more work. 
    //
    // wait_for is lke a pulling mechanism.
    //
    // Note: if the asynchronous function threw an exception:
    //      - If you are waiting on the thread, the wai will termninate
    //      - You will get the exception when you call get(). This means in practice, when you call get(), you might need to wrap
    //        in a try-catch



    // this function will now be executing on another thread. The main thread returns inmediately with the future object 'f'
    std::future<double> f = std::async( [](int x, int y) -> double
                                        {
                                            return x*y;
                                        },
                                        10, 20 );

    // Do other work here

    // In my main thread, im periodically checking the status of the future object
    while( f.wait_for( std::chrono::seconds(0) ) != std::future_status::ready )
    {
        // isnt ready, so do some more work
    }

    try
    {       
        // now get the result (or exceltion) from the future object
        double val = f.get();
        std::cout << val << std::endl; // 200

    }catch (const std::exception& e) // caught by reference to base
    {
        std::cout << " a standard exception was caught, with message: '"
                  << e.what() << "'\n";
    }

    // std::future<T>
    //      Result can only be acceed once. So if multiple thread would read the result to the future object, it could be a problem
    //      because only one thread would have the result. The solution is to create a std::shared_future<T>

    // std::shared_future<T>
    //  - Creatable from std::future
    //  - Resilt can be accessed multiple times
    //  - Appropiate when many threads access a single result 
    //
    // std::shared_future<double> f = std::async( ... )






    return 0;
}