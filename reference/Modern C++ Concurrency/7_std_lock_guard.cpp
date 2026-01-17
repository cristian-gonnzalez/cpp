/** Preventing deadlock with std::lock_guard in modern C++ 
 */

// @file thread5.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock;
static int shared_value= 0;

/*

//
// Deadlock
//

void shared_value_increment(){
    gLock.lock();        
        shared_value = shared_value + 1;
    //gLock.unlock();
    ~~~
    If I commented this unlock, that is a thread did not return the lock
}

    We have threads (t1, t2, ....) trying to acquire this lock and t3 happends to get the lock and
    when it leaves or goes out of the scope (an unexpected return or exception) but it does not return
    this lock. That is what we call deadlock. It means that lock is never returned.

             ^ 
             | 
             |
     --------------------
    |  Critical section  | 
     -------------------- 
            lock       
      ^      ^      ^                              
      |      |      |                                                
      |      |      |                                                   
      |      |      |
     t1     t3      t2  .....


    A deadlock happens when none of our threads are able to make progress because they're blcoked or 
    not able to acquire the resource. 

*/


// This is an example where a deadlock happens when an exeption is throw
void shared_value_w_deadlock(){
    gLock.lock();        
        
    try{

        shared_value = shared_value + 1;
        throw  "dangerous...abort"; 

    }catch(...)
    {
        std::cout << "handle exception\n";
        return;   // go out of the scope without returning the lock
    }

    gLock.unlock();
}

//
// std::lock_guard:
//
//      Defined in header <mutex>
//
// template< class Mutex >
// class lock_guard;
//
//      The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a 
// mutex for the duration of a scoped block. As it is RAII-stype, even though an exception is thrown, the mutex
// is release.
//
//      When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When 
// control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and 
// the mutex is released.
// 
// The lock_guard class is non-copyable.
//
void shared_value_increment(){
    
    // All these sentences are not syncrhonized with lock_guard
    int i = 0;
    i += 5;

    std::lock_guard<std::mutex> lockGuard(gLock);  // --------> After this call, the mutex is lock
    //                                    ~~~~~                 This means that the mutex is lock when the lock_guard 
    //                      lock_guard is holding the mutex     object is cretaed until the object is destroyed
    
    shared_value = shared_value + 1;

} // releasing the mutex

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 100; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 100; i++){
        threads[i].join(); 
    }

    std::cout << "Shared value: " << shared_value << std::endl; // Shared value: 100
    return 0;
}
