/** C++ Safety part 1 of n - Language Level Safety
 *  Run-Time
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <string>

/*
thread_local

    - For concurrent application, data races can be a huge headache.
    - thread_local storage ensures every thread gets a copy of that variable.
        * This eases the need to lock in a program, with the trade-off of extra memory
        thread_local variable per thread.
            -* thread_local storage I think probably should have been the default
            for safety but with C++ we make that decision explicity
*/

int global_counter{0};
thread_local int local_counter{0};
//^~~~~~~~~~
// Every threar that's launched will have its own copy of this variable
// so I can avoid issues of shared global values without any sort of synchronization.
// We do pay a cost but we do not have to make synchornization
std::mutex gmutex;


int main()
{
 auto increment_f = [](std::string worker)
                    {
                        local_counter++;
                        {
                            std::lock_guard<std::mutex> lock(gmutex);
                            global_counter++;
                        }
                        std::cout << worker << std::endl
                                  << "\tlocal counter : " << local_counter << std::endl
                                  << "\tglobal counter: " << global_counter << std::endl;
                    };

  for(size_t i=0; i<20; ++i)
  {
    std::jthread a(increment_f, "worker 1");
    std::jthread b(increment_f, "worker 1");
  }
  
  return 0;
}