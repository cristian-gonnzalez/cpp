/** RAII (Resource Acquisition Is Initialization)
 */

#include <iostream>
#include <mutex>

/*
  RAII is C++ technique that ensures that resources are acquired and released safely 
and automatically.

  Formal definition (cppreference):
    RAII is a C++ programming technique which binds the lifetime of a resource (heap memory, 
  threads, sockets, files, mutex locks, disk space, database connection—anything that exists 
  in limited supplyetc.) to the lifetime of an object. The resource is acquired in the 
  constructor and released in the destructor.

The essential idea:

    "Use scope to manage resources."
    
  When an object goes out of scope → its destructor runs → the resource  is automatically 
released, even if:

    - a function returns early
    - a branch is skipped
    - an exception is thrown (execption safety): If an exception occurs, all destructors
    for objects on the stack are automatically called.  

- Common RAII-managed resources:
        std::lock_guard, std::unique_lock → mutex locks
        std::unique_ptr, std::shared_ptr → heap memory
        std::fstream → file handles
        std::thread → join/detach management
        std::vector, std::string → dynamic storage                           

*/

std::mutex m;

void f()
{
    throw std::runtime_error("An expetion occurs");
}

bool everything_ok()
{
    return false;
}

// Example WITHOUT RAII — unsafe
void bad() 
{
    m.lock();             // acquire the mutex
    f();                  // if f() throws an exception, the mutex is never released
    if (!everything_ok())
        return;           // early return, the mutex is never released
    m.unlock();           // if bad() reaches this statement, the mutex is released
}
 
// Example WITH RAII — safe
void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    //  ~~~~~~~~~~
    // RAII helper class: acquires the mutex in the constructor,
    // releases it automatically in the destructor.    
    
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok())
        return;                        // early return, the mutex is released
}      

int main()
{
    return 0;
}
