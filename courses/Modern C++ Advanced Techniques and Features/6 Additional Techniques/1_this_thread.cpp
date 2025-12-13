// -std=c++17 -lpthread

/** std::this_thread namespace
 * 
 *
 */
#include <iostream>
#include <thread>
#include <chrono>

int main()
{

    std::thread t( []()
                   {
                        //
                        // std::this_thread namespace 
                        //   
                        // The std::this_thread namespace has functions that enable you to work with the current thread


                        std::thread::id id= std::this_thread::get_id();
                        std::cout << id << std::endl;  // 139732153529920


                        // it tells the current thread to stop using the CPU
                        // This is useful if you have lots of threads, so you could get the situation where if you've got 
                        std::this_thread::yield();

                    
                        // sleep in milisecons
                        using namespace std::chrono_literals;
                        std::this_thread::sleep_for( 1000ms );
                   } );


    t.join();
    return 0;
}