

// @file thread5.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock; 
        // ^
        // Global variable

// This is our critical section to be access by multiple threads
static int shared_value= 0;

// 
// std::mutex:
//
//      Mutex stands for 'mutual exclusion' so you have  mutually exclusive access. That means that one entity
//  has exclusive access to some resource
//
//      Mutes is called a binary semaphore.

/*
                   unlock                 
     ----------------
    |  shared_value  |    <------- Critical section
     ---------------- 
                   lock
      ^      ^      ^                              
      |      |      |                                                
      |      |      |                                                   
      |      |      |
     t1     t3      t2  .....
   

   Each of these threads are trying to race to access this particular shared_value.
   If t2 adquire the lock, all the other threas are blcoked from accessing this value 
   untils t2 unlocks the value
*/


void shared_value_increment(){
    gLock.lock();
    //    ~~~~~
    //   locks the mutex, blocks all the other threads if the mutex is not available
    //   Now the other threads will essentially will be waiting there for that lock to be available

    // this is our synchonized piece of code
    //  ----- CRITICAL SECTION ---------
        
        shared_value = shared_value + 1;
        
    //  --------------------------------
    
    gLock.unlock();
    //    ~~~~~~
    //    unlocks the mutex
}

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 100; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(auto& t: threads){
        t.join(); 
    }

    std::cout << "Shared value: " << shared_value << std::endl; // Shared value: 100
    return 0;
}
