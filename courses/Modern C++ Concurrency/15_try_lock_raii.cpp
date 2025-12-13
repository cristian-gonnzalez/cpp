#include <mutex>
#include <iostream>
#include <thread>

std::mutex my_mutex;


/*
    NOTE: try_lock with RAII


        Use std::adopt_lock in C++ is a tag used with lock wrappers like std::lock_guard or std::unique_lock 
    to signify that the calling thread already owns the mutex it's trying to wrap. This is useful when you've 
    already locked the mutex using std::lock and want to create a RAII-style wrapper to ensure it's unlocked 
    when the scope ends. It prevents the wrapper from attempting to lock the mutex again, which would be 
    an error.

    std::lock( my_mutext );
    std::lock_guard<std::mutex> lock(my_mutex, std::adopt_lock);

        But only use try_to_lock with unique_lock. std::lock_guard only supports std::adopt_lock;

*/



void thread_function() {
    // Attempt to lock the mutex without blocking
    std::unique_lock<std::mutex> lock(my_mutex, std::try_to_lock);

    if (lock.owns_lock()) {
        // Successfully locked the mutex
        std::cout << "Thread " << std::this_thread::get_id() << " locked the mutex.\n";
        // ... do work ...
        // Mutex is automatically unlocked when 'lock' goes out of scope
    } else {
        // The mutex was not available
        std::cout << "Thread " << std::this_thread::get_id() << " failed to lock the mutex.\n";
        // ... handle the failure, e.g., try again later ...
    }
}

int main() {
    std::thread t1(thread_function);
    std::thread t2(thread_function);

    t1.join();
    t2.join();

    return 0;
}
