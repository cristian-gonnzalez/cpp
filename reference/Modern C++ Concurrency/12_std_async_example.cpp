/** std::async in cpp with background thread loading data example
 */

// @file async_buffer.cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

bool bufferedFileLoader(){
    size_t bytesLoaded = 0;
    while(bytesLoaded < 20000){
        std::cout << "thread: loading file ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}


// template< class F, class... Args >
// std::future< ReturnType > async( std::launch policy,
//                                              ~~~~~~~
//                          This is a way to design custom classes with policies
//                                     F&& f, Args&&... args );
//
// Defined in header <future>
// 
// enum class launch : /* unspecified */ {
//     async =    /* unspecified */,
//     deferred = /* unspecified */,
//     /* implementation-defined */
// };
// 
// 
// async   the task is executed on a different thread, potentially by creating and launching it first
// deferred    the task is executed on the calling thread the first time its result is requested (lazy evaluation)

//
// We can keep track of the task with:
//
// std::future_status
// 
//  enum class future_status {
//      ready,
//      timeout,
//      deferred
// };
//
//      Specifies state of a future as returned by wait_for and wait_until functions of std::future 
// and std::shared_future.

int main(){

    // This thread is going to be loading some file behind the scenes
    std::future<bool> backgroundThread = std::async(std::launch::async,
                                                    bufferedFileLoader);

    std::future_status status;
  
    // Our main program loop
    while(true)
    {
        std::cout << "Main thread is running" << std::endl;

        // artificial sleep for our program
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));
        
        // If our data is ready, that is, our background
        // thread has completed
        if(status == std::future_status::ready){
            std::cout << "Our data is ready ..." << std::endl;
            break;
        }
    }

    std::cout << "Program is complete" << std::endl;

    return 0;
}
