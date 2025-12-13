/** Condition Variable in Modern cpp and unique lock
 */
// @file cv.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable> // std::conditional_variable

/*
    std::conditional_variable:

        We have threads. Each of those threads might be spawning some piece of code
    and trying to access some critical section that is protected by a lock. This means 
    that only one of the threads at a time can acquire the lock and access the critical 
    section.

     -----------------------------
    |       Critical section     | 
     ---------------------------- 
            lock       
      ^      ^      ^                              
      |      |      |                                                
      |      |      |                                                   
      |      |      |
     t1     t2      t3  ..... tn

        The condition variable is another type of synchronization primitive that can be
    used to block a thread or multiple threads at the same time, until another thread 
    modifies a shared variable (the condition) and notifies the condition_variable

        The condition varibale class used with a std::mutex to block one or more threads.
    In a sense just putting them to sleep and and taking off the queue to avoid keep constantly
    check if you acquire the lock amking this very efficient
        
*/


std::mutex g_mutex;
std::condition_variable g_cv;

int main(){

    int result = 0;
    bool notified = false;  // With this we can wake up one or more threads 

    // Reporting thread
    // Must wait on work, done by the working thread
    std::thread reporter( [&]
                          {
                              // Why it must use std::unique_lock instead of std::lock_guard?
                              // wait() requires std::unique_lock because it needs to:
                              //
                              // - atomically unlock the mutex,
                              // - sleep,
                              // - re-lock the mutex on wakeup.
                              //
                              // std::lock_guard cannot do that (no unlock/relock interface).
                              std::unique_lock<std::mutex> lock(g_mutex);

                              // blocks the current thread until the condition variable is awakened
                              //
                              // NOTE:
                              //   This means that even if this reporting thread happens to execute first
                              // we have to wait until our condition variable is woken up. 
                              // So, the condition variable will automatically release the lock and blocks 
                              // until being notified by the condition variable
                              g_cv.wait(lock, [&] { return notified; });
                              //   ~~~~
                              //  we wait some true/false condition

                              /* We can also do this
                              if(!notified)
                              {
                                  g_cv.wait(lock);    
                              }*/

                              std::cout << "Reporter, result is: " << result << std::endl; // Reporter, result is: 50
                          });

    // Working thread
    std::thread worker([&]
                        {
                            std::unique_lock<std::mutex> lock(g_mutex); // we could use std::lock_guard here
                         
                            // Do our work, because we have the lock
                            result = 42 + 1 + 7;
                         
                            // Our work is done
                            notified = true;
                         
                            std::this_thread::sleep_for(std::chrono::seconds(5));
                            std::cout << "Work complete\n"; // Work complete

                         
                            // Wake up a thread, that is waiting, for some
                            // condition to be true
                            g_cv.notify_one();
                        });

    reporter.join();
    worker.join();

    std::cout << "Program complete" << std::endl; // Program complete
    return 0;
}
